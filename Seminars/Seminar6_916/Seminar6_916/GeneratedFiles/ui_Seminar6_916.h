/********************************************************************************
** Form generated from reading UI file 'Seminar6_916.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEMINAR6_916_H
#define UI_SEMINAR6_916_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Seminar6_916Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Seminar6_916Class)
    {
        if (Seminar6_916Class->objectName().isEmpty())
            Seminar6_916Class->setObjectName(QStringLiteral("Seminar6_916Class"));
        Seminar6_916Class->resize(600, 400);
        menuBar = new QMenuBar(Seminar6_916Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Seminar6_916Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Seminar6_916Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Seminar6_916Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Seminar6_916Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Seminar6_916Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Seminar6_916Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Seminar6_916Class->setStatusBar(statusBar);

        retranslateUi(Seminar6_916Class);

        QMetaObject::connectSlotsByName(Seminar6_916Class);
    } // setupUi

    void retranslateUi(QMainWindow *Seminar6_916Class)
    {
        Seminar6_916Class->setWindowTitle(QApplication::translate("Seminar6_916Class", "Seminar6_916", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Seminar6_916Class: public Ui_Seminar6_916Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEMINAR6_916_H
