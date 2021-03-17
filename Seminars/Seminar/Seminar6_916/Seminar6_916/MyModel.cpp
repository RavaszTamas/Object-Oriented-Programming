#include "MyModel.h"
#include "qcolor.h"

MyModel::MyModel(Repository& r) : repo{ r }
{
}


MyModel::~MyModel()
{
}

int MyModel::rowCount(const QModelIndex & parent) const
{
	return this->repo.getSize();
}

int MyModel::columnCount(const QModelIndex & parent) const
{
	return 4;
}

QVariant MyModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int col = index.column();
	Student currentStudent = this->repo.getStudents()[row];

	if (role == Qt::DisplayRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(currentStudent.getName());
		case 1:
			return QString::fromStdString(currentStudent.getGroup());
		case 2:
			return QString::number(currentStudent.getLabGrade());
		case 3:
			return QString::number(currentStudent.getSeminarGrade());
		default:
			break;
		}
	}

	if (role == Qt::BackgroundRole)
		if (row % 2 == 0)
			return QColor{ Qt::green };

	return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:
			return "Name";
		case 1:
			return "Group";
		case 2:
			return "Lab grade";
		case 3:
			return "Seminar grade";
		default:
			break;
		}
	}

	return QVariant();
}

bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	Student& currentStudent = this->repo.getStudents()[index.row()];

	if (role == Qt::EditRole)
	{
		switch (index.column())
		{
		case 0:
			currentStudent.setName(value.toString().toStdString());
			break;
		case 1:
			currentStudent.setGroup(value.toString().toStdString());
			break;
		case 2:
			currentStudent.setLabGrade(value.toString().toDouble());
			break;
		case 3:
			currentStudent.setSeminarGrade(value.toString().toDouble());
			break;
		default:
			break;
		}
	}

	emit dataChanged(index, index);

	return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & index) const
{
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
