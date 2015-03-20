#pragma once
#include <QThread>
#include "MainWindowScene.h"
#include "mainwindowview.h"

//the location in a raster dataset [row,column] zero-based
//struct RasterLocation
//{
//	int row;
//	int column;
//}RasterLoc;

class FireSimulator:
	public QThread
{
	Q_OBJECT
private:
	//raster data
	int **pArray;
	int **pFireData;
	MainWindowScene *pScene;
	MainWindowView* pView;
	bool bStop;
protected:
	void run();
signals:
	void valueChanged(int**);

public:

	FireSimulator(void);
	~FireSimulator(void);
	void stop();

	void loadIgnitionData(QString& fileName);
	void setScence(MainWindowScene * s);
	void setView(MainWindowView * v);
	int** getFireData();
};

