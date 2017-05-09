#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "filesystem.h"
#include "renderarea.h"

class QIcon;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void pageSliding( int );
    void mountSystem();
    void unmountSystem();
	void addItem();
	void deleteItem();
	void fileRadioButtonClicked();
	void folderRadioButtonClicked();
	void showSelectedBlockInfo( long long );
	void changeUIAfterMount();
	void changeUIAfterUnmount();

private:
    Ui::MainWindow *ui;
    RenderArea* m_renderArea;
    FileSystem* m_fileSystem;
	QIcon m_gridIcon;
	QIcon m_folderIcon;
	QIcon m_fileIcon;
};

#endif // MAINWINDOW_H
