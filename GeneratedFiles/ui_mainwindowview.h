/********************************************************************************
** Form generated from reading UI file 'mainwindowview.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWVIEW_H
#define UI_MAINWINDOWVIEW_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGraphicsView>
#include <QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_MainWindowView
{
public:

    void setupUi(QGraphicsView *MainWindowView)
    {
        if (MainWindowView->objectName().isEmpty())
            MainWindowView->setObjectName(QString::fromUtf8("MainWindowView"));
        MainWindowView->resize(400, 300);

        retranslateUi(MainWindowView);

        QMetaObject::connectSlotsByName(MainWindowView);
    } // setupUi

    void retranslateUi(QGraphicsView *MainWindowView)
    {
        MainWindowView->setWindowTitle(QApplication::translate("MainWindowView", "MainWindowView", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowView: public Ui_MainWindowView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWVIEW_H
