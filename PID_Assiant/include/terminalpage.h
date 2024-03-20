#ifndef TERMINALPAGE_H
#define TERMINALPAGE_H

#include <QWidget>

namespace Ui {
class TerminalPage;
}

class TerminalPage : public QWidget
{
    Q_OBJECT

public:
    explicit TerminalPage(QWidget *parent = nullptr);
    ~TerminalPage();

public:
    Ui::TerminalPage *ui;
};

#endif // TERMINALPAGE_H
