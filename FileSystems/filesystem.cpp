#include "filesystem.h"

FileSystem::FileSystem(QObject *parent) 
	: QObject(parent)
	, m_size( 0 )
	, m_blockSize( 0 )
	, m_blockCount( 0 )
	, m_writeCounter( 0 )
	, m_allocated( false )
{
}

/* 
 * Declare this functions in the child classes.
 */
bool FileSystem::mount() { return false; }

bool FileSystem::unmount() { return false; }

bool FileSystem::addFile( const QByteArray& name, SIZE size ) { return false; }

bool FileSystem::deleteFile( const QByteArray& name ) { return false; }

bool FileSystem::addDirectory( const QByteArray& name ) { return false; }

bool FileSystem::deleteDirectory( const QByteArray& name ) { return false; }

QString FileSystem::blockInfo( SIZE index ) { return "null info"; }

QString FileSystem::rootName() { return "/"; }

QString FileSystem::pathDelimeter() { return "/"; }

double FileSystem::freeSpace() const
{	
	return 1.0 - (double)m_writeCounter / m_blockCount;
}

/*
 * Protected functions for internal use by file system.
 */

bool FileSystem::write( SIZE startIndex, SIZE count, Block type )
{
	bool success = false;
    if ( m_allocated )
	{
		if ( startIndex + count <= m_blockCount )		
		{
			for (int i = startIndex; i < startIndex + count; i++)
			{
				// Increment the counter only if writing to empty block
				BYTE block = m_blocks[i];
				if ( block == Empty && type )
					m_writeCounter++;
				// Decrement only if writing empty to non-empty block
				else if ( block && type == Empty )
					m_writeCounter--;
				// Form new byte and write it to the current block
				BYTE leastSignificantBits = ( BYTE )type;
				BYTE highOrderBits = 0x0;
				BYTE result = ( highOrderBits << 4 ) | leastSignificantBits;
				m_blocks[i] = result;
			}
			success = true;
		}
		else
		{
			m_log.append( "Desired block index is out of range." );
			success = false;
		}
	}
	else
	{
		m_log.append( "File system is not initialized" );
		success = false;
	}
	return success;
}

bool FileSystem::allocate( SIZE size, SIZE blockSize )
{
	m_size			= size;
    m_blockSize		= blockSize;
	m_blockCount	= size / blockSize;

    m_blocks		= new BYTE[ m_blockCount ];

	for ( int i = 0; i < m_blockCount; i++ )
	{
		m_blocks[ i ] = 0x00;
	}
	
    m_allocated	= true;
	return true;
}

bool FileSystem::deallocate()
{
	bool success = false;
    if (m_allocated)
    {
        delete m_blocks;
        m_allocated = false;
		success = true;
    }
	else
	{
		m_log.append( "Can`t deallocatte memory. File system is not initialized." );
		success = false;
	}
	return success;
}

bool FileSystem::setSize( SIZE size )
{
	bool success = false;
	if ( m_allocated )
	{
		success = false;
	}
	else
	{
		m_size = size;
		success = true;
	}
	return success;
}

bool FileSystem::setBlockSize( SIZE size )
{
	bool success = false;
	if ( m_allocated )
	{
		success = false;
	}
	else
	{
		m_blockSize = size;
		success = true;
	}
	return success;
}

bool FileSystem::setBlockCount( SIZE count )
{
	bool success = false;
	if ( m_allocated )
	{
		success = false;
	}
	else
	{
		m_blockCount = count;
		success = true;
	}
	return success;
}

/*
 * Public static functions for convertation purposes.
 */

SIZE FileSystem::unitToSize( const QString& unit )
{
	SIZE result = 1;
	if ( unit == "B" ) result = 1;
	else if ( unit == "KB" ) result = 1000;
	else if ( unit == "MB" ) result = 1000000;
	else if ( unit == "GB" ) result = 1000000000;
	else if ( unit == "TB" ) result = 1000000000000;
	return result;
}

FileSystem::Type FileSystem::stringToType( const QString& str )
{
	Type type = ext3;
	if ( str == "ext3" ) type = ext3;
	else if ( str == "ext4" )	type = ext4;
	else if ( str == "FAT12" )	type = FAT12;
	else if ( str == "FAT16" )	type = FAT16;
	else if ( str == "FAT12" )	type = FAT32;
	else if ( str == "NTFS" )	type = NTFS;
	else if ( str == "XFS" )	type = XFS;
	return type;
}
