/********************************************************************************
** Form generated from reading UI file 'Assistant.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSISTANT_H
#define UI_ASSISTANT_H

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

class Ui_Assistant
{
public:
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditDescription;
    QLabel *label_2;
    QLineEdit *lineEditAct;
    QVBoxLayout *verticalLayout;
    QPushButton *plotButton;
    QPushButton *addPushButton;
    QPushButton *developPushButton;

    void setupUi(QWidget *Assistant)
    {
        if (Assistant->objectName().isEmpty())
            Assistant->setObjectName(QString::fromUtf8("Assistant"));
        Assistant->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Assistant);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(Assistant);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(Assistant);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditDescription = new QLineEdit(Assistant);
        lineEditDescription->setObjectName(QString::fromUtf8("lineEditDescription"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditDescription);

        label_2 = new QLabel(Assistant);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEditAct = new QLineEdit(Assistant);
        lineEditAct->setObjectName(QString::fromUtf8("lineEditAct"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditAct);


        horizontalLayout->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plotButton = new QPushButton(Assistant);
        plotButton->setObjectName(QString::fromUtf8("plotButton"));

        verticalLayout->addWidget(plotButton);

        addPushButton = new QPushButton(Assistant);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        verticalLayout->addWidget(addPushButton);

        developPushButton = new QPushButton(Assistant);
        developPushButton->setObjectName(QString::fromUtf8("developPushButton"));

        verticalLayout->addWidget(developPushButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEditDescription);
        label_2->setBuddy(lineEditAct);
#endif // QT_NO_SHORTCUT

        retranslateUi(Assistant);

        QMetaObject::connectSlotsByName(Assistant);
    } // setupUi

    void retranslateUi(QWidget *Assistant)
    {
        Assistant->setWindowTitle(QApplication::translate("Assistant", "Assistant", nullptr));
        label->setText(QApplication::translate("Assistant", "Description:", nullptr));
        label_2->setText(QApplication::translate("Assistant", "Act:", nullptr));
        plotButton->setText(QApplication::translate("Assistant", "Save plot", nullptr));
        addPushButton->setText(QApplication::translate("Assistant", "Add", nullptr));
        developPushButton->setText(QApplication::translate("Assistant", "Develop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assistant: public Ui_Assistant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSISTANT_H
