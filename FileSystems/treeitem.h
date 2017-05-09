#ifndef TREEITEM_H
#define TREEITEM_H

#include "filesystem.h"

#include <QTreeWidget>
#include <QTreeWidgetItem>

class TreeItem : public QTreeWidgetItem
{
public:
	enum Type
	{
		Folder,
		File
	};

	// add file
	TreeItem( QTreeWidgetItem* parent, const QString& name, const QString& path, SIZE size );
	// add folder
	TreeItem( QTreeWidgetItem* parent, const QString& name, const QString& path );
	// add root
	TreeItem( QTreeWidget* parent, const QString& name );
	~TreeItem();

	Type itemType() { return m_type; }
	QString path();
	QString name();

private:
	Type m_type;
	SIZE m_size;
	
	QString m_name;
	QString m_path;
};

#endif // TREEITEM_H
