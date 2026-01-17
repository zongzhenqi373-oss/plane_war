/****************************************************************************
** Meta object code from reading C++ file 'kernal.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../kernal.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kernal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
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
struct qt_meta_tag_ZN6KernalE_t {};
} // unnamed namespace

template <> constexpr inline auto Kernal::qt_create_metaobjectdata<qt_meta_tag_ZN6KernalE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
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

    QtMocHelpers::UintData qt_methods {
        // Signal 'signals_responce_ClientData'
        QtMocHelpers::SignalData<void(char *, int, unsigned long)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 }, { QMetaType::Int, 2 }, { QMetaType::ULong, 2 },
        }}),
        // Slot 'slots_sendRegisterToServe'
        QtMocHelpers::SlotData<void(QString, QString, QString)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::QString, 2 }, { QMetaType::QString, 2 },
        }}),
        // Slot 'slots_sendLoginToServe'
        QtMocHelpers::SlotData<void(QString, QString)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::QString, 2 },
        }}),
        // Slot 'slots_recvServerData'
        QtMocHelpers::SlotData<void(char *, int, unsigned long)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 }, { QMetaType::Int, 2 }, { QMetaType::ULong, 2 },
        }}),
        // Slot 'slots_updateFriInfo'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slots_sendMsgtoServe'
        QtMocHelpers::SlotData<void(QString, int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::Int, 2 },
        }}),
        // Slot 'slots_addFriend'
        QtMocHelpers::SlotData<void(QString)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'slots_addFriendTimer'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slots_FriofflineTimer'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slots_sendMyoffline'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slots_quitLogin'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Kernal, qt_meta_tag_ZN6KernalE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Kernal::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6KernalE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6KernalE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6KernalE_t>.metaTypes,
    nullptr
} };

void Kernal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Kernal *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
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
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Kernal::*)(char * , int , unsigned long )>(_a, &Kernal::signals_responce_ClientData, 0))
            return;
    }
}

const QMetaObject *Kernal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Kernal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6KernalE_t>.strings))
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Kernal::signals_responce_ClientData(char * _t1, int _t2, unsigned long _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3);
}
QT_WARNING_POP
