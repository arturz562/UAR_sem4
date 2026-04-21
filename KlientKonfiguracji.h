#ifndef KLIENTKONFIGURACJI_H
#define KLIENTKONFIGURACJI_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDataStream>
#include <vector>

#include "ProtokolSieciowy.h"

    class MyTCPClient : public QObject
    {
        Q_OBJECT
    public:
        explicit MyTCPClient(QObject *parent = nullptr);
        void connectTo(QString address, int port);
        void disconnectFrom();
        bool isConnected() {return m_socket.isOpen();}

        //void sendMsg(const QJsonObject &json);
        // Przykładowe deklaracje w .h:
        void wyslijKonfigPID(double kp, double ti, double td, int metoda);
        void wyslijKonfigARX(const std::vector<double>& A, const std::vector<double>& B, int opoznienie, double szum);
        void wyslijKonfigGen(double amplituda, double okres, int interwal, int typ, double skladowa, double wypelnienie);
        void wyslijAkcjeSymulacji(Akcja akcja, int parametr = 0);

    signals:
        void connected(QString adr, int port);
        void disconnected();
        //void messageReceived(QJsonObject json);

        void odebranoKonfigPID(double kp, double ti, double td, int metoda);
        void odebranoKonfigARX(std::vector<double> A, std::vector<double> B, int opoznienie, double szum);
        void odebranoKonfigGen(double amplituda, double okres, int interwal, int typ, double skladowa, double wypelnienie);
        void odebranoAkcjeSymulacji(Akcja akcja, int parametr);
    private slots:
        void slot_connected();
        void slot_readyRead();
    private:
        QTcpSocket m_socket;
        QString m_ipAddress = "127.0.0.1";
        int m_port = 12345;
        quint32 m_expectedSize = 0;
    };


#endif // KLIENTKONFIGURACJI_H