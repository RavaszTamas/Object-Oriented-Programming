#include "Patient.h"
#include <memory>

Patient::Patient(const std::string & n, std::vector<MedicalExamination>& exams) : name{ n }, examinations{ exams } {}

std::string Patient::getName() const
{
	return this->name;
}

std::vector<MedicalExamination>& Patient::getExaminations()
{
	return this->examinations;
}

Patient::~Patient()
{
}
