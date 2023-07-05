
#include "SimulatorWindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 设置全局字体
    QFont font("微软雅黑", 12);
    a.setFont(font);

    SimulatorWindow w;
    w.showMinimized();
    return a.exec();
}
