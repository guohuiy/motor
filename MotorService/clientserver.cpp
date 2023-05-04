#include "clientserver.h"
//#include "clientservicethread.h"
#include <QtServiceBase>
#include <QDateTime>
#include <QFile>

void ClientServer::incomingConnection(qintptr socketDescriptor)
{
    if (disabled)
        return;


    // When a new client connects, the server constructs a QTcpSocket and all
    // communication with the client is done over this QTcpSocket. QTcpSocket
    // works asynchronously, this means that all the communication is done
    // in the two slots readClient() and discardClient().
    QTcpSocket* s = new QTcpSocket(this);
    connect(s, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(s, SIGNAL(disconnected()), this, SLOT(discardClient()));
    s->setSocketDescriptor(socketDescriptor);

    QtServiceBase::instance()->logMessage("New Connection");
}

void ClientServer::clientTcpError(QAbstractSocket::SocketError socketError)
{

}

void ClientServer::readClient()
{
    if (disabled)
        return;

    // This slot is called when the client sent data to the server. The
    // server looks if it was a get request and sends a very simple HTML
    // document back.
    QTcpSocket* socket = (QTcpSocket*)sender();
    if(socket->isReadable())
    {
        QFile file("./aaa.txt");
        bool ok = file.open(QIODevice::ReadWrite);


        QByteArray buffer = socket->readAll();
        if(!buffer.isEmpty())
        {
            file.write(buffer);
        }

        file.close();
    }
}

void ClientServer::discardClient()
{
    QTcpSocket* socket = (QTcpSocket*)sender();
    socket->deleteLater();

    QtServiceBase::instance()->logMessage("Connection closed");
}
