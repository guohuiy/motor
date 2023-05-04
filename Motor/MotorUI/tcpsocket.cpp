#include "tcpsocket.h"
#include <QHostAddress>

TcpSocket::TcpSocket(QObject *parent) : QTcpSocket(parent)
{
    connect(this, &TcpSocket::readyRead, this, &TcpSocket::recvData);
}

TcpSocket::~TcpSocket()
{
    this->abort();
}


bool TcpSocket::connection()
{
    this->abort();
    this->connectToHost(QHostAddress::LocalHost,8080);
    if (this->waitForConnected(1000))  // 连接成功则true
    {
        return true;
    }
    return false;
}

void TcpSocket::disConnect()
{
    this->disconnectFromHost();//断开连接
}

void TcpSocket::sendMess(const QString &str)//发送数据
{
   this->write(str.toLocal8Bit());
}

void TcpSocket:: recvData() //从服务器接收到数据后
{
    QString ip = peerAddress().toString().remove(0, 7);
    QByteArray data = readAll();
    emit dataReady(ip, data); //向界面层发送带数据的信号量
}
