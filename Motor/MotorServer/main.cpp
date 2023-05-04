#include <QCoreApplication>

#include "service.h"

int main(int argc, char *argv[])
{
    Service service(argc,argv);

//    QtServiceController controller("QtMotorService");

//    if (controller.isInstalled()) qDebug() << "My service is installed";
//    else {
//        qDebug() << "My service isn't install";
//        controller.install(app.applicationDirPath() + "/MyService.exe");
//    }

//    if (controller.isRunning()) qDebug() << "My service is running";
//    else {
//        qDebug() << "My service isn't running";
//        controller.start();
//    }


    return service.exec();
}
