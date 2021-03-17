#pragma once
#include <vector>

class Distance
{
public:
	virtual double compute(const std::vector<double>& v1, const std::vector<double>& v2) const = 0;
	virtual Distance* copy() = 0;
	virtual ~Distance() {}
};

class EuclideanDistance : public Distance
{
	double compute(const std::vector<double>& v1, const std::vector<double>& v2) const override;
	EuclideanDistance* copy() override;
};

class ManhattanDistance : public Distance
{
	double compute(const std::vector<double>& v1, const std::vector<double>& v2) const override;
	ManhattanDistance* copy() override;
};