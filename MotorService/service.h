#ifndef SERVICE_H
#define SERVICE_H


#include <QCoreApplication>
#include "qtservice.h"

class ClientServer;

class Service : public QtService<QCoreApplication>
{
public:
    Service(int argc, char **argv);
    ~Service() override;

protected:
    void start()override;
    void pause()override;
    void resume()override;

private:

private:
    ClientServer *pClientServer{nullptr};
    int count{0};
};

#endif // SERVICE_H

