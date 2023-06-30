#include "CRedPackDlg.h"

CRedPackDlg::CRedPackDlg(QWidget* parent) : QDialog(parent)
{
	this->setWindowTitle(tr("新增红包"));
	this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
	this->setFixedSize(400, 300);

	m_label = new QLabel(tr("红包总额："));
	m_label->setStyleSheet("QLabel { background-color: none; }");

	m_valueLine = new CLineEdit(this);

	m_okBtn = new CPushButton(":/Resources/Duck.png", tr("确定"), this);

	m_layout = new QHBoxLayout(this);
	m_layout->addWidget(m_label);
	m_layout->addWidget(m_valueLine);
	m_layout->addWidget(m_okBtn);

	connect(m_okBtn, &CPushButton::clicked, this, &CRedPackDlg::onBtnClicked);
}

CRedPackDlg::~CRedPackDlg()
{

}

int CRedPackDlg::exec()
{
	m_valueLine->clear();
	return QDialog::exec();
}

void CRedPackDlg::onBtnClicked()
{
	if (m_valueLine->text().isEmpty())
	{
		QMessageBox::question(this, tr("提示"), tr("请输入红包金额"));
		return;
	}

	emit addRedPack(m_valueLine->text().toDouble());
	m_valueLine->clear();
}