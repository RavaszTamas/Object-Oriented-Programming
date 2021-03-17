#include "IdeaModel.h"




int IdeaModel::rowCount(const QModelIndex & parent) const
{
	return this->controller.getAll().size();
}

int IdeaModel::columnCount(const QModelIndex & parent) const
{
	return 4;
}

QVariant IdeaModel::data(const QModelIndex & index, int role) const
{
	auto elements = this->controller.getAll();
	if (role == Qt::DisplayRole)
	{
		switch (index.column())
		{
		case 0:
			return QString{ QString::fromStdString(elements[index.row()].getDescription()) };
		case 1:
			return QString{ QString::fromStdString(elements[index.row()].getStatus()) };
		case 2:
			return QString{ QString::fromStdString(elements[index.row()].getCreator()) };
		case 3:
			return QString{ QString::fromStdString(elements[index.row()].getAct()) };

		}
	}

	return QVariant{};
}

QVariant IdeaModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
		switch (section) {
		case 0:
			return QString("Description");
		case 1:
			return QString("Status");
		case 2:
			return QString("Creator");
		case 3:
			return QString("Act");

		}
	}
	return QVariant();
}

void IdeaModel::reset()
{
	this->beginResetModel();
	this->endResetModel();
}


IdeaModel::~IdeaModel()
{
}
