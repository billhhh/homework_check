/****************************************************************************
** Meta object code from reading C++ file 'ClipDlg.h'
**
** Created: Fri Jun 27 16:11:22 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AnswerCard/ClipDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClipDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClipDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      21,    8,    8,    8, 0x05,
      32,    8,    8,    8, 0x05,
      45,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,    8,    8,    8, 0x09,
      82,    8,    8,    8, 0x09,
     106,    8,    8,    8, 0x09,
     129,    8,    8,    8, 0x09,
     162,  157,    8,    8, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ClipDlg[] = {
    "ClipDlg\0\0clipBegin()\0clipDone()\0"
    "clipDelete()\0clipClicked(int)\0"
    "on_addBtn_clicked()\0on_confirmBtn_clicked()\0"
    "on_deleteBtn_clicked()\0"
    "on_secretCheckBox_toggled()\0item\0"
    "showClicked(QListWidgetItem*)\0"
};

void ClipDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClipDlg *_t = static_cast<ClipDlg *>(_o);
        switch (_id) {
        case 0: _t->clipBegin(); break;
        case 1: _t->clipDone(); break;
        case 2: _t->clipDelete(); break;
        case 3: _t->clipClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_addBtn_clicked(); break;
        case 5: _t->on_confirmBtn_clicked(); break;
        case 6: _t->on_deleteBtn_clicked(); break;
        case 7: _t->on_secretCheckBox_toggled(); break;
        case 8: _t->showClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ClipDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ClipDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ClipDlg,
      qt_meta_data_ClipDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClipDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClipDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClipDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClipDlg))
        return static_cast<void*>(const_cast< ClipDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int ClipDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ClipDlg::clipBegin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ClipDlg::clipDone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ClipDlg::clipDelete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ClipDlg::clipClicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
