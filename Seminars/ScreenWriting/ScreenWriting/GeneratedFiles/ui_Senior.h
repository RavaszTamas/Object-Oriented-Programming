/********************************************************************************
** Form generated from reading UI file 'Senior.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENIOR_H
#define UI_SENIOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Senior
{
public:
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *descriptionLineEdit;
    QLabel *label_2;
    QLineEdit *actLineEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *plotButton;
    QPushButton *addPushButton;
    QPushButton *developPushButton;
    QPushButton *acceptPushButton;

    void setupUi(QWidget *Senior)
    {
        if (Senior->objectName().isEmpty())
            Senior->setObjectName(QString::fromUtf8("Senior"));
        Senior->resize(367, 300);
        verticalLayout_2 = new QVBoxLayout(Senior);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(Senior);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(Senior);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        descriptionLineEdit = new QLineEdit(Senior);
        descriptionLineEdit->setObjectName(QString::fromUtf8("descriptionLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, descriptionLineEdit);

        label_2 = new QLabel(Senior);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        actLineEdit = new QLineEdit(Senior);
        actLineEdit->setObjectName(QString::fromUtf8("actLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, actLineEdit);


        horizontalLayout->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plotButton = new QPushButton(Senior);
        plotButton->setObjectName(QString::fromUtf8("plotButton"));

        verticalLayout->addWidget(plotButton);

        addPushButton = new QPushButton(Senior);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        verticalLayout->addWidget(addPushButton);

        developPushButton = new QPushButton(Senior);
        developPushButton->setObjectName(QString::fromUtf8("developPushButton"));

        verticalLayout->addWidget(developPushButton);

        acceptPushButton = new QPushButton(Senior);
        acceptPushButton->setObjectName(QString::fromUtf8("acceptPushButton"));

        verticalLayout->addWidget(acceptPushButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Senior);

        QMetaObject::connectSlotsByName(Senior);
    } // setupUi

    void retranslateUi(QWidget *Senior)
    {
        Senior->setWindowTitle(QApplication::translate("Senior", "Senior", nullptr));
        label->setText(QApplication::translate("Senior", "Description:", nullptr));
        label_2->setText(QApplication::translate("Senior", "Act:", nullptr));
        plotButton->setText(QApplication::translate("Senior", "Save plot", nullptr));
        addPushButton->setText(QApplication::translate("Senior", "Add", nullptr));
        developPushButton->setText(QApplication::translate("Senior", "Develop", nullptr));
        acceptPushButton->setText(QApplication::translate("Senior", "Accept", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Senior: public Ui_Senior {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENIOR_H
