#ifndef ABMWE_H
#define ABMWE_H

#include <QMainWindow>
#include "ui_abmwe.h"
#include <QDialog>
#include <QtGui>
#include "MainWindowScene.h"
#include <omp.h>
#include "FireSimulator.h"

class ABMWE : public QMainWindow
{
	Q_OBJECT

public:
	ABMWE(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ABMWE();

private:
	Ui::ABMWEClass ui;
	QMenu * editMenu;
	QDialog * dlg;
	MainWindowScene * scene;
	MainWindowView * pView;
	QRectF rect;
	//layer list
	QStandardItemModel* standardModel;
	QList<QStandardItem *> rowItems;


	FireSimulator* fireSimulator;

private slots:
	void slotImportData();
	void slotZoomIn();
	void slotZoomOut();
	void slotPan();
	void slotRunSimulation();
	void slotPauseSimulation();
	void slotValueChanged(int**);

public:
	// create menus
	void createMenus(void);
	const char* QString2char(QString& str);
	void addLayer(QString& strLayerName);

};

#endif // ABMWE_H
