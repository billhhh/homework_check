/****************************************************************************
** Meta object code from reading C++ file 'AnswerCardDlg3.h'
**
** Created: Mon Apr 14 15:53:49 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AnswerCardDlg3.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnswerCardDlg3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AnswerCardDlg3[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x09,
      40,   15,   15,   15, 0x09,
      66,   15,   15,   15, 0x09,
      91,   15,   15,   15, 0x09,
     116,   15,   15,   15, 0x09,
     129,   15,   15,   15, 0x09,
     142,   15,   15,   15, 0x09,
     154,   15,   15,   15, 0x09,
     169,   15,   15,   15, 0x09,
     186,   15,   15,   15, 0x09,
     198,   15,   15,   15, 0x09,
     216,   15,   15,   15, 0x09,
     234,   15,   15,   15, 0x09,
     251,   15,   15,   15, 0x09,
     268,   15,   15,   15, 0x09,
     291,  287,   15,   15, 0x09,
     308,  287,   15,   15, 0x09,
     328,   15,   15,   15, 0x09,
     347,   15,   15,   15, 0x09,
     367,   15,   15,   15, 0x09,
     385,   15,   15,   15, 0x09,
     405,   15,   15,   15, 0x09,
     427,   15,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_AnswerCardDlg3[] = {
    "AnswerCardDlg3\0\0on_newCardBtn_clicked()\0"
    "on_importXMLBtn_clicked()\0"
    "on_saveFileBtn_clicked()\0"
    "on_openFileBtn_clicked()\0anchorDone()\0"
    "markerDone()\0enableDlg()\0barCodeBegin()\0"
    "fillPointBegin()\0clipBegin()\0"
    "markerMakeBegin()\0lineDetectBegin()\0"
    "lineDetectDone()\0pagePointBegin()\0"
    "markerMakeDelete()\0idx\0clipClicked(int)\0"
    "barCodeClicked(int)\0fillPointClicked()\0"
    "markerMakeClicked()\0editCard(QString)\0"
    "deleteCard(QString)\0on_clearBtn_clicked()\0"
    "on_changePicBtn_clicked()\0"
};

void AnswerCardDlg3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AnswerCardDlg3 *_t = static_cast<AnswerCardDlg3 *>(_o);
        switch (_id) {
        case 0: _t->on_newCardBtn_clicked(); break;
        case 1: _t->on_importXMLBtn_clicked(); break;
        case 2: _t->on_saveFileBtn_clicked(); break;
        case 3: _t->on_openFileBtn_clicked(); break;
        case 4: _t->anchorDone(); break;
        case 5: _t->markerDone(); break;
        case 6: _t->enableDlg(); break;
        case 7: _t->barCodeBegin(); break;
        case 8: _t->fillPointBegin(); break;
        case 9: _t->clipBegin(); break;
        case 10: _t->markerMakeBegin(); break;
        case 11: _t->lineDetectBegin(); break;
        case 12: _t->lineDetectDone(); break;
        case 13: _t->pagePointBegin(); break;
        case 14: _t->markerMakeDelete(); break;
        case 15: _t->clipClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->barCodeClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->fillPointClicked(); break;
        case 18: _t->markerMakeClicked(); break;
        case 19: _t->editCard((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->deleteCard((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->on_clearBtn_clicked(); break;
        case 22: _t->on_changePicBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AnswerCardDlg3::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AnswerCardDlg3::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AnswerCardDlg3,
      qt_meta_data_AnswerCardDlg3, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AnswerCardDlg3::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AnswerCardDlg3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AnswerCardDlg3::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AnswerCardDlg3))
        return static_cast<void*>(const_cast< AnswerCardDlg3*>(this));
    return QDialog::qt_metacast(_clname);
}

int AnswerCardDlg3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE