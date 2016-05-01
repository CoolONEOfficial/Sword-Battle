/****************************************************************************
** Meta object code from reading C++ file 'animation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sword_Battle/animation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Animation_t {
    QByteArrayData data[18];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Animation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Animation_t qt_meta_stringdata_Animation = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Animation"
QT_MOC_LITERAL(1, 10, 6), // "create"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 4), // "stop"
QT_MOC_LITERAL(4, 23, 5), // "start"
QT_MOC_LITERAL(5, 29, 13), // "stopAnimation"
QT_MOC_LITERAL(6, 43, 16), // "setDefaultCoords"
QT_MOC_LITERAL(7, 60, 5), // "pause"
QT_MOC_LITERAL(8, 66, 5), // "reset"
QT_MOC_LITERAL(9, 72, 8), // "setValue"
QT_MOC_LITERAL(10, 81, 6), // "newVal"
QT_MOC_LITERAL(11, 88, 17), // "saveDefaultCoords"
QT_MOC_LITERAL(12, 106, 11), // "setEndValue"
QT_MOC_LITERAL(13, 118, 11), // "setDuration"
QT_MOC_LITERAL(14, 130, 8), // "duration"
QT_MOC_LITERAL(15, 139, 14), // "setEasingCurve"
QT_MOC_LITERAL(16, 154, 11), // "easingCurve"
QT_MOC_LITERAL(17, 166, 5) // "value"

    },
    "Animation\0create\0\0stop\0start\0stopAnimation\0"
    "setDefaultCoords\0pause\0reset\0setValue\0"
    "newVal\0saveDefaultCoords\0setEndValue\0"
    "setDuration\0duration\0setEasingCurve\0"
    "easingCurve\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Animation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       1,  104, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    2,   76,    2, 0x0a /* Public */,
       4,    1,   81,    2, 0x2a /* Public | MethodCloned */,
       4,    0,   84,    2, 0x2a /* Public | MethodCloned */,
       7,    0,   85,    2, 0x0a /* Public */,
       8,    0,   86,    2, 0x0a /* Public */,
       9,    2,   87,    2, 0x0a /* Public */,
       9,    1,   92,    2, 0x2a /* Public | MethodCloned */,
      12,    1,   95,    2, 0x0a /* Public */,
      13,    1,   98,    2, 0x0a /* Public */,
      15,    1,  101,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    5,    6,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QEasingCurve,   16,

 // properties: name, type, flags
      17, QMetaType::Int, 0x00095003,

       0        // eod
};

void Animation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Animation *_t = static_cast<Animation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->create(); break;
        case 1: _t->stop(); break;
        case 2: _t->start((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->start((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->start(); break;
        case 5: _t->pause(); break;
        case 6: _t->reset(); break;
        case 7: _t->setValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setEndValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setDuration((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setEasingCurve((*reinterpret_cast< QEasingCurve(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Animation *_t = static_cast<Animation *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getValueAnimation(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Animation *_t = static_cast<Animation *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValueAnimation(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Animation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Animation.data,
      qt_meta_data_Animation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Animation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Animation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Animation.stringdata0))
        return static_cast<void*>(const_cast< Animation*>(this));
    return QObject::qt_metacast(_clname);
}

int Animation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
