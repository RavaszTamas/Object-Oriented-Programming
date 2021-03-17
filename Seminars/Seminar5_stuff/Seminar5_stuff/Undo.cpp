#include "Undo.h"

UndoAdd::UndoAdd(Song s, Repository & _repo) : addedSong{ s }, repo{ _repo }
{
}

void UndoAdd::executeUndo()
{
	repo.removeSong(addedSong);
}

UndoRemove::UndoRemove(Song s, Repository & _repo) : deletedSong{ s },repo{ _repo }
{
}

void UndoRemove::executeUndo()
{
	repo.addSong(deletedSong);
}

UndoUpdate::UndoUpdate(Song s, Repository & _repo) : oldSong{ s }, repo{ _repo }
{
}

void UndoUpdate::executeUndo()
{
}

UndoAction::~UndoAction()
{
}
