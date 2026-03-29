/****************************************************************************
** Meta object code from reading C++ file 'KlasaUslugowa.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../W_USLUG/KlasaUslugowa.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KlasaUslugowa.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_KlasaUslugowa_t {
    uint offsetsAndSizes[16];
    char stringdata0[14];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[7];
    char stringdata5[8];
    char stringdata6[11];
    char stringdata7[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_KlasaUslugowa_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_KlasaUslugowa_t qt_meta_stringdata_KlasaUslugowa = {
    {
        QT_MOC_LITERAL(0, 13),  // "KlasaUslugowa"
        QT_MOC_LITERAL(14, 8),  // "noweDane"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 4),  // "czas"
        QT_MOC_LITERAL(29, 6),  // "zadana"
        QT_MOC_LITERAL(36, 7),  // "wyjscie"
        QT_MOC_LITERAL(44, 10),  // "sterowanie"
        QT_MOC_LITERAL(55, 5)   // "uchyb"
    },
    "KlasaUslugowa",
    "noweDane",
    "",
    "czas",
    "zadana",
    "wyjscie",
    "sterowanie",
    "uchyb"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_KlasaUslugowa[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    5,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,    7,

       0        // eod
};

Q_CONSTINIT const QMetaObject KlasaUslugowa::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_KlasaUslugowa.offsetsAndSizes,
    qt_meta_data_KlasaUslugowa,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_KlasaUslugowa_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<KlasaUslugowa, std::true_type>,
        // method 'noweDane'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>
    >,
    nullptr
} };

void KlasaUslugowa::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KlasaUslugowa *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->noweDane((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KlasaUslugowa::*)(double , double , double , double , double );
            if (_t _q_method = &KlasaUslugowa::noweDane; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *KlasaUslugowa::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KlasaUslugowa::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KlasaUslugowa.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int KlasaUslugowa::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void KlasaUslugowa::noweDane(double _t1, double _t2, double _t3, double _t4, double _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
