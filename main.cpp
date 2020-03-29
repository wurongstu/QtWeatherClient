#include "QtWeatherClient.h"
#include <QtWidgets/QApplication>
#include "weatherClient.h"


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	QtWeatherClient w;
	w.setAutoFillBackground(true);
	QPalette palette;
	QPixmap pixmap("picture/background.jpg");
	palette.setBrush(QPalette::Window, QBrush(pixmap));

	w.setPalette(palette);
	w.show();
	return app.exec();
}
