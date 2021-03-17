#pragma once
#include <string>
#include <vector>
#include "Instance.h"

# define PI 3.14159265358979323846

/*
	Trims leading and trailing spaces from a string.
	Input: s - string
	Output: a string, with no leading and trailing spaces.
*/
std::string trim(const std::string& s);

/*
	Tokenizes a string.
	Input:	str - the string to be tokenized.
	delimiter - char - the delimiter used for tokenization
	Output: a vector of strings, containing the tokens
*/
std::vector<std::string> tokenize(const std::string& str, char delimiter);

double compute_gaussian_probability_density(double x, double mean, double stddev);

std::vector<Instance> load_data(std::string filename);

void split_data(std::vector<Instance> dataset, double factor, std::vector<Instance>& train, std::vector<Instance>& test);