/****************************************************************************
** Meta object code from reading C++ file 'ConnectDevice.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/app/ConnectDevice.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConnectDevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.3. It"
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
struct qt_meta_tag_ZN11LaserDriverE_t {};
} // unnamed namespace

template <> constexpr inline auto LaserDriver::qt_create_metaobjectdata<qt_meta_tag_ZN11LaserDriverE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "LaserDriver",
        "connectfinish",
        "",
        "serialRead",
        "line",
        "SerialError",
        "msg",
        "onSerialErrorOccurred",
        "QSerialPort::SerialPortError",
        "e",
        "onSerialReadyRead",
        "transmit",
        "bytes",
        "sendAndWait",
        "cmd",
        "sendCommandSlowly",
        "command"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'connectfinish'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'serialRead'
        QtMocHelpers::SignalData<void(QString)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'SerialError'
        QtMocHelpers::SignalData<void(QString)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Slot 'onSerialErrorOccurred'
        QtMocHelpers::SlotData<void(QSerialPort::SerialPortError)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Slot 'onSerialReadyRead'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'transmit'
        QtMocHelpers::SlotData<void(const QByteArray &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 12 },
        }}),
        // Slot 'sendAndWait'
        QtMocHelpers::SlotData<void(const QString &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Slot 'sendCommandSlowly'
        QtMocHelpers::SlotData<void(QByteArray)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QByteArray, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<LaserDriver, qt_meta_tag_ZN11LaserDriverE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject LaserDriver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11LaserDriverE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11LaserDriverE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11LaserDriverE_t>.metaTypes,
    nullptr
} };

void LaserDriver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LaserDriver *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->connectfinish(); break;
        case 1: _t->serialRead((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->SerialError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->onSerialErrorOccurred((*reinterpret_cast< std::add_pointer_t<QSerialPort::SerialPortError>>(_a[1]))); break;
        case 4: _t->onSerialReadyRead(); break;
        case 5: _t->transmit((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 6: _t->sendAndWait((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->sendCommandSlowly((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (LaserDriver::*)()>(_a, &LaserDriver::connectfinish, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (LaserDriver::*)(QString )>(_a, &LaserDriver::serialRead, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (LaserDriver::*)(QString )>(_a, &LaserDriver::SerialError, 2))
            return;
    }
}

const QMetaObject *LaserDriver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LaserDriver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11LaserDriverE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LaserDriver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void LaserDriver::connectfinish()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LaserDriver::serialRead(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void LaserDriver::SerialError(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN11MeterDeviceE_t {};
} // unnamed namespace

template <> constexpr inline auto MeterDevice::qt_create_metaobjectdata<qt_meta_tag_ZN11MeterDeviceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MeterDevice",
        "powerUpdated",
        "",
        "watts",
        "statusText",
        "msg",
        "errorText",
        "stringReceived",
        "text",
        "intReceived",
        "value",
        "floatReceived",
        "startPolling",
        "intervalMs",
        "stopPolling",
        "sendCommand",
        "command"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'powerUpdated'
        QtMocHelpers::SignalData<void(double)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 3 },
        }}),
        // Signal 'statusText'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Signal 'errorText'
        QtMocHelpers::SignalData<void(const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Signal 'stringReceived'
        QtMocHelpers::SignalData<void(QString)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 },
        }}),
        // Signal 'intReceived'
        QtMocHelpers::SignalData<void(int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Signal 'floatReceived'
        QtMocHelpers::SignalData<void(float)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 10 },
        }}),
        // Slot 'startPolling'
        QtMocHelpers::SlotData<void(int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Slot 'startPolling'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'stopPolling'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'sendCommand'
        QtMocHelpers::SlotData<void(QString)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MeterDevice, qt_meta_tag_ZN11MeterDeviceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MeterDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11MeterDeviceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11MeterDeviceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11MeterDeviceE_t>.metaTypes,
    nullptr
} };

void MeterDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MeterDevice *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->powerUpdated((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->statusText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->errorText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->stringReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->intReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->floatReceived((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 6: _t->startPolling((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->startPolling(); break;
        case 8: _t->stopPolling(); break;
        case 9: _t->sendCommand((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MeterDevice::*)(double )>(_a, &MeterDevice::powerUpdated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MeterDevice::*)(const QString & )>(_a, &MeterDevice::statusText, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MeterDevice::*)(const QString & )>(_a, &MeterDevice::errorText, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MeterDevice::*)(QString )>(_a, &MeterDevice::stringReceived, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MeterDevice::*)(int )>(_a, &MeterDevice::intReceived, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (MeterDevice::*)(float )>(_a, &MeterDevice::floatReceived, 5))
            return;
    }
}

const QMetaObject *MeterDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeterDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11MeterDeviceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MeterDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MeterDevice::powerUpdated(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void MeterDevice::statusText(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void MeterDevice::errorText(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void MeterDevice::stringReceived(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void MeterDevice::intReceived(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void MeterDevice::floatReceived(float _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN20ThorLABS_MeterDeviceE_t {};
} // unnamed namespace

template <> constexpr inline auto ThorLABS_MeterDevice::qt_create_metaobjectdata<qt_meta_tag_ZN20ThorLABS_MeterDeviceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ThorLABS_MeterDevice",
        "update_measPower",
        "",
        "pw",
        "errorOccurred",
        "msg"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'update_measPower'
        QtMocHelpers::SignalData<void(double)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 3 },
        }}),
        // Signal 'errorOccurred'
        QtMocHelpers::SignalData<void(QString)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ThorLABS_MeterDevice, qt_meta_tag_ZN20ThorLABS_MeterDeviceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ThorLABS_MeterDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20ThorLABS_MeterDeviceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20ThorLABS_MeterDeviceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20ThorLABS_MeterDeviceE_t>.metaTypes,
    nullptr
} };

void ThorLABS_MeterDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ThorLABS_MeterDevice *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->update_measPower((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ThorLABS_MeterDevice::*)(double )>(_a, &ThorLABS_MeterDevice::update_measPower, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ThorLABS_MeterDevice::*)(QString )>(_a, &ThorLABS_MeterDevice::errorOccurred, 1))
            return;
    }
}

const QMetaObject *ThorLABS_MeterDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThorLABS_MeterDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20ThorLABS_MeterDeviceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThorLABS_MeterDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ThorLABS_MeterDevice::update_measPower(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void ThorLABS_MeterDevice::errorOccurred(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
