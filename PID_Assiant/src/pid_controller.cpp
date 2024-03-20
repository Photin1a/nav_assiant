#include "pid_controller.h"
using namespace photinia;

bool PIDController::ComputeVelocityCommands(geometry_msgs::Twist &cmd_vel) {}
bool PIDController::IsGoalReached() {}
bool PIDController::SetPlan(
    const std::vector<geometry_msgs::PoseStamped> &global_plan) {
  global_plan_ = &global_plan;
}
void PIDController::Initialize(const QString &name,
                               const QString &config_file_path) {
  config_file_path_ = config_file_path; //配置文件
  params_ = &pid_controller_params_;    //父类成员指针指向子类成员
  // std::cout << name.toStdString() << std::endl;
}
PIDController::~PIDController() {}

bool PIDController::LoadConfig() {
  QJsonValue pos_p, pos_i, pos_d, max_v, pos_limit_i, yaw_p, yaw_i, yaw_d,
      max_w, yaw_limit_i;
  if (!ReadJsonParam(config_file_path_, "pos_p", pos_p) ||
      !ReadJsonParam(config_file_path_, "pos_i", pos_i) ||
      !ReadJsonParam(config_file_path_, "pos_d", pos_d) ||
      !ReadJsonParam(config_file_path_, "max_v", max_v) ||
      !ReadJsonParam(config_file_path_, "pos_limit_i", pos_limit_i) ||
      !ReadJsonParam(config_file_path_, "yaw_p", yaw_p) ||
      !ReadJsonParam(config_file_path_, "yaw_i", yaw_i) ||
      !ReadJsonParam(config_file_path_, "yaw_d", yaw_d) ||
      !ReadJsonParam(config_file_path_, "max_w", max_w) ||
      !ReadJsonParam(config_file_path_, "limit_yaw_i", yaw_limit_i)) {
    Error("Load PID controller faild!");
    return false;
  }
  pid_controller_params_ = {pos_p.toDouble(),       pos_i.toDouble(),
                            pos_d.toDouble(),       max_v.toDouble(),
                            pos_limit_i.toDouble(), yaw_p.toDouble(),
                            yaw_i.toDouble(),       yaw_d.toDouble(),
                            max_w.toDouble(),       yaw_limit_i.toDouble()};
  return true;
}

bool PIDController::SaveConfig() {
  QJsonObject json;
  json["pos_p"] = pid_controller_params_.pos_p;
  json["pos_i"] = pid_controller_params_.pos_i;
  json["pos_d"] = pid_controller_params_.pos_d;
  json["max_v"] = pid_controller_params_.max_v;
  json["pos_limit_i"] = pid_controller_params_.pos_limit_i;
  json["yaw_p"] = pid_controller_params_.yaw_p;
  json["yaw_i"] = pid_controller_params_.yaw_i;
  json["yaw_d"] = pid_controller_params_.yaw_d;
  json["max_w"] = pid_controller_params_.max_w;
  json["yaw_limit_i"] = pid_controller_params_.yaw_limit_i;
  QJsonDocument json_document2(json);
  QFile file(config_file_path_);
  if (file.open(QIODevice::WriteOnly)) {
    file.write(json_document2.toJson());
    file.close();
    Info("Already saved to" + config_file_path_ + "!");
  } else {
    Error("File " + config_file_path_ + " save failed!");
    return false;
  }
  return true;
}

//不稳定的参数设置
void PIDController::SetParameter() {
  auto ptr = (PIDParams *)params_;
  pid_controller_params_.pos_p = ptr->pos_p;
  pid_controller_params_.pos_i = ptr->pos_i;
  pid_controller_params_.pos_d = ptr->pos_d;
  pid_controller_params_.max_v = ptr->max_v;
  pid_controller_params_.pos_limit_i = ptr->pos_limit_i;
  pid_controller_params_.yaw_p = ptr->yaw_p;
  pid_controller_params_.yaw_i = ptr->yaw_i;
  pid_controller_params_.yaw_d = ptr->yaw_d;
  pid_controller_params_.max_w = ptr->max_w;
  pid_controller_params_.yaw_limit_i = ptr->yaw_limit_i;
}

bool PIDController::CurrentPose(geometry_msgs::Pose &current_pose) {}
double PIDController::PositionPid(const double &current_x,
                                  const double &current_y,
                                  const double &destination_x,
                                  const double &destination_y) {
  auto current_error = sqrt(pow(destination_x - current_x, 2) +
                            pow(destination_y - current_y, 2));
  pos_sum_error_ += current_error;
  pos_diff_error_ = current_error - pos_last_error_;
  pos_sum_error_ > pid_controller_params_.pos_limit_i
      ? pos_sum_error_ = pid_controller_params_.pos_limit_i
      : pos_sum_error_; //积分限幅
  auto output = pid_controller_params_.pos_p * current_error +
                pid_controller_params_.pos_i * pos_sum_error_ +
                pid_controller_params_.pos_d * pos_diff_error_;
  output > pid_controller_params_.max_v ? output = pid_controller_params_.max_w
                                        : output; //输出限幅
  return output;
}
double PIDController::YawPid(const double &current_yaw,
                             const double &destination_yaw) {
  auto current_error = destination_yaw - current_yaw;
  yaw_sum_error_ += current_error;
  yaw_diff_error_ = current_error - yaw_last_error_;
  yaw_sum_error_ > pid_controller_params_.yaw_limit_i
      ? yaw_sum_error_ = pid_controller_params_.yaw_limit_i
      : yaw_sum_error_; //积分限幅
  auto output = pid_controller_params_.yaw_p * current_error +
                pid_controller_params_.yaw_i * yaw_sum_error_ +
                pid_controller_params_.yaw_d * yaw_diff_error_;
  output > pid_controller_params_.max_v ? output = pid_controller_params_.max_w
                                        : output; //输出限幅
  return output;
}
