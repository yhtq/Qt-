/****************************************************************************
** Meta object code from reading C++ file 'downloader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Downloader_Ver2/downloader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Downloader_t {
    QByteArrayData data[6];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Downloader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Downloader_t qt_meta_stringdata_Downloader = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Downloader"
QT_MOC_LITERAL(1, 11, 17), // "download_progress"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "cur_byte"
QT_MOC_LITERAL(4, 39, 9), // "last_byte"
QT_MOC_LITERAL(5, 49, 6) // "finish"

    },
    "Downloader\0download_progress\0\0cur_byte\0"
    "last_byte\0finish"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Downloader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       5,    0,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,

       0        // eod
};

void Downloader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Downloader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->download_progress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->finish(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Downloader::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Downloader::download_progress)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Downloader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Downloader::finish)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Downloader::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Downloader.data,
    qt_meta_data_Downloader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Downloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Downloader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Downloader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Downloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Downloader::download_progress(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Downloader::finish()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
