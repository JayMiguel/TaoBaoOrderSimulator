
#include "SimulatorWindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimulatorWindow w;
    w.showMinimized();
    return a.exec();
}
