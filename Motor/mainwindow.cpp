#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpsocket.h"

#include <QProcess>
#include <QDataStream>
#include <QtDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pService = new QProcess();
    // 阻塞调用 当前窗口处理结束关闭之后 主窗口才能操作
    // pCaller->execute("/home/gsk/Qt/build-Demo-child1-Desktop_Qt_5_12_3_GCC_64bit-Debug/Demo-child1");
    // 非阻塞调用 当前窗口的执行状态不影 影响主窗口的操作
    QStringList strList;
    strList.append("-e");

    //strList.append("8000");//port
    pService->start("../build-MotorService-Desktop_Qt_5_12_2_GCC_64bit-Release/MotorService", strList);
    // startDetached
    // pCaller->startDetached("/home/gsk/Qt/build-Demo-child1-Desktop_Qt_5_12_3_GCC_64bit-Debug/Demo-child1", QStringList());
    // printf("pCaller->processId() = %d\n", getpid());
    qDebug() << pService->processId();

    tcpSocket=new TcpSocket(this);
    //tcpSocket=new QTcpSocket(this);
    connect(tcpSocket, static_cast<void(TcpSocket::*)(const QString &ip, const QByteArray &data)>(&TcpSocket::dataReady),
            this,static_cast<void(MainWindow::*)(const QString &ip, const QByteArray &data)>(&MainWindow::receiveTcpData));
    connect(tcpSocket,static_cast<void(QTcpSocket::*)(QAbstractSocket::SocketError)>(&QTcpSocket::error),
            this, static_cast<void(MainWindow::*)(QAbstractSocket::SocketError)>(&MainWindow::showTcpError));

}

MainWindow::~MainWindow()
{
    delete ui;

    if(pService != nullptr)
    {
        pService->close();
        delete pService;
    }

    if(tcpSocket != nullptr)
    {
        tcpSocket->close();
        delete tcpSocket;
    }
}

void MainWindow::receiveTcpData(const QString &ip, const QByteArray &data)
{
    QDataStream in(data);
    in.setVersion(QDataStream::Qt_5_11);
//    if(strTcpData.isEmpty())
//    {
//        if(tcpSocket->bytesAvailable()<2048)
//            return;
//        in>>strTcpData;
//    }

    in>>strTcpData;
    qDebug()<<ip<<":"<<strTcpData;

}

void MainWindow::showTcpError(QAbstractSocket::SocketError socketErr)
{
    switch (socketErr) {
    case QAbstractSocket::RemoteHostClosedError:
        qDebug()<<tcpSocket->errorString();
        break;
    case QAbstractSocket::HostNotFoundError:
        qDebug()<<"主机不可达！"<<tcpSocket->errorString();
        break;
    case QAbstractSocket::ConnectionRefusedError:
        qDebug()<<"refuse connection！"<<tcpSocket->errorString();
        break;

    default:
        qDebug()<<tcpSocket->errorString()<<"default";
    }
}


void MainWindow::on_pushButton_clicked()
{
    strTcpData.clear();
    tcpSocket->connection();
    //test send data
    tcpSocket->write("hello!");
}
