#include "terminalpage.h"
#include "ui_terminalpage.h"

TerminalPage::TerminalPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TerminalPage)
{
    ui->setupUi(this);
}

TerminalPage::~TerminalPage()
{
    delete ui;
}
