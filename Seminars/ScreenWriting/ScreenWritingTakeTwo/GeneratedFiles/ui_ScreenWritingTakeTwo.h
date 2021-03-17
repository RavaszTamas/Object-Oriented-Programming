/********************************************************************************
** Form generated from reading UI file 'ScreenWritingTakeTwo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENWRITINGTAKETWO_H
#define UI_SCREENWRITINGTAKETWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenWritingTakeTwoClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *developPushButton;
    QPushButton *savePlotButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ScreenWritingTakeTwoClass)
    {
        if (ScreenWritingTakeTwoClass->objectName().isEmpty())
            ScreenWritingTakeTwoClass->setObjectName(QString::fromUtf8("ScreenWritingTakeTwoClass"));
        ScreenWritingTakeTwoClass->resize(600, 400);
        centralWidget = new QWidget(ScreenWritingTakeTwoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        developPushButton = new QPushButton(centralWidget);
        developPushButton->setObjectName(QString::fromUtf8("developPushButton"));

        horizontalLayout->addWidget(developPushButton);

        savePlotButton = new QPushButton(centralWidget);
        savePlotButton->setObjectName(QString::fromUtf8("savePlotButton"));

        horizontalLayout->addWidget(savePlotButton);


        verticalLayout->addLayout(horizontalLayout);

        ScreenWritingTakeTwoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ScreenWritingTakeTwoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        ScreenWritingTakeTwoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ScreenWritingTakeTwoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ScreenWritingTakeTwoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ScreenWritingTakeTwoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ScreenWritingTakeTwoClass->setStatusBar(statusBar);

        retranslateUi(ScreenWritingTakeTwoClass);

        QMetaObject::connectSlotsByName(ScreenWritingTakeTwoClass);
    } // setupUi

    void retranslateUi(QMainWindow *ScreenWritingTakeTwoClass)
    {
        ScreenWritingTakeTwoClass->setWindowTitle(QApplication::translate("ScreenWritingTakeTwoClass", "ScreenWritingTakeTwo", nullptr));
        developPushButton->setText(QApplication::translate("ScreenWritingTakeTwoClass", "Develop", nullptr));
        savePlotButton->setText(QApplication::translate("ScreenWritingTakeTwoClass", "Save plot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScreenWritingTakeTwoClass: public Ui_ScreenWritingTakeTwoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENWRITINGTAKETWO_H
