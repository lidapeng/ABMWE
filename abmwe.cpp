#include "abmwe.h"
#include <QFileDialog>
#include "configdialog.h"
#include <QDebug>

#include "../gdal/include/gdal_priv.h"
#include "../gdal/include/ogrsf_frmts.h"

#include <QGraphicsScene>

#include "qt_windows.h"
#include <QThread>
#include <fstream>
#include <sstream>
#include "AgentHousehold.h"

using namespace std;
#pragma comment(lib, "gdal_i.lib")


//constructor
ABMWE::ABMWE(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	//connect signals with relevant slots
	connect(ui.actionImport_Data,SIGNAL(triggered()),this,SLOT(slotImportData()));
	connect(ui.actionZoom_In, SIGNAL(triggered()),this,SLOT(slotZoomIn()));
	connect(ui.actionPan,SIGNAL(triggered()),this,SLOT(slotPan()));
	connect(ui.actionZoom_Out,SIGNAL(triggered()),this,SLOT(slotZoomOut()));
	connect(ui.actionRun_Model,SIGNAL(triggered()),this, SLOT(slotRunSimulation()));
	connect(ui.actionPause,SIGNAL(triggered()),this,SLOT(slotPauseSimulation()));


	scene = new MainWindowScene();
	scene->setSceneRect(ui.graphicsView->rect());
	//scene->setSceneRect(-116.50,33.00,1.0,1.0);

	fireSimulator = new FireSimulator();
	fireSimulator->loadIgnitionData(QString("test"));
	connect(fireSimulator, SIGNAL(valueChanged(int**)),this,SLOT(slotValueChanged(int**)));
	
	pView = ui.graphicsView;

	QRectF rect = scene->sceneRect();
	qDebug()<<rect.x()<<", "<<rect.y()<<"  "<<rect.width()<<", "<<rect.height();
	ui.graphicsView->setScene(scene);
	ui.graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	ui.graphicsView->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
	QPen pen(Qt::red,5);

	QBrush brush(Qt::red);
	//QGraphicsEllipseItem* ellipse = scene->addEllipse(0,0,100,100,pen);
	//QGraphicsRectItem * rectangle =	scene->addRect(10,10,40,40);
	//QGraphicsLineItem * line = scene->addLine(100,100,300,300);
	//rectangle->setFlag(QGraphicsItem::ItemIsMovable);

	//ui.graphicsView->fitInView(QRectF(-116.50,33.0,1.0,1.0));

	standardModel = new QStandardItemModel();
	
	for(int i = 0;i<rowItems.size();i++)
	{
		rowItems[i]->setCheckable(true);
	}

	qDebug()<< "This is being printed on the Master thread \n" ;
	omp_set_num_threads(2);

	#pragma omp parallel
	{
		qDebug() << "In parallel region. This statement is being printed by each worker thread \n" ;
	}

	qDebug()<< "Out of parallel region. This is being printed on the Master thread";


	
}

ABMWE::~ABMWE()
{
	//if (fireSimulator!=NULL)
	//{
	//	delete fireSimulator;
	//}

}


