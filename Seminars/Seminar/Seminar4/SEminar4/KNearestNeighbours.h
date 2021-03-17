#pragma once
#include "Classifier.h"
#include "Distance.h"

class KNearestNeighbours : public Classifier
{
private:
	int k;
	Distance* distance;
	std::vector<int> class_values; // optional - one version of implementation
	std::vector<Instance> training_set;
	~KNearestNeighbours();

public:
	KNearestNeighbours(int _k = 1, Distance* dist = new EuclideanDistance{}) noexcept : k{ _k }, distance{ dist->copy() } {}
	KNearestNeighbours(const KNearestNeighbours& knn);
	KNearestNeighbours& operator=(const KNearestNeighbours& knn);

	void train(const std::vector<Instance>& instances) override;
	std::vector<int> predict(const std::vector<Instance>& instances) override;

private:
	// stores all possible class values in the data member class_values
	void get_class_values(const std::vector<Instance>& instances);

	int get_closest_instance_index(const std::vector<Instance>& dataset, const Instance& instance) const;
};

