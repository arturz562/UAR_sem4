#include "SerwerKonfiguracji.h"
#include <QDebug>

    MyTCPServer::MyTCPServer(QObject *parent)
     : QObject{parent}, m_server(this) {
        connect(&m_server,SIGNAL(newConnection()),
        this,SLOT(slot_new_client()));
    }
    bool MyTCPServer::startListening(int port) {
        m_port = port;
        m_isListening = m_server.listen(QHostAddress::Any, port);
        return m_isListening;
    }
    void MyTCPServer::stopListening() {
        m_server.close();
        m_isListening = false;
    }
    int MyTCPServer::getNumClients() {
        return m_clients.length();
    }
    // void MyTCPServer::sendMsg(const QJsonObject &json, int numCli) {
    //     if (numCli >= m_clients.length() || numCli < 0) return;

    //     QJsonDocument doc(json);
    //     QByteArray data = doc.toJson(QJsonDocument::Compact);

    //     QByteArray ramka;
    //     QDataStream out(&ramka, QIODevice::WriteOnly);
    //     out.setVersion(QDataStream::Qt_6_0);
    //     out << (quint32)0;
    //     out.device()->write(data);
    //     out.device()->seek(0);
    //     out << (quint32)(ramka.size() - sizeof(quint32));

    //     m_clients.at(numCli)->write(ramka);
    // }

    void MyTCPServer::wyslijKonfigPID(double kp, double ti, double td, int metoda, int numCli) {
        if (numCli >= m_clients.length() || numCli < 0) return;
        QByteArray ramka;
        QDataStream out(&ramka, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_0);

        out << (quint32)0;
        out << (quint8)TypRamki::KonfigPID;
        out << kp << ti << td << metoda;

        out.device()->seek(0);
        out << (quint32)(ramka.size() - sizeof(quint32));
        m_clients.at(numCli)->write(ramka);
    }

    void MyTCPServer::wyslijKonfigARX(const std::vector<double>& A, const std::vector<double>& B, int opoznienie, double szum, int numCli) {
        if (numCli >= m_clients.length() || numCli < 0) return;
        QByteArray ramka;
        QDataStream out(&ramka, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_0);

        out << (quint32)0;
        out << (quint8)TypRamki::KonfigARX;

        out << (quint32)A.size();
        for(double v : A) out << v;

        out << (quint32)B.size();
        for(double v : B) out << v;

        out << opoznienie << szum;

        out.device()->seek(0);
        out << (quint32)(ramka.size() - sizeof(quint32));
        m_clients.at(numCli)->write(ramka);
    }

    void MyTCPServer::wyslijKonfigGen(double amplituda, double okres, int interwal, int typ, double skladowa, double wypelnienie, int numCli) {
        if (numCli >= m_clients.length() || numCli < 0) return;
        QByteArray ramka;
        QDataStream out(&ramka, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_0);

        out << (quint32)0;
        out << (quint8)TypRamki::KonfigGeneratora;
        out << amplituda << okres << interwal << typ << skladowa << wypelnienie;

        out.device()->seek(0);
        out << (quint32)(ramka.size() - sizeof(quint32));
        m_clients.at(numCli)->write(ramka);
    }

    void MyTCPServer::wyslijAkcjeSymulacji(Akcja akcja, int parametr, int numCli) {
        if (numCli >= m_clients.length() || numCli < 0) return;
        QByteArray ramka;
        QDataStream out(&ramka, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_0);

        out << (quint32)0;
        out << (quint8)TypRamki::SterowanieSymulacja;
        out << (quint8)akcja;
        if (akcja == Akcja::ZmienInterwal) {
            out << parametr;
        }

        out.device()->seek(0);
        out << (quint32)(ramka.size() - sizeof(quint32));
        m_clients.at(numCli)->write(ramka);
    }

    // int MyTCPServer::getClinetID() {
    //     QTcpSocket *client = static_cast<QTcpSocket*> (QObject::sender());
    //     return m_clients.indexOf(client);
    // }
    void MyTCPServer::slot_new_client()
    {
        QTcpSocket *client = m_server.nextPendingConnection();
        m_clients.push_back(client);
        m_expectedSizes[client] = 0;

        auto adr = client->peerAddress();

        connect(client, SIGNAL(disconnected()), this, SLOT(slot_client_disconnected()));
        connect(client, SIGNAL(readyRead()), this, SLOT(slot_newMsg()));

        emit newClientConnected(adr.toString());
        // auto adr = client->peerAddress();
        // QString msgBack = "Hello client " +
        // QString::number( m_clients.indexOf(client));
        // client->write(msgBack.toUtf8());
        // connect(client,SIGNAL(disconnected()),
        // this,SLOT(slot_client_disconnetcted()));
        // connect(client,SIGNAL(readyRead()),
        // this,SLOT(slot_newMsg()));
        // emit newClientConnected(adr.toString());
    }
    void MyTCPServer::slot_client_disconnected()
    {
        // int idx = getClinetID();
        // m_clients.removeAt(idx);
        // emit clientDisconnetced(idx);
        QTcpSocket *client = static_cast<QTcpSocket*>(QObject::sender());
        int idx = m_clients.indexOf(client);
        if (idx != -1) {
            m_clients.removeAt(idx);
            m_expectedSizes.remove(client);
            emit clientDisconnected(idx);
        }
    }
    void MyTCPServer::slot_newMsg()
    {
        // int idx = getClinetID();
        // QString msg = m_clients.at(idx)->readAll();
        // emit newMsgFrom(msg, idx);
        QTcpSocket *client = static_cast<QTcpSocket*>(QObject::sender());
        // int idx = m_clients.indexOf(client);
        // if (idx == -1) return;

        // QDataStream in(client);
        // in.setVersion(QDataStream::Qt_6_0);

        // while (true) {
        //     if (m_expectedSizes[client] == 0) {
        //         if (client->bytesAvailable() < sizeof(quint32)) return;
        //         in >> m_expectedSizes[client];
        //     }

        //     if (client->bytesAvailable() < m_expectedSizes[client]) return;

        //     QByteArray odebraneDane;
        //     odebraneDane.resize(m_expectedSizes[client]);
        //     in.readRawData(odebraneDane.data(), m_expectedSizes[client]);

        //     QJsonDocument doc = QJsonDocument::fromJson(odebraneDane);
        //     if (!doc.isNull() && doc.isObject()) {
        //         emit newMsgFrom(doc.object(), idx);
        //     }

        //     m_expectedSizes[client] = 0;
        //     if (client->bytesAvailable() == 0) break;
        // }
        if (!client) return;

        QDataStream in(client);
        in.setVersion(QDataStream::Qt_6_0);

        while (true) {
            if (m_expectedSizes[client] == 0) {
                if (client->bytesAvailable() < sizeof(quint32)) return;
                in >> m_expectedSizes[client];
            }

            if (client->bytesAvailable() < m_expectedSizes[client]) return;

            // Odczyt pełnej ramki (bez zmieniania logiki wielkości m_expectedSizes)
            quint8 typBajt;
            in >> typBajt;
            TypRamki typ = static_cast<TypRamki>(typBajt);

            switch (typ) {
            case TypRamki::KonfigPID: {
                double kp, ti, td;
                int metoda;
                in >> kp >> ti >> td >> metoda;
                emit odebranoKonfigPID(kp, ti, td, metoda);
                break;
            }
            case TypRamki::KonfigARX: {
                std::vector<double> A, B;
                quint32 sizeA, sizeB;
                double val;
                int opoznienie;
                double szum;

                in >> sizeA;
                for(quint32 i=0; i<sizeA; ++i) { in >> val; A.push_back(val); }

                in >> sizeB;
                for(quint32 i=0; i<sizeB; ++i) { in >> val; B.push_back(val); }

                in >> opoznienie >> szum;
                emit odebranoKonfigARX(A, B, opoznienie, szum);
                break;
            }
            case TypRamki::KonfigGeneratora: {
                double amplituda, okres, skladowa, wypelnienie;
                int interwal, typGen;
                in >> amplituda >> okres >> interwal >> typGen >> skladowa >> wypelnienie;
                emit odebranoKonfigGen(amplituda, okres, interwal, typGen, skladowa, wypelnienie);
                break;
            }
            case TypRamki::SterowanieSymulacja: {
                quint8 akcjaBajt;
                in >> akcjaBajt;
                Akcja akcja = static_cast<Akcja>(akcjaBajt);
                int parametr = 0;
                if (akcja == Akcja::ZmienInterwal) {
                    in >> parametr;
                }
                emit odebranoAkcjeSymulacji(akcja, parametr);
                break;
            }
            default:
                break;
            }

            m_expectedSizes[client] = 0;
            if (client->bytesAvailable() == 0) break;
        }
    }

