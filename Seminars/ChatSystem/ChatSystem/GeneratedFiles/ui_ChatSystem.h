/********************************************************************************
** Form generated from reading UI file 'ChatSystem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATSYSTEM_H
#define UI_CHATSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatSystemClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatSystemClass)
    {
        if (ChatSystemClass->objectName().isEmpty())
            ChatSystemClass->setObjectName(QString::fromUtf8("ChatSystemClass"));
        ChatSystemClass->resize(600, 400);
        centralWidget = new QWidget(ChatSystemClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        ChatSystemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChatSystemClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        ChatSystemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChatSystemClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ChatSystemClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ChatSystemClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ChatSystemClass->setStatusBar(statusBar);

        retranslateUi(ChatSystemClass);

        QMetaObject::connectSlotsByName(ChatSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChatSystemClass)
    {
        ChatSystemClass->setWindowTitle(QApplication::translate("ChatSystemClass", "ChatSystem", nullptr));
        pushButton->setText(QApplication::translate("ChatSystemClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatSystemClass: public Ui_ChatSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATSYSTEM_H
