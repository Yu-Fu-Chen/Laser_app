/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/Gui/MainWindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "cmdFinished",
        "",
        "openSimulation",
        "openLogin",
        "openStressTest",
        "setEnginerring",
        "ok",
        "onConnectClicked",
        "onSocketConnected",
        "onSocketDisconnected",
        "onSocketReadyRead",
        "onErrorOccurred",
        "QAbstractSocket::SocketError",
        "sendCommand",
        "cmd",
        "sendArbitrary",
        "changSDCorSDAC",
        "index",
        "switchPage",
        "page",
        "refreshSConnect",
        "saveLogToFile",
        "clearLog",
        "loadSettings",
        "model",
        "saveSettings",
        "updateUiScale",
        "applyAdaptiveSpacing",
        "appendLog",
        "line",
        "isTx",
        "setConnected",
        "showMessageBox",
        "QMessageBox::Icon",
        "icon",
        "title",
        "text",
        "infoText",
        "lineValidator",
        "QLineEdit*",
        "ui",
        "min",
        "max",
        "f",
        "currentMode",
        "Mode",
        "onMConnectClicked",
        "setMConnected",
        "onMSWaveSelect",
        "s",
        "setMStarted",
        "onMPowerUpdated",
        "w",
        "onMStatusText",
        "onMErrorText",
        "onbtnMSendClicked",
        "onbtnScanClicked",
        "onbtnThorMConnectCclicked",
        "onScanFinished",
        "onTimerTimeout",
        "onAutoPStatusText",
        "onAutoLogText",
        "info",
        "mag"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'cmdFinished'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'openSimulation'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'openLogin'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'openStressTest'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'setEnginerring'
        QtMocHelpers::SlotData<void(bool)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 7 },
        }}),
        // Slot 'onConnectClicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSocketConnected'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSocketDisconnected'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSocketReadyRead'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onErrorOccurred'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketError)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 13, 2 },
        }}),
        // Slot 'sendCommand'
        QtMocHelpers::SlotData<bool(const QString &)>(14, 2, QMC::AccessPrivate, QMetaType::Bool, {{
            { QMetaType::QString, 15 },
        }}),
        // Slot 'sendArbitrary'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'changSDCorSDAC'
        QtMocHelpers::SlotData<void(int)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 18 },
        }}),
        // Slot 'switchPage'
        QtMocHelpers::SlotData<void(int)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 20 },
        }}),
        // Slot 'refreshSConnect'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'saveLogToFile'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'clearLog'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'loadSettings'
        QtMocHelpers::SlotData<void(QString)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 25 },
        }}),
        // Slot 'loadSettings'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate | QMC::MethodCloned, QMetaType::Void),
        // Slot 'saveSettings'
        QtMocHelpers::SlotData<void(QString)>(26, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 25 },
        }}),
        // Slot 'saveSettings'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate | QMC::MethodCloned, QMetaType::Void),
        // Slot 'updateUiScale'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'applyAdaptiveSpacing'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'appendLog'
        QtMocHelpers::SlotData<void(const QString &, bool)>(29, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::Bool, 31 },
        }}),
        // Slot 'setConnected'
        QtMocHelpers::SlotData<void(bool)>(32, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 7 },
        }}),
        // Slot 'showMessageBox'
        QtMocHelpers::SlotData<void(QMessageBox::Icon, const QString &, const QString &, const QString &)>(33, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 34, 35 }, { QMetaType::QString, 36 }, { QMetaType::QString, 37 }, { QMetaType::QString, 38 },
        }}),
        // Slot 'showMessageBox'
        QtMocHelpers::SlotData<void(QMessageBox::Icon, const QString &, const QString &)>(33, 2, QMC::AccessPrivate | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 34, 35 }, { QMetaType::QString, 36 }, { QMetaType::QString, 37 },
        }}),
        // Slot 'lineValidator'
        QtMocHelpers::SlotData<void(QLineEdit *, double, double, int)>(39, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 40, 41 }, { QMetaType::Double, 42 }, { QMetaType::Double, 43 }, { QMetaType::Int, 44 },
        }}),
        // Slot 'lineValidator'
        QtMocHelpers::SlotData<void(QLineEdit *, int, int)>(39, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 40, 41 }, { QMetaType::Int, 42 }, { QMetaType::Int, 43 },
        }}),
        // Slot 'currentMode'
        QtMocHelpers::SlotData<enum Mode() const>(45, 2, QMC::AccessPrivate, 0x80000000 | 46),
        // Slot 'onMConnectClicked'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'setMConnected'
        QtMocHelpers::SlotData<void(bool)>(48, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 7 },
        }}),
        // Slot 'onMSWaveSelect'
        QtMocHelpers::SlotData<void(const QString)>(49, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 50 },
        }}),
        // Slot 'setMStarted'
        QtMocHelpers::SlotData<void(bool)>(51, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 7 },
        }}),
        // Slot 'onMPowerUpdated'
        QtMocHelpers::SlotData<void(double)>(52, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Double, 53 },
        }}),
        // Slot 'onMStatusText'
        QtMocHelpers::SlotData<void(const QString &)>(54, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 50 },
        }}),
        // Slot 'onMErrorText'
        QtMocHelpers::SlotData<void(const QString &)>(55, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 50 },
        }}),
        // Slot 'onbtnMSendClicked'
        QtMocHelpers::SlotData<void()>(56, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onbtnScanClicked'
        QtMocHelpers::SlotData<void()>(57, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onbtnThorMConnectCclicked'
        QtMocHelpers::SlotData<void()>(58, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onScanFinished'
        QtMocHelpers::SlotData<void()>(59, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onTimerTimeout'
        QtMocHelpers::SlotData<void()>(60, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAutoPStatusText'
        QtMocHelpers::SlotData<void(const QString &)>(61, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 50 },
        }}),
        // Slot 'onAutoLogText'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(62, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 63 }, { QMetaType::QString, 64 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->cmdFinished(); break;
        case 1: _t->openSimulation(); break;
        case 2: _t->openLogin(); break;
        case 3: _t->openStressTest(); break;
        case 4: _t->setEnginerring((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->onConnectClicked(); break;
        case 6: _t->onSocketConnected(); break;
        case 7: _t->onSocketDisconnected(); break;
        case 8: _t->onSocketReadyRead(); break;
        case 9: _t->onErrorOccurred((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 10: { bool _r = _t->sendCommand((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->sendArbitrary(); break;
        case 12: _t->changSDCorSDAC((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->switchPage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->refreshSConnect(); break;
        case 15: _t->saveLogToFile(); break;
        case 16: _t->clearLog(); break;
        case 17: _t->loadSettings((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->loadSettings(); break;
        case 19: _t->saveSettings((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->saveSettings(); break;
        case 21: _t->updateUiScale(); break;
        case 22: _t->applyAdaptiveSpacing(); break;
        case 23: _t->appendLog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 24: _t->setConnected((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 25: _t->showMessageBox((*reinterpret_cast< std::add_pointer_t<QMessageBox::Icon>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 26: _t->showMessageBox((*reinterpret_cast< std::add_pointer_t<QMessageBox::Icon>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 27: _t->lineValidator((*reinterpret_cast< std::add_pointer_t<QLineEdit*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 28: _t->lineValidator((*reinterpret_cast< std::add_pointer_t<QLineEdit*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 29: { enum Mode _r = _t->currentMode();
            if (_a[0]) *reinterpret_cast< enum Mode*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->onMConnectClicked(); break;
        case 31: _t->setMConnected((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 32: _t->onMSWaveSelect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 33: _t->setMStarted((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 34: _t->onMPowerUpdated((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 35: _t->onMStatusText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 36: _t->onMErrorText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 37: _t->onbtnMSendClicked(); break;
        case 38: _t->onbtnScanClicked(); break;
        case 39: _t->onbtnThorMConnectCclicked(); break;
        case 40: _t->onScanFinished(); break;
        case 41: _t->onTimerTimeout(); break;
        case 42: _t->onAutoPStatusText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 43: _t->onAutoLogText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLineEdit* >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLineEdit* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::cmdFinished, 0))
            return;
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::cmdFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
