#include "Subject.h"
#include <algorithm>


Subject::Subject()
{
}

void Subject::registerObserver(Observer * obs)
{
	observers.push_back(obs);
}

void Subject::unRegisterObserver(Observer * obs)
{
	observers.erase(std::remove(observers.begin(), observers.end(), obs));
}

void Subject::notify()
{
	for (auto it : observers)
	{
		it->update();
	}

}


Subject::~Subject()
{
}
