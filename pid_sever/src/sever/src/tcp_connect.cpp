#include "tcp_connect.h"
#include <QObject>

TcpClient::TcpClient() { tcp_socket_ = new QTcpSocket(); }

void TcpClient::ConnectToHostSlot(const QString &ip, const QString &port) {
  tcp_socket_->connectToHost(ip, port.toUInt());
  QObject::connect(tcp_socket_, &QAbstractSocket::connected, [&]() {
    emit Connected(); //已连接
    QObject::connect(tcp_socket_, &QIODevice::readyRead, [&]() {
      buf_ = tcp_socket_->readAll();
      emit ReadyRead(buf_);
    });
    QObject::connect(tcp_socket_, &QTcpSocket::disconnected,
                     [&]() { emit Disconnected(); });
  });
}

void TcpClient::DisconnectToHostSlot() { tcp_socket_->close(); }

void TcpClient::SendData(const QString &text) {
  tcp_socket_->write(text.toLocal8Bit());
  tcp_socket_->flush();   //刷新缓存，write只是写入缓存
}
TcpClient::~TcpClient() {
  if (tcp_socket_ != nullptr)
    delete tcp_socket_;
}

TcpSever::TcpSever() {
  tcp_server_ = new QTcpServer();
  // tcp_socket_ = new QTcpSocket();
  QObject::connect(tcp_server_, &QTcpServer::newConnection, [&]() {
    tcp_socket_ = tcp_server_->nextPendingConnection();
    emit NewConnection(tcp_socket_);
    QObject::connect(tcp_socket_, &QIODevice::readyRead, [&]() {
      buf_ = tcp_socket_->readAll();
      emit ReadyRead(buf_);
    });
  });
}

void TcpSever::ListenSlot(const QString &port) {
  if (!tcp_server_->listen(QHostAddress::Any, port.toUInt()))
    qDebug() << "!tcp_server_->listen(QHostAddress::Any, port.toUInt())\n";
}

void TcpSever::DisconnectAllSlot() { tcp_server_->close(); }

void TcpSever::SendData(const QString &text) {
  tcp_socket_->write(text.toLocal8Bit());
  tcp_socket_->flush();   //刷新缓存，write只是写入缓存
}
TcpSever::~TcpSever() {
  if (tcp_server_ != nullptr)
    delete tcp_server_;
  if (tcp_socket_ != nullptr)
    delete tcp_socket_;
}