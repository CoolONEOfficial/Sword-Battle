/****************************************************************************
** Meta object code from reading C++ file 'sword.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sword_Battle/sword.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sword.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Sword_t {
    QByteArrayData data[10];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sword_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sword_t qt_meta_stringdata_Sword = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Sword"
QT_MOC_LITERAL(1, 6, 4), // "load"
QT_MOC_LITERAL(2, 11, 0), // ""
QT_MOC_LITERAL(3, 12, 4), // "type"
QT_MOC_LITERAL(4, 17, 6), // "player"
QT_MOC_LITERAL(5, 24, 9), // "setWidget"
QT_MOC_LITERAL(6, 34, 7), // "Widget*"
QT_MOC_LITERAL(7, 42, 1), // "w"
QT_MOC_LITERAL(8, 44, 8), // "setSpeed"
QT_MOC_LITERAL(9, 53, 8) // "newSpeed"

    },
    "Sword\0load\0\0type\0player\0setWidget\0"
    "Widget*\0w\0setSpeed\0newSpeed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sword[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x0a /* Public */,
       1,    1,   39,    2, 0x2a /* Public | MethodCloned */,
       5,    1,   42,    2, 0x0a /* Public */,
       8,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void Sword::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sword *_t = static_cast<Sword *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->load((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->load((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setWidget((*reinterpret_cast< Widget*(*)>(_a[1]))); break;
        case 3: _t->setSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Sword::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Sword.data,
      qt_meta_data_Sword,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Sword::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sword::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Sword.stringdata0))
        return static_cast<void*>(const_cast< Sword*>(this));
    return QObject::qt_metacast(_clname);
}

int Sword::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
