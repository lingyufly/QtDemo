#include "LyRadar.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LyRadar w;
    w.show();
    return a.exec();
}
