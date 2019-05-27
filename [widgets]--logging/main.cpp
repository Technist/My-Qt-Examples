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
    
    QObject::connect(&pb, &QPushButton::clicked, [&] {
        pb.setEnabled(false);
        pb.setText("Logging...");
        
        QString text;
        double t = 0.0;
        for (int N = 1; N < 50; N++)
        {
            t += 2.0;
            QString line = QString("\tN=%1\tt=%2").arg(N).arg(t);
            te.append(line);
            
            pb.setText("Logging" + QString().fill('.', (N/10)%3 + 1));
            QThread::msleep(100);
            QApplication::processEvents();
        }
        
        pb.setText("Click me!");
        pb.setEnabled(true);
    });
    
    vbLayout.addWidget(&te);
    vbLayout.addWidget(&pb);
    w.setLayout(&vbLayout);
    
    w.show();
    
    return app.exec();
}
