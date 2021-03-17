/********************************************************************************
** Form generated from reading UI file 'Junior.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JUNIOR_H
#define UI_JUNIOR_H

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

class Ui_Junior
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

    void setupUi(QWidget *Junior)
    {
        if (Junior->objectName().isEmpty())
            Junior->setObjectName(QString::fromUtf8("Junior"));
        Junior->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Junior);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(Junior);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(Junior);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        descriptionLineEdit = new QLineEdit(Junior);
        descriptionLineEdit->setObjectName(QString::fromUtf8("descriptionLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, descriptionLineEdit);

        label_2 = new QLabel(Junior);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        actLineEdit = new QLineEdit(Junior);
        actLineEdit->setObjectName(QString::fromUtf8("actLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, actLineEdit);


        horizontalLayout->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plotButton = new QPushButton(Junior);
        plotButton->setObjectName(QString::fromUtf8("plotButton"));

        verticalLayout->addWidget(plotButton);

        addPushButton = new QPushButton(Junior);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        verticalLayout->addWidget(addPushButton);

        developPushButton = new QPushButton(Junior);
        developPushButton->setObjectName(QString::fromUtf8("developPushButton"));

        verticalLayout->addWidget(developPushButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Junior);

        QMetaObject::connectSlotsByName(Junior);
    } // setupUi

    void retranslateUi(QWidget *Junior)
    {
        Junior->setWindowTitle(QApplication::translate("Junior", "Junior", nullptr));
        label->setText(QApplication::translate("Junior", "Description:", nullptr));
        label_2->setText(QApplication::translate("Junior", "Act:", nullptr));
        plotButton->setText(QApplication::translate("Junior", "Save plot", nullptr));
        addPushButton->setText(QApplication::translate("Junior", "Add", nullptr));
        developPushButton->setText(QApplication::translate("Junior", "Develop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Junior: public Ui_Junior {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUNIOR_H
