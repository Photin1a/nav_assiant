#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include <./ui_display.h>

// namespace Ui {
// class Display;
// }

class Display : public QWidget
{
    Q_OBJECT
public:
    explicit Display(QWidget *parent = nullptr);
    ~Display();

public:
    Ui::Display *ui;
};

#endif // DISPLAY_H
