#include "Undo.h"

UndoAdd::UndoAdd(Plant plant, PlantRepository & _repo) :addedPlant{ plant }, repo{ _repo }
{
}

void UndoAdd::executeUndo()
{
	this->repo.removePlant(addedPlant.getCodeName());
}

void UndoAdd::executeRedo()
{
	this->repo.storeNewPlant(addedPlant);

}

UndoAction::~UndoAction()
{
}

UndoRemove::UndoRemove(Plant plant, PlantRepository & _repo) :deletedPlant{ plant }, repo{ _repo }
{
}

void UndoRemove::executeUndo()
{
	this->repo.storeNewPlant(deletedPlant);
}

void UndoRemove::executeRedo()
{
	this->repo.removePlant(deletedPlant.getCodeName());

}

UndoUpdate::UndoUpdate(Plant _oldPlant, Plant _newPlant, PlantRepository & _repo) :oldPlant{ _oldPlant }, newPlant{ _newPlant }, repo{ _repo }
{
}

void UndoUpdate::executeUndo()
{
	this->repo.updatePlant(oldPlant);
}

void UndoUpdate::executeRedo()
{
	this->repo.updatePlant(newPlant);
}

//RedoAdd::RedoAdd(Plant plant, PlantRepository & _repo) :plantToAdd{ plant }, repo{ _repo }
//{
//}
//
//void RedoAdd::executeRedo()
//{
//	this->repo.storeNewPlant(plantToAdd);
//}
//
//RedoRemove::RedoRemove(Plant plant, PlantRepository & _repo) :plantToDelete{ plant }, repo{ _repo }
//{
//}
//
//void RedoRemove::executeRedo()
//{
//	this->repo.removePlant(plantToDelete.getCodeName());
//}
//
//RedoUpdate::RedoUpdate(Plant _oldPlant, Plant _newPlant, PlantRepository & _repo) :oldPlant{ _oldPlant }, newPlant{ _newPlant }, repo{ _repo }
//{
//}
//
//void RedoUpdate::executeRedo()
//{
//	this->repo.updatePlant(newPlant);
//}

UndoAddUproot::UndoAddUproot(Plant plant, FileManagerMyList * _repo) :addedPlant{ plant }, repo{ _repo }
{
}

void UndoAddUproot::executeUndo()
{
	this->repo->removeFromFile(addedPlant);
}

void UndoAddUproot::executeRedo()
{
	this->repo->saveToFile(addedPlant);
}

UndoRemoveUproot::UndoRemoveUproot(Plant plant, FileManagerMyList * _repo) :deletedPlant{ plant }, repo{ _repo }
{
}

void UndoRemoveUproot::executeUndo()
{
	this->repo->saveToFile(deletedPlant);

}

void UndoRemoveUproot::executeRedo()
{
	this->repo->removeFromFile(deletedPlant);
}
