#ifndef SERWERKONFIGURACJI_H
#define SERWERKONFIGURACJI_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDataStream>
#include <QMap>

    class MyTCPServer : public QObject
    {
        Q_OBJECT
    public:
        explicit MyTCPServer(QObject *parent = nullptr);
        bool startListening(int port);
        bool isListening() {return m_isListening;}
        void stopListening();
        int getNumClients();
        void sendMsg(const QJsonObject &json, int numCli);
    signals:
        void newClientConnected(QString adr);
        void clientDisconnected(int num);
        void newMsgFrom(QJsonObject json, int num);
    private slots:
        void slot_new_client();
        void slot_client_disconnetcted();
        void slot_newMsg();
    private:
        int getClinetID();
        bool m_isListening = false;
        int m_port = 12345;
        QTcpServer m_server;
        QVector<QTcpSocket*> m_clients;
        QMap<QTcpSocket*, quint32> m_expectedSizes;
    };

#endif // SERWERKONFIGURACJI_H