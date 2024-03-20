#ifndef ROBOT_H
#define ROBOT_H

#include <QWidget>

namespace Ui {
class Robot;
}

class Robot : public QWidget
{
    Q_OBJECT

public:
    explicit Robot(QWidget *parent = nullptr);
    ~Robot();

public:
    Ui::Robot *ui;
};

#endif // ROBOT_H
