#pragma once
#include <QAbstractTableModel>
#include "Controller.h"

class IdeasModel:public QAbstractTableModel
{
private:
	Controller& controller;
public:
	IdeasModel(Controller& _controller);
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
	void resetModel();
	~IdeasModel();
};

