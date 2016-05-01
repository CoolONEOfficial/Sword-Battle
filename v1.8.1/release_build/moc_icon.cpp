/****************************************************************************
** Meta object code from reading C++ file 'icon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sword_Battle/icon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'icon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Icon_t {
    QByteArrayData data[15];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Icon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Icon_t qt_meta_stringdata_Icon = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Icon"
QT_MOC_LITERAL(1, 5, 4), // "load"
QT_MOC_LITERAL(2, 10, 0), // ""
QT_MOC_LITERAL(3, 11, 4), // "type"
QT_MOC_LITERAL(4, 16, 9), // "setWidget"
QT_MOC_LITERAL(5, 26, 7), // "Widget*"
QT_MOC_LITERAL(6, 34, 1), // "w"
QT_MOC_LITERAL(7, 36, 4), // "draw"
QT_MOC_LITERAL(8, 41, 9), // "QPainter&"
QT_MOC_LITERAL(9, 51, 1), // "p"
QT_MOC_LITERAL(10, 53, 8), // "setState"
QT_MOC_LITERAL(11, 62, 8), // "newState"
QT_MOC_LITERAL(12, 71, 6), // "inside"
QT_MOC_LITERAL(13, 78, 7), // "cursorX"
QT_MOC_LITERAL(14, 86, 7) // "cursorY"

    },
    "Icon\0load\0\0type\0setWidget\0Widget*\0w\0"
    "draw\0QPainter&\0p\0setState\0newState\0"
    "inside\0cursorX\0cursorY"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Icon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,
      10,    1,   48,    2, 0x0a /* Public */,
      12,    2,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Bool, QMetaType::Int, QMetaType::Int,   13,   14,

       0        // eod
};

void Icon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Icon *_t = static_cast<Icon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->load((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setWidget((*reinterpret_cast< Widget*(*)>(_a[1]))); break;
        case 2: _t->draw((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 3: _t->setState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: { bool _r = _t->inside((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Icon::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Icon.data,
      qt_meta_data_Icon,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Icon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Icon::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Icon.stringdata0))
        return static_cast<void*>(const_cast< Icon*>(this));
    return QObject::qt_metacast(_clname);
}

int Icon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
