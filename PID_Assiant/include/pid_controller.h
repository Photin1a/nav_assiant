#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include "base_local_planner.h"
#include "msgs.hpp"
#include "types.h"
#include <QApplication>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <cmath>
#include <iostream>
#include <memory>

class PIDController : public QObject, BaseLocalPlanner {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID PLUGIN_IID)
  Q_INTERFACES(BaseLocalPlanner)
public:
  bool ComputeVelocityCommands(geometry_msgs::Twist &cmd_vel) override;
  bool IsGoalReached() override;

  bool
  SetPlan(const std::vector<geometry_msgs::PoseStamped> &global_plan) override;
  void Initialize(const QString &name,
                  const QString &config_file_path) override;
  bool LoadConfig() override;
  bool SaveConfig() override;
  void SetParameter() override;

  ~PIDController();

private:
  struct photinia::PIDParams
      pid_controller_params_; //外部访问修改，通过父类参数指针指向调用
  const std::vector<geometry_msgs::PoseStamped> *global_plan_;
  QString config_file_path_;
  double pos_last_error_ = 0, pos_sum_error_ = 0, pos_diff_error_ = 0;
  double yaw_last_error_ = 0, yaw_sum_error_ = 0, yaw_diff_error_ = 0;

private:
  bool CurrentPose(geometry_msgs::Pose &current_pose);
  double PositionPid(const double &current_x, const double &current_y,
                     const double &destination_x, const double &destination_y);
  double YawPid(const double &current_yaw, const double &destination_yaw);
};

#endif