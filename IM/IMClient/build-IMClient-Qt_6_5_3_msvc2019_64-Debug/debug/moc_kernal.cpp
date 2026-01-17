/****************************************************************************
** Meta object code from reading C++ file 'kernal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kernal.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kernal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSKernalENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSKernalENDCLASS = QtMocHelpers::stringData(
    "Kernal",
    "signals_responce_ClientData",
    "",
    "char*",
    "slots_sendRegisterToServe",
    "slots_sendLoginToServe",
    "slots_recvServerData",
    "slots_updateFriInfo",
    "slots_sendMsgtoServe",
    "slots_addFriend",
    "slots_addFriendTimer",
    "slots_FriofflineTimer",
    "slots_sendMyoffline",
    "slots_quitLogin"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSKernalENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[7];
    char stringdata1[28];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[26];
    char stringdata5[23];
    char stringdata6[21];
    char stringdata7[20];
    char stringdata8[21];
    char stringdata9[16];
    char stringdata10[21];
    char stringdata11[22];
    char stringdata12[20];
    char stringdata13[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSKernalENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSKernalENDCLASS_t qt_meta_stringdata_CLASSKernalENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Kernal"
        QT_MOC_LITERAL(7, 27),  // "signals_responce_ClientData"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 5),  // "char*"
        QT_MOC_LITERAL(42, 25),  // "slots_sendRegisterToServe"
        QT_MOC_LITERAL(68, 22),  // "slots_sendLoginToServe"
        QT_MOC_LITERAL(91, 20),  // "slots_recvServerData"
        QT_MOC_LITERAL(112, 19),  // "slots_updateFriInfo"
        QT_MOC_LITERAL(132, 20),  // "slots_sendMsgtoServe"
        QT_MOC_LITERAL(153, 15),  // "slots_addFriend"
        QT_MOC_LITERAL(169, 20),  // "slots_addFriendTimer"
        QT_MOC_LITERAL(190, 21),  // "slots_FriofflineTimer"
        QT_MOC_LITERAL(212, 19),  // "slots_sendMyoffline"
        QT_MOC_LITERAL(232, 15)   // "slots_quitLogin"
    },
    "Kernal",
    "signals_responce_ClientData",
    "",
    "char*",
    "slots_sendRegisterToServe",
    "slots_sendLoginToServe",
    "slots_recvServerData",
    "slots_updateFriInfo",
    "slots_sendMsgtoServe",
    "slots_addFriend",
    "slots_addFriendTimer",
    "slots_FriofflineTimer",
    "slots_sendMyoffline",
    "slots_quitLogin"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSKernalENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   80,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    3,   87,    2, 0x0a,    5 /* Public */,
       5,    2,   94,    2, 0x0a,    9 /* Public */,
       6,    3,   99,    2, 0x0a,   12 /* Public */,
       7,    0,  106,    2, 0x0a,   16 /* Public */,
       8,    2,  107,    2, 0x0a,   17 /* Public */,
       9,    1,  112,    2, 0x0a,   20 /* Public */,
      10,    0,  115,    2, 0x0a,   22 /* Public */,
      11,    0,  116,    2, 0x0a,   23 /* Public */,
      12,    0,  117,    2, 0x0a,   24 /* Public */,
      13,    0,  118,    2, 0x0a,   25 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::ULong,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::ULong,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Kernal::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSKernalENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSKernalENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSKernalENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Kernal, std::true_type>,
        // method 'signals_responce_ClientData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned long, std::false_type>,
        // method 'slots_sendRegisterToServe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slots_sendLoginToServe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slots_recvServerData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned long, std::false_type>,
        // method 'slots_updateFriInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slots_sendMsgtoServe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slots_addFriend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slots_addFriendTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slots_FriofflineTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slots_sendMyoffline'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slots_quitLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Kernal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Kernal *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signals_responce_ClientData((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ulong>>(_a[3]))); break;
        case 1: _t->slots_sendRegisterToServe((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->slots_sendLoginToServe((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->slots_recvServerData((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ulong>>(_a[3]))); break;
        case 4: _t->slots_updateFriInfo(); break;
        case 5: _t->slots_sendMsgtoServe((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->slots_addFriend((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->slots_addFriendTimer(); break;
        case 8: _t->slots_FriofflineTimer(); break;
        case 9: _t->slots_sendMyoffline(); break;
        case 10: _t->slots_quitLogin(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Kernal::*)(char * , int , unsigned long );
            if (_t _q_method = &Kernal::signals_responce_ClientData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Kernal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Kernal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSKernalENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Kernal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Kernal::signals_responce_ClientData(char * _t1, int _t2, unsigned long _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
