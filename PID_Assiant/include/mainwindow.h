#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qdebug.h"
#include <QDir>
#include <QHBoxLayout>
#include <QHostAddress>
#include <QIcon>
#include <QJsonArray>
#include <QJsonObject>
#include <QLabel>
#include <QMainWindow>
#include <QProcess>
#include <QProgressBar>
#include <QPushButton>
#include <QRegExp>
#include <QString>
#include <QToolButton>

#include <iostream>
#include <map>
#include <vector>

#include "chart.h"
#include "display.h"
#include "qtermwidget.h"
#include "robot.h"
#include "robot_master.h"
#include "tcp_connect.h"
#include "terminalpage.h"
#include "toolpage.h"
#include "types.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void StatusBarLayout();

  // StateBar
  QPushButton *message_btn_;
  QPushButton *ping_btn_;
  QLabel *ping_label_;
  QLabel *signal_type_label_;
  QLabel *position3D_label_;  // m
  QLabel *euler_angle_label_; //度
  QLabel *confidence_label_;  //置信度%
  QProgressBar *battery_progressbar_;

  // tool stackedwidget
  ToolPage *tool_page_; // page 1

  // toolbar
  QToolButton *add_robot_btn_;
  bool list_open_ = false;
  int robot_num_ = 0; //从0开始计数
  int current_robot_index_ = 0;

  // terminal stackedwidget
  TerminalPage *terminal_page_;
  QTermWidget *console_;

  // user stackedwidget
  Display *display_page_;
  Chart *chart_1_;
  QHBoxLayout *chart_1_layout_;
  Chart *chart_2_;
  Chart *chart_3_;

  std::map<QString, QWidget *> statusbar_;

  // Robot list
  std::vector<QToolButton *> robot_btns_;
  std::vector<RobotMaster *> robots_;

  // request location thread
  int location_check_state_ = 0;
  LocationRequest location_request_thread_;

private:
  RobotMaster *AddRobot(RobotMaster *robot_master);
  bool LoadRobotJson();
  RobotMaster *Json2Robot(QJsonObject *json_object);
  bool RemoveRobot(QString name);
  void SetupToolPage(int current_robot_index);
  void SetupStateBar(RobotMaster *robot_master);
  void SetupNewRobotUi();

  //判断robot_ui输入界面参数的合法性
  bool IsLegal(QString name, QString ip, QString port, QString p, QString i,
               QString d, QString max_v);
  bool IsLegal(QString name, QString ip, QString port, QString p, QString i,
               QString d, QString max_v, QString test_distance,
               QString brake_distance, QString detail);
  bool IsLegalName(const QString &name,
                   const std::vector<RobotMaster *> &robots);
  bool IsLegalIP(const QString &ip, const std::vector<RobotMaster *> &robots);
  bool IsLegalPort(const QString &port);
  bool IsLegalVelocity(const QString &velocity);
  bool IsLegalPID(const QString p, const QString i, const QString d);

  void DoTask(const QString &buf);

private slots:
  // MainWindow
  void on_robot_menu_btn_clicked();
  void on_list_robot_btn_clicked();
  void on_new_terminal_triggered();
  void AddRobotBtnClicked();

  // new_robot_ui
  void NewRobot_SaveBtnClicked();

  // ToolPage
  void ToolPage_ConnectBtnClicked();
  void ToolPage_SaveBtnClicked();
  void ToolPage_SendParamsClicked();
  void ToolPage_StartBtnClicked();
  void ToolPage_ResetBtnClicked();

private:
  Ui::MainWindow *ui;
  Robot *new_robot_ui_;
};
#endif // MAINWINDOW_H
