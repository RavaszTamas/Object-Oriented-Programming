#pragma once
#include "Repository.h"
#include "Song.h"


class UndoAction
{
public:
	virtual void executeUndo() = 0;
	virtual ~UndoAction() = 0;
};


class UndoAdd : public UndoAction
{
private:
	Song addedSong;
	Repository& repo;
public:
	UndoAdd();
	void executeUndo() override;
};

class UndoRemove : public UndoAction
{
private:
	Song deletedSong;
	Repository& repo;
public:
	UndoRemove();
	void executeUndo() override;
};

class UndoUpdate : public UndoAction
{
private:
	Song oldSong;
	Repository& repo;
public:
	UndoUpdate();
	void executeUndo() override;
};