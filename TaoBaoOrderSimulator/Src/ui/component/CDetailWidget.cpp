#include "CDetailWidget.h"

CDetailWidget::CDetailWidget(QWidget* parent) : QWidget(parent)
{
	this->setStyleSheet("background-color: rgba(255, 255, 255, 0.7);");

	// 订单详情
	m_model = new QStandardItemModel(this);
	m_model->setColumnCount(2);
	m_model->setHorizontalHeaderItem(0, new QStandardItem(tr("原始金额")));
	m_model->setHorizontalHeaderItem(1, new QStandardItem(tr("使用金额")));

	m_table = new QTableView(this);
	m_table->setModel(m_model);
	m_table->verticalHeader()->hide();
	m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); // 该列自动调整宽度
	m_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // 该列自动调整宽度

	m_layout = new QVBoxLayout(this);
	m_layout->addWidget(m_table);
}

CDetailWidget::~CDetailWidget()
{

}