#include "SimulatorWindow.h"

SimulatorWindow::SimulatorWindow(QWidget *parent) : QMainWindow(parent)
{
	this->setWindowTitle(tr("�Ա�����ģ����"));
	this->setMinimumSize(800, 600);
	this->setMaximumSize(1200, 900);

	// ���ر���ͼƬ
	QPixmap background(":/Resources/Disney.jpg");

	// ����������ʾ����ͼƬ�� QLabel
	QLabel* backgroundLabel = new QLabel(this);
	backgroundLabel->setPixmap(background);
	backgroundLabel->setScaledContents(true);
	backgroundLabel->resize(this->size());

	// �Ӵ���
	m_detail = new CDetailWidget(this);
	m_redPack = new CRedPackWidget(this);
	m_order = new COrderWidget(this);

	// ���ָ���
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
