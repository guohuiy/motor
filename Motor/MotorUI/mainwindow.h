#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

class QProcess;
class TcpSocket;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void receiveTcpData(const QString &ip, const QByteArray &data);
    void showTcpError(QAbstractSocket::SocketError);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QProcess *pService{nullptr} ;

    QString strTcpData;
    TcpSocket *tcpSocket{nullptr};
};

#endif // MAINWINDOW_H
