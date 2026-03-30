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
    //qDebug() << "Test konsoli - program wystartowal poprawnie!";
#ifdef KONSOLA
    QApplication a(argc, argv);

    int wybor = 0;
    QString ipSerwera = "127.0.0.1"; // Domyślne IP

    // --- PARSOWANIE ARGUMENTÓW Z KONSOLI ---
    if (argc > 1) {
        QString argument(argv[1]);
        if (argument == "-serwer") {
            wybor = 1;
        } else if (argument == "-klient") {
            wybor = 2;
            if (argc > 2) {
                ipSerwera = QString(argv[2]); // Pobranie IP z drugiego argumentu
            } else {
                std::cout << "[INFO] Nie podano IP w argumencie. Uzywam domyslnego: 127.0.0.1\n";
            }
        } else {
            std::cout << "Zly argument!\n";
            std::cout << "Uzycie: UAR_QT.exe [-serwer | -klient <ip>]\n";
            return 0;
        }
    }
    // --- BRAK ARGUMENTÓW - KLASYCZNE MENU ---
    else {
        std::cout << "=== SYMULATOR UAR - TEST SIECI ===" << std::endl;
        std::cout << "1. Uruchom jako SERWER (nasluchuje)" << std::endl;
        std::cout << "2. Uruchom jako KLIENT (laczy sie)" << std::endl;
        std::cout << "Wybierz tryb (1 lub 2): ";
        std::cin >> wybor;

        if (wybor == 2) {
            std::cout << "Podaj IP serwera (wpisz 127.0.0.1 dla testu na 1 komputerze): ";
            std::string wejscieIp;
            std::cin >> wejscieIp;
            ipSerwera = QString::fromStdString(wejscieIp);
        }
    }

    // --- URUCHOMIENIE WYBRANEGO TRYBU ---
    MyTCPServer* serwer = nullptr;
    MyTCPClient* klient = nullptr;

    if (wybor == 1) {
        serwer = new MyTCPServer(&a);
        if(serwer->startListening(12345)) {
            qDebug() << "\n[SERWER] Uruchomiono. Nasluchuje na porcie 12345...";
        } else {
            qDebug() << "\n[SERWER] Blad startu serwera!";
            return -1;
        }

        QJsonObject testowaKonfiguracja;
        testowaKonfiguracja["typ"] = "RegulatorPID";
        testowaKonfiguracja["Kp"] = 1.5;
        testowaKonfiguracja["Ti"] = 2.0;
        testowaKonfiguracja["Td"] = 0.5;

        QObject::connect(serwer, &MyTCPServer::newClientConnected, [serwer, testowaKonfiguracja](QString adr){
            qDebug() << "[SERWER] Nowy klient podlaczyl sie z IP:" << adr;
            qDebug() << "[SERWER] Wysylam konfiguracje za 1 sekunde...";

            QTimer::singleShot(1000, [serwer, testowaKonfiguracja](){
                if(serwer->getNumClients() > 0) {
                    serwer->sendMsg(testowaKonfiguracja, 0);
                    qDebug() << "[SERWER] Konfiguracja JSON zostala wyslana!";
                }
            });
        });

    } else if (wybor == 2) {
        klient = new MyTCPClient(&a);

        qDebug() << "\n[KLIENT] Proba polaczenia z" << ipSerwera << "na porcie 12345...";
        klient->connectTo(ipSerwera, 12345);

        QObject::connect(klient, &MyTCPClient::connected, [](){
            qDebug() << "[KLIENT] Polaczono z serwerem! Oczekuje na dane...";
        });

        QObject::connect(klient, &MyTCPClient::messageReceived, [](QJsonObject json){
            qDebug() << "\n[KLIENT] Odebrano poprawna konfiguracje JSON z serwera:";
            qDebug() << QJsonDocument(json).toJson(QJsonDocument::Indented);
        });

    } else {
        std::cout << "Zly wybor. Zamykam program." << std::endl;
        return 0;
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
