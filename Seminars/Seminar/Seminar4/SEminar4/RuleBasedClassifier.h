#pragma once
#include "Classifier.h"
#include <vector>
#include <functional>

class RuleBasedClassifier :	public Classifier
{
private:
	std::vector<std::function<int(Instance)>> rules;

public:
	RuleBasedClassifier() {}
	~RuleBasedClassifier() {}

	void train(const std::vector<Instance>& instances) override;
	std::vector<int> predict(const std::vector<Instance>& instances) override;
};

