/****************************************************************************
** Meta object code from reading C++ file 'adminstrator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../adminstrator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminstrator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Adminstrator_t {
    const uint offsetsAndSize[24];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Adminstrator_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Adminstrator_t qt_meta_stringdata_Adminstrator = {
    {
QT_MOC_LITERAL(0, 12), // "Adminstrator"
QT_MOC_LITERAL(13, 11), // "backToLogIn"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 13), // "searchAccount"
QT_MOC_LITERAL(40, 10), // "searchBook"
QT_MOC_LITERAL(51, 25), // "on_backToLoginBtn_clicked"
QT_MOC_LITERAL(77, 31), // "on_accountManagementBtn_clicked"
QT_MOC_LITERAL(109, 28), // "on_bookManagementBtn_clicked"
QT_MOC_LITERAL(138, 21), // "on_addBookBtn_clicked"
QT_MOC_LITERAL(160, 24), // "on_deleteBookBtn_clicked"
QT_MOC_LITERAL(185, 24), // "handleAddBookButtonPress"
QT_MOC_LITERAL(210, 6) // "button"

    },
    "Adminstrator\0backToLogIn\0\0searchAccount\0"
    "searchBook\0on_backToLoginBtn_clicked\0"
    "on_accountManagementBtn_clicked\0"
    "on_bookManagementBtn_clicked\0"
    "on_addBookBtn_clicked\0on_deleteBookBtn_clicked\0"
    "handleAddBookButtonPress\0button"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Adminstrator[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    0,   74,    2, 0x08,    7 /* Private */,
       9,    0,   75,    2, 0x08,    8 /* Private */,
      10,    1,   76,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void Adminstrator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Adminstrator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->backToLogIn(); break;
        case 1: _t->searchAccount(); break;
        case 2: _t->searchBook(); break;
        case 3: _t->on_backToLoginBtn_clicked(); break;
        case 4: _t->on_accountManagementBtn_clicked(); break;
        case 5: _t->on_bookManagementBtn_clicked(); break;
        case 6: _t->on_addBookBtn_clicked(); break;
        case 7: _t->on_deleteBookBtn_clicked(); break;
        case 8: _t->handleAddBookButtonPress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Adminstrator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Adminstrator::backToLogIn)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Adminstrator::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Adminstrator.offsetsAndSize,
    qt_meta_data_Adminstrator,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Adminstrator_t
, QtPrivate::TypeAndForceComplete<Adminstrator, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *Adminstrator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Adminstrator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Adminstrator.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Adminstrator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Adminstrator::backToLogIn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
