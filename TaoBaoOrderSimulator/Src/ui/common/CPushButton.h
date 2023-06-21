#pragma once
#include <QVBoxLayout>
#include <QLabel>
#include <QPainter>

class CPushButton  : public QWidget
{
	Q_OBJECT

public:
	CPushButton(const QString& text = nullptr, QWidget *parent = nullptr);
	CPushButton(const QString& imagePath, const QString& text, QWidget *parent = nullptr);
	~CPushButton();

private:
	void paintEvent(QPaintEvent* event) override;

private:
	QString m_imagePath;
};
