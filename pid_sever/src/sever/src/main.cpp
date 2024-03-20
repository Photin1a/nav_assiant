#include "tcp_connect.h"
#include "types.h"
#include <QCoreApplication>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>
#include <cmath>
#include <iostream>
#include <ros/ros.h>

void SetParams(const QJsonObject &obj, TcpSever &sever) {
  QString str;
  QJsonObject obj_response;
  obj_response["response_type"] = "received_params";
  sever.SendData(photinia::ObjectToString(obj_response, str));
}
void StartTest(){};
void SendLocation(){};
int main(int argc, char **argv) {
  QCoreApplication app(argc, argv);
  ros::init(argc, argv, "node");
  ros::NodeHandle nh;
  auto location_srv = nh.serviceClient<>()
  auto sever = new TcpSever();
  sever->ListenSlot("4042");
  QObject::connect(sever, &TcpSever::NewConnection,
                   []() { ROS_INFO("Receive a connection."); });
  QObject::connect(sever, &TcpSever::ReadyRead, [&](const QString &buf) {
    auto doc = QJsonDocument::fromJson(buf.toUtf8());
    if (doc.isNull())
      return;
    auto obj = doc.object();
    if (obj["require_type"].toString() == "send_params") {
      SetParams(obj, *sever);
    } else if (obj["require_type"].toString() == "start_to_test") {
      StartTest();
    } else if (obj["require_type"].toString() == "realtime_location") {
      SendLocation();
      // TODO Test
      static double x = 50, y = 50, z0 = 50, v0 = 2.5, w0 = 2.5;
      static double t = 0;
      std::cout << t << "send \n";
      auto v = v0 + 2.5 * sin(t);
      auto w = w0 + 2.5 * cos(t);
      x = x + 0.1 * v * cos(t);
      y = y + 0.1 * v * sin(t);
      QJsonObject obj;
      obj["response_type"] = "realtime_location";
      obj["time_stamped"] = QString::number(t);
      QJsonArray loc = {x, y, 0};
      obj["localization"] = loc;
      QJsonArray qua = {x, y, 0, 0};
      obj["Quaternion"] = qua;
      QJsonArray arry_v = {v, 0, 0};
      obj["linear_velocity"] = arry_v;
      QJsonArray arry_w = {w, 0, 0};
      obj["angular_velocity"] = arry_w;
      obj["battery"] = 10;
      obj["ping"] = 466;
      obj["confidence"] = 90;
      QJsonDocument doc(obj);
      sever->SendData(doc.toJson());
      t += 0.1;
    }
  });

  return app.exec();
}
