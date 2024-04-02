/********************************************************************************
** Form generated from reading UI file 'toolpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLPAGE_H
#define UI_TOOLPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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

class Ui_ToolPage
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *robot_name_label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *hide_btn;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_21;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *ip_lineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *port_lineEdit;
    QPushButton *connect_btn;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *pos_p_box;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *pos_i_box;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *pos_d_box;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_11;
    QDoubleSpinBox *yaw_p_box;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_12;
    QDoubleSpinBox *yaw_i_box;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_13;
    QDoubleSpinBox *yaw_d_box;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *brake_distance_lineEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_20;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_15;
    QDoubleSpinBox *max_v_box;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_9;
    QDoubleSpinBox *max_w_box;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *save_btn;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLineEdit *test_distance_lineEdit;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *send_params_btn;
    QPushButton *start_btn;
    QCheckBox *location_check_box;
    QPushButton *reset_btn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ToolPage)
    {
        if (ToolPage->objectName().isEmpty())
            ToolPage->setObjectName(QString::fromUtf8("ToolPage"));
        ToolPage->resize(413, 804);
        gridLayout_2 = new QGridLayout(ToolPage);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, -1, 0, 0);
        robot_name_label = new QLabel(ToolPage);
        robot_name_label->setObjectName(QString::fromUtf8("robot_name_label"));

        horizontalLayout_7->addWidget(robot_name_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        hide_btn = new QPushButton(ToolPage);
        hide_btn->setObjectName(QString::fromUtf8("hide_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hide_btn->sizePolicy().hasHeightForWidth());
        hide_btn->setSizePolicy(sizePolicy);
        hide_btn->setMinimumSize(QSize(40, 30));
        QFont font;
        font.setPointSize(10);
        hide_btn->setFont(font);
        hide_btn->setStyleSheet(QString::fromUtf8("QPushButton{border:3px solid gray;border-radius:15px;border-style:outset;}"));

        horizontalLayout_7->addWidget(hide_btn);


        gridLayout_2->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        groupBox = new QGroupBox(ToolPage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
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


        horizontalLayout_21->addLayout(verticalLayout);

        connect_btn = new QPushButton(groupBox);
        connect_btn->setObjectName(QString::fromUtf8("connect_btn"));
        connect_btn->setMinimumSize(QSize(0, 55));
        connect_btn->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_21->addWidget(connect_btn);


        gridLayout->addLayout(horizontalLayout_21, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        pos_p_box = new QDoubleSpinBox(groupBox_2);
        pos_p_box->setObjectName(QString::fromUtf8("pos_p_box"));
        pos_p_box->setMinimum(-9999999.000000000000000);
        pos_p_box->setMaximum(9999999.000000000000000);

        horizontalLayout->addWidget(pos_p_box);


        horizontalLayout_12->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        pos_i_box = new QDoubleSpinBox(groupBox_2);
        pos_i_box->setObjectName(QString::fromUtf8("pos_i_box"));
        pos_i_box->setMinimum(-9999999.000000000000000);
        pos_i_box->setMaximum(9999999.000000000000000);

        horizontalLayout_2->addWidget(pos_i_box);


        horizontalLayout_12->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        pos_d_box = new QDoubleSpinBox(groupBox_2);
        pos_d_box->setObjectName(QString::fromUtf8("pos_d_box"));
        pos_d_box->setMinimum(-9999999.000000000000000);
        pos_d_box->setMaximum(9999999.000000000000000);

        horizontalLayout_3->addWidget(pos_d_box);


        horizontalLayout_12->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_18->addWidget(label_14);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_18);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_15->addWidget(label_11);

        yaw_p_box = new QDoubleSpinBox(groupBox_2);
        yaw_p_box->setObjectName(QString::fromUtf8("yaw_p_box"));
        yaw_p_box->setMinimum(-9999999.000000000000000);
        yaw_p_box->setMaximum(9999999.000000000000000);

        horizontalLayout_15->addWidget(yaw_p_box);


        horizontalLayout_14->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_16->addWidget(label_12);

        yaw_i_box = new QDoubleSpinBox(groupBox_2);
        yaw_i_box->setObjectName(QString::fromUtf8("yaw_i_box"));
        yaw_i_box->setMinimum(-9999999.000000000000000);
        yaw_i_box->setMaximum(9999999.000000000000000);

        horizontalLayout_16->addWidget(yaw_i_box);


        horizontalLayout_14->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_17->addWidget(label_13);

        yaw_d_box = new QDoubleSpinBox(groupBox_2);
        yaw_d_box->setObjectName(QString::fromUtf8("yaw_d_box"));
        yaw_d_box->setMinimum(-9999999.000000000000000);
        yaw_d_box->setMaximum(9999999.000000000000000);

        horizontalLayout_17->addWidget(yaw_d_box);


        horizontalLayout_14->addLayout(horizontalLayout_17);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(90, 0));

        horizontalLayout_5->addWidget(label_7);

        brake_distance_lineEdit = new QLineEdit(groupBox_2);
        brake_distance_lineEdit->setObjectName(QString::fromUtf8("brake_distance_lineEdit"));

        horizontalLayout_5->addWidget(brake_distance_lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_8->addWidget(label_15);

        max_v_box = new QDoubleSpinBox(groupBox_2);
        max_v_box->setObjectName(QString::fromUtf8("max_v_box"));
        max_v_box->setMinimum(-9999999.000000000000000);
        max_v_box->setMaximum(9999999.000000000000000);

        horizontalLayout_8->addWidget(max_v_box);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_19->addWidget(label_9);

        max_w_box = new QDoubleSpinBox(groupBox_2);
        max_w_box->setObjectName(QString::fromUtf8("max_w_box"));
        max_w_box->setMinimum(-9999999.000000000000000);
        max_w_box->setMaximum(9999999.000000000000000);

        horizontalLayout_19->addWidget(max_w_box);


        verticalLayout_2->addLayout(horizontalLayout_19);


        horizontalLayout_20->addLayout(verticalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_4);

        save_btn = new QPushButton(groupBox_2);
        save_btn->setObjectName(QString::fromUtf8("save_btn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(save_btn->sizePolicy().hasHeightForWidth());
        save_btn->setSizePolicy(sizePolicy1);
        save_btn->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_20->addWidget(save_btn);


        verticalLayout_3->addLayout(horizontalLayout_20);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(-1, 0, -1, -1);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(90, 0));

        horizontalLayout_11->addWidget(label_10);

        test_distance_lineEdit = new QLineEdit(groupBox_2);
        test_distance_lineEdit->setObjectName(QString::fromUtf8("test_distance_lineEdit"));

        horizontalLayout_11->addWidget(test_distance_lineEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        send_params_btn = new QPushButton(groupBox_2);
        send_params_btn->setObjectName(QString::fromUtf8("send_params_btn"));
        send_params_btn->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_10->addWidget(send_params_btn);

        start_btn = new QPushButton(groupBox_2);
        start_btn->setObjectName(QString::fromUtf8("start_btn"));
        start_btn->setStyleSheet(QString::fromUtf8("background-color:#5cd46b;"));

        horizontalLayout_10->addWidget(start_btn);


        verticalLayout_3->addLayout(horizontalLayout_10);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);

        location_check_box = new QCheckBox(groupBox);
        location_check_box->setObjectName(QString::fromUtf8("location_check_box"));

        gridLayout->addWidget(location_check_box, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        reset_btn = new QPushButton(ToolPage);
        reset_btn->setObjectName(QString::fromUtf8("reset_btn"));

        gridLayout_2->addWidget(reset_btn, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);


        retranslateUi(ToolPage);

        QMetaObject::connectSlotsByName(ToolPage);
    } // setupUi

    void retranslateUi(QWidget *ToolPage)
    {
        ToolPage->setWindowTitle(QCoreApplication::translate("ToolPage", "Form", nullptr));
        robot_name_label->setText(QCoreApplication::translate("ToolPage", "Robot Config", nullptr));
        hide_btn->setText(QCoreApplication::translate("ToolPage", "hide", nullptr));
        groupBox->setTitle(QString());
        label_4->setText(QCoreApplication::translate("ToolPage", "Robot IP", nullptr));
        ip_lineEdit->setText(QString());
        label_8->setText(QCoreApplication::translate("ToolPage", "Port", nullptr));
        connect_btn->setText(QCoreApplication::translate("ToolPage", "\350\277\236\346\216\245", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ToolPage", "\351\205\215\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("ToolPage", "Linear PID:", nullptr));
        label->setText(QCoreApplication::translate("ToolPage", "P:", nullptr));
        label_2->setText(QCoreApplication::translate("ToolPage", "I:", nullptr));
        label_3->setText(QCoreApplication::translate("ToolPage", "D:", nullptr));
        label_14->setText(QCoreApplication::translate("ToolPage", "Angular PID:", nullptr));
        label_11->setText(QCoreApplication::translate("ToolPage", "P:", nullptr));
        label_12->setText(QCoreApplication::translate("ToolPage", "I:", nullptr));
        label_13->setText(QCoreApplication::translate("ToolPage", "D:", nullptr));
        label_7->setText(QCoreApplication::translate("ToolPage", "\345\210\266\345\212\250\350\267\235\347\246\273m:", nullptr));
        label_15->setText(QCoreApplication::translate("ToolPage", "\346\234\200\345\244\247\347\272\277\351\200\237\345\272\246m/s:", nullptr));
        label_9->setText(QCoreApplication::translate("ToolPage", "\346\234\200\345\244\247\350\247\222\351\200\237\345\272\246r/s:  ", nullptr));
        save_btn->setText(QCoreApplication::translate("ToolPage", "\344\277\235\345\255\230\351\205\215\347\275\256", nullptr));
        label_10->setText(QCoreApplication::translate("ToolPage", "\346\265\213\350\257\225\350\267\235\347\246\273m:", nullptr));
        send_params_btn->setText(QCoreApplication::translate("ToolPage", "\345\217\221\351\200\201\345\217\202\346\225\260", nullptr));
        start_btn->setText(QCoreApplication::translate("ToolPage", "\345\220\257\345\212\250", nullptr));
        location_check_box->setText(QCoreApplication::translate("ToolPage", "Enable Location", nullptr));
        reset_btn->setText(QCoreApplication::translate("ToolPage", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolPage: public Ui_ToolPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLPAGE_H
