#include "xfs.h"

using namespace std;

XFS::XFS()
	: FileSystem()
{

}

bool XFS::mount( 
		SIZE size_hd,
		SIZE size_journal,
		SIZE size_AG,
		SIZE size_c )
{
	// Modify size if not enough
	srand (time(NULL));//���������� ��� ������ AG ��� �������� �����
	if ( size_hd < 128 * 1024 )
	{
		size_hd = 128 * 1024;
	}

	if ( size_c < 512 )	
		size_c = 512;
	else if ( size_c>65536)
		size_c=65536;

	if (size_AG<536870912) size_AG=536870912;
	else if (size_AG>4294967296) size_AG=4294967296;

	if (size_hd/size_c > 33554432) size_hd = size_c*33554432;

	if (size_journal > size_hd) size_journal = size_hd - 10 * size_c;

	size_cell=size_c;
		
		number_cells=size_hd/size_c;

		number_files=0;

		if ((size_AG%size_c)!=0) length_AG=size_AG/size_c + 1;
		else length_AG=size_AG/size_c;

		if ((size_journal%size_c)!=0) length_journal=size_journal/size_c + 1;
		else length_journal=size_journal/size_c;

		if (((2*1024)%size_c)!=0) length_inode=2*1024/size_c + 1;
		else length_inode=2*1024/size_c;

		if (((number_cells-length_journal)%length_AG)!=0) number_AG=(number_cells-length_journal)/length_AG+1;
		else number_AG=(number_cells-length_journal)/length_AG;
				
		
		SIZE i=length_journal;

	setSize( size_hd );
	setBlockSize( size_cell );
	setBlockCount( number_cells );

	allocate( size(), blockSize() );

		segment temp(0,length_journal-1,0,0);
		cells.insert(std::pair<SIZE,segment>(0,temp));//�������� ������ �� ����
		write(0, length_journal, Block::Green);
		
		number_inodes=0;
		//���������� ������� ����� � �������� ����������
		segment temp1(i,i+length_inode-1,1,number_inodes);
			cells.insert(std::pair<SIZE,segment>(i,temp1));
			write(i, length_inode, Block::Cyan);
			inode temp2(number_inodes, i, rootName().toLatin1());//�������� �������� �����
			inodes[number_inodes]=temp2;
			number_inodes++;
			i+=length_AG;

		while (i<number_cells)//���������� ������ ������ ���������
		{
			segment temp(i,i+length_inode-1,1,number_inodes);
			cells.insert(std::pair<SIZE,segment>(i,temp));
			
			write(i, length_inode, Block::Cyan);

			inode temp2(number_inodes, i,"");
			inodes[number_inodes]=temp2;

			number_inodes++;
			i+=length_AG;
		}
	
	return true;
}


//!!!
bool XFS::unmount()
{
    deallocate();
	return true;
}

QString XFS::rootName()
{
	return ".\\";
}

QString XFS::pathDelimeter()
{
	return "\\";
}

