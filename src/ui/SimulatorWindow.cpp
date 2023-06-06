#include "SimulatorWindow.h"

SimulatorWindow::SimulatorWindow(QWidget *parent) : QMainWindow(parent)
{
	setWindowTitle(tr("淘宝订单模拟器"));
	setMinimumSize(800, 600);
	setMaximumSize(1200, 900);

	m_detail = new CDetailWidget(this);
	m_redPack = new CRedPackWidget(this);
	m_order = new COrderWidget(this);

	// 布局
	m_layout = new QGridLayout(this);
	m_layout->addWidget(m_detail, 0, 0, 6, 3);
	m_layout->addWidget(m_redPack, 0, 3, 3, 3);
	m_layout->addWidget(m_order, 3, 3, 3, 3);

	m_centralWidget = new QWidget(this);
	m_centralWidget->setLayout(m_layout);
	setCentralWidget(m_centralWidget);
}

SimulatorWindow::~SimulatorWindow()
{

}


