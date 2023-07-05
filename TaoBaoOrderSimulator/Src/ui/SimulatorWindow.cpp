#include "SimulatorWindow.h"

SimulatorWindow::SimulatorWindow(QWidget *parent) : QMainWindow(parent)
{
	this->setWindowTitle(tr("淘宝订单模拟器"));
	this->setMinimumSize(800, 600);
	this->setMaximumSize(1200, 900);

	// 加载背景图片
	QPixmap background(":/Resources/Disney.jpg");

	// 创建用于显示背景图片的 QLabel
	QLabel* backgroundLabel = new QLabel(this);
	backgroundLabel->setPixmap(background);
	backgroundLabel->setScaledContents(true);
	backgroundLabel->resize(this->size());

	// 子窗口
	m_detail = new CDetailWidget(this);
	m_redPack = new CRedPackWidget(this);
	m_order = new COrderWidget(this);

	// 主分割器
	m_splitter = new QSplitter(Qt::Horizontal, this);
	m_splitter->setWindowOpacity(0.5);

	QSplitter* subSplitter = new QSplitter(Qt::Vertical, this);
	subSplitter->addWidget(m_redPack);
	subSplitter->addWidget(m_order);
	subSplitter->setSizes({ 5000, 5000 });

	m_splitter->addWidget(m_detail);
	m_splitter->addWidget(subSplitter);
	m_splitter->setSizes({ 5000, 5000 });

	this->setCentralWidget(m_splitter);
}

SimulatorWindow::~SimulatorWindow()
{

}