// create menus
void ABMWE::createMenus(void)
{
	//editMenu = menuBar()->addMenu(tr("&Edit"));

}
//import data into the system
void ABMWE::slotImportData()
{

	QFileDialog *dlg = new QFileDialog();
	dlg->setAcceptMode(QFileDialog::AcceptOpen);

	QString strFileName = dlg->getOpenFileName(this,tr("Open File"),QDir::currentPath(),tr("shape files(*.shp)"));
	qDebug()<<strFileName;
	OGRRegisterAll();
	GDALDataset *poDataset;
	GDALAllRegister();

	//poDataset = (GDALDataset *) GDALOpen( argv[1], GA_ReadOnly );
	OGRDataSource *poDS = NULL;
	qDebug()<<strFileName.toLocal8Bit().constData();
	poDS = OGRSFDriverRegistrar::Open(strFileName.toLocal8Bit().constData(), FALSE );
	//poDS = OGRSFDriverRegistrar::Open("D:/Project/Triggers/ABMWE/Data/julian_household.shp", FALSE );

	if( poDS == NULL )
	{
		qDebug()<<"failure";
		return;
	}
	OGRLayer  *poLayer;
	qDebug()<<"GetName(): "<<poDS->GetName();
	QFileInfo fileInfo(strFileName);
	qDebug()<<fileInfo.baseName();

	poLayer = poDS->GetLayerByName(fileInfo.baseName().toLocal8Bit().constData());
	//poLayer = poDS->GetLayerByName("roads");
	OGRFeature *poFeature;
	addLayer(fileInfo.baseName());
	poLayer->ResetReading();
	while( (poFeature = poLayer->GetNextFeature()) != NULL )
	{
		OGRFeatureDefn *poFDefn = poLayer->GetLayerDefn();
		int iField;
		qDebug()<<poFDefn->GetFieldCount()<<endl;
		for( iField = 0; iField < poFDefn->GetFieldCount(); iField++ )
		{
			OGRFieldDefn *poFieldDefn = poFDefn->GetFieldDefn( iField );
			//cout<< poFeature->GetFieldAsInteger( iField )<<endl;
			//cout<<poFieldDefn->GetNameRef()<<endl;
			//if( poFieldDefn->GetType() == OFTInteger )
			//	printf( "%d,", poFeature->GetFieldAsInteger( iField ) );
			//else if( poFieldDefn->GetType() == OFTReal )
			//	printf( "%.3f,", poFeature->GetFieldAsDouble(iField) );
			//else if( poFieldDefn->GetType() == OFTString )
			//	printf( "%s,", poFeature->GetFieldAsString(iField) );
			//else
			//	printf( "%s,", poFeature->GetFieldAsString(iField) );
		}

		OGRGeometry *poGeometry;

		poGeometry = poFeature->GetGeometryRef();

		if( poGeometry != NULL && wkbFlatten(poGeometry->getGeometryType()) == wkbPoint )
		{
			OGRPoint *poPoint = (OGRPoint *) poGeometry;
			qDebug()<<poPoint->getX()<<", "<<poPoint->getY();
			OGREnvelope envelope;
			poPoint->getEnvelope(&envelope);
			//cout<<envelope.MaxX<<endl;
			OGRPolygon * poPolygon = (OGRPolygon*)poGeometry;
			poPolygon->getEnvelope(&envelope);
			//qDebug()<<envelope.MaxX;
			if (scene!=NULL)
			{
				QGraphicsEllipseItem* item = scene->addEllipse(poPoint->getX(),poPoint->getY(),0.0005,0.0005,QPen(Qt::black),QBrush(Qt::SolidPattern));
				rect = item->boundingRect();
				qDebug()<<"rect: "<<rect.x()<<", "<<rect.y()<<" "<<rect.width()<<", "<<rect.height();
			}

		}
		else if( poGeometry != NULL && wkbFlatten(poGeometry->getGeometryType()) == wkbPolygon)
		{
			OGREnvelope envelope;
			OGRPolygon * poPolygon = (OGRPolygon*)poGeometry;
			poPolygon->getEnvelope(&envelope);
			//qDebug()<<envelope.MaxX<<endl;
		}
		else if (poGeometry != NULL && wkbFlatten(poGeometry->getGeometryType()) == wkbLineString)
		{
			OGRLineString* poLine = (OGRLineString*)poGeometry;
			int nPtCount = poLine->getNumPoints();
			QPolygonF polyline;

			for (int i = 0;i<nPtCount;i++)
			{
				OGRPoint pt;
				poLine->getPoint(i,&pt);
				polyline.append(QPointF(pt.getX(),pt.getY()));
			}
			QPainterPath* painterPath = new QPainterPath();
			painterPath->addPolygon(polyline);
			QGraphicsPathItem* lineItem = scene->addPath(*painterPath);
			rect = lineItem->boundingRect();
			qDebug()<<"Num of Pts: "<<nPtCount;
		}
		else
		{
			//printf( "no point geometry\n" );
			qDebug()<<"no point geometry";
		}       
		OGRFeature::DestroyFeature(poFeature);
	}
	//ConfigDialog * configDlg = new ConfigDialog();
	//configDlg->setWindowTitle("Configure the model");
	//configDlg->show();
	

	//QRect itemSize = ui.graphicsView->mapFromScene(scene->sceneRect()).boundingRect().size();
	////QRect scaledSize =s.scale(ui.graphicsView->viewport().size(), Qt::KeepAspectRatio);
	//double ratio = qMin((double)scaledSize.width()/itemSize.width(), (double)scaledSize.height()/itemSize.height());
	//scene->setTransform(QTransform::fromScale(ratio,ratio), true);
	//ui.graphicsView->scale(ratio,ratio);
	//ui.graphicsView->setSceneRect(-116.50,33.0,1.0,1.0);
	//ui.graphicsView->fitInView(-116.50,33.0,1.0,1.0);
	//ui.graphicsView->fitInView(-116.578,33.07, 0.05, 0.05 );
	//scene->update(rect);
	ui.graphicsView->fitInView(rect);
	//ui.graphicsView->invalidateScene(rect);
	ui.graphicsView->update();
	
	//ui.graphicsView->update();
}

