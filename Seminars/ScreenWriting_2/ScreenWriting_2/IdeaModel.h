#pragma once
#include "Controller.h"
#include <qabstractitemmodel.h>

class IdeaModel:public QAbstractTableModel
{
private:
	Controller& controller;
public:
	IdeaModel(Controller& _controller) :controller{ _controller } {};
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	//bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
	//Qt::ItemFlags flags(const QModelIndex &index) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
	void reset();


	~IdeaModel();
};

