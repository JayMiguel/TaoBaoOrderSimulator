#include "CRedPackWidget.h"

CRedPackWidget::CRedPackWidget(QWidget* parent) : QWidget(parent)
{
	this->setStyleSheet("background-color: rgba(255, 255, 255, 0.7);");

	// 订单详情
	m_model = new QStandardItemModel(this);
	m_model->setColumnCount(3);
	m_model->setHorizontalHeaderItem(0, new QStandardItem(tr("序号")));
	m_model->setHorizontalHeaderItem(1, new QStandardItem(tr("原始金额")));
	m_model->setHorizontalHeaderItem(2, new QStandardItem(tr("剩余金额")));

	m_table = new QTableView(this);
	m_table->setModel(m_model);
	m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_table->setSelectionMode(QAbstractItemView::MultiSelection);
	m_table->verticalHeader()->hide();
	m_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // 该列自动调整宽度
	m_table->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch); // 该列自动调整宽度

	m_addBtn = new RoundButton(tr("新增红包"), this);
	m_removeBtn = new RoundButton(tr("删除红包"), this);
	
	QHBoxLayout* m_btnLayout = new QHBoxLayout;
	m_btnLayout->addWidget(m_addBtn);
	m_btnLayout->addWidget(m_removeBtn);
	
	m_layout = new QVBoxLayout(this);
	m_layout->addLayout(m_btnLayout);
	m_layout->addWidget(m_table);

	m_dialog = new CRedPackDlg(this);
	m_dialog->close();

	/////////////////////////////////////////////////////////
	connect(m_addBtn, SIGNAL(clicked()), this, SLOT(onAddClicked()));
	connect(m_removeBtn, SIGNAL(clicked()), this, SLOT(onRemoveClicked()));
	connect(m_dialog, SIGNAL(addRedPack(const double)), this, SLOT(onAddRedPack(const double)));
}

CRedPackWidget::~CRedPackWidget()
{

}

void CRedPackWidget::onAddClicked()
{
	m_dialog->exec();
}

void CRedPackWidget::onRemoveClicked()
{
	// 获取所有选中项
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

	// 获取所有行号
	QVector<int> rows;
	for (QModelIndex& index : indexList)
	{
		if (!rows.contains(index.row()))
		{
			rows.push_back(index.row());
		}
	}
	
	// 升序排序
	qSort(rows);

	// 删除红包
	for (auto iter = rows.rbegin() ; iter != rows.rend(); iter++)
	{
		// 从表格中移除
		if (m_model->removeRow(*iter))
		{
			// 从容器中移除
			vecRedPack.removeAt(*iter);
		}
	}

	// 重新设定序号
	for (int i = 0; i < m_model->rowCount(); i++)
	{
		m_model->item(i, 0)->setData(i + 1, Qt::DisplayRole);
	}
}

void CRedPackWidget::onAddRedPack(double money)
{
	RedPack* redPack = new RedPack(money);
	redPack->m_itemNum = new QStandardItem(QString::number(m_model->rowCount() + 1));
	redPack->m_itemTotal = new QStandardItem(QString::number(redPack->m_total));
	redPack->m_itemSurplus = new QStandardItem(QString::number(redPack->m_surplus));

	m_model->appendRow({ redPack->m_itemNum, redPack->m_itemTotal, redPack->m_itemSurplus });
	vecRedPack.push_back(redPack);
	m_dialog->close();
}