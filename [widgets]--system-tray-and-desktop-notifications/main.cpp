 /*******************************************************
/ **
** Qt Examples by John Law (aka Technist)
**
** Published under the GNU GPLv3 License.
** Github Repository: 
** Technist/My-Qt-Examples/tree/master
**   /[widgets]--system-tray-and-desktop-notifications
**                                                      /
*******************************************************/

#include <QtCore>
#include <QtWidgets>

int main(int argc, char *argv[])
{
	QApplication app{argc, argv};

	
	QIcon wallet{":/res/wallet.png"};
	app.setWindowIcon(wallet);
	
	
	QSystemTrayIcon sti{wallet};
	sti.setToolTip("Tool tip from Qt.");
	
	QMenu mn;
	mn.addAction("Send Message", [&](){ sti.showMessage("Important!", "Alright soldier, I've got good news and bad news.", wallet, 1000); });
	mn.addAction("Quit", [&]()
	{
		sti.showMessage("Sayonara", "Good-bye soldier!", wallet, 5000);
		QApplication::quit();
	});
	
	
	sti.setContextMenu(&mn);
	sti.show();
	
	QObject::connect(&sti, &QSystemTrayIcon::messageClicked, [](){ qDebug() << "Message clicked!"; });
	
	return app.exec();
}

