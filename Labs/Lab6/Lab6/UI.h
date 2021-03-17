#pragma once
#include <iostream>
#include "Service.h"
#include <vector>

using namespace std;

class Console
{
private:
	AppController& controller;


	void UIList(vector<string>& inputParameters);

	void UIDeletePlant(vector<string>& inputParameters);

	void UIUpdatePlant(vector<string>& inputParameters);

	void UIAddPlant(vector<string>& inputParameters);

	void UIChooseMode(vector<string>& inputParameters);

	void ProcessInput(vector<string>& inputParameters, string& inputData);

	void UINext();

	void UIMylist();

	void UISave(vector<string>& inputParameters);

public:
	Console(AppController& applicationController);

	void run();

};