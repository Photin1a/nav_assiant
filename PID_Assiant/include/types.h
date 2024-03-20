#ifndef TYPES_H_
#define TYPES_H_
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <iostream>

namespace photinia {
struct PIDParams {
  double pos_p = 0;
  double pos_i = 0;
  double pos_d = 0;
  double max_v = 9999999999;       // 输出限幅
  double pos_limit_i = 9999999999; // 积分限幅
  double yaw_p = 0;
  double yaw_i = 0;
  double yaw_d = 0;
  double max_w = 9999999999;
  double yaw_limit_i = 9999999999;
};

struct Pose {
  double x = 0;
  double y = 0;
  double z = 0;
  double yaw = 0;
  double pitch = 0;
  double roll = 0;
};

struct Position {
  double x = 0;
  double y = 0;
  double z = 0;
};

struct Euler {
  double yaw = 0;
  double pitch = 0;
  double roll = 0;
};

struct Quaternion {
  double w = 0;
  double x = 0;
  double y = 0;
  double z = 0;
};
// declare
void Info(const QString &info_str);
void Warn(const QString &warn_str);
void Error(const QString &error_str);

double Rand(const double &min, const double &max);

void SavePose(const QString &file_path, const struct photinia::Pose &pose);

struct photinia::Pose &LoadPoseFromJson(const QString &file_path,
                                        struct photinia::Pose &pose);

//读取json文件到json object
bool ReadJsonToObject(const QString &file_path, QJsonObject &json_object);

// json object保存在文件中
bool SaveJsonObject(const QString &file_path, const QJsonObject &param);

//将pid参数保存在json_object中
void PID2JsonObject(const double &pos_p, const double &pos_i,
                    const double &pos_d, const double &yaw_p,
                    const double &yaw_i, const double &yaw_d,
                    const double &max_v, const double &max_w,
                    const double &brake_distance, QJsonObject &pid_json_object);

//将json object转换为QString
QString &ObjectToString(const QJsonObject &object, QString &json_str);

//检查文件是否存在，如果不存在就其default_dir拷贝一个模板过来
void CheckFileExist(const QString &file_path,
                    const QString &default_dir = QString("./template"));

//从json文件中读取key=name的value.
bool ReadJsonParam(const QString &file_path, const QString &name,
                   QJsonValue &json_value);

//在json object中添加键值对
template <typename T>
void AppendJsonValue(QJsonObject &json_object, const QString &key,
                     const T &value) {
  json_object[key] = value;
}

//将键值对追加在json文件中
template <typename T>
bool AddItemJson(const QString &key, const T &value, const QString &file_path) {
  QJsonObject json_object;
  if (!ReadJsonToObject(file_path, json_object)) {
    Error("!ReadJsonToObject(file_path, json_object)");
    return false;
  }
  json_object[key] = value;

  QJsonDocument newJsonDocument(json_object);
  QByteArray newJsonData = newJsonDocument.toJson();
  QFile file(file_path);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate |
                 QIODevice::Text)) {
    Error("!file.open(QIODevice::WriteOnly | QIODevice::Truncate | "
          "QIODevice::Text)");
    return false;
  }
  file.write(newJsonData);
  file.close();
  return true;
}
}; // namespace photinia

#endif