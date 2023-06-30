#include "CRedPackDlg.h"

CRedPackDlg::CRedPackDlg(QWidget* parent) : QDialog(parent)
{
	this->setWindowTitle(tr("�������"));
	this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
	this->setFixedSize(400, 300);

	m_label = new QLabel(tr("����ܶ"));
	m_label->setStyleSheet("QLabel { background-color: none; }");

	m_valueLine = new CLineEdit(this);

	m_okBtn = new CPushButton(":/Resources/Duck.png", tr("ȷ��"), this);

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
		QMessageBox::question(this, tr("��ʾ"), tr("�����������"));
		return;
	}

	emit addRedPack(m_valueLine->text().toDouble());
	m_valueLine->clear();
}