

#include <QtCore>
#include <QtWidgets>
#include <QtPrintSupport>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	//	basic gui
	QWidget w;
	QVBoxLayout vLayout(&w);
	
	//	text editing
	QTextEdit te(&w);
	te.setPlaceholderText("Type something here!");
	te.setFont(QFont("Consolas", 13, 2, true));
	te.setText("Cat ipsum dolor sit amet, groom yourself 4 hours - checked, have your beauty sleep 18 hours - checked, be fabulous for the rest of the day - checked so stare at ceiling light and curl up and sleep on the freshly laundered towels why use post when this sofa is here.");
	vLayout.addWidget(&te);
	
	//	horizontal layouts to contain buttons
	QHBoxLayout hLayout;
	hLayout.setMargin(0);
	vLayout.addLayout(&hLayout);
	
	//	printers and settings classes
	QPrinter printer;
	printer.setDocName("Cat Ipsum");
	QPageSetupDialog setupDialog(&printer, &w);
	QPrintDialog printDialog(&printer, &w);
	
	//	setup button
	QPushButton setupButton("Setup", &w);
	hLayout.addWidget(&setupButton);
	QObject::connect(&setupButton, &QPushButton::clicked, &setupDialog, &QDialog::open);
	
	//	print button
	QPushButton printButton("Print", &w);
	hLayout.addWidget(&printButton);
	QObject::connect(&printButton, &QPushButton::clicked, &printDialog, &QDialog::open);
	QObject::connect(&printDialog, &QDialog::accepted, [&]()
	{
		te.print(&printer);
	});
	
	qDebug() << "Printer Name:" << printer.printerName();
	
	w.show();
	
	return app.exec();
}

