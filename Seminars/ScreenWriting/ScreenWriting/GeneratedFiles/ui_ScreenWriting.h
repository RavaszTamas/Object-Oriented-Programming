/********************************************************************************
** Form generated from reading UI file 'ScreenWriting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENWRITING_H
#define UI_SCREENWRITING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenWritingClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ScreenWritingClass)
    {
        if (ScreenWritingClass->objectName().isEmpty())
            ScreenWritingClass->setObjectName(QString::fromUtf8("ScreenWritingClass"));
        ScreenWritingClass->resize(600, 400);
        menuBar = new QMenuBar(ScreenWritingClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ScreenWritingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ScreenWritingClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ScreenWritingClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ScreenWritingClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ScreenWritingClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ScreenWritingClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ScreenWritingClass->setStatusBar(statusBar);

        retranslateUi(ScreenWritingClass);

        QMetaObject::connectSlotsByName(ScreenWritingClass);
    } // setupUi

    void retranslateUi(QMainWindow *ScreenWritingClass)
    {
        ScreenWritingClass->setWindowTitle(QApplication::translate("ScreenWritingClass", "ScreenWriting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScreenWritingClass: public Ui_ScreenWritingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENWRITING_H
