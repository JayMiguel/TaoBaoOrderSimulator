
#include "SimulatorWindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ����ȫ������
    QFont font("΢���ź�", 12);
    a.setFont(font);

    SimulatorWindow w;
    w.showMinimized();
    return a.exec();
}
