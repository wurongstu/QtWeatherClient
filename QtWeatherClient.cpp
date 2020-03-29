#include "QtWeatherClient.h"
#include <QMessageBox>
#include <vector>
#include <QString>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QPainter>
#include <QTextCodec>
using namespace std;
QtWeatherClient::QtWeatherClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_weatherClient = new weatherClient();
	if(m_weatherClient->initClient())
	{ 

	}
	
	
	QObject::connect(ui.pushButtonQuerySupport, SIGNAL(clicked()),this,SLOT(slot_showSupportAllCities()));

}

void QtWeatherClient::slot_showWeaterByCityname()
{
	QTextCodec* pCode = QTextCodec::codecForName("gb18030");
	QModelIndex inmdex = ui.listViewAllCity->currentIndex();
	QString qcityName = ui.listViewAllCity->model()->data(inmdex).toString();
	if (qcityName.isEmpty())
	{
		return;
	}
	string cityName = pCode->fromUnicode(qcityName).data();
	vector<string> cityWeatherInfo;
	QStringList strList;
	QStandardItemModel* ItemModel = new QStandardItemModel(ui.listViewCityInfo);
	if (m_weatherClient->getcityWeatherInfoByName(cityName, cityWeatherInfo))
	{
		for (auto it = cityWeatherInfo.begin(); it != cityWeatherInfo.end(); it++)
		{
			strList.append(QString::fromStdString(*it));
			QStandardItem* item = new QStandardItem(QString::fromStdString(*it));
			ItemModel->appendRow(item);
		}
		ui.listViewCityInfo->setModel(ItemModel);
		ui.listViewCityInfo->setContextMenuPolicy(Qt::CustomContextMenu);
		ui.listViewCityInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);     //
	}
	return;
}


void QtWeatherClient::slot_showSupportAllCities()
{
	vector<QString> vec;
	QStringListModel* Model;
	QStringList strList;
	QStandardItemModel* ItemModel = new QStandardItemModel(ui.listViewAllCity);
	if (m_weatherClient->getAllSupportCities(vec))
	{
		
		for (auto it = vec.begin(); it != vec.end(); it++)
		{
			strList.append(*it);
		}
		int nCount = strList.size();
		for (int i = 0; i < nCount; i++)
		{
			QString string = static_cast<QString>(strList.at(i));
			QStandardItem* item = new QStandardItem(string);
			item->setEditable(false);
			ItemModel->appendRow(item);
		}
	}
	ui.listViewAllCity->setModel(ItemModel);
	ui.listViewAllCity->setContextMenuPolicy(Qt::CustomContextMenu);

	ui.listViewAllCity->setEditTriggers(QAbstractItemView::NoEditTriggers);     //���� listView���ɱ༭
	QObject::connect(ui.listViewAllCity, SIGNAL(customContextMenuRequested(const QPoint&)),\
		this, SLOT(inneraddClickEvent(const QPoint&)));

}



void QtWeatherClient::inneraddClickEvent(const QPoint& pos)
{
	if (!((ui.listViewAllCity->selectionModel()->selectedIndexes()).empty()))
	{
		QMenu* cmenu = new QMenu(ui.listViewAllCity);
		cmenu->setTitle("1223");
		QAction* ascendSortAction = cmenu->addAction("11");
		QAction* descendSortAction = cmenu->addAction(QString::fromStdString("����"));
		QAction* filterAction = cmenu->addAction(QString::fromStdString("����"));
		QAction* reshowAction = cmenu->addAction(QString::fromStdString("����"));
		connect(ascendSortAction, SIGNAL(triggered(bool)), this, SLOT(slot_showWeaterByCityname()));
		connect(descendSortAction, SIGNAL(triggered(bool)), this, SLOT(edit_menu2()));
		connect(filterAction, SIGNAL(triggered(bool)), this, SLOT(edit_menu3()));
		connect(reshowAction, SIGNAL(triggered(bool)), this, SLOT(edit_menu4()));
		cmenu->exec(QCursor::pos());//�ڵ�ǰ���λ����ʾ
	}
}





