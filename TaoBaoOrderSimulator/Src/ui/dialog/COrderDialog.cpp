#include "COrderDialog.h"

COrderDialog::COrderDialog(QWidget* parent) : QDialog(parent)
{
	this->setWindowTitle(tr("新增订单"));
	this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
	this->setFixedSize(400, 300);

	m_label = new QLabel(tr("订单金额："));
	m_label->setStyleSheet("QLabel { background-color: none; }");

	m_valueLine = new CLineEdit(this);

	m_okBtn = new CPushButton(":/Resources/Duck.png", tr("确定"), this);

	m_layout = new QHBoxLayout(this);
	m_layout->addWidget(m_label);
	m_layout->addWidget(m_valueLine);
	m_layout->addWidget(m_okBtn);

	connect(m_okBtn, &CPushButton::clicked, this, &COrderDialog::onBtnClicked);
}

COrderDialog::~COrderDialog()
{

}

int COrderDialog::exec()
{
	m_valueLine->clear();
	return QDialog::exec();
}

void COrderDialog::onBtnClicked()
{
	if (m_valueLine->text().isEmpty())
	{
		QMessageBox::question(this, tr("提示"), tr("请输入订单金额"));
		return;
	}

	emit addOrder(m_valueLine->text().toDouble());
	m_valueLine->clear();
}