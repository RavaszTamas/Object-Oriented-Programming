#pragma once
#include "Domain.h"

void UIFilter(char* specialization,Robot* RobotRepository,int* lengthOfRobotRepository);

void UIListRobots(char* inputParameters,Robot* RobotRepository,int* lengthOfRobotRepository);

void UIDeleteRobot(char* serialNumber,Robot* RobotRepository,int* lengthOfRobotRepository);

void UIUpdateExistingRobot(char* inputParameters,Robot* RobotRepository,int* lengthOfRobotRepository);

void UIAddNewRobot(char* inputParameters,Robot* RobotRepository,int* lengthOfRobotRepository);

void UI();