#ifndef TCP_CONNECT_H
#define TCP_CONNECT_H

#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>

class TcpClient : public QObject {
  Q_OBJECT
public:
  QTcpSocket *tcp_socket_;
  QString buf_;

public:
  TcpClient();
  ~TcpClient();
  void SendData(const QString &text);

signals:
  void ReadyRead(const QString &buf); 
  void Connected();
  void Disconnected();

public slots:
  void ConnectToHostSlot(const QString &ip, const QString &port);
  void DisconnectToHostSlot();
};

class TcpSever : public QObject {
  Q_OBJECT
public:
  QTcpServer *tcp_server_;
  QTcpSocket *tcp_socket_;
  QString buf_;

public:
  TcpSever();
  ~TcpSever();
  void SendData(const QString &text);

signals:
  void ReadyRead(const QString &buf);
  void NewConnection(const QTcpSocket *tcp_socket);

public slots:
  void ListenSlot(const QString &port);
  void DisconnectAllSlot();
};

#endif
