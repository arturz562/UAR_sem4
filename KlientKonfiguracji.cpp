#include "KlientKonfiguracji.h"
#include <QDebug>

    MyTCPClient::MyTCPClient(QObject *parent)
     : QObject{parent}, m_socket(this) {
        connect(&m_socket,SIGNAL(connected()),this,SLOT(slot_connected()));
        connect(&m_socket,SIGNAL(disconnected()),this,SIGNAL(disconnected()));
        connect(&m_socket,SIGNAL(readyRead()),this,SLOT(slot_readyRead()));
    }
    void MyTCPClient::connectTo(QString address, int port) {
        m_ipAddress = address;
        m_port = port;
        m_socket.connectToHost(m_ipAddress,port);
    }
    void MyTCPClient::disconnectFrom() {
        m_socket.close();
    }
    void MyTCPClient::sendMsg(const QJsonObject &json) {
        QJsonDocument doc(json);
        QByteArray data = doc.toJson(QJsonDocument::Compact);

        QByteArray ramka;
        QDataStream out(&ramka, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_0);
        out << (quint32)0;
        out.device()->write(data);
        out.device()->seek(0);
        out << (quint32)(ramka.size() - sizeof(quint32));

        m_socket.write(ramka);
    }
    void MyTCPClient::slot_connected() {
        emit connected(m_ipAddress,m_port);
    }
    void MyTCPClient::slot_readyRead() {
        QDataStream in(&m_socket);
        in.setVersion(QDataStream::Qt_6_0);

        while (true) {
            if (m_expectedSize == 0) {
                if (m_socket.bytesAvailable() < sizeof(quint32)) return;
                in >> m_expectedSize;
            }

            if (m_socket.bytesAvailable() < m_expectedSize) return;

            QByteArray odebraneDane;
            odebraneDane.resize(m_expectedSize);
            in.readRawData(odebraneDane.data(), m_expectedSize);

            QJsonDocument doc = QJsonDocument::fromJson(odebraneDane);
            if (!doc.isNull() && doc.isObject()) {
                emit messageReceived(doc.object());
            }

            m_expectedSize = 0;
            if (m_socket.bytesAvailable() == 0) break;
        }
    }
