#pragma once
#include "Classifier.h"
#include <map>

class NaiveBayes : public Classifier
{
private:
	// TODO

public:
	void train(const std::vector<Instance>& instances) override;
	std::vector<int> predict(const std::vector<Instance>& instances) override;

private:
	// TODO
};

