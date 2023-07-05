#include "CRedPackDlg.h"

CRedPackDlg::CRedPackDlg(QWidget* parent) : QDialog(parent)
{
	this->setWindowTitle(tr("�������"));
	this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);


	m_label = new QLabel(tr("����ܶ"));

	m_valueLine = new QLineEdit(this);
	QDoubleValidator* validator = new QDoubleValidator(this);
	m_valueLine->setFixedHeight(50);

	m_valueLine->setValidator(validator);

	m_okBtn = new QPushButton(tr("ȷ��"), this);

	m_layout = new QHBoxLayout(this);
	m_layout->addWidget(m_label);
	m_layout->addWidget(m_valueLine);
	m_layout->addWidget(m_okBtn);

	connect(m_okBtn, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
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
		QMessageBox::warning(this, tr("��ʾ"), tr("�����������"));
		return;
	}

	emit addRedPack(m_valueLine->text().toDouble());
	m_valueLine->clear();
}