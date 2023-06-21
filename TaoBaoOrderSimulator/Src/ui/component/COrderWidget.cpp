#include "COrderWidget.h"

COrderWidget::COrderWidget(QWidget* parent) : QWidget(parent)
{
	// 订单列表
	m_model = new QStandardItemModel(this);
	m_model->setColumnCount(1);
	m_model->setHorizontalHeaderItem(0, new QStandardItem(tr("订单使用的红包总额")));

	m_table = new QTableView(this);
	m_table->setModel(m_model);
	m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_table->verticalHeader()->setMinimumWidth(30);
	m_table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); // 该列自动调整宽度

	m_addBtn = new QPushButton(tr("新增订单"), this);
	m_removeBtn = new QPushButton(tr("删除订单"), this);

	QHBoxLayout* m_btnLayout = new QHBoxLayout;
	m_btnLayout->addWidget(m_addBtn);
	m_btnLayout->addWidget(m_removeBtn);

	m_layout = new QVBoxLayout(this);
	m_layout->addLayout(m_btnLayout);
	m_layout->addWidget(m_table);

	/////////////////////////////////////////////////////////
	connect(m_addBtn, SIGNAL(clicked()), this, SLOT(onAddClicked()));
	connect(m_removeBtn, SIGNAL(clicked()), this, SLOT(onRemoveClicked()));
}

COrderWidget::~COrderWidget()
{

}

void COrderWidget::onAddClicked()
{

}

void COrderWidget::onRemoveClicked()
{

}