//�������� ��� � ������ �������, ���� ��������
bool XFS::addFile( const QByteArray& name, /*const QByteArray& path,*/ SIZE size_file ) { 
	if ((size_file%size_cell)!=0) size_file=size_file/size_cell + 1;
		else size_file=size_file/size_cell;

		SIZE start, end;
		 set <SIZE> set_temp;//����� ��� ����������� ����� ��� �����
		 map<SIZE,segment>::iterator it;

		 QByteArray path= rootName().toLatin1();//�������� ��� � ������ �������

		 inode* in_temp=find_dir(path);//��������� �� ����, ���� �� ���� �����, �� �������
		 in_temp->files_left--;

		 while (size_file>0)
		 {
			 pair< SIZE, bool > start_lr=find_empty_space(in_temp->AG, in_temp->start);//����� ������ �������� ����� ������ ������

			 if (start_lr.second) //���� ��� ������
			{
				start=cells[start_lr.first].end+1;//������ - ��������� �� �����
				it=cells.find(start_lr.first);

				end=((it)->second.start)-1;
				if (it!=cells.end())
					{it++;//��� ����� ������� �� ����������, ���� �������
						if (it!=cells.end()){end=((it)->second.start)-1;}
						else end=number_cells-1;}
				else
					end=number_cells-1;
			}
			else //���� ��� �����
			{
				it=cells.find(start_lr.first);
				end=start_lr.first-1;
				start=((it--)->second.end)+1;
			}
			
			 size_file=size_file-(end-start)-1;//����� ���������� ������ �����
			if (size_file<0)
			{
				if (start_lr.second) end=end+size_file;//���� ���������� ����� ������, ��� ������� �����, ������� ����� �����
				else start=start-size_file;//��� ����� ������
			}

			segment seg_temp(start,end,2,number_files);//������� �������
			cells.insert(std::pair<SIZE,segment>(start,seg_temp));//�������� ��� � ������ ���������
			write(start, end-start+1, Block::Red);

			 set_temp.insert(start);//��������
		 }
		 file f1(name,in_temp,set_temp);//������� ����
		 files.insert(std::pair<SIZE,file>(number_files,f1));
		 //files[number_files]=f1;
		 number_files++;//��������� ����� ������

	return false; }

bool XFS::deleteFile( const QByteArray& name ) { 
			  map<SIZE,file>::iterator it_f;
		for(it_f=files.begin(); it_f != files.end(); it_f++) 
		 {
			 if (it_f->second.name==name) //���� ������� ��� �����
			 {
				 it_f->second.dad->files_left++; //������� ���� � �����
				 for(set<SIZE>::const_iterator it = it_f->second.start_cells.begin(); 
					it != it_f->second.start_cells.end(); it++) {//�������� �� ������ �����
						write(cells[*it].start,cells[*it].end-cells[*it].start+1,Block::Empty);//������� ��������
						set<SIZE>::const_iterator iter= it;
						cells.erase(*iter);//������� ������ �����
				 }  
				 files.erase(it_f);//������� ���� ����
				 //number_files--;
				 break;
			 }
		 }	


	/*for each (file i in files)
		 {
			 if (i.name==name) //���� ������� ��� �����
			 {
				 i.dad->files_left++; //������� ���� � �����
				 for(set<SIZE>::const_iterator it = i.start_cells.begin(); 
					it != i.start_cells.end(); it++) {//�������� �� ������ �����
						write(cells[*it].start,cells[*it].end-cells[*it].start+1,Block::Empty);
						set<SIZE>::const_iterator iter= it;
						cells.erase(*iter);//������� ������ �����
				 }  
				 i.name=""; 
				 number_files--;
				 break;
			 }
		 }	 */
	
	return true; }

bool XFS::addDirectory( const QByteArray& name ) { 
		 SIZE i;
		 for(i=0;i<number_inodes;++i)
			 if (inodes[i].path=="") break;
		 if (i<number_inodes) //���������� ������������, ������ ����
			{
				inodes[i].path=name;
				inodes[i].files_left=64;
			}
		 else inode *temp2=create_dir(name);//������� �����	
	return true; }

bool XFS::deleteDirectory( const QByteArray& name, QList<QByteArray> fileList ) { 
		 for each(inode i in inodes)//���� ������ ����� � ����� ������, �������
		 {
			 
			 if (i.path.contains(name))
			 {
				i.path=""; 
				i.files_left=64;
			 }
		 }

		   map<SIZE,file>::iterator it_f;
		for(it_f=files.begin(); it_f != files.end(); it_f++) 
		 {
			 if (it_f->second.name.contains(name))
			{
				 for(set<SIZE>::const_iterator it = it_f->second.start_cells.begin(); 
					it != it_f->second.start_cells.end(); it++) {//�������� �� ������ �����
						write(cells[*it].start,cells[*it].end-cells[*it].start+1,Block::Empty);//������� ��������
						set<SIZE>::const_iterator iter= it;
						cells.erase(*iter);//������� ������ �����				
				 }  
				 files.erase(it_f);
				 //number_files--;
			}
		}
		/*for each(file f in files)//���� ������ ���� � ����� �������, �������
		{
			if (f.name.contains(name))
			{
				 for(set<SIZE>::const_iterator it = f.start_cells.begin(); 
					it != f.start_cells.end(); it++) {//�������� �� ������ �����
						write(cells[*it].start,cells[*it].end-cells[*it].start+1,Block::Empty);
						cells.erase(*it);//������� ������ �����				
				 }  
				 f.name=""; 
				 number_files--;
			}
		}*/
	
	return true; }

