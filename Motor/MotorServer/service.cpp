#include "service.h"
#include <QDebug>
#include <QFile>

#include "clientserver.h"

Service::Service(int argc, char **argv)
    : QtService<QCoreApplication>(argc, argv, "MotorService")
{
    setServiceDescription("Motor Service!");
    setServiceFlags(QtServiceBase::CanBeSuspended);
}

Service::~Service()
{
    if(pClientServer!=nullptr)
        delete  pClientServer;

}

void Service::start()
{
    qDebug() << __FUNCTION__;
    QCoreApplication *app = application();

#if QT_VERSION < 0x040100
    quint16 port = (app->argc() > 1) ?
            QString::fromLocal8Bit(app->argv()[1]).toUShort() : 8080;
#else
    const QStringList arguments = QCoreApplication::arguments();
    quint16 port = (arguments.size() > 1) ?
            arguments.at(1).toUShort() : 8080;
#endif

    qDebug() <<"port:"<<port;
    qDebug() <<arguments;

    if(pClientServer==nullptr) pClientServer = new ClientServer(port, app);

    if (!pClientServer->isListening())
    {
        QFile file("./ccc.txt");
        bool ok = file.open(QIODevice::ReadWrite);
        file.close();

        logMessage(QString("Failed to bind to port %1").arg(pClientServer->serverPort()), QtServiceBase::Error);
        app->quit();
    }

}


void Service::pause()
{
    pClientServer->pause();
}

void Service::resume()
{
    pClientServer->resume();
}



