#include "Utilities.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool CheckIfAllDigits(string & stringtToCheck)
{
	if (stringtToCheck.size() == 0)
		return false;
	for (int i = 0; i < stringtToCheck.size(); ++i)
	{
		if (!isdigit(stringtToCheck[i]))
			return false;
	}
	return true;
}

std::vector<std::string> tokenize(const std::string & str, char delimiter)
{

	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

std::string getExtention(std::string input)
{
	string result;
	stringstream stream{ input };
	while (getline(stream, result, '.'));

	return result;
}