QString XFS::blockInfo( SIZE number ) {
//	int i=((number-length_journal)/length_AG)*length_AG+length_journal+1;//��� ���� ����� 1�� ����� � AG
	SIZE i=0;
		  map<SIZE,segment>::iterator it;
		  it=cells.find(i);
		for(it; it != cells.end(); it++) 
		{
			if (((it->second.end) >= number)&&(it->second.start<=number)) 
			{
				i=it->second.type;
				if (i==2) return "file - "+files[it->second.number].name;
				else if (i==1) 
					{QByteArray  s;
						if (inodes[it->second.number].path==""){s="inode number - "+QByteArray::number((it->second.number),10);
						}
					else s="inode path - "+inodes[it->second.number].path;
					
					return s;
				}
				else return "journal";
				break;
			}
			
		}
	
	return "Empty"; }

int XFS::tb( SIZE byteCount )
{
	return byteCount / blockSize();
}

pair< SIZE, bool > XFS::find_empty_space_inode(int AG,int num_cells)
{
	map<SIZE,segment>::iterator it;

	SIZE i=length_AG*AG+length_journal;//��� ���� ����� 1�� ����� � AG

	it=cells.find(i);//������� ������ �� ������

	SIZE prev_start=it->second.start;//���������� ��������� ���������� ������
	SIZE prev_end=it->second.end;
	it++;//��������� �� ���������

	SIZE closer_left=-1, closer_right=-1;//���������� ��������� ��������� ������
	SIZE left, right;//������ ��������� �����

	for(it; it != cells.end(); it++) //���� ������
	{
		if (((it->second.start)-prev_end)>num_cells) 
			{right=prev_start;
			closer_right=prev_end; break;}
		prev_start=it->second.start;
		prev_end=it->second.end;
	}
	//�������� ����� ������ � ��������� ���������, �.�. � ����� �� ���������
	if ((it == cells.end())&&((/*��������� ������*/number_cells-prev_end)>num_cells) )
			{right=prev_start;
			closer_right=prev_end;}
		 
//������ ��� ����
	it=cells.find(i);
	prev_start=it->second.start;
	prev_end=it->second.end;
	it--;

	for(it; it != cells.begin(); it--) //���� ��������� �����
	{
		if ((prev_start-(it->second.end))>num_cells){
			left=it->first;
			closer_left=prev_start; 
			break;}
		prev_start=it->second.start;
		prev_end=it->second.end;
	}
	//�������� ���������� ��������, �.�. � ����� �� ���������
	if ((it == cells.begin())&&((prev_start-(it->second.end))>num_cells)){
	left=it->first;
	closer_left=prev_start; 
	}

	if (closer_left==-1) return pair<SIZE,bool>(right,true);
	else if (closer_right==-1) return pair<SIZE,bool>(closer_left,false);
	else if ((closer_right-i)<=(i-closer_left)) return pair<SIZE,bool>(right,true);//������ � ����������
else return pair<SIZE,bool>(closer_left,false);
}

