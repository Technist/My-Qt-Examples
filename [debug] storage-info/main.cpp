//	For more information on using QStorageInfo,
//	  see http://doc.qt.io/qt-5/qstorageinfo.html

#include <QtCore>
#include <QStorageInfo>

int main(/*int argc, char *argv[]*/)
{
	auto volumes = QStorageInfo::mountedVolumes();
	
	qDebug() << "Mounted Volumes:";
	foreach (const auto vol, volumes)
	{
		qDebug() << " Path:" << vol.rootPath();
		qDebug() << "  " << vol;
	}
	
	return 0;
}

