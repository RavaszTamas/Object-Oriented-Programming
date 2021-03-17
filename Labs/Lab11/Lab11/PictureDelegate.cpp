#include "PictureDelegate.h"
#include <string>
#include <iostream>

PictureDelegate::PictureDelegate(QWidget * parent)
{
}

void PictureDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	QString organism = index.model()->data(index, Qt::EditRole).toString();
	if (index.column() != 4)
	{
		QStyledItemDelegate::paint(painter, option, index);
		return;
	}
	if (index.row() % 2 == 1)
	{
		QPixmap pixMap("plant1.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else
	{
		QPixmap pixMap("plant2.jpg");
		painter->drawPixmap(option.rect, pixMap);

	}
	//std::string organismSTD = organism.toStdString();
	//if (organismSTD == "21")
	//{
	//	QPixmap pixMap("plant1.jpg");
	//	painter->drawPixmap(option.rect, pixMap);
	//}
	//else if (organismSTD == "murok")
	//{
	//	QPixmap pixMap("murok.jpg");
	//	painter->drawPixmap(option.rect, pixMap);
	//}
	//else
	//{
	//	QPixmap pixMap("plant2.jpg");
	//	painter->drawPixmap(option.rect, pixMap);
	//}

}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	if (index.column() == 1)
	{
		return QSize(100, 50);
	}

	return QStyledItemDelegate::sizeHint(option, index);
}
