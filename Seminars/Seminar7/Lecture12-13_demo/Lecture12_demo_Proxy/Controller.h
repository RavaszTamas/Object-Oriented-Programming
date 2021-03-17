#pragma once
#include "Patient.h"
#include <vector>

class Controller
{
private:
	std::vector<Patient> patients;

public:
	Controller();
	~Controller();

	std::vector<Patient>& getPatients();
	Patient& getPatientById(int id);

private:
	void initPatients();
};

