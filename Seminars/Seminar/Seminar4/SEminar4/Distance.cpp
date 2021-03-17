#include "Distance.h"
#include <algorithm>
#include <numeric>

double EuclideanDistance::compute(const std::vector<double>& v1, const std::vector<double>& v2) const
{
	std::vector<double>	aux;

	std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(aux), [](double e1, double e2) {return pow((e1 - e2), 2); });
	aux.shrink_to_fit();

	return  sqrt(accumulate(aux.begin(), aux.end(), 0.0));
}

EuclideanDistance * EuclideanDistance::copy()
{
	EuclideanDistance* dist = dynamic_cast<EuclideanDistance*>(this);
	if (dist != nullptr)
		return new EuclideanDistance{ *dist };
	else return nullptr;
}

double ManhattanDistance::compute(const std::vector<double>& v1, const std::vector<double>& v2) const
{
	std::vector<double>	aux;

	std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(aux), [](double e1, double e2) {return abs(e1 - e2); });
	aux.shrink_to_fit();

	return  sqrt(accumulate(aux.begin(), aux.end(), 0.0));
}

ManhattanDistance * ManhattanDistance::copy()
{
	ManhattanDistance* dist = dynamic_cast<ManhattanDistance*>(this);
	if (dist != nullptr)
		return new ManhattanDistance{ *dist };
	else return nullptr;
}
