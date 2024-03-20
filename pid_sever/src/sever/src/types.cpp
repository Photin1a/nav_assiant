#include "types.h"

namespace photinia {
void Info(const QString &info_str) {
  std::cout << "\033[32m[info]:" << info_str.toStdString() << "\033[0m\n";
}
void Warn(const QString &warn_str) {
  std::cout << "\033[33m[warn]:" << warn_str.toStdString() << "\033[0m\n";
}
void Error(const QString &error_str) {
  std::cout << "\033[31m[error]:" << error_str.toStdString() << "\033[0m\n";
}
double Rand(const double &min, const double &max) {
  return min + (double)(rand()) / RAND_MAX * (max - min);
}
void SavePose(const QString &file_path, const struct photinia::Pose &pose) {
  QJsonObject obj;
  obj["x"] = pose.x;
  obj["y"] = pose.y;
  obj["z"] = pose.z;
  obj["yaw"] = pose.yaw;
  obj["roll"] = pose.roll;
  obj["pitch"] = pose.pitch;
  photinia::SaveJsonObject(file_path, obj);
}

struct photinia::Pose &LoadPoseFromJson(const QString &file_path,
                                        struct photinia::Pose &pose) {
  QJsonObject obj;
  ReadJsonToObject(file_path, obj);
  pose.x = obj["x"].toDouble();
  pose.y = obj["y"].toDouble();
  pose.z = obj["z"].toDouble();
  pose.yaw = obj["yaw"].toDouble();
  pose.roll = obj["roll"].toDouble();
  pose.pitch = obj["pitch"].toDouble();
  return pose;
}

QString &ObjectToString(const QJsonObject &object, QString &json_str) {
  json_str = QJsonDocument(object).toJson();
  return json_str;
}

bool ReadJsonToObject(const QString &file_path, QJsonObject &json_object) {
  CheckFileExist(file_path);
  QFile json_file(file_path);
  if (!json_file.open(QIODevice::ReadWrite | QIODevice::Text)) {
    Error("false " + file_path +
          ".open(QIODevice::ReadWrite | QIODevice::Text)");
    return false;
  }
  QByteArray data = json_file.readAll();
  QJsonParseError parseError;
  QJsonDocument json_doc = QJsonDocument::fromJson(data, &parseError);
  if (parseError.error != QJsonParseError::NoError) {
    Warn("Error parsing JSON:" + parseError.errorString() + "," + file_path +
         "is not a json file!");
    return false;
  }
  if (!json_doc.isObject()) {
    Error("JSON document is not an object.");
    return false;
  }
  json_object = json_doc.object();
  json_file.close();
  return true;
}

// 检查文件是否存在，不在去默认路径拷贝
void CheckFileExist(const QString &file_path, const QString &default_dir) {
  QFileInfo fileinfo(file_path);
  QDir directory(fileinfo.absolutePath());
  if (!directory.exists()) {
    directory.mkpath("."); // 新建目录./robot_name/
  }
  auto file = QFile(file_path);
  if (!file.exists()) {
    QFile::copy(default_dir + "/" + fileinfo.fileName(), file_path);
  }
}
bool ReadJsonParam(const QString &file_path, const QString &name,
                   QJsonValue &json_value) {
  QJsonObject json_object;
  if (!ReadJsonToObject(file_path, json_object)) {
    Error("!ReadJsonToObject(file_path, json_object)");
    return false;
  }
  json_value = json_object.value(name);
  return true;
}

bool SaveJsonObject(const QString &file_path, const QJsonObject &param) {
  QJsonValue json_value;
  if (!ReadJsonParam(file_path, "params list", json_value))
    return false;
  QJsonArray params_list = json_value.toArray();
  params_list.append(QJsonObject(param));
  QFile file(file_path);
  QJsonObject object;
  object["params list"] = params_list;
  file.open(QFileDevice::WriteOnly);
  file.write(QJsonDocument(object).toJson());
  file.close();
  Info("Saved " + file_path);
  return true;
}
} // namespace photinia