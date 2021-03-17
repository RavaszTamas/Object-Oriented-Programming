#pragma once
#include <string>
#include <vector>
#include "Image.h"

class MedicalExamination
{
private:
	std::string date;
	Image* img;

public:
	MedicalExamination(const std::string& d, Image* i) : date{ d }, img{ i } {}

	std::string getDate() const { return date; }

	Image* geImage() { return this->img; }
};

class Patient
{
private:
	std::string name;
	std::vector<MedicalExamination> examinations;

public:
	Patient(const std::string& n, std::vector<MedicalExamination>& exams);

	std::string getName() const;
	std::vector<MedicalExamination>& getExaminations();
	~Patient();
};