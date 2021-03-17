#pragma once
#include <vector>
#include "Observer.h"

class Subject
{
private:
	std::vector<Observer*> observers;
public:
	Subject();
	void registerObserver(Observer * obs);
	void unRegisterObserver(Observer * obs);
	void notify();
	~Subject();
};

