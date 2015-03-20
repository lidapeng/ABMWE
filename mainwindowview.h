#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include <QGraphicsView>
#include "ui_mainwindowview.h"

class MainWindowView : public QGraphicsView
{
	Q_OBJECT

public:
	MainWindowView(QWidget *parent = 0);
	~MainWindowView();

	void setFire(int ** f);
private:
	Ui::MainWindowView ui;

	int ** pFire;
protected:
	// Paint Event Function
	//void paintEvent(QPaintEvent* event);
	void drawBackground(QPainter *painter, const QRectF &rect);
};

#endif // MAINWINDOWVIEW_H
