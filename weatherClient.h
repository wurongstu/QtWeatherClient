#pragma once
#include "weatherClient/soapWeatherWebServiceSoapProxy.h"
#include<vector>
#include<qstring>
using namespace std;
class weatherClient
{
public:
	weatherClient();
	~weatherClient();
	bool initClient();
	bool getAllSupportCities(vector<QString>& vecAllSupportCity);
	bool getcityWeatherInfoByName(string& cityName, vector<string>& outCityWeatherInfo);
private:
	WeatherWebServiceSoapProxy* m_weatherProxy;
	bool                        m_bInit;
};
