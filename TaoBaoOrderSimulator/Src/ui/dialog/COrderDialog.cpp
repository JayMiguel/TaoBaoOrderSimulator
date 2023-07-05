#include "COrderDialog.h"

COrderDialog::COrderDialog(QWidget* parent) : QDialog(parent)
{
	this->setWindowTitle(tr("��������"));
	this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
	this->setFixedSize(400, 300);

	m_label = new QLabel(tr("������"));
	m_label->setStyleSheet("QLabel { background-color: none; }");

	m_valueLine = new CLineEdit(this);

	m_okBtn = new CPushButton(":/Resources/Duck.png", tr("ȷ��"), this);

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
		QMessageBox::question(this, tr("��ʾ"), tr("�����붩�����"));
		return;
	}

	emit addOrder(m_valueLine->text().toDouble());
	m_valueLine->clear();
}