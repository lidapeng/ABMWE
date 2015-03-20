/****************************************************************************
** Meta object code from reading C++ file 'abmwe.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../abmwe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abmwe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ABMWE[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      24,    6,    6,    6, 0x08,
      37,    6,    6,    6, 0x08,
      51,    6,    6,    6, 0x08,
      61,    6,    6,    6, 0x08,
      81,    6,    6,    6, 0x08,
     103,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ABMWE[] = {
    "ABMWE\0\0slotImportData()\0slotZoomIn()\0"
    "slotZoomOut()\0slotPan()\0slotRunSimulation()\0"
    "slotPauseSimulation()\0slotValueChanged(int**)\0"
};

void ABMWE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ABMWE *_t = static_cast<ABMWE *>(_o);
        switch (_id) {
        case 0: _t->slotImportData(); break;
        case 1: _t->slotZoomIn(); break;
        case 2: _t->slotZoomOut(); break;
        case 3: _t->slotPan(); break;
        case 4: _t->slotRunSimulation(); break;
        case 5: _t->slotPauseSimulation(); break;
        case 6: _t->slotValueChanged((*reinterpret_cast< int**(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ABMWE::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ABMWE::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ABMWE,
      qt_meta_data_ABMWE, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ABMWE::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ABMWE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ABMWE::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ABMWE))
        return static_cast<void*>(const_cast< ABMWE*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ABMWE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
