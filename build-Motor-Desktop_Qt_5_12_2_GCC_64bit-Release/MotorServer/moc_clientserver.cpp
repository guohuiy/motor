/****************************************************************************
** Meta object code from reading C++ file 'clientserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MOTOR/MotorServer/clientserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientServer_t {
    QByteArrayData data[9];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientServer_t qt_meta_stringdata_ClientServer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ClientServer"
QT_MOC_LITERAL(1, 13, 18), // "clientDisconnected"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 8), // "sockDesc"
QT_MOC_LITERAL(4, 42, 14), // "clientTcpError"
QT_MOC_LITERAL(5, 57, 23), // "QTcpSocket::SocketError"
QT_MOC_LITERAL(6, 81, 11), // "socketError"
QT_MOC_LITERAL(7, 93, 10), // "readClient"
QT_MOC_LITERAL(8, 104, 13) // "discardClient"

    },
    "ClientServer\0clientDisconnected\0\0"
    "sockDesc\0clientTcpError\0QTcpSocket::SocketError\0"
    "socketError\0readClient\0discardClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       7,    0,   40,    2, 0x0a /* Public */,
       8,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClientServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clientDisconnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->clientTcpError((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 2: _t->readClient(); break;
        case 3: _t->discardClient(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientServer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientServer::clientDisconnected)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClientServer::staticMetaObject = { {
    &QTcpServer::staticMetaObject,
    qt_meta_stringdata_ClientServer.data,
    qt_meta_data_ClientServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClientServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientServer.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int ClientServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ClientServer::clientDisconnected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
