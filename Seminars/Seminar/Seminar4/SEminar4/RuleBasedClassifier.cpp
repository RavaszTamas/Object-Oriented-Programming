#include "RuleBasedClassifier.h"
#include <algorithm>

using namespace std;

void RuleBasedClassifier::train(const std::vector<Instance>& instances)
{
	// infer a simple rule - start with instances having the value of the first feature less than 8 (chosen random, just for the example)

	int positives_less_than_8 = count_if(instances.begin(), instances.end(), [](const Instance& i) {return i.get_input()[0] < 8 && i.get_output() == 1; });
	int negatives_less_than_8 = count_if(instances.begin(), instances.end(), [](const Instance& i) {return i.get_input()[0] < 8 && i.get_output() == 0; });
	
	if (positives_less_than_8 > negatives_less_than_8)
	{
		auto rule = [](Instance i) { if (i.get_input()[0] < 8) return 1; return 0;  };
		this->rules.push_back(rule);
	}
	else
	{
		auto rule = [](Instance i) { if (i.get_input()[0] < 8) return 0; return 1; };
		this->rules.push_back(rule);
	}
}

std::vector<int> RuleBasedClassifier::predict(const std::vector<Instance>& instances)
{
	std::vector<int> result{};

	for (const Instance& i : instances)
	{
		for (auto rule : this->rules)
		{
			result.push_back(rule(i));
		}
	}

	return result;
}
