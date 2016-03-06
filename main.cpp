#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("macintosh");
    Widget w;
    w.show();
    w.setWindowTitle("XRFv3.0");
    return a.exec();
}
