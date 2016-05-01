/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sword_Battle/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[23];
    char stringdata0[376];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 11), // "checkAttack"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 15), // "setMatrixPlayer"
QT_MOC_LITERAL(4, 36, 14), // "setMatrixEnemy"
QT_MOC_LITERAL(5, 51, 9), // "enemyShot"
QT_MOC_LITERAL(6, 61, 6), // "goFade"
QT_MOC_LITERAL(7, 68, 10), // "paintEvent"
QT_MOC_LITERAL(8, 79, 12), // "QPaintEvent*"
QT_MOC_LITERAL(9, 92, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(10, 110, 12), // "QMouseEvent*"
QT_MOC_LITERAL(11, 123, 15), // "mousePressEvent"
QT_MOC_LITERAL(12, 139, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(13, 154, 19), // "startMainAnimations"
QT_MOC_LITERAL(14, 174, 15), // "iconsAnimations"
QT_MOC_LITERAL(15, 190, 20), // "startIconsAnimations"
QT_MOC_LITERAL(16, 211, 20), // "startQExitAnimations"
QT_MOC_LITERAL(17, 232, 22), // "startOptionsAnimations"
QT_MOC_LITERAL(18, 255, 19), // "startGameAnimations"
QT_MOC_LITERAL(19, 275, 20), // "startPauseAnimations"
QT_MOC_LITERAL(20, 296, 19), // "startShopAnimations"
QT_MOC_LITERAL(21, 316, 26), // "startGameOptionsAnimations"
QT_MOC_LITERAL(22, 343, 32) // "restartMainSwordOpasityAnimation"

    },
    "Widget\0checkAttack\0\0setMatrixPlayer\0"
    "setMatrixEnemy\0enemyShot\0goFade\0"
    "paintEvent\0QPaintEvent*\0mouseReleaseEvent\0"
    "QMouseEvent*\0mousePressEvent\0"
    "mouseMoveEvent\0startMainAnimations\0"
    "iconsAnimations\0startIconsAnimations\0"
    "startQExitAnimations\0startOptionsAnimations\0"
    "startGameAnimations\0startPauseAnimations\0"
    "startShopAnimations\0startGameOptionsAnimations\0"
    "restartMainSwordOpasityAnimation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x08 /* Private */,
       3,    0,  110,    2, 0x08 /* Private */,
       4,    0,  111,    2, 0x08 /* Private */,
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    1,  114,    2, 0x08 /* Private */,
       9,    1,  117,    2, 0x08 /* Private */,
      11,    1,  120,    2, 0x08 /* Private */,
      12,    1,  123,    2, 0x08 /* Private */,
      13,    1,  126,    2, 0x08 /* Private */,
      13,    0,  129,    2, 0x28 /* Private | MethodCloned */,
      15,    0,  130,    2, 0x08 /* Private */,
      16,    0,  131,    2, 0x08 /* Private */,
      17,    0,  132,    2, 0x08 /* Private */,
      18,    0,  133,    2, 0x08 /* Private */,
      19,    0,  134,    2, 0x08 /* Private */,
      20,    0,  135,    2, 0x08 /* Private */,
      21,    0,  136,    2, 0x08 /* Private */,
      22,    0,  137,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkAttack(); break;
        case 1: _t->setMatrixPlayer(); break;
        case 2: _t->setMatrixEnemy(); break;
        case 3: _t->enemyShot(); break;
        case 4: _t->goFade(); break;
        case 5: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 6: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 9: _t->startMainAnimations((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->startMainAnimations(); break;
        case 11: _t->startIconsAnimations(); break;
        case 12: _t->startQExitAnimations(); break;
        case 13: _t->startOptionsAnimations(); break;
        case 14: _t->startGameAnimations(); break;
        case 15: _t->startPauseAnimations(); break;
        case 16: _t->startShopAnimations(); break;
        case 17: _t->startGameOptionsAnimations(); break;
        case 18: _t->restartMainSwordOpasityAnimation(); break;
        default: ;
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
