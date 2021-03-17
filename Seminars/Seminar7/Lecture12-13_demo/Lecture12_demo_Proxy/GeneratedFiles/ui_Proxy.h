/********************************************************************************
** Form generated from reading UI file 'Proxy.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROXY_H
#define UI_PROXY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProxyClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *patientsList;
    QListWidget *examsList;
    QLabel *photo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProxyClass)
    {
        if (ProxyClass->objectName().isEmpty())
            ProxyClass->setObjectName(QStringLiteral("ProxyClass"));
        ProxyClass->resize(600, 400);
        centralWidget = new QWidget(ProxyClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        patientsList = new QListWidget(centralWidget);
        patientsList->setObjectName(QStringLiteral("patientsList"));
        patientsList->setMaximumSize(QSize(250, 16777215));
        QFont font;
        font.setPointSize(14);
        patientsList->setFont(font);

        horizontalLayout->addWidget(patientsList);

        examsList = new QListWidget(centralWidget);
        examsList->setObjectName(QStringLiteral("examsList"));
        examsList->setMaximumSize(QSize(250, 16777215));
        examsList->setFont(font);

        horizontalLayout->addWidget(examsList);

        photo = new QLabel(centralWidget);
        photo->setObjectName(QStringLiteral("photo"));
        photo->setMinimumSize(QSize(400, 0));
        photo->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(photo);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        ProxyClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProxyClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        ProxyClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProxyClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProxyClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProxyClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProxyClass->setStatusBar(statusBar);

        retranslateUi(ProxyClass);

        QMetaObject::connectSlotsByName(ProxyClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProxyClass)
    {
        ProxyClass->setWindowTitle(QApplication::translate("ProxyClass", "PACS", nullptr));
        photo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProxyClass: public Ui_ProxyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROXY_H
