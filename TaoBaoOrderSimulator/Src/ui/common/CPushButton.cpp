#include "CPushButton.h"

CPushButton::CPushButton(const QString& text, QWidget* parent) : QWidget(parent)
{
	this->setFixedSize(100, 300);
	QLabel* imageLabel = new QLabel(this);
	QLabel* textLabel = new QLabel(text);
}

CPushButton::CPushButton(const QString& imagePath, const QString& text, QWidget* parent): QWidget(parent)
{
	this->setFixedSize(100, 300);

	this->m_imagePath = imagePath;

	QLabel* textLabel = new QLabel(text);
	textLabel->setAlignment(Qt::AlignHCenter);

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(textLabel);

	this->setLayout(layout);
}

CPushButton::~CPushButton()
{

}

void CPushButton::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.drawPixmap(rect(), QPixmap(m_imagePath), QRect());
}
