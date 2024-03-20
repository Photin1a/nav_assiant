#ifndef _ROBOT_MASTER_H_
#define _ROBOT_MASTER_H_
#include "base_local_planner.h"
#include "tcp_connect.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
// #include <memory.h>
#include "types.h"
#include <QApplication>
#include <QThread>
#include <QPluginLoader>

class RobotMaster : public TcpClient {
  Q_OBJECT
public:
  QString name_ = "deepGlint";
  QString signal_model_ = "TCP";
  QString ip_ = "127.0.0.1";
  QString port_ = "4042";
  double max_v_ = 0;
  double max_w_ = 0;
  double test_distance_ = 0;
  double brake_distance_ = 0;
  QString detail_ = "empty";

  double battery_ = 0;
  unsigned int ping_ = 999;
  struct photinia::Position position_ = {0, 0, 0};
  struct photinia::Euler euler_ = {0, 0, 0};
  struct photinia::Quaternion quaternion_ = {0, 0, 0, 0};

  QString chassis_state_ = "empty";
  double confidence_ = 0; //置信度

  bool online_ = false;

  QString global_planner_name_ = "pid_controller";
  QString local_planner_name_ = "pid_controller";
  BaseLocalPlanner *local_planner_ = nullptr;

public:
  RobotMaster();
  RobotMaster(QString name, QString ip, QString port, double max_v,
              double max_w);
  RobotMaster(QString name, QString ip, QString port, double max_v,
              double max_w, double test_distance, double brake_distance,
              QString detail);
  bool RequestState();
  void SendCommandJson(QString key, double value);
  void SendCommandJson(QString key, QString value);
  void SendJsonObject(QJsonObject json_object);
  void SendJsonFile(const QString &file_name);
  bool SaveRobotJson();

private:
  QPluginLoader blp_loader_;
  void Config();
  QString robot_config_file_;
  QString robot_config_file_path_;
};

class LocationRequest : public QThread {
  Q_OBJECT
public:
  int state_ = 0;
  RobotMaster *robot_ptr_ = nullptr;
  void run() override {
    while (true) {
      if (robot_ptr_ == nullptr) {
        continue;
      };
      if (state_ == Qt::Checked) {
        QString request_location = "{\"require_type\":\"realtime_location\"}";
        robot_ptr_->SendData(request_location);
        QThread::msleep(100);
      }
    }
  }
};

#endif