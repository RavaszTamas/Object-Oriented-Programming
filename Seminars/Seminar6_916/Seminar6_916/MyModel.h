#pragma once
#include <QAbstractTableModel>
#include "Repository.h"

class MyModel :
	public QAbstractTableModel
{
private:
	Repository& repo;

public:
	MyModel(Repository& r);
	~MyModel();

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
};

