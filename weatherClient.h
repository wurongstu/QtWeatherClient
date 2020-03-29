#pragma once
#include "weatherClient/soapWeatherWebServiceSoapProxy.h"
#include<vector>
#include<qstring>
class weatherClient
{
public:
	weatherClient();
	~weatherClient();
	bool initClient();
	bool getAllSupportCities(OUT std::vector<QString>& vecAllSupportCity);
private:
	WeatherWebServiceSoapProxy* m_weatherProxy;
	bool                        m_bInit;
};
