 /**********************************************
/ *
 ** Qt Examples by John Law (aka Technist)
 **
 ** Published under the GNU GPLv3 License.
 ** Github Repository: 
 ** Technist/My-Qt-Examples/tree/master
 **   /[widgets]--regex-validators
 **                                            /
 *********************************************/

//	This program was made in demonstration of a StackOverflow answer:
//	https://stackoverflow.com/a/54849972/10239789

#include <QtCore>
#include <QtWidgets>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	//	set some style ✨
	app.setFont(QFont("Monaco", 12, -1, true));
	app.setStyleSheet(".QLineEdit { color: black; }"
					  "QLineEdit[status=\"valid\"] { background-color: rgb(200, 230, 200); }"
					  "QLineEdit[status=\"editing\"] { background-color: rgb(230, 230, 150); }"
					  "QLineEdit[status=\"invalid\"] { background-color: rgb(230, 200, 200); }");
	
	//	compile a list of regexes
	QStringList regexes;
	regexes << "[0-9]*" << "[1-9][0-9]*" << "\\d*" << "[0-9]+" << "[0-9]{8,32}"
			<< "[0-1]{,4}" << "0x[0-9a-fA-F]" << "[0-9]{13}";
	
	QWidget w;
	QFormLayout fLayout(&w);
	
	//	fill the layout with widgets
	foreach (const QString &r, regexes)
	{
		//	instantiate labels and line-edits with the regex validators
		QLabel *label = new QLabel(QString("QRegExp('%1')").arg(r));
		label->setFont(app.font());
		QLineEdit *edit = new QLineEdit;
		edit->setValidator(new QRegExpValidator(QRegExp(r), edit));
		edit->setPlaceholderText(r);
		
		//	add widgets into layout
		fLayout.addRow(label, edit);
		
		//	connect the line-edit to signals which determine the colour
		QObject::connect(edit, &QLineEdit::textEdited, [=](QString text)
		{
			int i; 
			if (edit->validator()->validate(text, i) == QValidator::Acceptable)
				edit->setProperty("status", "editing");
			else
				edit->setProperty("status", "invalid");
			edit->setStyleSheet("color: yellow");	//	force the stylesheet to repaint
			edit->setStyleSheet("");
		});
		
		QObject::connect(edit, &QLineEdit::editingFinished, [=]()
		{
			edit->setProperty("status", "valid");
			edit->setStyleSheet("color: yellow");	//	force the stylesheet to repaint
			edit->setStyleSheet("");
		});
		
		edit->textEdited("");	//	flush the background colour
	}
	
	w.show();
	
	return app.exec();
}

