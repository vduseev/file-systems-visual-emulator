#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderarea.h"
#include "filesystem.h"
#include "treeitem.h"

#include <QIcon>
#include <QGridLayout>
#include <QMouseEvent>
#include <qdebug.h>

#include "ext3.h"
#include "xfs.h"

const int BlocksPerPage = 2048;
const int ProgressBarMax = 10000;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	m_gridIcon = QIcon("grid.png");
	m_folderIcon = QIcon("folder.png");
	m_fileIcon = QIcon("file.png");

	// Actual block drawing area
    m_renderArea = new RenderArea();

	// Fill render widget with a render area
    QGridLayout* renderLayout = new QGridLayout();
	renderLayout->setHorizontalSpacing( 0 );
	renderLayout->setVerticalSpacing( 0 );
	renderLayout->setSpacing( 0 );
	renderLayout->setMargin( 0 );
	renderLayout->setColumnMinimumWidth( 0, 790 );
	renderLayout->setRowMinimumHeight( 0, 390 );
    renderLayout->addWidget(m_renderArea, 0, 0);
    ui->unmountButton->setEnabled(false);
	ui->pageScrollBar->setEnabled(false);
    ui->renderWidget->setLayout(renderLayout);
	
	// Configure progress bar
	ui->filesystemProgressBar->setMinimum( 0 );
	ui->filesystemProgressBar->setMaximum( ProgressBarMax );

	// Configure tree widget
	QList<QString> headerLabels;
	headerLabels.append( "Name" );
	headerLabels.append( "Size" );
	headerLabels.append( "Path" );
	ui->directoriesTreeWidget->setHeaderLabels( headerLabels );

	// Connect widget signals with mainwindow slots
    connect(ui->mountButton, SIGNAL(clicked()),
            this, SLOT(mountSystem()));
    connect(ui->unmountButton, SIGNAL(clicked()),
            this, SLOT(unmountSystem()));
    connect(ui->pageScrollBar, SIGNAL(valueChanged(int)),
            this, SLOT(pageSliding(int)));
	// item managing
	connect(ui->createButton, SIGNAL(clicked()),
			this, SLOT(addItem()));
	connect(ui->deleteButton, SIGNAL(clicked()),
			this, SLOT(deleteItem()));
	connect(ui->fileRadioButton, SIGNAL(clicked()),
			this, SLOT(fileRadioButtonClicked()));
	connect(ui->folderRadioButton, SIGNAL(clicked()),
			this, SLOT(folderRadioButtonClicked()));
	// render area connection
	connect(m_renderArea, SIGNAL(blockSelected(long long)),
			this, SLOT(showSelectedBlockInfo(long long)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pageSliding( int page )
{
	ui->currentPagelcdNumber->display( page );
    m_renderArea->setPage(page);
}

void MainWindow::showSelectedBlockInfo( long long index )
{
	if ( m_fileSystem->isInitialized() )
	{
		QString info = m_fileSystem->blockInfo( index );
		ui->blockInfoLabel->setText( "Info: " + info );
		ui->blockInfoIndexLabel->setText( "Index: " + QString::number( index ) );
		ui->blockInfoColorLabel->setText( "Color: white" );
	}
}

void MainWindow::mountSystem()
{
	SIZE filesystemSizeUnit 
		= FileSystem::unitToSize( ui->filesystemSizeUnitComboBox->currentText() );	
	SIZE filesystemSize = 
		ui->filesystemSizeSpinBox->value() * filesystemSizeUnit;
	SIZE journalSizeUnit
		= FileSystem::unitToSize( ui->journalSizeUnitComboBox->currentText() );
	SIZE journalSize 
		= ui->journalSizeSpinBox->value() * journalSizeUnit;
	SIZE blockGroupSizeUnit
		= FileSystem::unitToSize( ui->journalSizeUnitComboBox->currentText() );
	SIZE blockGroupSize 
		= ui->blockGroupSizeSpinBox->value() * blockGroupSizeUnit;
    SIZE blockSize = ui->blockSizeSpinBox->value();
	FileSystem::Type type = FileSystem::stringToType( ui->filesystemTypeComboBox->currentText() );

	switch ( type )
	{
	case FileSystem::ext3:
		{
			if ( filesystemSize > 1 
				&& journalSize > 1
				&& blockGroupSize > 1
				&& blockSize > 0 )
			{
				// create file system
				m_fileSystem = new Ext3();
				Ext3* system = dynamic_cast<Ext3*>( m_fileSystem );
				system->mount(
					filesystemSize,
					journalSize,
					blockGroupSize,
					blockSize );

				// pass file system to the block renderer
				m_renderArea->setFileSystem( m_fileSystem );
				
				// reconfigure ui elements according to mounted file system
				SIZE fsSize = system->size();
				SIZE fsSizeInUnits = fsSize / filesystemSizeUnit;
				ui->filesystemSizeSpinBox->setValue( fsSizeInUnits );
				SIZE bSize = system->blockSize();
				ui->blockSizeSpinBox->setValue( bSize );
				SIZE bCount = system->blockCount();
				ui->totalBlocksLabel->setText( "Total blocks count " 
					+ QString::number( bCount ) );
				float freeSpacePercent = (float)system->freeSpace();
				ui->filesystemProgressBar->setValue( ProgressBarMax * ( 1.0f - freeSpacePercent ) );
				QString unit = ui->filesystemSizeUnitComboBox->currentText();
				ui->filesystemProgressLabel->setText( 
					QString::number( freeSpacePercent * fsSizeInUnits ) 
					+ " " + unit + " free of " + QString::number( fsSizeInUnits ) + " " + unit );

				// horizontal scroll bar
				int min = 0, max = bCount / BlocksPerPage;
				ui->pageScrollBar->setRange( min, max );
				ui->pageScrollBar->setPageStep( 1 );
				ui->pageScrollBar->setSingleStep( 1 );
				ui->pageScrollBar->setSliderPosition( 0 );

				// add root element in the tree
				TreeItem* root = new TreeItem( 
					ui->directoriesTreeWidget, 
					system->rootName() );
				root->setIcon( 0, m_gridIcon );

				changeUIAfterMount();
			}
		}
		break;

	case FileSystem::ext4:
		break;

	case FileSystem::FAT12:
		break;

	case FileSystem::FAT16:
		break;

	case FileSystem::FAT32:
		break;

	case FileSystem::NTFS:
		break;

	case FileSystem::XFS:
		{
			if ( filesystemSize > 1 
				&& journalSize > 1
				&& blockGroupSize > 1
				&& blockSize > 0 )
			{
				// create file system
				m_fileSystem = new XFS();
				XFS* system = dynamic_cast<XFS*>( m_fileSystem );
				system->mount(
					filesystemSize,
					journalSize,
					blockGroupSize,
					blockSize );

				// pass file system to the block renderer
				m_renderArea->setFileSystem( m_fileSystem );
				
				// reconfigure ui elements according to mounted file system
				SIZE fsSize = system->size();
				SIZE fsSizeInUnits = fsSize / filesystemSizeUnit;
				ui->filesystemSizeSpinBox->setValue( fsSizeInUnits );
				SIZE bSize = system->blockSize();
				ui->blockSizeSpinBox->setValue( bSize );
				SIZE bCount = system->blockCount();
				ui->totalBlocksLabel->setText( "Total blocks count " 
					+ QString::number( bCount ) );
				float freeSpacePercent = (float)system->freeSpace();
				ui->filesystemProgressBar->setValue( ProgressBarMax * ( 1.0f - freeSpacePercent ) );
				QString unit = ui->filesystemSizeUnitComboBox->currentText();
				ui->filesystemProgressLabel->setText( 
					QString::number( freeSpacePercent * fsSizeInUnits ) 
					+ " " + unit + " free of " + QString::number( fsSizeInUnits ) + " " + unit );

				// horizontal scroll bar
				int min = 0, max = bCount / BlocksPerPage;
				ui->pageScrollBar->setRange( min, max );
				ui->pageScrollBar->setPageStep( 1 );
				ui->pageScrollBar->setSingleStep( 1 );
				ui->pageScrollBar->setSliderPosition( 0 );

				// add root element in the tree
				TreeItem* root = new TreeItem( 
					ui->directoriesTreeWidget, 
					system->rootName() );
				root->setIcon( 0, m_gridIcon );

				changeUIAfterMount();
			}
		}
		break;
	}
}

void MainWindow::unmountSystem()
{
    if ( m_fileSystem->isInitialized() )
    {
        m_fileSystem->unmount();
		delete m_fileSystem;
    }

	changeUIAfterUnmount();
}

void MainWindow::addItem()
{
	if ( ui->directoriesTreeWidget->selectedItems().count() == 1 )
	{
		QTreeWidgetItem* parent = ui->directoriesTreeWidget->currentItem();
		TreeItem* current = (TreeItem*)parent;
		QString name = ui->nameLineEdit->text();

		if ( !name.isEmpty() )
		{
			if ( current->itemType() == TreeItem::Folder )
			{
				// If creating a file
				if ( ui->fileRadioButton->isChecked() )
				{							
					// form child names list
					QList<QString> childrenNames;
					int count = current->childCount();
					for ( int i = 0; i < count; i++ )
					{
						TreeItem* child = (TreeItem*)current->child( i );
						if ( child->itemType() == TreeItem::File )
						{
							childrenNames.append( child->text( 0 ) );
						}
					}

					if ( childrenNames.contains( name ) )
					{
						// There is already a file with such name
					}
					else
					{
						SIZE size = ui->fileSizeSpinBox->value();
						size *= FileSystem::unitToSize( ui->fileSizeUnitComboBox->currentText() );
				
						if ( size > 0 )
						{
							// pass request to file system
							QString fullName = current->path() + name;
							m_fileSystem->addFile( fullName.toLatin1(), size );
							// update directory tree
							TreeItem* file = new TreeItem( parent, name, current->path(), size );
							file->setIcon( 0, m_fileIcon );
							parent->setExpanded( true );
						}
						else
						{
							// size is zero
						}
					}
				}
				else if ( ui->folderRadioButton->isChecked() )
				{
					// form child names list
					QList<QString> childrenNames;
					int count = current->childCount();
					for ( int i = 0; i < count; i++ )
					{
						TreeItem* child = (TreeItem*)current->child( i );
						if ( child->itemType() == TreeItem::Folder )
						{
							childrenNames.append( child->text( 0 ) );
						}
					}

					if ( childrenNames.contains( name ) )
					{
						// There is already a folder with such name
					}
					else
					{
						// pass request to file system
						QString path = current->path() + name + m_fileSystem->pathDelimeter();
						m_fileSystem->addDirectory( path.toLatin1() );
						// update directory tree		
						TreeItem* folder = new TreeItem( parent, name, path );
						folder->setIcon( 0, m_folderIcon );
						parent->setExpanded( true );
					}
				}
			}
			else
			{
				// curent item is not a folder
			}
		}
		else
		{
			// name is empty
		}
	}
	else
	{
		// no selected items
	}
}

void MainWindow::deleteItem()
{
	if ( ui->directoriesTreeWidget->selectedItems().count() == 1 )
	{
		TreeItem* current = (TreeItem*)ui->directoriesTreeWidget->currentItem();
		TreeItem* parent = (TreeItem*)current->parent();

		if ( current->itemType() == TreeItem::File )
		{
			// file system request
			QString fullName = current->path();
			m_fileSystem->deleteFile( fullName.toLatin1() );

			// remove tree widget item
			parent->removeChild( current );
		}
		else if ( current->itemType() == TreeItem::Folder )
		{
			if ( current->text( 0 ) == m_fileSystem->rootName() )
			{
				// you can`t delete root folder
			}
			else
			{
				// form child names list
				QList<QTreeWidgetItem*> children = current->takeChildren();
				QList<QByteArray> childrenNames;
				int count = current->childCount();
				for ( int i = 0; i < count; i++ )
				{
					childrenNames.append( children[ i ]->text( 0 ).toLatin1() );
				}

				// file system request
				QString fullName = current->path();
				m_fileSystem->deleteDirectory( fullName.toLatin1() );

				// remove tree widget item
				parent->removeChild( current );
			}
		}
	}
	else
	{
		// no selected items
	}
}

void MainWindow::fileRadioButtonClicked()
{
	ui->folderRadioButton->setChecked( false );
	ui->fileSizeSpinBox->setEnabled( true );
	ui->fileSizeUnitComboBox->setEnabled( true );
}

void MainWindow::folderRadioButtonClicked()
{
	ui->fileRadioButton->setChecked( false );
	ui->fileSizeSpinBox->setEnabled( false );
	ui->fileSizeUnitComboBox->setEnabled( false );
}

void MainWindow::changeUIAfterMount()
{
	// disable elements
	ui->filesystemTypeComboBox->setEnabled( false );
	ui->filesystemSizeSpinBox->setEnabled( false );
	ui->filesystemSizeUnitComboBox->setEnabled( false );
	ui->blockSizeSpinBox->setEnabled( false );
	ui->journalSizeSpinBox->setEnabled( false );
	ui->journalSizeUnitComboBox->setEnabled( false );
	ui->blockGroupSizeSpinBox->setEnabled( false );
	ui->blockGroupSizeUnitComboBox->setEnabled( false );
	ui->mountButton->setEnabled( false );

	// enable elements
	ui->directoriesTreeWidget->setEnabled( true );
	ui->unmountButton->setEnabled( true );
	ui->filesystemProgressBar->setEnabled( true );
	ui->newItemGroupBox->setEnabled( true );
	ui->pageScrollBar->setEnabled( true );
	ui->totalBlocksLabel->setEnabled( true );
				
	// allow drawing
	m_renderArea->allowDrawing();
	
	this->update();
}

void MainWindow::changeUIAfterUnmount()
{
	// disable drawing
	m_renderArea->forbidDrawing();

	// enable elements
	ui->filesystemTypeComboBox->setEnabled( true );
	ui->filesystemSizeSpinBox->setEnabled( true );
	ui->filesystemSizeUnitComboBox->setEnabled( true );
	ui->blockSizeSpinBox->setEnabled( true );
	ui->journalSizeSpinBox->setEnabled( true );
	ui->journalSizeUnitComboBox->setEnabled( true );
	ui->blockGroupSizeSpinBox->setEnabled( true );
	ui->blockGroupSizeUnitComboBox->setEnabled( true );
	ui->mountButton->setEnabled( true );

	// disable elements
	ui->directoriesTreeWidget->setEnabled( false );
	ui->unmountButton->setEnabled( false );
	ui->filesystemProgressBar->setEnabled( false );
	ui->newItemGroupBox->setEnabled( false );
	ui->pageScrollBar->setEnabled( false );
	ui->totalBlocksLabel->setEnabled( false );
		
	// labels
	ui->totalBlocksLabel->setText( "Total blocks count 0" );
	ui->currentPagelcdNumber->display( 0 );
	ui->filesystemProgressLabel->setText( "0 GB free of 0 GB" );
	ui->filesystemProgressBar->setValue( 0 );

	// page scroll config
	ui->pageScrollBar->setRange( 0, 0 );
	ui->pageScrollBar->setSliderPosition( 0 );

	// block info
	ui->blockInfoLabel->setText( "" );
	ui->blockInfoColorLabel->setText( "Color: " );
	ui->blockInfoIndexLabel->setText( "Index: " );

	ui->directoriesTreeWidget->clear();

    this->update();
}