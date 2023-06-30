#include "COrderWidget.h"

COrderWidget::COrderWidget(QWidget* parent) : QWidget(parent)
{
	this->setStyleSheet("background-color: rgba(255, 255, 255, 0.7);");

	// 订单列表
	m_model = new QStandardItemModel(this);
	m_model->setColumnCount(2);
	m_model->setHorizontalHeaderItem(0, new QStandardItem(tr("序号")));
	m_model->setHorizontalHeaderItem(1, new QStandardItem(tr("订单使用的红包总额")));

	m_table = new QTableView(this);
	m_table->setModel(m_model);
	m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_table->verticalHeader()->hide();
	m_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // 该列自动调整宽度

	m_addBtn = new RoundButton(tr("新增订单"), this);
	m_removeBtn = new RoundButton(tr("删除订单"), this);

	QHBoxLayout* m_btnLayout = new QHBoxLayout;
	m_btnLayout->addWidget(m_addBtn);
	m_btnLayout->addWidget(m_removeBtn);

	m_layout = new QVBoxLayout(this);
	m_layout->addLayout(m_btnLayout);
	m_layout->addWidget(m_table);

	m_dialog = new COrderDialog(this);
	connect(m_dialog, &COrderDialog::addOrder, this, &COrderWidget::onAddOrder);

	/////////////////////////////////////////////////////////
	connect(m_addBtn, SIGNAL(clicked()), this, SLOT(onAddClicked()));
	connect(m_removeBtn, SIGNAL(clicked()), this, SLOT(onRemoveClicked()));
}

COrderWidget::~COrderWidget()
{

}

void COrderWidget::onAddClicked()
{
	m_dialog->exec();
}

void COrderWidget::onRemoveClicked()
{

}

void COrderWidget::onAddOrder(double total)
{
	std::shared_ptr<Order> order(new Order(total));
	m_model->appendRow({ new QStandardItem(QString::number(m_model->rowCount() + 1)), new QStandardItem(QString::number(order->m_total))});
	m_vOrder.push_back(order);
	m_dialog->close();
}