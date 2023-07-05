#include "SimulatorWindow.h"

SimulatorWindow::SimulatorWindow(QWidget *parent) : QMainWindow(parent)
{
	this->setWindowTitle(tr("淘宝订单模拟器"));
	this->setMinimumSize(800, 600);
	this->setMaximumSize(1200, 900);
	this->statusBar()->show();

	m_detail = new CDetailWidget(this);
	m_redPack = new CRedPackWidget(this);
	m_order = new COrderWidget(this);

	// 布局
	m_splitter = new QSplitter(Qt::Horizontal, this);
	m_splitter->addWidget(m_detail);
	QSplitter* subSplitter = new QSplitter(Qt::Vertical);
	subSplitter->addWidget(m_redPack);
	subSplitter->addWidget(m_order);
	subSplitter->setSizes({ 5000, 5000 });
	m_splitter->addWidget(subSplitter);
	m_splitter->setSizes({ 5000, 5000 });
	this->setCentralWidget(m_splitter);
}

SimulatorWindow::~SimulatorWindow()
{

}


