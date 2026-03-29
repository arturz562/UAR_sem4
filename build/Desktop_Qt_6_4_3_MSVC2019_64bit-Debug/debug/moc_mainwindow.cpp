/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../W_PREZENTACJI/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[84];
    char stringdata0[11];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[24];
    char stringdata5[18];
    char stringdata6[5];
    char stringdata7[7];
    char stringdata8[8];
    char stringdata9[5];
    char stringdata10[6];
    char stringdata11[30];
    char stringdata12[23];
    char stringdata13[32];
    char stringdata14[25];
    char stringdata15[20];
    char stringdata16[20];
    char stringdata17[2];
    char stringdata18[2];
    char stringdata19[2];
    char stringdata20[5];
    char stringdata21[5];
    char stringdata22[5];
    char stringdata23[5];
    char stringdata24[5];
    char stringdata25[26];
    char stringdata26[26];
    char stringdata27[24];
    char stringdata28[38];
    char stringdata29[33];
    char stringdata30[29];
    char stringdata31[37];
    char stringdata32[35];
    char stringdata33[29];
    char stringdata34[29];
    char stringdata35[29];
    char stringdata36[39];
    char stringdata37[6];
    char stringdata38[36];
    char stringdata39[15];
    char stringdata40[20];
    char stringdata41[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 20),  // "on_pushStart_clicked"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 19),  // "on_pushStop_clicked"
        QT_MOC_LITERAL(53, 23),  // "on_pushResetSym_clicked"
        QT_MOC_LITERAL(77, 17),  // "aktualizujWykresy"
        QT_MOC_LITERAL(95, 4),  // "czas"
        QT_MOC_LITERAL(100, 6),  // "zadana"
        QT_MOC_LITERAL(107, 7),  // "wyjscie"
        QT_MOC_LITERAL(115, 4),  // "ster"
        QT_MOC_LITERAL(120, 5),  // "uchyb"
        QT_MOC_LITERAL(126, 29),  // "aktualizujParametryGeneratora"
        QT_MOC_LITERAL(156, 22),  // "aktualizujParametryPID"
        QT_MOC_LITERAL(179, 31),  // "on_spinInterwal_editingFinished"
        QT_MOC_LITERAL(211, 24),  // "on_pushConfigARX_clicked"
        QT_MOC_LITERAL(236, 19),  // "odbierzParametryARX"
        QT_MOC_LITERAL(256, 19),  // "std::vector<double>"
        QT_MOC_LITERAL(276, 1),  // "a"
        QT_MOC_LITERAL(278, 1),  // "b"
        QT_MOC_LITERAL(280, 1),  // "k"
        QT_MOC_LITERAL(282, 4),  // "szum"
        QT_MOC_LITERAL(287, 4),  // "umin"
        QT_MOC_LITERAL(292, 4),  // "umax"
        QT_MOC_LITERAL(297, 4),  // "ymin"
        QT_MOC_LITERAL(302, 4),  // "ymax"
        QT_MOC_LITERAL(307, 25),  // "on_pushSaveConfig_clicked"
        QT_MOC_LITERAL(333, 25),  // "on_pushLoadConfig_clicked"
        QT_MOC_LITERAL(359, 23),  // "on_pushResetPID_clicked"
        QT_MOC_LITERAL(383, 37),  // "on_spinOknoObserwacji_editing..."
        QT_MOC_LITERAL(421, 32),  // "on_spinAmplituda_editingFinished"
        QT_MOC_LITERAL(454, 28),  // "on_spinOkres_editingFinished"
        QT_MOC_LITERAL(483, 36),  // "on_spinSkladowaStala_editingF..."
        QT_MOC_LITERAL(520, 34),  // "on_spinWypelnienie_editingFin..."
        QT_MOC_LITERAL(555, 28),  // "on_spinPidKp_editingFinished"
        QT_MOC_LITERAL(584, 28),  // "on_spinPidTi_editingFinished"
        QT_MOC_LITERAL(613, 28),  // "on_spinPidTd_editingFinished"
        QT_MOC_LITERAL(642, 38),  // "on_comboTypSygnalu_currentInd..."
        QT_MOC_LITERAL(681, 5),  // "index"
        QT_MOC_LITERAL(687, 35),  // "on_comboMetCalk_currentIndexC..."
        QT_MOC_LITERAL(723, 14),  // "resetSymulacji"
        QT_MOC_LITERAL(738, 19),  // "on_checkBox_toggled"
        QT_MOC_LITERAL(758, 7)   // "checked"
    },
    "MainWindow",
    "on_pushStart_clicked",
    "",
    "on_pushStop_clicked",
    "on_pushResetSym_clicked",
    "aktualizujWykresy",
    "czas",
    "zadana",
    "wyjscie",
    "ster",
    "uchyb",
    "aktualizujParametryGeneratora",
    "aktualizujParametryPID",
    "on_spinInterwal_editingFinished",
    "on_pushConfigARX_clicked",
    "odbierzParametryARX",
    "std::vector<double>",
    "a",
    "b",
    "k",
    "szum",
    "umin",
    "umax",
    "ymin",
    "ymax",
    "on_pushSaveConfig_clicked",
    "on_pushLoadConfig_clicked",
    "on_pushResetPID_clicked",
    "on_spinOknoObserwacji_editingFinished",
    "on_spinAmplituda_editingFinished",
    "on_spinOkres_editingFinished",
    "on_spinSkladowaStala_editingFinished",
    "on_spinWypelnienie_editingFinished",
    "on_spinPidKp_editingFinished",
    "on_spinPidTi_editingFinished",
    "on_spinPidTd_editingFinished",
    "on_comboTypSygnalu_currentIndexChanged",
    "index",
    "on_comboMetCalk_currentIndexChanged",
    "resetSymulacji",
    "on_checkBox_toggled",
    "checked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  158,    2, 0x08,    1 /* Private */,
       3,    0,  159,    2, 0x08,    2 /* Private */,
       4,    0,  160,    2, 0x08,    3 /* Private */,
       5,    5,  161,    2, 0x08,    4 /* Private */,
      11,    0,  172,    2, 0x08,   10 /* Private */,
      12,    0,  173,    2, 0x08,   11 /* Private */,
      13,    0,  174,    2, 0x08,   12 /* Private */,
      14,    0,  175,    2, 0x08,   13 /* Private */,
      15,    8,  176,    2, 0x08,   14 /* Private */,
      25,    0,  193,    2, 0x08,   23 /* Private */,
      26,    0,  194,    2, 0x08,   24 /* Private */,
      27,    0,  195,    2, 0x08,   25 /* Private */,
      28,    0,  196,    2, 0x08,   26 /* Private */,
      29,    0,  197,    2, 0x08,   27 /* Private */,
      30,    0,  198,    2, 0x08,   28 /* Private */,
      31,    0,  199,    2, 0x08,   29 /* Private */,
      32,    0,  200,    2, 0x08,   30 /* Private */,
      33,    0,  201,    2, 0x08,   31 /* Private */,
      34,    0,  202,    2, 0x08,   32 /* Private */,
      35,    0,  203,    2, 0x08,   33 /* Private */,
      36,    1,  204,    2, 0x08,   34 /* Private */,
      38,    1,  207,    2, 0x08,   36 /* Private */,
      39,    0,  210,    2, 0x08,   38 /* Private */,
      40,    1,  211,    2, 0x08,   39 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    6,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   17,   18,   19,   20,   21,   22,   23,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   41,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_pushStart_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushStop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushResetSym_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'aktualizujWykresy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'aktualizujParametryGeneratora'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'aktualizujParametryPID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinInterwal_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushConfigARX_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'odbierzParametryARX'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double>, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_pushSaveConfig_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushLoadConfig_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushResetPID_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinOknoObserwacji_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinAmplituda_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinOkres_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinSkladowaStala_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinWypelnienie_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinPidKp_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinPidTi_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinPidTd_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboTypSygnalu_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_comboMetCalk_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'resetSymulacji'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBox_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushStart_clicked(); break;
        case 1: _t->on_pushStop_clicked(); break;
        case 2: _t->on_pushResetSym_clicked(); break;
        case 3: _t->aktualizujWykresy((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5]))); break;
        case 4: _t->aktualizujParametryGeneratora(); break;
        case 5: _t->aktualizujParametryPID(); break;
        case 6: _t->on_spinInterwal_editingFinished(); break;
        case 7: _t->on_pushConfigARX_clicked(); break;
        case 8: _t->odbierzParametryARX((*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[8]))); break;
        case 9: _t->on_pushSaveConfig_clicked(); break;
        case 10: _t->on_pushLoadConfig_clicked(); break;
        case 11: _t->on_pushResetPID_clicked(); break;
        case 12: _t->on_spinOknoObserwacji_editingFinished(); break;
        case 13: _t->on_spinAmplituda_editingFinished(); break;
        case 14: _t->on_spinOkres_editingFinished(); break;
        case 15: _t->on_spinSkladowaStala_editingFinished(); break;
        case 16: _t->on_spinWypelnienie_editingFinished(); break;
        case 17: _t->on_spinPidKp_editingFinished(); break;
        case 18: _t->on_spinPidTi_editingFinished(); break;
        case 19: _t->on_spinPidTd_editingFinished(); break;
        case 20: _t->on_comboTypSygnalu_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->on_comboMetCalk_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->resetSymulacji(); break;
        case 23: _t->on_checkBox_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 24;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