void ABMWE::slotZoomIn()
{
	ui.graphicsView->scale(1.5,1.5);
	//QTransform t;
	//t.rotate(45,Qt::ZAxis);
	//ui.graphicsView->setTransform(t);


}
void ABMWE::slotZoomOut()
{
	ui.graphicsView->scale(0.75,0.75);
	//QMessageBox qMB;
	//
	//qMB.setText("Outcome");
	//qMB.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
	//if (QMessageBox::Yes == qMB.exec() )
	//{
	//	qDebug()<<"YES";
	//}
	//else
	//{
	//	qDebug()<<"NO";
	//}
}

void ABMWE::slotPan()
{
	ui.graphicsView->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
	CAgentHousehold agentHH;
	
}

void ABMWE::slotRunSimulation()
{
	qDebug()<<"run simulation";

	
	fireSimulator->loadIgnitionData(QString("test"));
	//ui.graphicsView->setFire(fireSimulator.getFireData());

	fireSimulator->start();
	
}

void ABMWE::slotPauseSimulation()
{
	scene->clear();
	QPen pen;
	pen.setWidth(1);
	QPen pen1;
	pen1.setWidth(2);
	QColor color;
	color.setRgb(0,0,0);
	QBrush brush(color,Qt::SolidPattern);
	QPointF p1(100.0,300.0);
	QPointF p2(500.0,300.0);
	QRect rect1(p1.x()-2.5,p1.y()-2.5,5.0,5.0);
	QRect rect2(p2.x()-2.5,p2.y()-2.5,5.0,5.0);

	QRect rectp3(p1.x()+50.0-2.5,p1.y()-2.5,5.0,5.0);

	QRect rectp4(p1.x()+100.0-2.5,p1.y()-2.5,5.0,5.0);
	QRect rectp5(p1.x()+150.0-2.5,p1.y()-2.5,5.0,5.0);
	QRect rectp6(p1.x()+200.0-2.5,p1.y()-2.5,5.0,5.0);
	QRect rectp7(p1.x()+250.0-2.5,p1.y()-2.5,5.0,5.0);
	QRect rectp8(p1.x()+300.0-2.5,p1.y()-2.5,5.0,5.0);
	QRect rectp9(p1.x()+350.0-2.5,p1.y()-2.5,5.0,5.0);

	scene->addEllipse(rect1,pen,brush);
	scene->addEllipse(rect2,pen,brush);
	scene->addEllipse(rectp3,pen,brush);
	scene->addEllipse(rectp4,pen,brush);
	scene->addEllipse(rectp5,pen,brush);
	scene->addEllipse(rectp6,pen,brush);
	scene->addEllipse(rectp7,pen,brush);
	scene->addEllipse(rectp8,pen,brush);
	scene->addEllipse(rectp9,pen,brush);

	QLineF line1(p1,p2);
	scene->addLine(line1,pen1);

	QLineF line2(QPointF(p1.x(),p1.y()-25.0),QPointF(p2.x(),p2.y()-25.0));
	QLineF line3(QPointF(p1.x(),p1.y()+25.0),QPointF(p2.x(),p2.y()+25.0));
	scene->addLine(line2);
	scene->addLine(line3);
	QBrush brush1(color,Qt::NoBrush);
	QRectF rect3(p1.x()-25.0,p1.y()-25.0,50.0,50.0);
	QRectF rect4(p2.x()-25.0,p2.y()-25.0,50.0,50.0);
	QRectF rect5(p1.x()+50.0-25.0,p1.y()-25.0,50.0,50.0);
	QRectF rect6(p1.x()+100.0-25.0,p1.y()-25.0,50.0,50.0);

	QRectF rect7(p1.x()+150.0-25.0,p1.y()-25.0,50.0,50.0);
	QRectF rect8(p1.x()+200.0-25.0,p1.y()-25.0,50.0,50.0);

	QRectF rect9(p1.x()+250.0-25.0,p1.y()-25.0,50.0,50.0);
	QRectF rect10(p1.x()+300.0-25.0,p1.y()-25.0,50.0,50.0);
	QRectF rect11(p1.x()+350.0-25.0,p1.y()-25.0,50.0,50.0);
	scene->addEllipse(rect3,pen,brush1);
	scene->addEllipse(rect4,pen,brush1);
	scene->addEllipse(rect5,pen,brush1);
	scene->addEllipse(rect6,pen,brush1);
	scene->addEllipse(rect7,pen,brush1);
	scene->addEllipse(rect8,pen,brush1);
	scene->addEllipse(rect9,pen,brush1);
	scene->addEllipse(rect10,pen,brush1);
	scene->addEllipse(rect11,pen,brush1);

	scene->update();
	
}

