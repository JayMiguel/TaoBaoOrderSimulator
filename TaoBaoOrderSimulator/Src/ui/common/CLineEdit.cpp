#include "CLineEdit.h"

CLineEdit::CLineEdit(QWidget* parent) : QLineEdit(parent)
{
	this->setFixedHeight(30);

	m_validator = new QDoubleValidator(this);
}

CLineEdit::~CLineEdit()
{

}

void CLineEdit::setValidator(QValidator* validator)
{
	m_validator = validator;
}