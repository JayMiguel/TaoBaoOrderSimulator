#pragma once
#include <QWidget>
#include <QLabel>
#include <QPainter>

class CPushButton  : public QWidget
{
	Q_OBJECT

public:
	CPushButton(const QString& imagePath, const QString& text = nullptr, QWidget *parent = nullptr);
	~CPushButton();

signals:
	void clicked();

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

private:
	QString m_imagePath;

	QLabel* m_backgroundLabel;
	QLabel* m_textLabel;
};
