#include "CPushButton.h"
#include <QDebug>
CPushButton::CPushButton(const QString& imagePath, const QString& text, QWidget* parent): QWidget(parent)
{
	this->setFixedSize(100, 100);
	this->setStyleSheet("QWidget { background-color: blue; }");

	m_imagePath = imagePath;

	// 加载背景图片
	QPixmap image(m_imagePath);

	// 创建用于显示背景图片的 QLabel
	m_backgroundLabel = new QLabel(this);
	m_backgroundLabel->setPixmap(image);
	m_backgroundLabel->setScaledContents(true);
	m_backgroundLabel->resize(this->size());
	m_backgroundLabel->setStyleSheet("QLabel { background-color: none; }");

	m_textLabel = new QLabel(text, this);
	m_textLabel->setStyleSheet("QLabel { background-color: none; }");
	m_textLabel->setAlignment(Qt::AlignHCenter);
	m_textLabel->move(35, 65);
}

CPushButton::~CPushButton()
{

}

void CPushButton::mousePressEvent(QMouseEvent* event)
{
	this->move(this->x() + 5, this->y() + 5);
	m_backgroundLabel->resize(90, 90);
	QFont font;
	font.setPointSize(9);
	m_textLabel->setFont(font);
	m_textLabel->move(30, 60);
}

void CPushButton::mouseReleaseEvent(QMouseEvent* event)
{
	this->move(this->x() - 5, this->y() - 5);
	m_backgroundLabel->resize(100, 100);
	QFont font;
	font.setPointSize(12);
	m_textLabel->setFont(font);
	m_textLabel->move(35, 65);

	emit clicked();
}
