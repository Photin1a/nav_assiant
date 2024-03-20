/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *new_terminal;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *toolbar;
    QVBoxLayout *toolbar_layout;
    QToolButton *robot_menu_btn;
    QToolButton *list_robot_btn;
    QSpacerItem *verticalSpacer;
    QToolButton *toolButton_4;
    QToolButton *toolButton;
    QToolButton *toolButton_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *user_hlayout;
    QStackedWidget *action_stackedwidget;
    QWidget *map_page;
    QStackedWidget *tool_stackedwidget;
    QWidget *map_page_2;
    QStackedWidget *terminal_stackedwidget;
    QWidget *map_page_3;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTerminal;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(824, 653);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);"));
        new_terminal = new QAction(MainWindow);
        new_terminal->setObjectName(QString::fromUtf8("new_terminal"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        toolbar = new QWidget(centralwidget);
        toolbar->setObjectName(QString::fromUtf8("toolbar"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolbar->sizePolicy().hasHeightForWidth());
        toolbar->setSizePolicy(sizePolicy);
        toolbar->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 51, 51);"));
        toolbar_layout = new QVBoxLayout(toolbar);
        toolbar_layout->setSpacing(0);
        toolbar_layout->setObjectName(QString::fromUtf8("toolbar_layout"));
        toolbar_layout->setContentsMargins(0, 0, 0, 0);
        robot_menu_btn = new QToolButton(toolbar);
        robot_menu_btn->setObjectName(QString::fromUtf8("robot_menu_btn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(robot_menu_btn->sizePolicy().hasHeightForWidth());
        robot_menu_btn->setSizePolicy(sizePolicy1);
        robot_menu_btn->setMinimumSize(QSize(48, 48));
        robot_menu_btn->setStyleSheet(QString::fromUtf8("/* \344\270\212\350\276\271\346\241\206\345\256\275\345\272\2460\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\351\200\217\346\230\216 */\n"
"QToolButton{   \n"
"	border-top: 0px outset transparent;       \n"
"	border-bottom: 0px outset transparent;\n"
"	border-right: 0px outset transparent;\n"
"	border-left: 0px outset transparent;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: #151515;	\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 3px outset rgb(93, 95, 97);  /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\346\267\261\347\201\260 */\n"
"	background-color:#151515;	\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    bor"
                        "der-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/robot.png"), QSize(), QIcon::Normal, QIcon::Off);
        robot_menu_btn->setIcon(icon);
        robot_menu_btn->setIconSize(QSize(35, 35));

        toolbar_layout->addWidget(robot_menu_btn);

        list_robot_btn = new QToolButton(toolbar);
        list_robot_btn->setObjectName(QString::fromUtf8("list_robot_btn"));
        sizePolicy1.setHeightForWidth(list_robot_btn->sizePolicy().hasHeightForWidth());
        list_robot_btn->setSizePolicy(sizePolicy1);
        list_robot_btn->setMinimumSize(QSize(48, 24));
        list_robot_btn->setStyleSheet(QString::fromUtf8("/* \344\270\212\350\276\271\346\241\206\345\256\275\345\272\2460\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\351\200\217\346\230\216 */\n"
"QToolButton{   \n"
"	border-top: 0px outset transparent;       \n"
"	border-bottom: 0px outset transparent;\n"
"	border-right: 0px outset transparent;\n"
"	border-left: 0px outset transparent;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: #151515;	\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 3px outset rgb(93, 95, 97);  /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\346\267\261\347\201\260 */\n"
"	background-color:#151515;	\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    bor"
                        "der-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        list_robot_btn->setIcon(icon1);
        list_robot_btn->setIconSize(QSize(35, 24));

        toolbar_layout->addWidget(list_robot_btn);

        verticalSpacer = new QSpacerItem(20, 409, QSizePolicy::Minimum, QSizePolicy::Expanding);

        toolbar_layout->addItem(verticalSpacer);

        toolButton_4 = new QToolButton(toolbar);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        sizePolicy1.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy1);
        toolButton_4->setMinimumSize(QSize(48, 48));
        toolButton_4->setStyleSheet(QString::fromUtf8("/* \344\270\212\350\276\271\346\241\206\345\256\275\345\272\2460\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\351\200\217\346\230\216 */\n"
"QToolButton{   \n"
"	border-top: 0px outset transparent;       \n"
"	border-bottom: 0px outset transparent;\n"
"	border-right: 0px outset transparent;\n"
"	border-left: 0px outset transparent;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: #151515;	\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 3px outset rgb(93, 95, 97);  /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\346\267\261\347\201\260 */\n"
"	background-color:#151515;	\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    bor"
                        "der-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon2);
        toolButton_4->setIconSize(QSize(35, 35));

        toolbar_layout->addWidget(toolButton_4);

        toolButton = new QToolButton(toolbar);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        sizePolicy1.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy1);
        toolButton->setMinimumSize(QSize(48, 48));
        toolButton->setAutoFillBackground(false);
        toolButton->setStyleSheet(QString::fromUtf8("/* \344\270\212\350\276\271\346\241\206\345\256\275\345\272\2460\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\351\200\217\346\230\216 */\n"
"QToolButton{   \n"
"	border-top: 0px outset transparent;       \n"
"	border-bottom: 0px outset transparent;\n"
"	border-right: 0px outset transparent;\n"
"	border-left: 0px outset transparent;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: #151515;	\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 3px outset rgb(93, 95, 97);  /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\346\267\261\347\201\260 */\n"
"	background-color:#151515;	\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    bor"
                        "der-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imgs/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon3);
        toolButton->setIconSize(QSize(30, 30));

        toolbar_layout->addWidget(toolButton);

        toolButton_3 = new QToolButton(toolbar);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        sizePolicy1.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy1);
        toolButton_3->setMinimumSize(QSize(48, 48));
        toolButton_3->setStyleSheet(QString::fromUtf8("/* \344\270\212\350\276\271\346\241\206\345\256\275\345\272\2460\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\351\200\217\346\230\216 */\n"
"QToolButton{   \n"
"	border-top: 0px outset transparent;       \n"
"	border-bottom: 0px outset transparent;\n"
"	border-right: 0px outset transparent;\n"
"	border-left: 0px outset transparent;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
"QToolButton:hover{\n"
"	background-color: #151515;	\n"
"}\n"
"\n"
"/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
"QToolButton:pressed,QToolButton:checked{\n"
"	border-left: 3px outset rgb(93, 95, 97);  /* \345\267\246\350\276\271\346\241\206\345\256\275\345\272\2463\345\203\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244\272\343\200\201\351\242\234\350\211\262\344\270\272\346\267\261\347\201\260 */\n"
"	background-color:#151515;	\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    bor"
                        "der-color: navy; /* make the default button prominent */\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imgs/setup.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon4);
        toolButton_3->setIconSize(QSize(38, 38));

        toolbar_layout->addWidget(toolButton_3);


        gridLayout->addWidget(toolbar, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        user_hlayout = new QHBoxLayout();
        user_hlayout->setSpacing(0);
        user_hlayout->setObjectName(QString::fromUtf8("user_hlayout"));
        action_stackedwidget = new QStackedWidget(centralwidget);
        action_stackedwidget->setObjectName(QString::fromUtf8("action_stackedwidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(action_stackedwidget->sizePolicy().hasHeightForWidth());
        action_stackedwidget->setSizePolicy(sizePolicy2);
        action_stackedwidget->setMinimumSize(QSize(300, 0));
        action_stackedwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 21, 21);"));
        map_page = new QWidget();
        map_page->setObjectName(QString::fromUtf8("map_page"));
        action_stackedwidget->addWidget(map_page);

        user_hlayout->addWidget(action_stackedwidget);

        tool_stackedwidget = new QStackedWidget(centralwidget);
        tool_stackedwidget->setObjectName(QString::fromUtf8("tool_stackedwidget"));
        sizePolicy.setHeightForWidth(tool_stackedwidget->sizePolicy().hasHeightForWidth());
        tool_stackedwidget->setSizePolicy(sizePolicy);
        tool_stackedwidget->setMinimumSize(QSize(300, 0));
        tool_stackedwidget->setMaximumSize(QSize(300, 16777215));
        tool_stackedwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 21, 21);"));
        map_page_2 = new QWidget();
        map_page_2->setObjectName(QString::fromUtf8("map_page_2"));
        tool_stackedwidget->addWidget(map_page_2);

        user_hlayout->addWidget(tool_stackedwidget);


        verticalLayout_2->addLayout(user_hlayout);

        terminal_stackedwidget = new QStackedWidget(centralwidget);
        terminal_stackedwidget->setObjectName(QString::fromUtf8("terminal_stackedwidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(terminal_stackedwidget->sizePolicy().hasHeightForWidth());
        terminal_stackedwidget->setSizePolicy(sizePolicy3);
        terminal_stackedwidget->setMinimumSize(QSize(0, 200));
        terminal_stackedwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 21, 21);"));
        map_page_3 = new QWidget();
        map_page_3->setObjectName(QString::fromUtf8("map_page_3"));
        terminal_stackedwidget->addWidget(map_page_3);

        verticalLayout_2->addWidget(terminal_stackedwidget);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 824, 27));
        menubar->setStyleSheet(QString::fromUtf8("background-color: rgb(62, 61, 57);\n"
"color: rgb(204, 204, 204);\n"
"\n"
"\n"
""));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setStyleSheet(QString::fromUtf8(""));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTerminal = new QMenu(menubar);
        menuTerminal->setObjectName(QString::fromUtf8("menuTerminal"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTerminal->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuTerminal->addAction(new_terminal);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        new_terminal->setText(QCoreApplication::translate("MainWindow", "new terminal", nullptr));
        robot_menu_btn->setText(QString());
        list_robot_btn->setText(QString());
        toolButton_4->setText(QString());
        toolButton->setText(QString());
        toolButton_3->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuTerminal->setTitle(QCoreApplication::translate("MainWindow", "Terminal", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