pair< SIZE, bool > XFS::find_empty_space(int AG, int start_cell)//������� ������ ��������, ����� �������� ���� ������ �����
{
	map<SIZE,segment>::iterator it;
	it=cells.find(start_cell);//������� ������ �� ������

	SIZE prev_start=it->second.start;
	SIZE prev_end=it->second.end;
	it++;//��������� �� ���������

	SIZE closer_left=-1, closer_right=-1;
	SIZE left, right;
	bool left_after_limit, right_after_limit;//������� �� ��������� ������ ����� �� AG ���� �����

	int ag_lim=length_journal+length_AG*(AG+1);//�������, ������� �� ��������� ������ ����� �� AG ���� �����

	for(it; it != cells.end(); it++) //���� ��������� ������
	{
		if (((it->second.start)-prev_end)>1) 
		{
			if (ag_lim>prev_end) right_after_limit=true;
			else right_after_limit=false;
			right=prev_start;
			closer_right=prev_end; break;}
		prev_start=it->second.start;
		prev_end=it->second.end;
	}
	//�������� ����� ������ � ��������� ���������, �.�. � ����� �� ���������
	if ((it == cells.end())&&((number_cells-prev_end)>1) )
			{
			if (ag_lim>prev_end) right_after_limit=true;
			else right_after_limit=false;
				right=prev_start;
			closer_right=prev_end;}

	//��� ����
	it=cells.find(start_cell);
	prev_start=it->second.start;
	prev_end=it->second.end;
	it--;

	ag_lim=length_journal+length_AG*AG+1;

	for(it; it != cells.begin(); it--) //���� ��������� �����
	{
		if ((prev_start-(it->second.end))>1) {
			if (ag_lim>(it->second.end)) left_after_limit=true;
			else left_after_limit=false;
			left=it->first;
			closer_left=prev_start; 
			break;}
		prev_start=it->second.start;
		prev_end=it->second.end;
	}
	//�������� ���������� ��������, �.�. � ����� �� ���������
	if ((it == cells.begin())&&((prev_start-(it->second.end))>1)){
	if (ag_lim>(it->second.end)) left_after_limit=true;
	else left_after_limit=false;
	left=it->first;
	closer_left=prev_start; 
	}

	if (closer_left==-1) return pair<SIZE,bool>(right,true);//���� ����� ��� �����
	else if (closer_right==-1) return pair<SIZE,bool>(closer_left,false);//���� ������ ��� �����
	else if (left_after_limit==right_after_limit)//���� � ����� ������ �� ������� �� �������
	{
	if ((closer_right-start_cell)<=(start_cell-closer_left)) return pair<SIZE,bool>(right,true);//���� ������ �����
	else return pair<SIZE,bool>(closer_left,false);//���� ����� �����
	}
	else if (left_after_limit) return pair<SIZE,bool>(right,true);//���� ����� �� ��������, � ������ ���
	else return pair<SIZE,bool>(closer_left,false);//���� ������ �� ��������, � ����� ���
}

XFS::inode *XFS::create_dir(const QByteArray& name)
{
	SIZE	start_ind = rand() % number_AG;
		pair< SIZE, bool > start_lr=find_empty_space_inode(start_ind,length_inode);

		
		//�� ������ ������� �������, � ������ ��������� ������ �������
	if (start_lr.second) //���� ��� ������
	{
		start_ind=cells[start_lr.first].end+1;//������ - ��������� �� �����
	}
	else //���� ��� �����
	{
		start_ind=cells[start_lr.first].start-length_inode;//������ - ���������� �� ������
	}
	inode temp2((start_ind-length_journal)/length_AG, start_ind,name);//�������� ����, �������� �� ����� AG �����

	inodes[number_inodes]=temp2;
	segment temp(start_ind,start_ind+length_inode-1,1,number_inodes);
		cells.insert(std::pair<SIZE,segment>(start_ind,temp));
	write(start_ind, length_inode, Block::Cyan);
			
	number_inodes++;

	return &inodes[number_inodes-1];
}

XFS::inode* XFS::find_dir(const QByteArray& p)//��� �����, ���� � ����������
{
	int i=-1;
	int empty=-1;
	for(i=0;i<number_inodes;++i)
	{
		if ((inodes[i].path==p)&&(inodes[i].files_left!=0)) return &inodes[i];//���� ����� ����������, �� �� �����
		if ((inodes[i].path=="")&&(empty==-1)) empty=i;
	}
	if (empty>-1) //���� �� �����, �� ���� ������, �� ������ �� � ����������
	{
		inodes[empty].path=p;
		return &inodes[empty];
	}

	return create_dir(p);//�����, ������� �����
}
