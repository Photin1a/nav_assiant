/********************************************************************************
** Form generated from reading UI file 'display.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Display
{
public:
    QGridLayout *gridLayout;
    QWidget *map;
    QVBoxLayout *verticalLayout;
    QDockWidget *line_speed;
    QWidget *dockWidgetContents;
    QDockWidget *angle_speed;
    QWidget *dockWidgetContents_2;

    void setupUi(QWidget *Display)
    {
        if (Display->objectName().isEmpty())
            Display->setObjectName(QString::fromUtf8("Display"));
        Display->resize(490, 384);
        gridLayout = new QGridLayout(Display);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        map = new QWidget(Display);
        map->setObjectName(QString::fromUtf8("map"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(map->sizePolicy().hasHeightForWidth());
        map->setSizePolicy(sizePolicy);

        gridLayout->addWidget(map, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line_speed = new QDockWidget(Display);
        line_speed->setObjectName(QString::fromUtf8("line_speed"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line_speed->sizePolicy().hasHeightForWidth());
        line_speed->setSizePolicy(sizePolicy1);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        line_speed->setWidget(dockWidgetContents);

        verticalLayout->addWidget(line_speed);

        angle_speed = new QDockWidget(Display);
        angle_speed->setObjectName(QString::fromUtf8("angle_speed"));
        sizePolicy1.setHeightForWidth(angle_speed->sizePolicy().hasHeightForWidth());
        angle_speed->setSizePolicy(sizePolicy1);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        angle_speed->setWidget(dockWidgetContents_2);

        verticalLayout->addWidget(angle_speed);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(Display);

        QMetaObject::connectSlotsByName(Display);
    } // setupUi

    void retranslateUi(QWidget *Display)
    {
        Display->setWindowTitle(QCoreApplication::translate("Display", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Display: public Ui_Display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_H
