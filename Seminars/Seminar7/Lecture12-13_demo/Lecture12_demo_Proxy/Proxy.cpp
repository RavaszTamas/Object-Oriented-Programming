#include "Proxy.h"
#include <qdebug.h>

using namespace std;

Proxy::Proxy(Controller& c, QWidget *parent) : QMainWindow(parent), ctrl{ c }
{
	ui.setupUi(this);

	// connect signals and slots
	QObject::connect(this->ui.patientsList, &QListWidget::itemSelectionChanged, this, [this]() {this->patientsListItemChanged(); });
	QObject::connect(this->ui.examsList, &QListWidget::itemSelectionChanged, this, [this]() {this->imagesListItemChanged(); });

	// populate patients list
	this->populatePatientsList();
}

void Proxy::populatePatientsList()
{
	for (Patient& p : this->ctrl.getPatients())
		this->ui.patientsList->addItem(QString::fromStdString(p.getName()));
}

void Proxy::populateStudyList(Patient & p)
{
	this->ui.examsList->clear();

	std::vector<MedicalExamination>& examinations = p.getExaminations();
	for (const auto& e : examinations)
		this->ui.examsList->addItem(QString::fromStdString(e.getDate()));
}

int Proxy::getListSelectedIndex(QListWidget* listWidget)
{
	if (listWidget->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = listWidget->selectionModel()->selectedIndexes();
	if (index.size() == 0)
		return -1;

	int idx = index.at(0).row();
	return idx;
}

Patient& Proxy::getCurrentPatient()
{
	int idx = this->getListSelectedIndex(this->ui.patientsList);
	if (idx == -1)
		throw std::runtime_error{ "No patient selected" };

	Patient& p = this->ctrl.getPatientById(idx);
	return p;
}

void Proxy::patientsListItemChanged()
{
	Patient& p = this->getCurrentPatient();
	this->populateStudyList(p);
}

void Proxy::imagesListItemChanged()
{
	Patient& p = getCurrentPatient();

	int idx = this->getListSelectedIndex(this->ui.examsList);
	if (idx == -1)
		return;

	auto& exams = p.getExaminations();
	// the user does not know whether it is the resource or the proxy that is being accessed
	ui.photo->setPixmap(exams[idx].geImage()->getData());
}
