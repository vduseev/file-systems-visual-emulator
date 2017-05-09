/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File_System;
    QWidget *globalLayout;
    QGridLayout *gridLayout_3;
    QHBoxLayout *globalDivisionHoriaontalLayout;
    QGridLayout *gridLayout;
    QGroupBox *filesystemConfigurationGroupBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *mountButton;
    QSpinBox *blockSizeSpinBox;
    QLabel *label_4;
    QSpinBox *filesystemSizeSpinBox;
    QComboBox *filesystemSizeUnitComboBox;
    QLabel *label_6;
    QLabel *label_3;
    QPushButton *unmountButton;
    QLabel *label;
    QLabel *label_5;
    QComboBox *filesystemTypeComboBox;
    QSpinBox *journalSizeSpinBox;
    QComboBox *journalSizeUnitComboBox;
    QLabel *label_7;
    QSpinBox *blockGroupSizeSpinBox;
    QComboBox *blockGroupSizeUnitComboBox;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_3;
    QFrame *line;
    QFrame *line_2;
    QGridLayout *pageSliderGridLayout;
    QLabel *pageSliderLabel;
    QLCDNumber *currentPagelcdNumber;
    QScrollBar *pageScrollBar;
    QLabel *currentPageLabel;
    QWidget *renderWidget;
    QGroupBox *blockInfoGroupBox;
    QGridLayout *gridLayout_7;
    QLabel *blockInfoLabel;
    QLabel *blockInfoIndexLabel;
    QLabel *blockInfoColorLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *freeSpaceHorizontalLayout;
    QLabel *filesystemProgressLabel;
    QProgressBar *filesystemProgressBar;
    QHBoxLayout *renderWidgetDescriptionLayout;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QFrame *line_4;
    QLabel *totalBlocksLabel;
    QGridLayout *sidebarGridLayout;
    QGroupBox *newItemGroupBox;
    QGridLayout *gridLayout_8;
    QLabel *sizeLabel;
    QPushButton *deleteButton;
    QLabel *nameLabel;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *folderRadioButton;
    QRadioButton *fileRadioButton;
    QSpinBox *fileSizeSpinBox;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *createButton;
    QComboBox *fileSizeUnitComboBox;
    QLineEdit *nameLineEdit;
    QLabel *directoriesTreeLabel;
    QTreeWidget *directoriesTreeWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1015, 667);
        actionOpen_File_System = new QAction(MainWindow);
        actionOpen_File_System->setObjectName(QStringLiteral("actionOpen_File_System"));
        globalLayout = new QWidget(MainWindow);
        globalLayout->setObjectName(QStringLiteral("globalLayout"));
        gridLayout_3 = new QGridLayout(globalLayout);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, 3, 6, 0);
        globalDivisionHoriaontalLayout = new QHBoxLayout();
        globalDivisionHoriaontalLayout->setSpacing(1);
        globalDivisionHoriaontalLayout->setObjectName(QStringLiteral("globalDivisionHoriaontalLayout"));
        globalDivisionHoriaontalLayout->setContentsMargins(-1, 0, 0, -1);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        filesystemConfigurationGroupBox = new QGroupBox(globalLayout);
        filesystemConfigurationGroupBox->setObjectName(QStringLiteral("filesystemConfigurationGroupBox"));
        filesystemConfigurationGroupBox->setMinimumSize(QSize(768, 80));
        filesystemConfigurationGroupBox->setMaximumSize(QSize(16777215, 80));
        QPalette palette;
        QBrush brush(QColor(255, 1, 251, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush);
        QBrush brush1(QColor(204, 204, 204, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        filesystemConfigurationGroupBox->setPalette(palette);
        gridLayout_2 = new QGridLayout(filesystemConfigurationGroupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(0);
        horizontalSpacer = new QSpacerItem(50, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 13, 2, 1);

        mountButton = new QPushButton(filesystemConfigurationGroupBox);
        mountButton->setObjectName(QStringLiteral("mountButton"));

        gridLayout_2->addWidget(mountButton, 0, 15, 1, 1);

        blockSizeSpinBox = new QSpinBox(filesystemConfigurationGroupBox);
        blockSizeSpinBox->setObjectName(QStringLiteral("blockSizeSpinBox"));
        blockSizeSpinBox->setMaximum(99999999);

        gridLayout_2->addWidget(blockSizeSpinBox, 1, 5, 1, 1);

        label_4 = new QLabel(filesystemConfigurationGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 7, 1, 1);

        filesystemSizeSpinBox = new QSpinBox(filesystemConfigurationGroupBox);
        filesystemSizeSpinBox->setObjectName(QStringLiteral("filesystemSizeSpinBox"));
        filesystemSizeSpinBox->setMaximum(999999999);

        gridLayout_2->addWidget(filesystemSizeSpinBox, 0, 5, 1, 1);

        filesystemSizeUnitComboBox = new QComboBox(filesystemConfigurationGroupBox);
        filesystemSizeUnitComboBox->setObjectName(QStringLiteral("filesystemSizeUnitComboBox"));

        gridLayout_2->addWidget(filesystemSizeUnitComboBox, 0, 7, 1, 1);

        label_6 = new QLabel(filesystemConfigurationGroupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 9, 1, 1);

        label_3 = new QLabel(filesystemConfigurationGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 4, 1, 1);

        unmountButton = new QPushButton(filesystemConfigurationGroupBox);
        unmountButton->setObjectName(QStringLiteral("unmountButton"));

        gridLayout_2->addWidget(unmountButton, 1, 15, 2, 1);

        label = new QLabel(filesystemConfigurationGroupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(filesystemConfigurationGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 4, 1, 1);

        filesystemTypeComboBox = new QComboBox(filesystemConfigurationGroupBox);
        filesystemTypeComboBox->setObjectName(QStringLiteral("filesystemTypeComboBox"));

        gridLayout_2->addWidget(filesystemTypeComboBox, 0, 1, 1, 1);

        journalSizeSpinBox = new QSpinBox(filesystemConfigurationGroupBox);
        journalSizeSpinBox->setObjectName(QStringLiteral("journalSizeSpinBox"));
        journalSizeSpinBox->setMaximum(999999999);

        gridLayout_2->addWidget(journalSizeSpinBox, 0, 10, 1, 1);

        journalSizeUnitComboBox = new QComboBox(filesystemConfigurationGroupBox);
        journalSizeUnitComboBox->setObjectName(QStringLiteral("journalSizeUnitComboBox"));

        gridLayout_2->addWidget(journalSizeUnitComboBox, 0, 11, 1, 1);

        label_7 = new QLabel(filesystemConfigurationGroupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 9, 1, 1);

        blockGroupSizeSpinBox = new QSpinBox(filesystemConfigurationGroupBox);
        blockGroupSizeSpinBox->setObjectName(QStringLiteral("blockGroupSizeSpinBox"));
        blockGroupSizeSpinBox->setMaximum(999999999);

        gridLayout_2->addWidget(blockGroupSizeSpinBox, 1, 10, 1, 1);

        blockGroupSizeUnitComboBox = new QComboBox(filesystemConfigurationGroupBox);
        blockGroupSizeUnitComboBox->setObjectName(QStringLiteral("blockGroupSizeUnitComboBox"));

        gridLayout_2->addWidget(blockGroupSizeUnitComboBox, 1, 11, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(77, 1, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(59, 1, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 9, 1, 1);

        line_3 = new QFrame(filesystemConfigurationGroupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 0, 12, 2, 1);

        line = new QFrame(filesystemConfigurationGroupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 0, 2, 2, 1);

        line_2 = new QFrame(filesystemConfigurationGroupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 0, 8, 2, 1);


        gridLayout->addWidget(filesystemConfigurationGroupBox, 0, 0, 1, 1);

        pageSliderGridLayout = new QGridLayout();
        pageSliderGridLayout->setSpacing(6);
        pageSliderGridLayout->setObjectName(QStringLiteral("pageSliderGridLayout"));
        pageSliderGridLayout->setContentsMargins(-1, 5, -1, -1);
        pageSliderLabel = new QLabel(globalLayout);
        pageSliderLabel->setObjectName(QStringLiteral("pageSliderLabel"));
        pageSliderLabel->setMaximumSize(QSize(55, 16777215));

        pageSliderGridLayout->addWidget(pageSliderLabel, 0, 0, 1, 1);

        currentPagelcdNumber = new QLCDNumber(globalLayout);
        currentPagelcdNumber->setObjectName(QStringLiteral("currentPagelcdNumber"));
        currentPagelcdNumber->setMaximumSize(QSize(50, 16777215));
        currentPagelcdNumber->setSmallDecimalPoint(false);
        currentPagelcdNumber->setSegmentStyle(QLCDNumber::Filled);

        pageSliderGridLayout->addWidget(currentPagelcdNumber, 0, 3, 1, 1);

        pageScrollBar = new QScrollBar(globalLayout);
        pageScrollBar->setObjectName(QStringLiteral("pageScrollBar"));
        pageScrollBar->setEnabled(false);
        pageScrollBar->setOrientation(Qt::Horizontal);

        pageSliderGridLayout->addWidget(pageScrollBar, 0, 1, 1, 1);

        currentPageLabel = new QLabel(globalLayout);
        currentPageLabel->setObjectName(QStringLiteral("currentPageLabel"));
        currentPageLabel->setMaximumSize(QSize(65, 16777215));

        pageSliderGridLayout->addWidget(currentPageLabel, 0, 2, 1, 1);


        gridLayout->addLayout(pageSliderGridLayout, 7, 0, 1, 1);

        renderWidget = new QWidget(globalLayout);
        renderWidget->setObjectName(QStringLiteral("renderWidget"));
        renderWidget->setMinimumSize(QSize(773, 389));
        renderWidget->setMaximumSize(QSize(773, 389));
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush3(QColor(203, 203, 203, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        QBrush brush5(QColor(255, 230, 153, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        QBrush brush6(QColor(255, 117, 195, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        QBrush brush7(QColor(190, 190, 190, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
        renderWidget->setPalette(palette1);

        gridLayout->addWidget(renderWidget, 4, 0, 1, 1);

        blockInfoGroupBox = new QGroupBox(globalLayout);
        blockInfoGroupBox->setObjectName(QStringLiteral("blockInfoGroupBox"));
        blockInfoGroupBox->setEnabled(false);
        gridLayout_7 = new QGridLayout(blockInfoGroupBox);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        blockInfoLabel = new QLabel(blockInfoGroupBox);
        blockInfoLabel->setObjectName(QStringLiteral("blockInfoLabel"));

        gridLayout_7->addWidget(blockInfoLabel, 0, 0, 1, 1);

        blockInfoIndexLabel = new QLabel(blockInfoGroupBox);
        blockInfoIndexLabel->setObjectName(QStringLiteral("blockInfoIndexLabel"));

        gridLayout_7->addWidget(blockInfoIndexLabel, 1, 0, 1, 1);

        blockInfoColorLabel = new QLabel(blockInfoGroupBox);
        blockInfoColorLabel->setObjectName(QStringLiteral("blockInfoColorLabel"));

        gridLayout_7->addWidget(blockInfoColorLabel, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 0, 1, 1, 1);


        gridLayout->addWidget(blockInfoGroupBox, 8, 0, 1, 1);

        freeSpaceHorizontalLayout = new QHBoxLayout();
        freeSpaceHorizontalLayout->setSpacing(6);
        freeSpaceHorizontalLayout->setObjectName(QStringLiteral("freeSpaceHorizontalLayout"));
        freeSpaceHorizontalLayout->setContentsMargins(1, 1, 1, 1);
        filesystemProgressLabel = new QLabel(globalLayout);
        filesystemProgressLabel->setObjectName(QStringLiteral("filesystemProgressLabel"));
        filesystemProgressLabel->setEnabled(false);

        freeSpaceHorizontalLayout->addWidget(filesystemProgressLabel);

        filesystemProgressBar = new QProgressBar(globalLayout);
        filesystemProgressBar->setObjectName(QStringLiteral("filesystemProgressBar"));
        filesystemProgressBar->setEnabled(false);
        filesystemProgressBar->setValue(0);

        freeSpaceHorizontalLayout->addWidget(filesystemProgressBar);


        gridLayout->addLayout(freeSpaceHorizontalLayout, 2, 0, 1, 1);

        renderWidgetDescriptionLayout = new QHBoxLayout();
        renderWidgetDescriptionLayout->setSpacing(6);
        renderWidgetDescriptionLayout->setObjectName(QStringLiteral("renderWidgetDescriptionLayout"));
        renderWidgetDescriptionLayout->setContentsMargins(1, 1, 1, 1);
        label_11 = new QLabel(globalLayout);
        label_11->setObjectName(QStringLiteral("label_11"));

        renderWidgetDescriptionLayout->addWidget(label_11);

        label_12 = new QLabel(globalLayout);
        label_12->setObjectName(QStringLiteral("label_12"));

        renderWidgetDescriptionLayout->addWidget(label_12);

        label_13 = new QLabel(globalLayout);
        label_13->setObjectName(QStringLiteral("label_13"));

        renderWidgetDescriptionLayout->addWidget(label_13);

        line_4 = new QFrame(globalLayout);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        renderWidgetDescriptionLayout->addWidget(line_4);

        totalBlocksLabel = new QLabel(globalLayout);
        totalBlocksLabel->setObjectName(QStringLiteral("totalBlocksLabel"));

        renderWidgetDescriptionLayout->addWidget(totalBlocksLabel);


        gridLayout->addLayout(renderWidgetDescriptionLayout, 3, 0, 1, 1);


        globalDivisionHoriaontalLayout->addLayout(gridLayout);

        sidebarGridLayout = new QGridLayout();
        sidebarGridLayout->setSpacing(6);
        sidebarGridLayout->setObjectName(QStringLiteral("sidebarGridLayout"));
        sidebarGridLayout->setHorizontalSpacing(0);
        sidebarGridLayout->setVerticalSpacing(4);
        sidebarGridLayout->setContentsMargins(-1, -1, 0, -1);
        newItemGroupBox = new QGroupBox(globalLayout);
        newItemGroupBox->setObjectName(QStringLiteral("newItemGroupBox"));
        newItemGroupBox->setEnabled(false);
        newItemGroupBox->setMinimumSize(QSize(0, 138));
        newItemGroupBox->setMaximumSize(QSize(16777215, 138));
        gridLayout_8 = new QGridLayout(newItemGroupBox);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        sizeLabel = new QLabel(newItemGroupBox);
        sizeLabel->setObjectName(QStringLiteral("sizeLabel"));

        gridLayout_8->addWidget(sizeLabel, 2, 0, 1, 1, Qt::AlignRight);

        deleteButton = new QPushButton(newItemGroupBox);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        gridLayout_8->addWidget(deleteButton, 4, 4, 1, 1);

        nameLabel = new QLabel(newItemGroupBox);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout_8->addWidget(nameLabel, 1, 0, 1, 1, Qt::AlignRight);

        horizontalSpacer_2 = new QSpacerItem(27, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_2, 4, 0, 1, 1);

        folderRadioButton = new QRadioButton(newItemGroupBox);
        folderRadioButton->setObjectName(QStringLiteral("folderRadioButton"));

        gridLayout_8->addWidget(folderRadioButton, 4, 1, 1, 1);

        fileRadioButton = new QRadioButton(newItemGroupBox);
        fileRadioButton->setObjectName(QStringLiteral("fileRadioButton"));
        fileRadioButton->setChecked(true);

        gridLayout_8->addWidget(fileRadioButton, 3, 1, 1, 1);

        fileSizeSpinBox = new QSpinBox(newItemGroupBox);
        fileSizeSpinBox->setObjectName(QStringLiteral("fileSizeSpinBox"));
        fileSizeSpinBox->setMaximum(99999999);

        gridLayout_8->addWidget(fileSizeSpinBox, 2, 1, 1, 3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_8, 4, 2, 1, 2);

        createButton = new QPushButton(newItemGroupBox);
        createButton->setObjectName(QStringLiteral("createButton"));

        gridLayout_8->addWidget(createButton, 3, 4, 1, 1);

        fileSizeUnitComboBox = new QComboBox(newItemGroupBox);
        fileSizeUnitComboBox->setObjectName(QStringLiteral("fileSizeUnitComboBox"));

        gridLayout_8->addWidget(fileSizeUnitComboBox, 2, 4, 1, 1);

        nameLineEdit = new QLineEdit(newItemGroupBox);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout_8->addWidget(nameLineEdit, 1, 1, 1, 4);

        deleteButton->raise();
        sizeLabel->raise();
        nameLabel->raise();
        fileSizeSpinBox->raise();
        fileSizeUnitComboBox->raise();
        folderRadioButton->raise();
        fileRadioButton->raise();
        createButton->raise();
        nameLineEdit->raise();

        sidebarGridLayout->addWidget(newItemGroupBox, 3, 0, 1, 1);

        directoriesTreeLabel = new QLabel(globalLayout);
        directoriesTreeLabel->setObjectName(QStringLiteral("directoriesTreeLabel"));
        directoriesTreeLabel->setMinimumSize(QSize(0, 24));
        directoriesTreeLabel->setMaximumSize(QSize(16777215, 24));

        sidebarGridLayout->addWidget(directoriesTreeLabel, 0, 0, 1, 1);

        directoriesTreeWidget = new QTreeWidget(globalLayout);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(2, QStringLiteral("3"));
        __qtreewidgetitem->setText(1, QStringLiteral("2"));
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        directoriesTreeWidget->setHeaderItem(__qtreewidgetitem);
        directoriesTreeWidget->setObjectName(QStringLiteral("directoriesTreeWidget"));
        directoriesTreeWidget->setFrameShape(QFrame::StyledPanel);
        directoriesTreeWidget->setAnimated(true);
        directoriesTreeWidget->setColumnCount(3);
        directoriesTreeWidget->header()->setDefaultSectionSize(104);
        directoriesTreeWidget->header()->setHighlightSections(false);
        directoriesTreeWidget->header()->setProperty("showSortIndicator", QVariant(false));
        directoriesTreeWidget->header()->setStretchLastSection(true);

        sidebarGridLayout->addWidget(directoriesTreeWidget, 1, 0, 1, 1);


        globalDivisionHoriaontalLayout->addLayout(sidebarGridLayout);

        globalDivisionHoriaontalLayout->setStretch(1, 1);

        gridLayout_3->addLayout(globalDivisionHoriaontalLayout, 0, 1, 1, 1);

        MainWindow->setCentralWidget(globalLayout);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1015, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_File_System);

        retranslateUi(MainWindow);

        filesystemSizeUnitComboBox->setCurrentIndex(2);
        filesystemTypeComboBox->setCurrentIndex(0);
        journalSizeUnitComboBox->setCurrentIndex(2);
        blockGroupSizeUnitComboBox->setCurrentIndex(2);
        fileSizeUnitComboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen_File_System->setText(QApplication::translate("MainWindow", "Open File System", 0));
        filesystemConfigurationGroupBox->setTitle(QApplication::translate("MainWindow", "File System Configuration", 0));
        mountButton->setText(QApplication::translate("MainWindow", "Mount", 0));
        label_4->setText(QApplication::translate("MainWindow", "Bytes", 0));
        filesystemSizeUnitComboBox->clear();
        filesystemSizeUnitComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "B", 0)
         << QApplication::translate("MainWindow", "KB", 0)
         << QApplication::translate("MainWindow", "MB", 0)
         << QApplication::translate("MainWindow", "GB", 0)
         << QApplication::translate("MainWindow", "TB", 0)
        );
        label_6->setText(QApplication::translate("MainWindow", "Journal size", 0));
        label_3->setText(QApplication::translate("MainWindow", "File system size", 0));
        unmountButton->setText(QApplication::translate("MainWindow", "Unmount", 0));
        label->setText(QApplication::translate("MainWindow", "Choose", 0));
        label_5->setText(QApplication::translate("MainWindow", "Block size", 0));
        filesystemTypeComboBox->clear();
        filesystemTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ext3", 0)
         << QApplication::translate("MainWindow", "ext4", 0)
         << QApplication::translate("MainWindow", "FAT12", 0)
         << QApplication::translate("MainWindow", "FAT16", 0)
         << QApplication::translate("MainWindow", "FAT32", 0)
         << QApplication::translate("MainWindow", "NTFS", 0)
         << QApplication::translate("MainWindow", "XFS", 0)
        );
        filesystemTypeComboBox->setCurrentText(QApplication::translate("MainWindow", "ext3", 0));
        journalSizeUnitComboBox->clear();
        journalSizeUnitComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "B", 0)
         << QApplication::translate("MainWindow", "KB", 0)
         << QApplication::translate("MainWindow", "MB", 0)
         << QApplication::translate("MainWindow", "GB", 0)
         << QApplication::translate("MainWindow", "TB", 0)
        );
        label_7->setText(QApplication::translate("MainWindow", "Group size", 0));
        blockGroupSizeUnitComboBox->clear();
        blockGroupSizeUnitComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "B", 0)
         << QApplication::translate("MainWindow", "KB", 0)
         << QApplication::translate("MainWindow", "MB", 0)
         << QApplication::translate("MainWindow", "GB", 0)
         << QApplication::translate("MainWindow", "TB", 0)
        );
        pageSliderLabel->setText(QApplication::translate("MainWindow", "Page slider", 0));
        currentPageLabel->setText(QApplication::translate("MainWindow", "Current page", 0));
        blockInfoGroupBox->setTitle(QApplication::translate("MainWindow", "Block Info", 0));
        blockInfoLabel->setText(QString());
        blockInfoIndexLabel->setText(QApplication::translate("MainWindow", "Index", 0));
        blockInfoColorLabel->setText(QApplication::translate("MainWindow", "Color", 0));
        filesystemProgressLabel->setText(QApplication::translate("MainWindow", "0 GB free of 0 GB", 0));
        label_11->setText(QApplication::translate("MainWindow", "Data blocks layout", 0));
        label_12->setText(QApplication::translate("MainWindow", "2048 Blocks displayed", 0));
        label_13->setText(QApplication::translate("MainWindow", "64 x 32 Grid", 0));
        totalBlocksLabel->setText(QApplication::translate("MainWindow", "Total blocks count 0", 0));
        newItemGroupBox->setTitle(QApplication::translate("MainWindow", "New", 0));
        sizeLabel->setText(QApplication::translate("MainWindow", "Size", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        nameLabel->setText(QApplication::translate("MainWindow", "Name", 0));
        folderRadioButton->setText(QApplication::translate("MainWindow", "Folder", 0));
        fileRadioButton->setText(QApplication::translate("MainWindow", "File", 0));
        createButton->setText(QApplication::translate("MainWindow", "Create", 0));
        fileSizeUnitComboBox->clear();
        fileSizeUnitComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "B", 0)
         << QApplication::translate("MainWindow", "KB", 0)
         << QApplication::translate("MainWindow", "MB", 0)
         << QApplication::translate("MainWindow", "GB", 0)
         << QApplication::translate("MainWindow", "TB", 0)
        );
        directoriesTreeLabel->setText(QApplication::translate("MainWindow", "Directory Tree", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
