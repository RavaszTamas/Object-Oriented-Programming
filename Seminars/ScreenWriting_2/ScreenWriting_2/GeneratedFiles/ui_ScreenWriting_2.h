/********************************************************************************
** Form generated from reading UI file 'ScreenWriting_2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENWRITING_2_H
#define UI_SCREENWRITING_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenWriting_2Class
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *descLineEdit;
    QLabel *label_2;
    QLineEdit *actLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *developPushButton;
    QPushButton *savePlotButton;
    QPushButton *acceptPushButton;
    QPushButton *addPushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ScreenWriting_2Class)
    {
        if (ScreenWriting_2Class->objectName().isEmpty())
            ScreenWriting_2Class->setObjectName(QString::fromUtf8("ScreenWriting_2Class"));
        ScreenWriting_2Class->resize(600, 400);
        centralWidget = new QWidget(ScreenWriting_2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        descLineEdit = new QLineEdit(centralWidget);
        descLineEdit->setObjectName(QString::fromUtf8("descLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, descLineEdit);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        actLineEdit = new QLineEdit(centralWidget);
        actLineEdit->setObjectName(QString::fromUtf8("actLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, actLineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        developPushButton = new QPushButton(centralWidget);
        developPushButton->setObjectName(QString::fromUtf8("developPushButton"));

        horizontalLayout->addWidget(developPushButton);

        savePlotButton = new QPushButton(centralWidget);
        savePlotButton->setObjectName(QString::fromUtf8("savePlotButton"));

        horizontalLayout->addWidget(savePlotButton);

        acceptPushButton = new QPushButton(centralWidget);
        acceptPushButton->setObjectName(QString::fromUtf8("acceptPushButton"));

        horizontalLayout->addWidget(acceptPushButton);

        addPushButton = new QPushButton(centralWidget);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        horizontalLayout->addWidget(addPushButton);


        verticalLayout->addLayout(horizontalLayout);

        ScreenWriting_2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ScreenWriting_2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        ScreenWriting_2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ScreenWriting_2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ScreenWriting_2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ScreenWriting_2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ScreenWriting_2Class->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(descLineEdit);
        label_2->setBuddy(actLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(ScreenWriting_2Class);

        QMetaObject::connectSlotsByName(ScreenWriting_2Class);
    } // setupUi

    void retranslateUi(QMainWindow *ScreenWriting_2Class)
    {
        ScreenWriting_2Class->setWindowTitle(QApplication::translate("ScreenWriting_2Class", "ScreenWriting_2", nullptr));
        label->setText(QApplication::translate("ScreenWriting_2Class", "Description", nullptr));
        label_2->setText(QApplication::translate("ScreenWriting_2Class", "Act", nullptr));
        developPushButton->setText(QApplication::translate("ScreenWriting_2Class", "Develop", nullptr));
        savePlotButton->setText(QApplication::translate("ScreenWriting_2Class", "Save plot", nullptr));
        acceptPushButton->setText(QApplication::translate("ScreenWriting_2Class", "Accept", nullptr));
        addPushButton->setText(QApplication::translate("ScreenWriting_2Class", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScreenWriting_2Class: public Ui_ScreenWriting_2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENWRITING_2_H
