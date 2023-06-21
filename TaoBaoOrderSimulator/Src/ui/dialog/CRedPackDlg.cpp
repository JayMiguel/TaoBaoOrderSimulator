#include "CRedPackDlg.h"

CRedPackDlg::CRedPackDlg(QWidget* parent) : QDialog(parent)
{
	setWindowTitle(tr("�������"));
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
	setFixedSize(400, 300);
	m_label = new QLabel(tr("����ܶ"));

	m_valueLine = new QLineEdit(this);
	QDoubleValidator* validator = new QDoubleValidator(this);
	m_valueLine->setValidator(validator);

	m_okBtn = new CPushButton(":/Resources/duck.png", tr("ȷ��"), this);

	m_layout = new QHBoxLayout(this);
	m_layout->addWidget(m_label);
	m_layout->addWidget(m_valueLine);
	m_layout->addWidget(m_okBtn);
	m_layout->setAlignment(m_okBtn, Qt::AlignCenter);

	//connect(m_okBtn, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
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