#ifndef KLIENTKONFIGURACJI_H
#define KLIENTKONFIGURACJI_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDataStream>

    class MyTCPClient : public QObject
    {
        Q_OBJECT
    public:
        explicit MyTCPClient(QObject *parent = nullptr);
        void connectTo(QString address, int port);
        void disconnectFrom();
        bool isConnected() {return m_socket.isOpen();}
        void sendMsg(const QJsonObject &json);
    signals:
        void connected(QString adr, int port);
        void disconnected();
        void messageReceived(QJsonObject json);
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