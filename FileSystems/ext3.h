#ifndef EXT3_H
#define EXT3_H

#include "filesystem.h"

class Ext3 : public FileSystem
{
public:
    Ext3();

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
	virtual QString blockInfo( int index );
	virtual QString rootName();
	virtual QString pathDelimeter();

private:
	int tb( SIZE byteCount );
};

#endif // EXT3_H
