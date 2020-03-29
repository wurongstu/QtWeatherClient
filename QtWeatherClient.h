#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWeatherClient.h"
#include "weatherClient.h"
class QtWeatherClient : public QMainWindow
{
	Q_OBJECT

public:
	QtWeatherClient(QWidget *parent = Q_NULLPTR);



private:
	
private:
	Ui::QtWeatherClientClass ui;
	weatherClient* m_weatherClient;

private slots:
	void slot_showSupportAllCities();void inneraddClickEvent(const QPoint& pos);
	void slot_showWeaterByCityname();
};
