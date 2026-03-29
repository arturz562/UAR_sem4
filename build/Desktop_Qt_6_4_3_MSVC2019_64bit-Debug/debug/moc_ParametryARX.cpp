/****************************************************************************
** Meta object code from reading C++ file 'ParametryARX.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../W_PREZENTACJI/ParametryARX.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ParametryARX.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ParametryARX_t {
    uint offsetsAndSizes[28];
    char stringdata0[13];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[2];
    char stringdata5[2];
    char stringdata6[11];
    char stringdata7[5];
    char stringdata8[5];
    char stringdata9[5];
    char stringdata10[5];
    char stringdata11[5];
    char stringdata12[22];
    char stringdata13[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ParametryARX_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ParametryARX_t qt_meta_stringdata_ParametryARX = {
    {
        QT_MOC_LITERAL(0, 12),  // "ParametryARX"
        QT_MOC_LITERAL(13, 18),  // "zglosNoweParametry"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 19),  // "std::vector<double>"
        QT_MOC_LITERAL(53, 1),  // "a"
        QT_MOC_LITERAL(55, 1),  // "b"
        QT_MOC_LITERAL(57, 10),  // "opoznienie"
        QT_MOC_LITERAL(68, 4),  // "szum"
        QT_MOC_LITERAL(73, 4),  // "umin"
        QT_MOC_LITERAL(78, 4),  // "umax"
        QT_MOC_LITERAL(83, 4),  // "ymin"
        QT_MOC_LITERAL(88, 4),  // "ymax"
        QT_MOC_LITERAL(93, 21),  // "on_pushZapisz_clicked"
        QT_MOC_LITERAL(115, 21)   // "on_pushAnuluj_clicked"
    },
    "ParametryARX",
    "zglosNoweParametry",
    "",
    "std::vector<double>",
    "a",
    "b",
    "opoznienie",
    "szum",
    "umin",
    "umax",
    "ymin",
    "ymax",
    "on_pushZapisz_clicked",
    "on_pushAnuluj_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ParametryARX[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    8,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,   49,    2, 0x08,   10 /* Private */,
      13,    0,   50,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    4,    5,    6,    7,    8,    9,   10,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ParametryARX::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ParametryARX.offsetsAndSizes,
    qt_meta_data_ParametryARX,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ParametryARX_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ParametryARX, std::true_type>,
        // method 'zglosNoweParametry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double>, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<double>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_pushZapisz_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushAnuluj_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ParametryARX::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ParametryARX *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->zglosNoweParametry((*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::vector<double>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[8]))); break;
        case 1: _t->on_pushZapisz_clicked(); break;
        case 2: _t->on_pushAnuluj_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ParametryARX::*)(std::vector<double> , std::vector<double> , int , double , double , double , double , double );
            if (_t _q_method = &ParametryARX::zglosNoweParametry; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ParametryARX::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParametryARX::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ParametryARX.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ParametryARX::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ParametryARX::zglosNoweParametry(std::vector<double> _t1, std::vector<double> _t2, int _t3, double _t4, double _t5, double _t6, double _t7, double _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
