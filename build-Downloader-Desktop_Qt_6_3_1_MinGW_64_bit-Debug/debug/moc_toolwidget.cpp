/****************************************************************************
** Meta object code from reading C++ file 'toolwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Downloader_Ver2/toolwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ToolWidget_t {
    const uint offsetsAndSize[14];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ToolWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ToolWidget_t qt_meta_stringdata_ToolWidget = {
    {
QT_MOC_LITERAL(0, 10), // "ToolWidget"
QT_MOC_LITERAL(11, 14), // "Widget_clicked"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 10), // "hoverEnter"
QT_MOC_LITERAL(38, 10), // "hoverLeave"
QT_MOC_LITERAL(49, 19), // "Widget_mousePressed"
QT_MOC_LITERAL(69, 20) // "Widget_mouseReleased"

    },
    "ToolWidget\0Widget_clicked\0\0hoverEnter\0"
    "hoverLeave\0Widget_mousePressed\0"
    "Widget_mouseReleased"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    0,   45,    2, 0x06,    2 /* Public */,
       4,    0,   46,    2, 0x06,    3 /* Public */,
       5,    0,   47,    2, 0x06,    4 /* Public */,
       6,    0,   48,    2, 0x06,    5 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ToolWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ToolWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Widget_clicked(); break;
        case 1: _t->hoverEnter(); break;
        case 2: _t->hoverLeave(); break;
        case 3: _t->Widget_mousePressed(); break;
        case 4: _t->Widget_mouseReleased(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ToolWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToolWidget::Widget_clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ToolWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToolWidget::hoverEnter)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ToolWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToolWidget::hoverLeave)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ToolWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToolWidget::Widget_mousePressed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ToolWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ToolWidget::Widget_mouseReleased)) {
                *result = 4;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject ToolWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ToolWidget.offsetsAndSize,
    qt_meta_data_ToolWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ToolWidget_t
, QtPrivate::TypeAndForceComplete<ToolWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *ToolWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToolWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ToolWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ToolWidget::Widget_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ToolWidget::hoverEnter()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ToolWidget::hoverLeave()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ToolWidget::Widget_mousePressed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ToolWidget::Widget_mouseReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
