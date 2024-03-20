#include "tcp_connect.h"
#include <QCoreApplication>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QThread>
#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);
  auto sever = new TcpSever();
  sever->ListenSlot("4042");

  QObject::connect(sever, &TcpSever::NewConnection,
                   [&](const QTcpSocket *tcp_socket) {
                     double x = 50, y = 50, z0 = 50, v0 = 2.5, w0 = 2.5;
                     double t = 0;
                     int num = 0;
                     while (num < 10000) {
                       std::cout << t << "send num:" << num << "\n";
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
                       QThread::msleep(100);
                       t += 0.1;
                       num++;
                     }
                   });
  app.exec();
}