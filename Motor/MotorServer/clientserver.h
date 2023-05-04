#ifndef CLIENTSERVER_H
#define CLIENTSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class ClientServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit ClientServer(quint16 port, QObject* parent = 0)
        : QTcpServer(parent), disabled(false)
    {
        if(!listen(QHostAddress::Any, port))
        {
            qDebug()<<"listen() error!";
        }
    }

    void pause()
    {
        disabled = true;
    }

    void resume()
    {
        disabled = false;
    }

protected:
    void incomingConnection(qintptr socketDescriptor);

private:

signals:
    void clientDisconnected(int sockDesc); //当产生客户端断开连接时向上层发送信号

public slots:
    void clientTcpError(QTcpSocket::SocketError socketError);
    void readClient();

private slots:
    void discardClient();


private:
    bool disabled;
};

#endif // CLIENTSERVER_H
