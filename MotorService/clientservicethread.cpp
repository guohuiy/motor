#include "clientservicethread.h"
#include <QDateTime>
#include <QByteArray>
#include <QDataStream>



ClientServiceThread::ClientServiceThread(qintptr socketDescriptor, QObject *parent)
    : QThread(parent), socketDescriptor(socketDescriptor)
{
    connect(&tcpSocket, &QTcpSocket::readyRead,  this, &ClientServiceThread::readData);
    connect(&tcpSocket, &QTcpSocket::disconnected, this,&ClientServiceThread::disconnectToHost);
}

void ClientServiceThread::run()
{

    if(!tcpSocket.setSocketDescriptor(socketDescriptor))
    {
        emit error(tcpSocket.error());

        //初始化时加载文件路径
        QFile file("./ddd.txt");
        //以读写的方式打开文件，成功返回true，失败返回false
        //想用其他方式打开文件，请看上面的文件打开模式
        bool ok = file.open(QIODevice::ReadWrite);
        //如果文件不存在，则创建并打开该文件
        file.close();


        return;
    }


    this->exec();//在Qt中启动消息机制

}

// 从客户端接收到的消息
void ClientServiceThread::readData()
{
    QFile file("./aaa.txt");
    bool ok = file.open(QIODevice::ReadWrite);


    if(tcpSocket.isReadable())
    {
        QByteArray buffer = tcpSocket.readAll();
        if(!buffer.isEmpty())
        {
            file.write(buffer);
        }

    }

    file.close();

    //读完数据就写
    writeData();
}

void ClientServiceThread::writeData()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);

    uint time2u=QDateTime::currentDateTime().toTime_t();
    out<<time2u<<":hello你好\n";

    tcpSocket.write(block);         //获取当前时间传会客户端
}

void ClientServiceThread::disconnectToHost()
{
    tcpSocket.disconnectFromHost(); //断开连接
    tcpSocket.waitForDisconnected();//等待返回

    emit disconnectTCP(this->socketDescriptor);

    this->quit();
}
