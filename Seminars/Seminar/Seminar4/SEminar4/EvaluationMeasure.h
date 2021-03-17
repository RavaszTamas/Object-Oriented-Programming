#pragma once
#include <vector>
#include "Instance.h"

class EvaluationMeasure
{
public:
	virtual double evaluate(const std::vector<Instance>& instances, const std::vector<int>& predictions) = 0;
	virtual ~EvaluationMeasure() {}
};

class Accuracy : public EvaluationMeasure
{
	double evaluate(const std::vector<Instance>& instances, const std::vector<int>& predictions);
};

class MeanSquaredError : public EvaluationMeasure
{
	double evaluate(const std::vector<Instance>& instances, const std::vector<int>& predictions);
};