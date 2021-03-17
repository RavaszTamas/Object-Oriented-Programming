#pragma once
#include "Repository.h"

class UndoAction
{
public:
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;
	virtual ~UndoAction();

};


class UndoAdd : public UndoAction
{
private:
	Plant addedPlant;
	PlantRepository& repo;
public:
	UndoAdd(Plant plant, PlantRepository& _repo);
	void executeUndo() override;
	void executeRedo() override;

};

class UndoRemove : public UndoAction
{
private:
	Plant deletedPlant;
	PlantRepository& repo;
public:
	UndoRemove(Plant plant, PlantRepository& _repo);
	void executeUndo() override;
	void executeRedo() override;
};

class UndoUpdate : public UndoAction
{
private:
	Plant oldPlant;
	Plant newPlant;
	PlantRepository& repo;
public:
	UndoUpdate(Plant _oldPlant, Plant _newPlant, PlantRepository& _repo);
	void executeUndo() override;
	void executeRedo() override;
};


class UndoAddUproot : public UndoAction
{
private:
Plant addedPlant;
FileManagerMyList* repo;
public:
UndoAddUproot(Plant plant, FileManagerMyList* _repo);
void executeUndo() override;
void executeRedo() override;

};

class UndoRemoveUproot : public UndoAction
{
private:
Plant deletedPlant;
FileManagerMyList* repo;
public:
UndoRemoveUproot(Plant plant, FileManagerMyList* _repo);
void executeUndo() override;
void executeRedo() override;
};


//class RedoAction
//{
//public:
//	virtual void executeRedo() = 0;
//	virtual ~RedoAction();
//};
//
//
//class RedoAdd : public RedoAction
//{
//private:
//	Plant plantToAdd;
//	PlantRepository& repo;
//public:
//	RedoAdd(Plant plant, PlantRepository& _repo);
//	void executeRedo() override;
//};
//
//class RedoRemove : public RedoAction
//{
//private:
//	Plant plantToDelete;
//	PlantRepository& repo;
//public:
//	RedoRemove(Plant plant, PlantRepository& _repo);
//	void executeRedo() override;
//};
//
//class RedoUpdate : public RedoAction
//{
//private:
//	Plant oldPlant;
//	Plant newPlant;
//	PlantRepository& repo;
//public:
//	RedoUpdate(Plant _oldPlant, Plant _newPlant, PlantRepository& _repo);
//	void executeRedo() override;
//};