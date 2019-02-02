

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
	te.setDocumentTitle("Cat Ipsum");
	vLayout.addWidget(&te);
	
	//	horizontal layouts to contain buttons
	QHBoxLayout hLayout;
	hLayout.setMargin(0);
	vLayout.addLayout(&hLayout);
	
	//	printers and settings classes
	QPrinter printer;
	QPageSetupDialog setupDialog(&printer, &w);
	
	//	setup button
	QPushButton setupButton("Setup", &w);
	hLayout.addWidget(&setupButton);
	QObject::connect(&setupButton, &QPushButton::clicked, &setupDialog, &QDialog::open);
	
	//	print button
	QPushButton printButton("Print", &w);
	hLayout.addWidget(&printButton);
	QObject::connect(&printButton, &QPushButton::clicked, [&]()
	{
		te.print(&printer);
	});
	
	
	w.show();
	
	
	return app.exec();
}

