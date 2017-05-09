#ifndef XFS_H
#define XFS_H

#include "filesystem.h"

#include <map>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
#include <time.h>
using namespace std;

class XFS : public FileSystem
{
public:
	struct segment//������ - ������ ��������
	{
		SIZE start;
		SIZE end;//����� ��������
		SIZE type;//���, ��� ����������(0-������, 1-����, 2-����)
		SIZE number;//�����, ���� ����������
		segment(){}
		segment(SIZE starti, SIZE endi, SIZE typei, SIZE numberi)
		{      
			start=starti;
			end = endi;
			type = typei;
			number = numberi;
		}
	};

	struct inode
	{
		SIZE AG;//����� Ag �����, � �������� �����������. ������ n���� ������, ���������.
		SIZE files_left;//������� ����� �������� ��� ������
		SIZE start;//��� inode ���������
		QByteArray path;//����� ��� �����
		inode(){}
		inode(SIZE AGi, SIZE starti,QByteArray pathi)
		{      
			AG = AGi;
			files_left = 64;
			start = starti;
			path=pathi;
		}	
	};

	struct file
	{
		QByteArray name;//��� �����
		inode* dad;//� ����� ����� ����������
		set <SIZE> start_cells;//������ ������ �����
		file(){}
		file(QByteArray namei, inode* dadi, set <SIZE> starti){
			name=namei;
			dad=dadi;
			start_cells=starti;
		}
	};

    XFS();
	map<SIZE,segment> cells;//������� �����
	inode inodes[131073];//������� inodes
	map<SIZE,file> files;//[10000];//������� ������
	SIZE length_AG;
	SIZE length_inode;
	SIZE length_journal;
	SIZE size_cell;

	SIZE number_AG;
	SIZE number_cells;
	SIZE number_inodes;
	SIZE number_files;

    virtual bool mount( 
		SIZE filesystemSize,
		SIZE journalSize,
		SIZE blockGroupSize,
		SIZE blockSize );
    virtual bool unmount();
	virtual bool addFile( const QByteArray& name, SIZE size );
	virtual bool deleteFile( const QByteArray& name );
	virtual bool addDirectory( const QByteArray& name );
	virtual bool deleteDirectory( const QByteArray& name, QList<QByteArray> fileList );
	virtual QString blockInfo( SIZE index );
	virtual QString rootName();
	virtual QString pathDelimeter();

private:
	int tb( SIZE byteCount );
	
	pair< SIZE, bool > find_empty_space_inode(int AG,int num_cells);	
	pair< SIZE, bool > find_empty_space(int AG, int start_cell); //������� ������ ��������, ����� �������� ���� ������ �����
	inode *create_dir(const QByteArray& name);
	inode* find_dir(const QByteArray& p); //��� �����, ���� � ����������
};

#endif // XFS_H
