#include "treeitem.h"

// add file
TreeItem::TreeItem( QTreeWidgetItem* parent, const QString& name, const QString& path, SIZE size )
	: QTreeWidgetItem( parent )
	, m_type( File )
	, m_name( name )
	, m_path( path )
	, m_size( size )
{
	this->setText( 0, name );
	this->setText( 1, QString::number( size ) );
	this->setText( 2, path );
}

// add folder
TreeItem::TreeItem( QTreeWidgetItem* parent, const QString& name, const QString& path )
	: QTreeWidgetItem( parent )
	, m_type( Folder )
	, m_name( name )
	, m_path( path )
	, m_size( 0 )
{
	this->setText( 0, name );
	this->setText( 2, path );
}

// root
TreeItem::TreeItem( QTreeWidget* parent, const QString& name )
	: QTreeWidgetItem( parent )
	, m_type( Folder )
	, m_name( name )
	, m_path( name )
	, m_size( 0 )
{
	this->setText( 0, name );
	this->setText( 2, name );
}

TreeItem::~TreeItem()
{
}

QString TreeItem::path()
{
	return m_path;
}

QString TreeItem::name()
{
	return m_name;
}
