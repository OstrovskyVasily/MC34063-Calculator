#include "mc34063.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mc34063 w;
    w.resize(1105,800);
    w.show();
    return a.exec();
}
