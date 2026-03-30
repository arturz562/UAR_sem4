#include "W_PREZENTACJI/mainwindow.h"
#include <QApplication>
#include <QTimer>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <iostream>
#include <string>
#include "SerwerKonfiguracji.h"
#include "KlientKonfiguracji.h"

//#define TRYB_TESTOWY
#define KONSOLA

extern void uruchomWszystkieTesty();

int main(int argc, char *argv[])
{
#ifdef KONSOLA
    QApplication a(argc, argv);

    int wybor = 0;
    QString ipSerwera = "127.0.0.1"; // Domyślne IP

    if (argc > 1) {
        QString argument(argv[1]);
        if (argument == "-serwer") {
            wybor = 1;
        } else if (argument == "-klient") {
            wybor = 2;
            if (argc > 2) {
                ipSerwera = QString(argv[2]); // Pobranie IP z drugiego argumentu
            } else {
                //std::cout << "Nie podano IP w argumencie. Uzywam domyslnego: 127.0.0.1\n";
            }
        } else {
            std::cout << "Zly argument!\n";
            //std::cout << "Uzycie: UAR_QT.exe [-serwer | -klient <ip>]\n";
            return 0;
        }
    }
    // --- BRAK ARGUMENTÓW - KLASYCZNE MENU ---
    // else {
    //     std::cout << "=== SYMULATOR UAR - TEST SIECI ===" << std::endl;
    //     std::cout << "1. Uruchom jako SERWER (nasluchuje)" << std::endl;
    //     std::cout << "2. Uruchom jako KLIENT (laczy sie)" << std::endl;
    //     std::cout << "Wybierz tryb (1 lub 2): ";
    //     std::cin >> wybor;

    //     if (wybor == 2) {
    //         std::cout << "Podaj IP serwera (wpisz 127.0.0.1 dla testu na 1 komputerze): ";
    //         std::string wejscieIp;
    //         std::cin >> wejscieIp;
    //         ipSerwera = QString::fromStdString(wejscieIp);
    //     }
    // }

    MyTCPServer* serwer = nullptr;
    MyTCPClient* klient = nullptr;

    if (wybor == 1) {
        serwer = new MyTCPServer(&a);
        if(serwer->startListening(12345)) {
            qInfo() << "\n[SERWER] Uruchomiono. Oczekuje na klienta";
        } else {
            return -1;
        }

        ModelARX obiektARX({2.0, 1.0, 1.0}, {1.0, 2.0, 2.0}, 1, 1.0);

        RegulatorPID regulatorPID(1.0, 0.5, 0.6);

        QJsonObject pelnaKonfiguracja;

        // JEŚLI MASZ ZAIMPLEMENTOWANE METODY toJson() W KLASACH:
        // pelnaKonfiguracja["ARX"] = obiektARX.toJson();
        // pelnaKonfiguracja["PID"] = regulatorPID.toJson();

        //
        QJsonObject jsonARX;

        jsonARX["typ"] = "ModelARX";
        jsonARX["opoznienie"] = obiektARX.getOpoznienieTransportowe();
        jsonARX["szum"] = obiektARX.getOdchylenieStandardoweSzumu();
        QJsonArray arrayA;
        for (double val : obiektARX.getA()) {
            arrayA.append(val);
        }
        jsonARX["A"] = arrayA;

        // Konwersja wektora B na tablicę JSON (potrzebne do poprawnego odczytu u klienta)
        QJsonArray arrayB;
        for (double val : obiektARX.getB()) {
            arrayB.append(val);
        }
        jsonARX["B"] = arrayB;

        QJsonObject jsonPID;
        jsonPID["typ"] = "RegulatorPID";
        jsonPID["Kp"] = regulatorPID.getWzmocnienie();
        jsonPID["Ti"] = regulatorPID.getStalaCalk();
        jsonPID["Td"] = regulatorPID.getStalaRozn();

        pelnaKonfiguracja["ARX"] = jsonARX;
        pelnaKonfiguracja["PID"] = jsonPID;
        // =========================================================

        QObject::connect(serwer, &MyTCPServer::newClientConnected, [serwer, pelnaKonfiguracja](QString adr){
            //qInfo() << "[SERWER] Nowy klient podlaczyl sie z IP:" << adr;

            QTimer::singleShot(1000, [serwer, pelnaKonfiguracja](){
                if(serwer->getNumClients() > 0) {
                    serwer->sendMsg(pelnaKonfiguracja, 0);
                    qInfo() << "[SERWER] Konfiguracja zostala wyslana!";
                }
            });
        });

    } else if (wybor == 2) {
        klient = new MyTCPClient(&a);

        //qInfo() << "\n[KLIENT] Proba polaczenia z" << ipSerwera << "na porcie 12345...";
        klient->connectTo(ipSerwera, 12345);

        QObject::connect(klient, &MyTCPClient::connected, [](){
            qInfo() << "[KLIENT] Polaczono z serwerem";
        });

        QObject::connect(klient, &MyTCPClient::messageReceived, [](QJsonObject json){
            qInfo().noquote() << "\n[KLIENT] Odebrano konfiguracje z serwera:";

            QJsonObject arx = json["ARX"].toObject();
            QJsonObject pid = json["PID"].toObject();

            QJsonArray tablicaA = arx["A"].toArray();
            QJsonArray tablicaB = arx["B"].toArray();

            QString strA = QJsonDocument(tablicaA).toJson(QJsonDocument::Compact);
            QString strB = QJsonDocument(tablicaB).toJson(QJsonDocument::Compact);

            qInfo().noquote() << "[ARX]: | A:" << strA
                              << "| B:" << strB
                              << "| opoznienie:" << arx["opoznienie"].toInt()
                              << "| szum:" << arx["szum"].toDouble();


            qInfo().noquote() << "[PID]: | Kp:" << pid["Kp"].toDouble()
                              << "| Ti:" << pid["Ti"].toDouble()
                              << "| Td:" << pid["Td"].toDouble();

        });

    }

    return a.exec();

#endif

#ifdef TRYB_TESTOWY
    uruchomWszystkieTesty();
    return 0;
#endif

#ifdef MAIN
    uruchomWszystkieTesty();
    QApplication a(argc, argv);

    KlasaUslugowa usluga;

    MainWindow w(nullptr, &usluga);

    w.show();

    return a.exec();
#endif
}
