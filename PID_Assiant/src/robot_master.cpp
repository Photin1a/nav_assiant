#include "robot_master.h"
using namespace photinia;

RobotMaster::RobotMaster() {}
RobotMaster::RobotMaster(QString name, QString ip, QString port, double max_v,
                         double max_w)
    : ip_(ip), port_(port), name_(name), signal_model_("TCP"), max_v_(max_v),
      max_w_(max_w) {
  Config();
}

RobotMaster::RobotMaster(QString name, QString ip, QString port, double max_v,
                         double max_w, double test_distance,
                         double brake_distance, QString detail)
    : ip_(ip), port_(port), name_(name), signal_model_("TCP"), max_v_(max_v),
      max_w_(max_w), test_distance_(test_distance),
      brake_distance_(brake_distance), detail_(detail) {
  Config();
}

void RobotMaster::Config() {
  // robot config
  robot_config_file_ = "RobotConfig.json";
  robot_config_file_path_ = "./robot_" + name_ + "/" + robot_config_file_;

  // load local planner
  local_planner_name_ = "pid_controller"; //需要从json文件获取  todo
  auto blp_config_file_path = "./robot_" + name_ + "/LocalPlannerConfig.json";
  auto blp_plugin_path = "./robot_" + name_ + "/lib" + local_planner_name_ +
                         ".so"; //插件路径  不同系统不同，todo
  auto blp_plugin_template =
      "./pid_controller_plugin/lib" + local_planner_name_ + ".so";
  // Error(QFileInfo(blp_plugin_template).absolutePath());

  // Load the plugin
  Info("Loading local planner plugin: " + blp_plugin_path);
  CheckFileExist(blp_plugin_path,
                 QFileInfo(blp_plugin_template).absolutePath());
  blp_loader_.setFileName(blp_plugin_path);
  blp_loader_.load();
  QObject *plugin = blp_loader_.instance();
  qDebug() << "pluginAddress:" << plugin << endl;

  if (plugin != nullptr) {
    local_planner_ = qobject_cast<BaseLocalPlanner *>(plugin);
    if (local_planner_) {
      local_planner_->Initialize(local_planner_name_, blp_config_file_path);
      local_planner_->LoadConfig();
      Info("Loaded local planner plugin: " + blp_plugin_path);
    } else {
      Warn("Failed to cast the plugin interface:" + blp_plugin_path);
    }
  } else {
    Warn("Failed to load the plugin, " + blp_loader_.errorString());
  }
}

void RobotMaster::SendCommandJson(QString key, double value) {
  QJsonObject json;
  json[key] = value;
  QJsonDocument doc(json);
  QByteArray jsonData = doc.toJson();
  SendData(jsonData);
}

void RobotMaster::SendCommandJson(QString key, QString value) {
  QJsonObject json;
  json[key] = value;
  QJsonDocument doc(json);
  QByteArray jsonData = doc.toJson();
  SendData(jsonData);
}

void RobotMaster::SendJsonObject(QJsonObject json_object) {
  QJsonDocument document(json_object);
  SendData(document.toJson());
}

void RobotMaster::SendJsonFile(const QString &file_name) {
  QFile file(file_name);
  if (!file.open(QFileDevice::ReadOnly)) {
    Error(file_name + " not opened!");
    return;
  }
  SendData(file.readAll());
}

bool RobotMaster::SaveRobotJson() {
  // write to robot_ name_ Config.json
  QJsonObject json;
  json["name"] = name_;
  json["signal_model"] = signal_model_;
  json["ip"] = ip_;
  json["port"] = port_;
  json["max_v"] = max_v_;
  json["max_w"] = max_w_;
  json["test_distance"] = test_distance_;
  json["brake_distance"] = brake_distance_;
  json["detail"] = detail_;
  QJsonDocument json_document(json);
  QFile file(robot_config_file_path_);
  if (file.open(QIODevice::WriteOnly)) {
    file.write(json_document.toJson());
    file.close();
    Info("Already saved to " + robot_config_file_path_ + "!");
  } else {
    Error("File save failed!");
    return false;
  }

  // write to robot_ name_ local_planner.json
  if (local_planner_ == nullptr) {
    Error("local_planner_==nullptr");
    return false;
  }
  if (!local_planner_->SaveConfig())
    return false;
  return true;
}

bool RobotMaster::RequestState() {}
