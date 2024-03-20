#include "robot.h"
#include "ui_robot.h"

Robot::Robot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Robot)
{
    ui->setupUi(this);
}

Robot::~Robot()
{
    delete ui;
}
