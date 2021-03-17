#include "IdeasModel.h"
#include <qcolor.h>


IdeasModel::IdeasModel(Controller& _controller) :controller{ _controller }
{
}

int IdeasModel::rowCount(const QModelIndex & parent) const
{
	return this->controller.getAll().size();
}

int IdeasModel::columnCount(const QModelIndex & parent) const
{
	return 4;
}

QVariant IdeasModel::data(const QModelIndex & index, int role) const
{
	Idea currentIdea = this->controller.getAll()[index.row()];
	if (role == Qt::DisplayRole)
	{
		switch (index.column())
		{
		case 0:
			return QString::fromStdString(currentIdea.getDesc());
			break;
		case 1:
			return QString::fromStdString(currentIdea.getStatus());
			break;
		case 2:
			return QString::fromStdString(currentIdea.getCreator());
			break;
		case 3:
			return QString::fromStdString(std::to_string(currentIdea.getAct()));
			break;
		}
	}
	//if (role == Qt::BackgroundRole)
	//	if (currentIdea.getStatus() == "accepted")
	//		return QColor{Qt::green };
	return QVariant{};
}

QVariant IdeasModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:
			return QString{ "Description" };
		case 1:
			return  QString{ "Status" };
		case 2:
			return  QString{ "Creator" };
		case 3:
			return QString{ "Act" };
		default:
			break;

		}
	}
	return QVariant{};
}

void IdeasModel::resetModel()
{
	this->beginResetModel();
	this->endResetModel();
}


IdeasModel::~IdeasModel()
{
}
