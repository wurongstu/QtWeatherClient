#include "QtWeatherClient.h"
#include <QMessageBox>
#include <vector>
#include <QString>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QPainter>
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

void slot_showWeaterByCityname(string cityName)
{

}


void QtWeatherClient::slot_showSupportAllCities()
{
	vector<QString> vec;
	QStringListModel* Model;
	QStandardItemModel* ItemModel = new QStandardItemModel(this);
	if (m_weatherClient->getAllSupportCities(vec))
	{
		QStringList strList;
		for (auto it = vec.begin(); it != vec.end(); it++)
		{
			strList.append(*it);
		}
		int nCount = strList.size();
		for (int i = 0; i < nCount; i++)
		{
			QString string = static_cast<QString>(strList.at(i));
			QStandardItem* item = new QStandardItem(string);
			ItemModel->appendRow(item);
		}
	}
	ui.listViewAllCity->setModel(ItemModel);
}




