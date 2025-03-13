/****************************************************************************
** Meta object code from reading C++ file 'EditItem.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/View/EditMedia/EditItem.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
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
struct qt_meta_tag_ZN4view4edit8EditItemE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN4view4edit8EditItemE = QtMocHelpers::stringData(
    "view::edit::EditItem",
    "modifiedMedia",
    "",
    "pickImage",
    "updateMedia",
    "const media::AbstractMedia*",
    "media",
    "deleteItem",
    "id",
    "addSongToAlbum",
    "const media::Album*",
    "a",
    "removeSongFromAlbum",
    "add",
    "media::Album*",
    "const media::Song*",
    "s",
    "remove"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN4view4edit8EditItemE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   63,    2, 0x0a,    2 /* Public */,
       4,    1,   64,    2, 0x0a,    3 /* Public */,
       7,    1,   67,    2, 0x0a,    5 /* Public */,
       9,    1,   70,    2, 0x0a,    7 /* Public */,
      12,    1,   73,    2, 0x0a,    9 /* Public */,
      13,    2,   76,    2, 0x0a,   11 /* Public */,
      17,    2,   81,    2, 0x0a,   14 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::UInt,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 15,   11,   16,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 15,   11,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject view::edit::EditItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN4view4edit8EditItemE.offsetsAndSizes,
    qt_meta_data_ZN4view4edit8EditItemE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN4view4edit8EditItemE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EditItem, std::true_type>,
        // method 'modifiedMedia'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pickImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateMedia'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const media::AbstractMedia *, std::false_type>,
        // method 'deleteItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned int, std::false_type>,
        // method 'addSongToAlbum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const media::Album *, std::false_type>,
        // method 'removeSongFromAlbum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const media::Album *, std::false_type>,
        // method 'add'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<media::Album *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const media::Song *, std::false_type>,
        // method 'remove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<media::Album *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const media::Song *, std::false_type>
    >,
    nullptr
} };

void view::edit::EditItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<EditItem *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->modifiedMedia(); break;
        case 1: _t->pickImage(); break;
        case 2: _t->updateMedia((*reinterpret_cast< std::add_pointer_t<const media::AbstractMedia*>>(_a[1]))); break;
        case 3: _t->deleteItem((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 4: _t->addSongToAlbum((*reinterpret_cast< std::add_pointer_t<const media::Album*>>(_a[1]))); break;
        case 5: _t->removeSongFromAlbum((*reinterpret_cast< std::add_pointer_t<const media::Album*>>(_a[1]))); break;
        case 6: _t->add((*reinterpret_cast< std::add_pointer_t<media::Album*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<const media::Song*>>(_a[2]))); break;
        case 7: _t->remove((*reinterpret_cast< std::add_pointer_t<media::Album*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<const media::Song*>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (EditItem::*)();
            if (_q_method_type _q_method = &EditItem::modifiedMedia; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *view::edit::EditItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view::edit::EditItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN4view4edit8EditItemE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int view::edit::EditItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void view::edit::EditItem::modifiedMedia()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
