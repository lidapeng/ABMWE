/********************************************************************************
** Form generated from reading UI file 'abmwe.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABMWE_H
#define UI_ABMWE_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QHeaderView>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QTreeView>
#include <QWidget>
#include "mainwindowview.h"

QT_BEGIN_NAMESPACE

class Ui_ABMWEClass
{
public:
    QAction *actionNew_Project;
    QAction *actionOpen_Project;
    QAction *actionSave_Project;
    QAction *actionExit;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionReturn_to_Prev;
    QAction *actionConfigure_Model;
    QAction *actionRun_Model;
    QAction *actionPause;
    QAction *actionImport_Data;
    QAction *actionReset_Model;
    QAction *actionTrigger_Buffer;
    QAction *actionTrigger_Points;
    QAction *actionHelp;
    QAction *actionAbout_ABMWE;
    QAction *actionExport;
    QAction *actionExport_Map;
    QAction *actionPan;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTreeView *treeView;
    MainWindowView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuABM;
    QMenu *menuData;
    QMenu *menuTriggers;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ABMWEClass)
    {
        if (ABMWEClass->objectName().isEmpty())
            ABMWEClass->setObjectName(QString::fromUtf8("ABMWEClass"));
        ABMWEClass->resize(765, 567);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(ABMWEClass->sizePolicy().hasHeightForWidth());
        ABMWEClass->setSizePolicy(sizePolicy);
        ABMWEClass->setAutoFillBackground(false);
        actionNew_Project = new QAction(ABMWEClass);
        actionNew_Project->setObjectName(QString::fromUtf8("actionNew_Project"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ABMWE/Resources/newfile.png"), QSize(), QIcon::Normal, QIcon::On);
        actionNew_Project->setIcon(icon);
        actionOpen_Project = new QAction(ABMWEClass);
        actionOpen_Project->setObjectName(QString::fromUtf8("actionOpen_Project"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ABMWE/Resources/openfile.png"), QSize(), QIcon::Normal, QIcon::On);
        actionOpen_Project->setIcon(icon1);
        actionSave_Project = new QAction(ABMWEClass);
        actionSave_Project->setObjectName(QString::fromUtf8("actionSave_Project"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ABMWE/Resources/savefile.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave_Project->setIcon(icon2);
        actionExit = new QAction(ABMWEClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionZoom_In = new QAction(ABMWEClass);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ABMWE/zoomin.png"), QSize(), QIcon::Normal, QIcon::On);
        actionZoom_In->setIcon(icon3);
        actionZoom_Out = new QAction(ABMWEClass);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ABMWE/zoomout.png"), QSize(), QIcon::Normal, QIcon::On);
        actionZoom_Out->setIcon(icon4);
        actionReturn_to_Prev = new QAction(ABMWEClass);
        actionReturn_to_Prev->setObjectName(QString::fromUtf8("actionReturn_to_Prev"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ABMWE/return.png"), QSize(), QIcon::Normal, QIcon::On);
        actionReturn_to_Prev->setIcon(icon5);
        actionConfigure_Model = new QAction(ABMWEClass);
        actionConfigure_Model->setObjectName(QString::fromUtf8("actionConfigure_Model"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/ABMWE/configureModel.png"), QSize(), QIcon::Normal, QIcon::On);
        actionConfigure_Model->setIcon(icon6);
        actionRun_Model = new QAction(ABMWEClass);
        actionRun_Model->setObjectName(QString::fromUtf8("actionRun_Model"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/ABMWE/run.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRun_Model->setIcon(icon7);
        actionPause = new QAction(ABMWEClass);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/ABMWE/pause.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPause->setIcon(icon8);
        actionImport_Data = new QAction(ABMWEClass);
        actionImport_Data->setObjectName(QString::fromUtf8("actionImport_Data"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/ABMWE/importdata.png"), QSize(), QIcon::Normal, QIcon::On);
        actionImport_Data->setIcon(icon9);
        actionReset_Model = new QAction(ABMWEClass);
        actionReset_Model->setObjectName(QString::fromUtf8("actionReset_Model"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/ABMWE/reset.png"), QSize(), QIcon::Normal, QIcon::On);
        actionReset_Model->setIcon(icon10);
        actionTrigger_Buffer = new QAction(ABMWEClass);
        actionTrigger_Buffer->setObjectName(QString::fromUtf8("actionTrigger_Buffer"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/ABMWE/buffer.png"), QSize(), QIcon::Normal, QIcon::On);
        actionTrigger_Buffer->setIcon(icon11);
        actionTrigger_Points = new QAction(ABMWEClass);
        actionTrigger_Points->setObjectName(QString::fromUtf8("actionTrigger_Points"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/ABMWE/point1.png"), QSize(), QIcon::Normal, QIcon::On);
        actionTrigger_Points->setIcon(icon12);
        actionHelp = new QAction(ABMWEClass);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/ABMWE/help.png"), QSize(), QIcon::Normal, QIcon::On);
        actionHelp->setIcon(icon13);
        actionAbout_ABMWE = new QAction(ABMWEClass);
        actionAbout_ABMWE->setObjectName(QString::fromUtf8("actionAbout_ABMWE"));
        actionExport = new QAction(ABMWEClass);
        actionExport->setObjectName(QString::fromUtf8("actionExport"));
        actionExport_Map = new QAction(ABMWEClass);
        actionExport_Map->setObjectName(QString::fromUtf8("actionExport_Map"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/ABMWE/exportmap.png"), QSize(), QIcon::Normal, QIcon::On);
        actionExport_Map->setIcon(icon14);
        actionPan = new QAction(ABMWEClass);
        actionPan->setObjectName(QString::fromUtf8("actionPan"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/ABMWE/draghand.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPan->setIcon(icon15);
        centralWidget = new QWidget(ABMWEClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(treeView, 0, 0, 1, 1);

        graphicsView = new MainWindowView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);

        gridLayout->addWidget(graphicsView, 0, 1, 1, 1);

        ABMWEClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ABMWEClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 765, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuABM = new QMenu(menuBar);
        menuABM->setObjectName(QString::fromUtf8("menuABM"));
        menuData = new QMenu(menuBar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        menuTriggers = new QMenu(menuBar);
        menuTriggers->setObjectName(QString::fromUtf8("menuTriggers"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        ABMWEClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ABMWEClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy3);
        mainToolBar->setAutoFillBackground(false);
        ABMWEClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ABMWEClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ABMWEClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuData->menuAction());
        menuBar->addAction(menuABM->menuAction());
        menuBar->addAction(menuTriggers->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_Project);
        menuFile->addAction(actionOpen_Project);
        menuFile->addAction(actionSave_Project);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuView->addAction(actionZoom_In);
        menuView->addAction(actionZoom_Out);
        menuView->addAction(actionPan);
        menuView->addAction(actionReturn_to_Prev);
        menuView->addSeparator();
        menuABM->addAction(actionConfigure_Model);
        menuABM->addAction(actionRun_Model);
        menuABM->addAction(actionPause);
        menuABM->addAction(actionReset_Model);
        menuData->addAction(actionImport_Data);
        menuData->addAction(actionExport);
        menuData->addAction(actionExport_Map);
        menuTriggers->addAction(actionTrigger_Buffer);
        menuTriggers->addAction(actionTrigger_Points);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout_ABMWE);
        mainToolBar->addAction(actionNew_Project);
        mainToolBar->addAction(actionOpen_Project);
        mainToolBar->addAction(actionSave_Project);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionImport_Data);
        mainToolBar->addAction(actionExport_Map);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionZoom_In);
        mainToolBar->addAction(actionZoom_Out);
        mainToolBar->addAction(actionPan);
        mainToolBar->addAction(actionReturn_to_Prev);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionConfigure_Model);
        mainToolBar->addAction(actionRun_Model);
        mainToolBar->addAction(actionPause);
        mainToolBar->addAction(actionReset_Model);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionTrigger_Buffer);
        mainToolBar->addAction(actionTrigger_Points);

        retranslateUi(ABMWEClass);

        QMetaObject::connectSlotsByName(ABMWEClass);
    } // setupUi

    void retranslateUi(QMainWindow *ABMWEClass)
    {
        ABMWEClass->setWindowTitle(QApplication::translate("ABMWEClass", "ABMWE", 0, QApplication::UnicodeUTF8));
        actionNew_Project->setText(QApplication::translate("ABMWEClass", "New Project", 0, QApplication::UnicodeUTF8));
        actionNew_Project->setShortcut(QApplication::translate("ABMWEClass", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionOpen_Project->setText(QApplication::translate("ABMWEClass", "Open Project", 0, QApplication::UnicodeUTF8));
        actionOpen_Project->setShortcut(QApplication::translate("ABMWEClass", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave_Project->setText(QApplication::translate("ABMWEClass", "Save Project", 0, QApplication::UnicodeUTF8));
        actionSave_Project->setShortcut(QApplication::translate("ABMWEClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("ABMWEClass", "Exit", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setText(QApplication::translate("ABMWEClass", "Zoom In", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setShortcut(QApplication::translate("ABMWEClass", "Ctrl+=", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setText(QApplication::translate("ABMWEClass", "Zoom Out", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionZoom_Out->setToolTip(QApplication::translate("ABMWEClass", "Zoom Out", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionZoom_Out->setShortcut(QApplication::translate("ABMWEClass", "Ctrl+-", 0, QApplication::UnicodeUTF8));
        actionReturn_to_Prev->setText(QApplication::translate("ABMWEClass", "Return to Prev", 0, QApplication::UnicodeUTF8));
        actionReturn_to_Prev->setShortcut(QApplication::translate("ABMWEClass", "Ctrl+Backspace", 0, QApplication::UnicodeUTF8));
        actionConfigure_Model->setText(QApplication::translate("ABMWEClass", "Configure Model", 0, QApplication::UnicodeUTF8));
        actionRun_Model->setText(QApplication::translate("ABMWEClass", "Run Model", 0, QApplication::UnicodeUTF8));
        actionRun_Model->setShortcut(QApplication::translate("ABMWEClass", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionPause->setText(QApplication::translate("ABMWEClass", "Pause Simulation", 0, QApplication::UnicodeUTF8));
        actionPause->setShortcut(QApplication::translate("ABMWEClass", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionImport_Data->setText(QApplication::translate("ABMWEClass", "Import Data", 0, QApplication::UnicodeUTF8));
        actionReset_Model->setText(QApplication::translate("ABMWEClass", "Reset Model", 0, QApplication::UnicodeUTF8));
        actionTrigger_Buffer->setText(QApplication::translate("ABMWEClass", "Trigger Buffer", 0, QApplication::UnicodeUTF8));
        actionTrigger_Points->setText(QApplication::translate("ABMWEClass", "Trigger Points", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("ABMWEClass", "Help", 0, QApplication::UnicodeUTF8));
        actionAbout_ABMWE->setText(QApplication::translate("ABMWEClass", "About ABMWE", 0, QApplication::UnicodeUTF8));
        actionExport->setText(QApplication::translate("ABMWEClass", "Export", 0, QApplication::UnicodeUTF8));
        actionExport_Map->setText(QApplication::translate("ABMWEClass", "Export Map", 0, QApplication::UnicodeUTF8));
        actionPan->setText(QApplication::translate("ABMWEClass", "Pan", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("ABMWEClass", "&File", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("ABMWEClass", "View", 0, QApplication::UnicodeUTF8));
        menuABM->setTitle(QApplication::translate("ABMWEClass", "ABM", 0, QApplication::UnicodeUTF8));
        menuData->setTitle(QApplication::translate("ABMWEClass", "Data", 0, QApplication::UnicodeUTF8));
        menuTriggers->setTitle(QApplication::translate("ABMWEClass", "Triggers", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("ABMWEClass", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ABMWEClass: public Ui_ABMWEClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABMWE_H
