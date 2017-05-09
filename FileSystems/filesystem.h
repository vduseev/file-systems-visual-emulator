#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>

#define BYTE unsigned char
#define SIZE long long int

class FileSystem : public QObject
{
    Q_OBJECT
public:
    FileSystem(QObject *parent = 0);

	// File system type
	enum Type
	{
		ext3,
		ext4,
		FAT12,
		FAT16,
		FAT32,
		NTFS,
		XFS
	};

	// File system block type (indicates color of the block)
    enum Block
    {
        Empty       = 0x0,
        Red         = 0x1,
        Green       = 0x2,
        Blue        = 0x3,
        Cyan        = 0x4,
        Magenta     = 0x5,
        Yellow      = 0x6,
        Black       = 0x7,
        White       = 0x8,
        DenseGreen  = 0xA,
        DenseWhite  = 0xB,
		DenseRed	= 0xC,
		DenseBlue	= 0xD
    };
	
	// Get file system size in bytes
    SIZE size() const { return m_size; }
	// Get block size in bytes
    SIZE blockSize() const { return m_blockSize; }
	// Get block count
	SIZE blockCount() const { return m_blockCount; }
	// Get constant pointer to data-blocks
    const BYTE* blocks() { return m_blocks; }
	// Get value in range of 0.0 to 1.0 indicating free space in file system
	double freeSpace() const;
	// Is file system initaialized
    bool isInitialized() const { return m_allocated; }
	// Get error log
	const QList<QString>& log() { return m_log; }

	// static converter from String with unit name to size in Bytes
	static SIZE	unitToSize( const QString& unit );
	// static converter from String with filesystem type name to Type enum
	static Type	stringToType( const QString& unit );

signals:
	void initialized(bool);
	void sizeChanged(long long);
	void blockSizeChanged(long long);
	void blockCountChanged(long long);

public slots:
    // Mount file system
	// This function must be reimplemented in the child class
    virtual bool mount();
	// Unmount file system
	// This function must be reimplemented in the child class
    virtual bool unmount();
	// This function must be reimplemented in the child class
	// arg1: name = full path + file name
	// arg2: size = size in bytes
	virtual bool addFile( const QByteArray& name, SIZE size );
	// This function must be reimplemented in the child class
	// arg1: name = full path + file name
	virtual bool deleteFile( const QByteArray& name );
	// This function must be reimplemented in the child class
	// arg1: name = full path + folder name + path delimeter (\\)
	virtual bool addDirectory( const QByteArray& name );
	// This function must be reimplemented in the child class
	// arg1: name = full path + file name + path delimeter
	virtual bool deleteDirectory( const QByteArray& name );

	// This function must be reimplemented in the child class
	// Return String with info about block at Index
	virtual QString blockInfo( SIZE index );
	// This function must be reimplemented in the child class
	// Return root folder name (e.g. '.\\' or '/')
	virtual QString rootName();
	// This function must be reimplemented in the child class
	// Return path delimeter (e.g. '/' or '\\')
	virtual QString pathDelimeter();

protected:
	// Set 'blockType' value to 'blockCount' blocks starting from 'startIndex'
    bool write( SIZE startIndex, SIZE blockCount, Block blockType );
	// Allocate 'size' bytes for filesystem
    bool allocate( SIZE size, SIZE blockSize );
	// Deallocate RAM memory for filesystem
	// Call this when unmount
    bool deallocate();

	// Set size of the file system in bytes
	// This operation is only available before allocate() call
	bool setSize( SIZE size );
	// Set block size in bytes
	// This operation is only available before allocate() call
	bool setBlockSize( SIZE size );
	// Set block count in filesystem
	// This operation is only available before allocate() call
	bool setBlockCount( SIZE count ); // NO!!!!!!!!!!!!!!!

private:
	SIZE	m_size;
    SIZE    m_blockSize;
    SIZE    m_blockCount;
	SIZE	m_writeCounter;
    BYTE*   m_blocks;
    bool    m_allocated;
	QList<QString> m_log;

};

#endif // FILESYSTEM_H
