/********************************************************************************
** Form generated from reading UI file 'robot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOT_H
#define UI_ROBOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Robot
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_5;
    QLineEdit *name_lineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *ip_lineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *port_lineEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *save_btn;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *p_box;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *i_box;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *d_box;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QDoubleSpinBox *max_v_box;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Robot)
    {
        if (Robot->objectName().isEmpty())
            Robot->setObjectName(QString::fromUtf8("Robot"));
        Robot->resize(293, 226);
        verticalLayout_2 = new QVBoxLayout(Robot);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(Robot);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(59, 25));
        label_5->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_12->addWidget(label_5);

        name_lineEdit = new QLineEdit(groupBox);
        name_lineEdit->setObjectName(QString::fromUtf8("name_lineEdit"));

        horizontalLayout_12->addWidget(name_lineEdit);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(label_4);

        ip_lineEdit = new QLineEdit(groupBox);
        ip_lineEdit->setObjectName(QString::fromUtf8("ip_lineEdit"));

        horizontalLayout_6->addWidget(ip_lineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(59, 0));
        label_8->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_9->addWidget(label_8);

        port_lineEdit = new QLineEdit(groupBox);
        port_lineEdit->setObjectName(QString::fromUtf8("port_lineEdit"));

        horizontalLayout_9->addWidget(port_lineEdit);


        verticalLayout->addLayout(horizontalLayout_9);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Robot);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        save_btn = new QPushButton(groupBox_2);
        save_btn->setObjectName(QString::fromUtf8("save_btn"));
        save_btn->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_10->addWidget(save_btn);


        gridLayout->addLayout(horizontalLayout_10, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        p_box = new QDoubleSpinBox(groupBox_2);
        p_box->setObjectName(QString::fromUtf8("p_box"));

        horizontalLayout->addWidget(p_box);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        i_box = new QDoubleSpinBox(groupBox_2);
        i_box->setObjectName(QString::fromUtf8("i_box"));

        horizontalLayout_2->addWidget(i_box);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        d_box = new QDoubleSpinBox(groupBox_2);
        d_box->setObjectName(QString::fromUtf8("d_box"));

        horizontalLayout_3->addWidget(d_box);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, 0, -1, 0);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_8->addWidget(label_9);

        max_v_box = new QDoubleSpinBox(groupBox_2);
        max_v_box->setObjectName(QString::fromUtf8("max_v_box"));

        horizontalLayout_8->addWidget(max_v_box);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_8, 1, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(Robot);

        QMetaObject::connectSlotsByName(Robot);
    } // setupUi

    void retranslateUi(QWidget *Robot)
    {
        Robot->setWindowTitle(QCoreApplication::translate("Robot", "Form", nullptr));
        groupBox->setTitle(QString());
        label_5->setText(QCoreApplication::translate("Robot", "Name", nullptr));
        label_4->setText(QCoreApplication::translate("Robot", "Robot IP", nullptr));
        label_8->setText(QCoreApplication::translate("Robot", "Port", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Robot", "\345\210\235\345\247\213\351\205\215\347\275\256", nullptr));
        save_btn->setText(QCoreApplication::translate("Robot", "\344\277\235\345\255\230", nullptr));
        label->setText(QCoreApplication::translate("Robot", "P:", nullptr));
        label_2->setText(QCoreApplication::translate("Robot", "I:", nullptr));
        label_3->setText(QCoreApplication::translate("Robot", "D:", nullptr));
        label_9->setText(QCoreApplication::translate("Robot", "\346\234\200\345\244\247\351\200\237\345\272\246m/s:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Robot: public Ui_Robot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOT_H
