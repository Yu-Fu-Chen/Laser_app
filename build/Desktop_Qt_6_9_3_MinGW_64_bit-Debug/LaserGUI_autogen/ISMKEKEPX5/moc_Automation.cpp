/****************************************************************************
** Meta object code from reading C++ file 'Automation.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/app/Automation.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Automation.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12LoggerObjectE_t {};
} // unnamed namespace

template <> constexpr inline auto LoggerObject::qt_create_metaobjectdata<qt_meta_tag_ZN12LoggerObjectE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "LoggerObject"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<LoggerObject, qt_meta_tag_ZN12LoggerObjectE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject LoggerObject::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12LoggerObjectE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12LoggerObjectE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12LoggerObjectE_t>.metaTypes,
    nullptr
} };

void LoggerObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LoggerObject *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *LoggerObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoggerObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12LoggerObjectE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LoggerObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN5AutoPE_t {};
} // unnamed namespace

template <> constexpr inline auto AutoP::qt_create_metaobjectdata<qt_meta_tag_ZN5AutoPE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AutoP",
        "statusText",
        "",
        "msg",
        "errorSignal",
        "info",
        "addCommandtoLog",
        "command",
        "powerDoub",
        "power",
        "processFinished",
        "PDerror",
        "AutoPinit",
        "playmusicWithWarning",
        "initialization",
        "takeMeterPower",
        "startProcess1",
        "startProcess2",
        "startProcess3",
        "pauseProcess",
        "resumeProcess",
        "stopProcess",
        "sendcommand",
        "powerOff",
        "vecToQString",
        "vector<double>",
        "x",
        "y",
        "PDvecToQString",
        "vector<int>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'statusText'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'errorSignal'
        QtMocHelpers::SignalData<void(const QString &, const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::QString, 3 },
        }}),
        // Signal 'addCommandtoLog'
        QtMocHelpers::SignalData<void(const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Signal 'powerDoub'
        QtMocHelpers::SignalData<void(const QString &, const QString &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::QString, 9 },
        }}),
        // Signal 'processFinished'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'PDerror'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'AutoPinit'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'playmusicWithWarning'
        QtMocHelpers::SlotData<void(const QString &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'initialization'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'takeMeterPower'
        QtMocHelpers::SlotData<double()>(15, 2, QMC::AccessPublic, QMetaType::Double),
        // Slot 'startProcess1'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'startProcess2'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'startProcess3'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'pauseProcess'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resumeProcess'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stopProcess'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'sendcommand'
        QtMocHelpers::SlotData<void(const QString &)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'powerOff'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'vecToQString'
        QtMocHelpers::SlotData<QString(const vector<double> &, const vector<double> &) const>(24, 2, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 25, 26 }, { 0x80000000 | 25, 27 },
        }}),
        // Slot 'PDvecToQString'
        QtMocHelpers::SlotData<QString(const vector<int> &) const>(28, 2, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 29, 26 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AutoP, qt_meta_tag_ZN5AutoPE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AutoP::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5AutoPE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5AutoPE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN5AutoPE_t>.metaTypes,
    nullptr
} };

void AutoP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AutoP *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->statusText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->errorSignal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->addCommandtoLog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->powerDoub((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->processFinished(); break;
        case 5: _t->PDerror(); break;
        case 6: _t->AutoPinit(); break;
        case 7: _t->playmusicWithWarning((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->initialization(); break;
        case 9: { double _r = _t->takeMeterPower();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->startProcess1(); break;
        case 11: _t->startProcess2(); break;
        case 12: _t->startProcess3(); break;
        case 13: _t->pauseProcess(); break;
        case 14: _t->resumeProcess(); break;
        case 15: _t->stopProcess(); break;
        case 16: _t->sendcommand((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->powerOff(); break;
        case 18: { QString _r = _t->vecToQString((*reinterpret_cast< std::add_pointer_t<vector<double>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<vector<double>>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { QString _r = _t->PDvecToQString((*reinterpret_cast< std::add_pointer_t<vector<int>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (AutoP::*)(const QString & )>(_a, &AutoP::statusText, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (AutoP::*)(const QString & , const QString & )>(_a, &AutoP::errorSignal, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (AutoP::*)(const QString & )>(_a, &AutoP::addCommandtoLog, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (AutoP::*)(const QString & , const QString & )>(_a, &AutoP::powerDoub, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (AutoP::*)()>(_a, &AutoP::processFinished, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (AutoP::*)()>(_a, &AutoP::PDerror, 5))
            return;
    }
}

const QMetaObject *AutoP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AutoP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5AutoPE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AutoP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void AutoP::statusText(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void AutoP::errorSignal(const QString & _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void AutoP::addCommandtoLog(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void AutoP::powerDoub(const QString & _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void AutoP::processFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void AutoP::PDerror()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
