#include "kalkulacka.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Kalkulacka w;
    w.show();

    return a.exec();
}
