#include "Utils.h"
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;

std::string trim(const std::string& s)
{
	std::string result(s);
	size_t pos = result.find_first_not_of(" ");
	if (pos != -1)
		result.erase(0, pos);
	pos = result.find_last_not_of(" ");
	if (pos != std::string::npos)
		result.erase(pos + 1);

	return result;
}

vector<string> tokenize(const string& str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

double compute_gaussian_probability_density(double x, double mean, double stddev)
{
	double exponential = exp((-pow(x - mean, 2)) / (2 * pow(stddev, 2)));
	return exponential / (stddev * sqrt(2 * PI));
}

std::vector<Instance> load_data(string filename)
{
	ifstream file{ filename };
	std::vector<Instance> dataset;
	Instance s{};
	int i = 0;
	while (file >> s)
	{
		dataset.push_back(s);
	}
	return dataset;
}

void split_data(std::vector<Instance> dataset, double factor, std::vector<Instance>& train, std::vector<Instance>& test)
{
	int number_instances_for_test = static_cast<int>(factor * dataset.size());
	int number_instances_for_train = static_cast<int>(dataset.size() - number_instances_for_test);

	int i = 0;
	while (i < number_instances_for_train)
		train.push_back(dataset[i++]);
		
	while (i < dataset.size())
		test.push_back(dataset[i++]);
}
