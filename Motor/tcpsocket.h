#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>

class QHostAddress;

class TcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpSocket(QObject *parent = nullptr);
    ~TcpSocket();

    bool connection();                //连接服务器
    void disConnect();                                          //断开服务器
    void sendMess(const QString &str);                         //向服务器发送数据
signals:
    void dataReady(const QString &ip, const QByteArray &data);  //从服务器接收到数据后向界面层发送信号

private slots:
    void recvData();                                            //对QTcpSocket 接收到数据产生的信号设定的槽函数
};

#endif // TCPSOCKET_H
