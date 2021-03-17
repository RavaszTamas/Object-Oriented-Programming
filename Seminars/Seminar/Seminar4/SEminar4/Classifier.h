#pragma once
#include <vector>
#include "Instance.h"

class Classifier
{
public:
	virtual void train(const std::vector<Instance>&) = 0;
	virtual std::vector<int> predict(const std::vector<Instance>&) = 0;
	virtual ~Classifier() {}
};