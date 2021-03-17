#include "Controller.h"

Controller::Controller()
{
	this->initPatients();
}

Controller::~Controller()
{
	// free memory
	for (Patient& p : this->patients)
	{
		std::vector<MedicalExamination>& exams = p.getExaminations();
		for (auto& ex : exams)
		{
			delete ex.geImage();
		}
	}
}

std::vector<Patient>& Controller::getPatients()
{
	return this->patients;
}

Patient & Controller::getPatientById(int id)
{
	// !!! For this simple example, we will get the patient on a certain position in the vector.
	return this->patients[id];
}

void Controller::initPatients()
{
	// !!! Patients are normally loaded from a database. In this simple example, they will be created here.

	// create the medical examinations: for each image in an examination we must create an ImageProxy
	Image* proxy1 = new ImageProxy{ "mri.jpg" };
	Image* proxy2 = new ImageProxy{ "radiography.jpg" };
	Image* proxy3 = new ImageProxy{ "us.jpg" };

	std::vector<MedicalExamination> examsPatient1{ MedicalExamination{ "2018-03-26", proxy1}, MedicalExamination{ "2018-04-02", proxy2 } };
	std::vector<MedicalExamination> examsPatient2{ MedicalExamination{ "2018-04-08", proxy3 } };

	Patient p1{ "John Doe", examsPatient1 };
	Patient p2{ "Jane Smith", examsPatient2 };
	this->patients.push_back(p1);
	this->patients.push_back(p2);
}
