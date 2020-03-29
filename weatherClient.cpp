#include "weatherClient.h"
using namespace std;
#include <qstring>
#include "weatherClient/stdsoap2.h"
#include "weatherClient/WeatherWebServiceSoap.nsmap"
#include "weatherClient/soapWeatherWebServiceSoapProxy.h"
#include <string>

weatherClient::weatherClient()
{
	m_bInit = false;
}

weatherClient::~weatherClient()
{
}



bool weatherClient::initClient()
{
	m_weatherProxy = new(nothrow) WeatherWebServiceSoapProxy();
	if (!m_weatherProxy)
	{
		return false;
	}
	soap_set_mode(m_weatherProxy, SOAP_C_UTFSTRING);
	return m_bInit = true;
}




bool weatherClient::getAllSupportCities(OUT std::vector<QString>& vecAllSupportCity)
{
	if (!m_bInit)
	{
		return false;
	}
	std::string provinceName = "";
	_ns1__getSupportCity supportCity;
	supportCity.byProvinceName = &provinceName;
	_ns1__getSupportCityResponse supportCityResponse;
	vector<string> result;
	bool bSuccess = false;
	int i = 0;
	int iTryCount = 3;
	do
	{
		if (SOAP_OK == m_weatherProxy->getSupportCity(&supportCity, supportCityResponse))
		{
			if (nullptr != supportCityResponse.getSupportCityResult)
			{
				result = supportCityResponse.getSupportCityResult->string;
				for (auto it = result.begin(); it != result.end(); it++)
				{
					vecAllSupportCity.push_back(QString::fromStdString(*it));
				}
			}
			bSuccess = true;
		}
		break;
	} while (++i<iTryCount);

	return bSuccess;
}


