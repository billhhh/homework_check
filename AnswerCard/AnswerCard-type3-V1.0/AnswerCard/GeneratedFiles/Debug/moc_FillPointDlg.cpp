/****************************************************************************
** Meta object code from reading C++ file 'FillPointDlg.h'
**
** Created: Sun Mar 30 10:01:48 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FillPointDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FillPointDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FillPointDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      31,   13,   13,   13, 0x05,
      47,   13,   13,   13, 0x05,
      65,   13,   13,   13, 0x05,
      84,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      99,   13,   13,   13, 0x09,
     119,   13,   13,   13, 0x09,
     143,   13,   13,   13, 0x09,
     166,   13,   13,   13, 0x09,
     191,   13,   13,   13, 0x09,
     216,   13,   13,   13, 0x09,
     244,   13,   13,   13, 0x09,
     271,   13,   13,   13, 0x09,
     307,   13,   13,   13, 0x09,
     337,   13,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_FillPointDlg[] = {
    "FillPointDlg\0\0fillPointBegin()\0"
    "fillPointDone()\0fillPointDelete()\0"
    "fillPointClicked()\0imageRefresh()\0"
    "on_addBtn_clicked()\0on_confirmBtn_clicked()\0"
    "on_deleteBtn_clicked()\0on_horRadioBtn_clicked()\0"
    "on_verRadioBtn_clicked()\0"
    "on_singleRadioBtn_clicked()\0"
    "on_multiRadioBtn_clicked()\0"
    "on_typeCmb_currentIndexChanged(int)\0"
    "showClicked(QListWidgetItem*)\0"
    "on_groupCmb_activated(int)\0"
};

void FillPointDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FillPointDlg *_t = static_cast<FillPointDlg *>(_o);
        switch (_id) {
        case 0: _t->fillPointBegin(); break;
        case 1: _t->fillPointDone(); break;
        case 2: _t->fillPointDelete(); break;
        case 3: _t->fillPointClicked(); break;
        case 4: _t->imageRefresh(); break;
        case 5: _t->on_addBtn_clicked(); break;
        case 6: _t->on_confirmBtn_clicked(); break;
        case 7: _t->on_deleteBtn_clicked(); break;
        case 8: _t->on_horRadioBtn_clicked(); break;
        case 9: _t->on_verRadioBtn_clicked(); break;
        case 10: _t->on_singleRadioBtn_clicked(); break;
        case 11: _t->on_multiRadioBtn_clicked(); break;
        case 12: _t->on_typeCmb_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->showClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->on_groupCmb_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FillPointDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FillPointDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FillPointDlg,
      qt_meta_data_FillPointDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FillPointDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FillPointDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FillPointDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FillPointDlg))
        return static_cast<void*>(const_cast< FillPointDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int FillPointDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void FillPointDlg::fillPointBegin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FillPointDlg::fillPointDone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FillPointDlg::fillPointDelete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void FillPointDlg::fillPointClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void FillPointDlg::imageRefresh()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE