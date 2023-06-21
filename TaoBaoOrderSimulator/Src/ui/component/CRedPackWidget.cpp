#include "CRedPackWidget.h"

CRedPackWidget::CRedPackWidget(QWidget* parent) : QWidget(parent)
{
	// 订单详情
	m_model = new QStandardItemModel(this);
	m_model->setColumnCount(2);
	m_model->setHorizontalHeaderItem(0, new QStandardItem(tr("原始金额")));
	m_model->setHorizontalHeaderItem(1, new QStandardItem(tr("剩余金额")));

	m_table = new QTableView(this);
	m_table->setModel(m_model);
	m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_table->setSelectionMode(QAbstractItemView::MultiSelection);
	m_table->verticalHeader()->setMinimumWidth(30);
	m_table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); // 该列自动调整宽度
	m_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // 该列自动调整宽度

	m_addBtn = new QPushButton(tr("新增红包"), this);
	m_removeBtn = new QPushButton(tr("删除红包"), this);
	
	QHBoxLayout* m_btnLayout = new QHBoxLayout;
	m_btnLayout->addWidget(m_addBtn);
	m_btnLayout->addWidget(m_removeBtn);
	
	m_layout = new QVBoxLayout(this);
	m_layout->addLayout(m_btnLayout);
	m_layout->addWidget(m_table);

	m_dlg = new CRedPackDlg(this);
	m_dlg->close();

	/////////////////////////////////////////////////////////
	connect(m_addBtn, SIGNAL(clicked()), this, SLOT(onAddClicked()));
	connect(m_removeBtn, SIGNAL(clicked()), this, SLOT(onRemoveClicked()));
	connect(m_dlg, SIGNAL(addRedPack(const double)), this, SLOT(onAddRedPack(const double)));
}

CRedPackWidget::~CRedPackWidget()
{

}

void CRedPackWidget::onAddClicked()
{
	m_dlg->exec();
}

void CRedPackWidget::onRemoveClicked()
{
	QModelIndexList indexList = m_table->selectionModel()->selectedIndexes();
	if (indexList.isEmpty())
	{
		return;
	}

	int result = QMessageBox::warning(this, tr("警告"), tr("确定删除已选中的红包吗？"), QMessageBox::Yes, QMessageBox::No);
	if (result != QMessageBox::Yes)
	{
		return;
	}

	QList<int> rows;
	for (QModelIndex& index : indexList)
	{
		if (!rows.contains(index.row()))
		{
			rows.append(index.row());
		}
	}
	
	for (const int& row : rows)
	{
		if (m_model->removeRow(row))
		{
			m_vRedPack.removeAt(row);
		}
	}
}

void CRedPackWidget::onAddRedPack(const double money)
{
	m_model->appendRow({ new QStandardItem(QString::number(money)), new QStandardItem(QString::number(money)) });
	m_vRedPack.push_back(std::make_shared<RedPack>(money));
}

//////////////////////////////////////////////////////////////////////
RedPack::RedPack(const double& money) : max(money), surplus(0.0)
{

}

RedPack::~RedPack()
{

}