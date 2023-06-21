#pragma once
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include <QGridLayout>
#include <QSplitter>

#include "CDetailWidget.h"
#include "CRedPackWidget.h"
#include "COrderWidget.h"

class SimulatorWindow : public QMainWindow
{
    Q_OBJECT
public:
    SimulatorWindow(QWidget *parent = nullptr);
    ~SimulatorWindow();

private:
    QSplitter* m_splitter;

    CDetailWidget* m_detail;
    CRedPackWidget* m_redPack;
    COrderWidget* m_order;
};
