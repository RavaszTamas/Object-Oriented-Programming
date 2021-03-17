#pragma once
#include <vector>
#include <iostream>

class Instance
{
private:
	std::vector<double> input;
	int output = -1;

public:
	std::vector<double> get_input() const { return input; }
	int get_output() const { return output; }
	int get_number_of_attributes() const { return static_cast<int>(input.size()); }

	friend std::istream& operator>>(std::istream& is, Instance& instane);

private:
	void reset_instance();
};

