#include "CDetailWidget.h"

CDetailWidget::CDetailWidget(QWidget* parent) : QWidget(parent)
{
	this->setStyleSheet("background-color: rgba(255, 255, 255, 0.7);");

	// ��������
	m_model = new QStandardItemModel(this);
	m_model->setColumnCount(2);
	m_model->setHorizontalHeaderItem(0, new QStandardItem(tr("ԭʼ���")));
	m_model->setHorizontalHeaderItem(1, new QStandardItem(tr("ʹ�ý��")));

	m_table = new QTableView(this);
	m_table->setModel(m_model);
	m_table->verticalHeader()->hide();
	m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); // �����Զ��������
	m_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // �����Զ��������

	m_layout = new QVBoxLayout(this);
	m_layout->addWidget(m_table);
}

CDetailWidget::~CDetailWidget()
{

}