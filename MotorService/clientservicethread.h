#ifndef CLIENTSERVICETHREAD_H
#define CLIENTSERVICETHREAD_H

//#include <QObject>
#include <QThread>
#include <QtNetwork>
#include <QTcpSocket>

class ClientServiceThread : public QThread
{
    Q_OBJECT
public:
    explicit ClientServiceThread(qintptr socketDescriptor, QObject *parent = nullptr);

    void run();

signals:
    void error(QTcpSocket::SocketError socketError);    //出错信号
    void disconnectTCP(qintptr socketDescriptor);


public slots:
    void readData();
    void writeData();
    void disconnectToHost();
private:
    qintptr socketDescriptor;
    QTcpSocket tcpSocket;
};

#endif // CLIENTSERVICETHREAD_H
