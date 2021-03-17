/********************************************************************************
** Form generated from reading UI file 'TaskManager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskManagerClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addPushButton;
    QLineEdit *addLineEdit;
    QPushButton *removePushButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *startPushButton;
    QPushButton *donePushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TaskManagerClass)
    {
        if (TaskManagerClass->objectName().isEmpty())
            TaskManagerClass->setObjectName(QString::fromUtf8("TaskManagerClass"));
        TaskManagerClass->resize(600, 400);
        centralWidget = new QWidget(TaskManagerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addPushButton = new QPushButton(centralWidget);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        horizontalLayout_2->addWidget(addPushButton);

        addLineEdit = new QLineEdit(centralWidget);
        addLineEdit->setObjectName(QString::fromUtf8("addLineEdit"));

        horizontalLayout_2->addWidget(addLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        removePushButton = new QPushButton(centralWidget);
        removePushButton->setObjectName(QString::fromUtf8("removePushButton"));

        verticalLayout->addWidget(removePushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        startPushButton = new QPushButton(centralWidget);
        startPushButton->setObjectName(QString::fromUtf8("startPushButton"));

        horizontalLayout->addWidget(startPushButton);

        donePushButton = new QPushButton(centralWidget);
        donePushButton->setObjectName(QString::fromUtf8("donePushButton"));

        horizontalLayout->addWidget(donePushButton);


        verticalLayout->addLayout(horizontalLayout);

        TaskManagerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TaskManagerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        TaskManagerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TaskManagerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TaskManagerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TaskManagerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TaskManagerClass->setStatusBar(statusBar);

        retranslateUi(TaskManagerClass);

        QMetaObject::connectSlotsByName(TaskManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *TaskManagerClass)
    {
        TaskManagerClass->setWindowTitle(QApplication::translate("TaskManagerClass", "TaskManager", nullptr));
        addPushButton->setText(QApplication::translate("TaskManagerClass", "Add", nullptr));
        removePushButton->setText(QApplication::translate("TaskManagerClass", "Remove", nullptr));
        startPushButton->setText(QApplication::translate("TaskManagerClass", "Start", nullptr));
        donePushButton->setText(QApplication::translate("TaskManagerClass", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskManagerClass: public Ui_TaskManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
