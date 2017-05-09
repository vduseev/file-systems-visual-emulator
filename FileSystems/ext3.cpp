#include "ext3.h"

Ext3::Ext3()
	: FileSystem()
{
}

bool Ext3::mount( 
		SIZE filesystemSize,
		SIZE journalSize,
		SIZE blockGroupSize,
		SIZE cblockSize )
{
	// Modify size if not enough
	if ( cblockSize < 1024 )	
	{
		cblockSize = 1024;
	}

	SIZE cblockCount = filesystemSize / cblockSize;

	if ( cblockCount < 1073741824 / cblockSize )
	{
		cblockCount = 1073741824 / cblockSize;
	}

	filesystemSize = cblockCount * cblockSize;

	setSize( filesystemSize );
	setBlockSize( cblockSize );
	setBlockCount( cblockCount );

	allocate( size(), blockSize() );

	int index = 0;

	// allocated freee space
	write(0, tb(1024), Block::Black);
	index += tb(1024);

	// super block (1024 bytes)
	// basic information about SIZE and CONFIGURATION
	write(index, tb(1024), Block::Red);
	index += tb(1024);

	// Ext3 is devided in group blocks
	// Each group has it`s own group descriptor that is stored
	// in the special table right after the superblock.
	
	// Besides this fact the file system also has backup copy of 
	// superblock and group descriptors table. The copies of superblock
	// are usually stored in the first block of each block group
	
	// group blocks descriptors table
	write(index, tb(2048), Block::Blue);
	index += tb(2048);

	for (int i = 0; i < 7; i++)
	{	
		// copy of superblock
		write(index, tb(1024), Block::DenseRed);
		index += tb(1024);
		// copy of descriptors table
		write(index, tb(2048), Block::DenseBlue);
		index += tb(2048);
		// block bit map
		write(index, tb(4096), Block::Magenta);
		index += tb(4096);
		// i-nodes bit map
		write(index, tb(4096), Block::Cyan);
		index += tb(4096);
		// i-node table
		write(index, tb(16384), Block::Yellow);
		index += tb(16384);
		// files
		write( index, tb(1048576), Block::Green);
		index += tb(1048576);
	}

	return true;
}

bool Ext3::unmount()
{
    deallocate();
	return true;
}

bool Ext3::addFile( const QByteArray& name, SIZE size ) { return false; }

bool Ext3::deleteFile( const QByteArray& name ) { return false; }

bool Ext3::addDirectory( const QByteArray& name ) { return false; }

bool Ext3::deleteDirectory( const QByteArray& name, QList<QByteArray> fileList ) { return false; }

QString Ext3::blockInfo( int index ) { return "null info"; }

QString Ext3::rootName()
{
	return ".\\";
}

QString Ext3::pathDelimeter()
{
	return "\\";
}

int Ext3::tb( SIZE byteCount )
{
	return byteCount / blockSize();
}
