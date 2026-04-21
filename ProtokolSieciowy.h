#ifndef PROTOKOLSIECIOWY_H
#define PROTOKOLSIECIOWY_H

#include <QtGlobal>

enum class TypRamki : quint8 {
    KonfigARX = 1,
    KonfigPID = 2,
    KonfigGeneratora = 3,
    SterowanieSymulacja = 4, // np. start, stop, interwal
    ProbkaSymulacji = 5      // Przesyłanie y (wyjście) i u (sterowanie)
};

enum class Akcja : quint8 {
    Start = 1,
    Stop = 2,
    Reset = 3,
    ZmienInterwal = 4
};

#endif // PROTOKOLSIECIOWY_H