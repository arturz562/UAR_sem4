#include "KlientKonfiguracji.h"
#include "ProtokolSieciowy.h"
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
    // void MyTCPClient::sendMsg(const QJsonObject &json) {
    //     QJsonDocument doc(json);
    //     QByteArray data = doc.toJson(QJsonDocument::Compact);

    //     QByteArray ramka;
    //     QDataStream out(&ramka, QIODevice::WriteOnly);
    //     out.setVersion(QDataStream::Qt_6_0);
    //     out << (quint32)0;
    //     out.device()->write(data);
    //     out.device()->seek(0);
    //     out << (quint32)(ramka.size() - sizeof(quint32));

    //     m_socket.write(ramka);
    // }

    void MyTCPClient::wyslijKonfigPID(double kp, double ti, double td, int metoda) {
        if (!isConnected()) return;

        QByteArray ramka;
        QDataStream out(&ramka, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_0);

        out << (quint32)0; // Miejsce na rozmiar
        out << (quint8)TypRamki::KonfigPID; // Identyfikator ramki
        out << kp << ti << td << metoda; // Dane

        out.device()->seek(0);
        out << (quint32)(ramka.size() - sizeof(quint32));

        m_socket.write(ramka);
    }

    void MyTCPClient::wyslijKonfigARX(const std::vector<double>& A, const std::vector<double>& B, int opoznienie, double szum) {
        if (!isConnected()) return;

        QByteArray ramka;
        QDataStream out(&ramka, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_0);

        out << (quint32)0;
        out << (quint8)TypRamki::KonfigARX;

        // Qt z łatwością serializuje QVector, ale dla std::vector musimy to zrobić ręcznie (lub zamienić na QVector)
        out << (quint32)A.size();
        for(double v : A) out << v;

        out << (quint32)B.size();
        for(double v : B) out << v;

        out << opoznienie << szum;

        out.device()->seek(0);
        out << (quint32)(ramka.size() - sizeof(quint32));

        m_socket.write(ramka);
    }

    void MyTCPClient::wyslijKonfigGen(double amplituda, double okres, int interwal, int typ, double skladowa, double wypelnienie) {
        if (!isConnected()) return;

        QByteArray ramka;
        QDataStream out(&ramka, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_0);

        out << (quint32)0;
        out << (quint8)TypRamki::KonfigGeneratora;
        out << amplituda << okres << interwal << typ << skladowa << wypelnienie;

        out.device()->seek(0);
        out << (quint32)(ramka.size() - sizeof(quint32));

        m_socket.write(ramka);
    }

    void MyTCPClient::wyslijAkcjeSymulacji(Akcja akcja, int parametr) {
        if (!isConnected()) return;

        QByteArray ramka;
        QDataStream out(&ramka, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_0);

        out << (quint32)0;
        out << (quint8)TypRamki::SterowanieSymulacja;
        out << (quint8)akcja;

        // Jeśli to zmiana interwału, dopisujemy go do ramki
        if (akcja == Akcja::ZmienInterwal) {
            out << parametr;
        }

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

            // QByteArray odebraneDane;
            // odebraneDane.resize(m_expectedSize);
            // in.readRawData(odebraneDane.data(), m_expectedSize);

            // QJsonDocument doc = QJsonDocument::fromJson(odebraneDane);
            // if (!doc.isNull() && doc.isObject()) {
            //     emit messageReceived(doc.object());
            // }

            // m_expectedSize = 0;
            // if (m_socket.bytesAvailable() == 0) break;

            // Mamy pełną ramkę, sprawdzamy jej typ
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

            m_expectedSize = 0;
            if (m_socket.bytesAvailable() == 0) break;

        }
    }
