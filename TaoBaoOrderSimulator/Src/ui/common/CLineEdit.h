#pragma once
#include <QLineEdit>
#include <QValidator>

class CLineEdit : public QLineEdit
{
	Q_OBJECT
public:
	CLineEdit(QWidget* parent = nullptr);
	~CLineEdit();

	void setValidator(QValidator* validator);

private:
	QValidator* m_validator;
};

