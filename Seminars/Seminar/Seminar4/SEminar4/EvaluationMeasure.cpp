#include "EvaluationMeasure.h"

double Accuracy::evaluate(const std::vector<Instance>& instances, const std::vector<int>& predictions)
{
	if (instances.size() != predictions.size())
		throw std::runtime_error{"The predictions vector has a different size than the instances vector!"};

	double accuracy = 0;
	for (int i = 0; i < instances.size(); i++)
		if (instances[i].get_output() == predictions[i])
			accuracy += 1;

	return accuracy / instances.size();
}

double MeanSquaredError::evaluate(const std::vector<Instance>& instances, const std::vector<int>& predictions)
{
	if (instances.size() != predictions.size())
		throw std::runtime_error{ "The predictions vector has a different size than the instances vector!" };

	double mse = 0;
	for (int i = 0; i < instances.size(); i++)
		mse += pow(instances[i].get_output() - predictions[i], 2);

	return mse / instances.size();
}
