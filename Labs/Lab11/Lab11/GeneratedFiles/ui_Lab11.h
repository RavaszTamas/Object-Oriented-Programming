/********************************************************************************
** Form generated from reading UI file 'Lab11.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB11_H
#define UI_LAB11_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab11Class
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab11Class)
    {
        if (Lab11Class->objectName().isEmpty())
            Lab11Class->setObjectName(QString::fromUtf8("Lab11Class"));
        Lab11Class->resize(600, 400);
        centralWidget = new QWidget(Lab11Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout->addWidget(tableView);

        Lab11Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Lab11Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        Lab11Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab11Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Lab11Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lab11Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Lab11Class->setStatusBar(statusBar);

        retranslateUi(Lab11Class);

        QMetaObject::connectSlotsByName(Lab11Class);
    } // setupUi

    void retranslateUi(QMainWindow *Lab11Class)
    {
        Lab11Class->setWindowTitle(QApplication::translate("Lab11Class", "Lab11", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab11Class: public Ui_Lab11Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB11_H
