/********************************************************************************
** Form generated from reading UI file 'terminalpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMINALPAGE_H
#define UI_TERMINALPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TerminalPage
{
public:
    QGridLayout *gridLayout_2;

    void setupUi(QWidget *TerminalPage)
    {
        if (TerminalPage->objectName().isEmpty())
            TerminalPage->setObjectName(QString::fromUtf8("TerminalPage"));
        TerminalPage->resize(597, 200);
        TerminalPage->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);"));
        gridLayout_2 = new QGridLayout(TerminalPage);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);

        retranslateUi(TerminalPage);

        QMetaObject::connectSlotsByName(TerminalPage);
    } // setupUi

    void retranslateUi(QWidget *TerminalPage)
    {
        TerminalPage->setWindowTitle(QCoreApplication::translate("TerminalPage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TerminalPage: public Ui_TerminalPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINALPAGE_H
