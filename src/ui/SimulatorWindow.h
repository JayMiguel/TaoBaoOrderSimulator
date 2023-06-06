#pragma once
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include <QGridLayout>

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
    QWidget* m_centralWidget;
    QGridLayout* m_layout;
    CDetailWidget* m_detail;
    CRedPackWidget* m_redPack;
    COrderWidget* m_order;
};
