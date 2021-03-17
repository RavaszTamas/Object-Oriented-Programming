#include "KNearestNeighbours.h"
#include "Utils.h"
#include <map>
#include <algorithm>

using namespace std;

KNearestNeighbours::~KNearestNeighbours()
{
	delete this->distance;
}

KNearestNeighbours::KNearestNeighbours(const KNearestNeighbours & knn)
{
	this->k = knn.k;
	this->distance = knn.distance->copy();
}

KNearestNeighbours & KNearestNeighbours::operator=(const KNearestNeighbours & knn)
{
	if (this == &knn)
		return *this;

	delete this->distance;
	this->k = knn.k;
	this->distance = knn.distance->copy();
	return *this;
}

void KNearestNeighbours::train(const std::vector<Instance>& instances)
{
	this->training_set = instances;
	this->get_class_values(instances);
}

std::vector<int> KNearestNeighbours::predict(const std::vector<Instance>& instances)
{
	std::vector<int> outputs{};
	int tt = 0;
	for (const auto& inst : instances)
	{
		std::map<int, int> outputs_per_class{};
		for (auto class_value: this->class_values)
			outputs_per_class.insert(std::pair<int, int>{class_value, 0});

		auto aux = this->training_set;

		// get closest k instances
		std::vector<Instance> closest{};
		int i = 0;
		while (i < this->k)
		{
			int index = this->get_closest_instance_index(aux, inst);
			Instance closest = aux[index];
			int instance_class = closest.get_output();
			auto it = outputs_per_class.find(instance_class);
			if (it != outputs_per_class.end())
				it->second++;

			// remove the instance that was already handled from the dataset
			aux.erase(aux.begin() + index);

			i++;
		}

		int best_class = std::max_element(outputs_per_class.begin(), outputs_per_class.end(),
			[](const auto& a, const auto& b) {return a.second < b.second; })->first;

		outputs.push_back(best_class);
	}
	
	return outputs;
}

void KNearestNeighbours::get_class_values(const std::vector<Instance>& instances)
{
	for (const auto& i : instances)
	{
		auto it = std::find(this->class_values.begin(), this->class_values.end(), i.get_output());
		if (it == this->class_values.end())
			this->class_values.push_back(i.get_output());
	}
}

int KNearestNeighbours::get_closest_instance_index(const std::vector<Instance>& dataset, const Instance & instance) const
{
	int index = 0;
	double min_dist = this->distance->compute(dataset[0].get_input(), instance.get_input());
	for (int i = 1; i < dataset.size(); i++)
	{
		double dist = this->distance->compute(dataset[i].get_input(), instance.get_input());
		if (dist < min_dist)
		{
			min_dist = dist;
			index = i;
		}
	}

	return index;
}
