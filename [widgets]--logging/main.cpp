#include <QApplication>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

#include <QString>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QWidget w;
    QVBoxLayout vbLayout;
    QPushButton pb("Click me!");
    QTextEdit te;
    
    QObject::connect(&pb, &QPushButton::clicked, [&te, &i] {
        double t = 0.0;
        for (int N = 1; N < 50; N++)
        {
            t += 2.0;
            te.append(QString("\tN=%1\tt=%2").arg(N).arg(t));
        }
    });
    
    vbLayout.addWidget(&te);
    vbLayout.addWidget(&pb);
    w.setLayout(&vbLayout);
    
    w.show();
    
    return app.exec();
}
