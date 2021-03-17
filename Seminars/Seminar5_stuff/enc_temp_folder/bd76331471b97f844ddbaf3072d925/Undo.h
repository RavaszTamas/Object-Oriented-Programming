#pragma once
#include "Repository.h"
#include "Song.h"


class UndoAction
{
public:
	virtual void executeUndo() = 0;
	///virtual ~UndoAction();
};


class UndoAdd : public UndoAction
{
private:
	Song addedSong;
	Repository& repo;
public:
	UndoAdd(Song s, Repository& _repo);
	void executeUndo() override;
};

class UndoRemove : public UndoAction
{
private:
	Song deletedSong;
	Repository& repo;
public:
	UndoRemove(Song s, Repository& _repo);
	void executeUndo() override;
};

class UndoUpdate : public UndoAction
{
private:
	Song oldSong;
	Repository& repo;
public:
	UndoUpdate(Song s, Repository& repo);
	void executeUndo() override;
};