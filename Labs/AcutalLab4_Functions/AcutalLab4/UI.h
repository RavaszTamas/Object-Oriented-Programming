#pragma once
#include "Domain.h"
#include "DynamicArray.h"

void UIFilterSpecialization(char* specialization,DynamicVector* RobotRepository);

void UIListRobots(char* inputParameters,DynamicVector* RobotRepository);

void UIDeleteRobot(char* serialNumber,DynamicVector* RobotRepository, DynamicVector* UndoRedoStackOfVectors);

void UIUpdateExistingRobot(char* inputParameters,DynamicVector* RobotRepository, DynamicVector* UndoRedoStackOfVectors);

void UIAddNewRobot(char* inputParameters,DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfVectors);

void UIFilterByMaxEnergyCapacity(int maxEnegryCapacity,DynamicVector* RobotRepository);

void UIUndo(DynamicVector* RobotRepository, DynamicVector* UndoRedoStack);

void UIRedo();

void UIUndoListofLists(DynamicVector* RobotRepository, DynamicVector* UndoRedoStackOfVectors);

void UIRedoListofLists(DynamicVector* RobotRepository, DynamicVector* UndoRedoStackOfVectors);

void UIUndoFunctionCalls(DynamicVector* RobotRepository, DynamicVector* UndoRedoStackOfFunctionCalls);

void UIRedoFunctionCalls(DynamicVector* RobotRepository,DynamicVector* UndoRedoStackOfFunctionCalls);

void UI();