void ABMWE::slotValueChanged(int** n)
{
	//qDebug()<<"valueChanged:" <<n;
	
	ui.graphicsView->setFire(n);
	//ui.graphicsView->update();
	QWidget* viewport = ui.graphicsView->viewport();
	viewport->update();
	//scene->setFire(n);

	//scene->drawFire();
	//scene->update();
	//scene->invalidate(0,0,101,101);
}

const char* ABMWE::QString2char(QString& str)
{

	return (str.toLocal8Bit().constData());
}

void ABMWE::addLayer(QString& strLayerName)
{
	if (standardModel != NULL)
	{
		QStandardItem *item = standardModel->invisibleRootItem();
		
		QStandardItem newItem(strLayerName);
		rowItems<<new QStandardItem(strLayerName);
		QStandardItem * pItem = new QStandardItem(strLayerName);
		pItem->setCheckable(true);
		item->setText("Layers");
		
		item->appendRow(pItem);
		

		for(int i = 0;i<rowItems.size();i++)
		{
			rowItems[i]->setCheckable(true);
		}
		
		
		// adding a row to the invisible root item prod;uces a root element
		
		//item->appendColumn(rowItems);
		QStandardItem * pHeaderTitle = new QStandardItem("Layers");
		//standardModel->setHorizontalHeaderItem(0,pHeaderTitle);
		ui.treeView->setModel(standardModel);
		standardModel->setHeaderData(0,Qt::Horizontal,"Layers");
		//standardModel->setHorizontalHeaderItem(1,pHeaderTitle);
		//QHeaderView headerView(Qt::Horizontal);
		//headerView.setWindowTitle("Layers");
		ui.treeView->expandAll();
		ui.treeView->setWindowTitle("Layers");
		if (pHeaderTitle!=NULL)
		{
			delete pHeaderTitle;
		}
		//if (pItem !=NULL)
		//{
		//	delete pItem;
		//}
	}

}

