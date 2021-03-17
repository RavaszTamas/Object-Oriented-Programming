#include "Instance.h"
#include <string>
#include <sstream>
#include "Utils.h"

using namespace std;

std::istream & operator>>(std::istream & is, Instance & instance)
{
	instance.reset_instance();

	string s{};
	getline(is, s);

	vector<string> tokens = tokenize(s, ',');
	if (tokens.size() == 0)
		return is;
	for (int i = 0; i < tokens.size() - 1; i++)
		instance.input.push_back(stod(tokens[i]));

	instance.output = stoi(tokens[tokens.size() - 1]);

	return is;
}

void Instance::reset_instance()
{
	this->input.clear();
	this->output = -1;
}
