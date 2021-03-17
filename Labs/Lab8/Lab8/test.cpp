#include "test.h"
#include "Repository.h"
#include "Domain.h"
#include "TextFileRepo.h"
#include "Service.h"
#include "Validator.h"
#include <assert.h>
#include <sstream>
#include <string>
#include <cstring>
#include <exception>
#include <fstream>
#include "Utilities.h"
#include "myexceptions.h"
#include "FileManagersMyList.h"

using namespace std;
void testDomain()
{
	Plant plant1{ "1c","2b",3,"4a" };
	Plant plant2{ "5c","6b",7,"8a" };
	Plant plant3;
	assert(plant1.getCodeName() == "1c");
	assert(plant1.getSpecies() == "2b");
	assert(plant1.getAgeInMonths() == 3);
	assert(plant1.getDigitizedScan() == "4a");

	plant2.setCodeName("1");
	plant2.setAgeInMonths(1);
	plant2.setDigitizedScan("1");
	plant2.setSpecies("1");

	assert(plant2.getCodeName() == "1");
	assert(plant2.getSpecies() == "1");
	assert(plant2.getAgeInMonths() == 1);
	assert(plant2.getDigitizedScan() == "1");
	plant3 = plant1;
	assert(plant3 == plant1);
	stringstream buffer;
	string plantString = plant3.toString();
	assert(plantString == "1c 2b 3 4a");

	buffer << plant2;
	buffer >> plant3;
	assert(plant3.toString() == "1 1 1 1");

}

void testRepoMemory()
{
	PlantRepository repo;
	Plant plant1{ "1c","2b",3,"4a" };
	Plant plant2{ "5c","6b",7,"8a" };
	Plant plant2SameButDifferent{ "5c","6asdb",76,"8a578" };

	repo.storeNewPlant(plant1);
	repo.storeNewPlant(plant2);
	try
	{
		repo.storeNewPlant(plant2);//store the same plant again
	}
	catch (exception&)
	{
		assert(true);
	}

	try
	{
		repo.storeNewPlant(plant2SameButDifferent);//store a plant with the same code name
	}
	catch (exception&)
	{
		assert(true);
	}


	try
	{
		repo.updatePlant(Plant{"2","2",2,"2"});
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}

	try
	{
		repo.updatePlant(Plant{ "1c","2",2,"2" });
		assert(true);
	}
	catch (exception&)
	{
		assert(false);
	}


	try
	{
		repo.removePlant(string("1c"));
		assert(true);
	}
	catch (exception&)
	{
		assert(false);
	}

	try
	{
		repo.removePlant(string("1c"));
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
	assert(repo.getNumberOfPlants() == 1);


	assert(repo.getElementByIndex(0) == plant2);
	try
	{
		assert(repo.getElementByIndex(1) == plant2);
	}
	catch (RepositoryException& exception)
	{
		assert(exception.what() == string("Invalid index!"));
		assert(true);
	}

	assert(repo.listAllElements().size() == 1);

	repo.removePlant(string("5c"));
	repo.storeNewPlant(plant1);
	repo.storeNewPlant(plant2);

	assert(repo.listofPlantsBySpecies(string("")).size() == 2);
	assert(repo.listofPlantsBySpecies(string("6b")).size() == 1);

}

void testValidator()
{
	Validator valid;
	try
	{
		valid.ValidateInteger(-1);//Negative invalid value
		assert(false);
	}
	catch (ValidationException& exception)
	{
		assert(exception.what() == string("Invalid integer!"));
		assert(true);
	}
	try
	{
		valid.ValidateInteger(0);//Valid value
		assert(true);
	}
	catch (exception&)
	{
		assert(false);
	}
	try
	{
		valid.ValidateInteger(1);//Valid value
		assert(true);
	}
	catch (exception&)
	{
		assert(false);
	}


	try
	{
		valid.ValidateMode(string("A"));//Valid mode
		assert(true);
	}
	catch (exception&)
	{
		assert(false);
	}

	try
	{
		valid.ValidateMode(string("Z"));//Invalid mode
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}


	ofstream readTestOut("testFile_2535234622");//valid file
	readTestOut << 1;
	try
	{
		valid.ValidateFile(string("testFile_2535234622"));//valid file
		assert(true);

	}
	catch (exception&)
	{
		assert(false);
	}

	try
	{
		valid.ValidateFile(string("Z"));//Invalid non-exsiting file
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
	readTestOut.close();
	remove("testFile_2535234622");

}

void testCheckAllDigts()
{
	assert(CheckIfAllDigits(string("123")) == true);//valid input
	assert(CheckIfAllDigits(string("12s3")) == false);// invalid input but with numbers
	assert(CheckIfAllDigits(string("asda")) == false);// invalid inpt no numbers
	assert(CheckIfAllDigits(string("")) == false);// empty string

}

void testUtilities()
{
	testCheckAllDigts();
	testExtentionGetter();
}

void testExtentionGetter()
{
	assert(getExtention(string("c:\\some long\\path\\with spaces\\myfile.csv")) == "csv");
	assert(getExtention(string("c:\\some long\\path\\with spaces\\myfile.html")) == "html");

}

void testService()
{
	PlantFileRepository repository;
	Validator validator;
	AppController controller{ repository,validator };
	Plant plant1{ "1","2",3,"4" };



	ofstream readTestOut("testFile_2535234622");

	Plant plant2{ "5","6",7,"8" };
	readTestOut << plant1 << endl << plant2 << endl;
	readTestOut.close();
	controller.ApplyFileLocation(string("testFile_2535234622"));
	try 
	{
		assert(controller.listAll().size() == 2);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
	try
	{
		controller.AddNewPlant(string("asd"), string("asd"),1, string("asd"));
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
	try
	{
		controller.DeletePlant(string("1"));
		assert(false);

	}
	catch (exception&)
	{
		assert(true);
	}
	try
	{
		controller.UpdatePlant(string("asd"), string("asd"), 1, string("asd"));
		assert(false);

	}
	catch (exception&)
	{
		assert(true);
	}
	try
	{
		controller.displayChosenPlantClusters();
		assert(false);

	}
	catch (exception&)
	{
		assert(true);
	}
	try
	{
		controller.displayPlantClutersByAgeAndSpecies(string(""), 1);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
	try
	{
		controller.getCurrentPlantByNext();
		assert(false);

	}
	catch (exception&)
	{
		assert(true);
	}	
	try
	{
		controller.saveToUprootList(string("1"));
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}

	controller.SetMode(string("A"));

	assert(controller.listAll().size() == 2);
	Plant plant3 = { "jaj","de",35,"jo" };
	controller.AddNewPlant(string("jaj"),string("de"),3,string("jo"));
	assert(controller.listAll().size() == 3);
	controller.UpdatePlant(string("jaj"), string("de_nagyon"), 3, string(" nagyon_jo"));

	assert(controller.listAll().size() == 3);

	controller.DeletePlant(string("jaj"));

	controller.AddNewPlant(string("jaj"), string("de"), 3, string("jo"));

	controller.SetMode(string("B"));
	try
	{
		controller.saveToUprootList(string(""));
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}

	controller.ApplyMyListLocation(string("murok.csv"));

	assert(controller.getCurrentPlantByNext()== plant1);
	assert(controller.getCurrentPlantByNext() == plant2);
	assert(controller.getCurrentPlantByNext() == plant3);
	assert(controller.getCurrentPlantByNext() == plant1);



	//assert(controller.displayChosenPlantClusters().size() == 0);

	//controller.saveToUprootList(string(""));
	//assert(controller.displayChosenPlantClusters().size() == 1);

	
	try
	{
		controller.saveToUprootList(string("jajoj"));
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}

	try
	{
		controller.saveToUprootList(string("1"));
		assert(true);
	}
	catch (exception&)
	{
		assert(false);
	}

	try
	{
		controller.saveToUprootList(string("jaj"));
		assert(true);
	}
	catch (exception&)
	{
		assert(false);
	}

	assert(controller.displayPlantClutersByAgeAndSpecies(string(""), 100).size() == 3);

	try
	{
		controller.displayPlantClutersByAgeAndSpecies(string(""), -1);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}


	PlantFileRepository repository_plus;
	Validator validator_plus;
	AppController controller_plus{ repository_plus,validator_plus};
	try
	{
		controller_plus.getCurrentPlantByNext();
		assert(false);
	}
	catch (ServiceException& exception)
	{
		assert(exception.what() == string("Invalid mode, no permission!"));
		assert(true);
	}

	remove("testFile_2535234622");
	try
	{
		controller.ApplyFileLocation(string("NewFile"));
		remove("NewFile");
		assert(true);
	}
	catch (exception&)
	{
		assert(false);
	}

	remove("murok.csv");
}

void testTextFileRepoCreateNewFile()
{
	PlantFileRepository repository;
	try
	{
		repository.createFile(string(""));// invalid file name, for empty string
		assert(false);
	}
	catch(RepositoryException& exception)
	{
		assert(exception.what() == string("File can't be created!"));
		assert(true);
	}
	try
	{
		repository.createFile(string("super nice_test_file"));//valid filename
		assert(true);
	}
	catch (RepositoryException&)
	{
		assert(false);
	}
	remove("super nice_test_file");


}

void testTextFileRepo()
{
	PlantFileRepository repository;
	Plant plant1{ "1","2",3,"4" };
	ofstream readTestOut("testFile_2535234622");
	readTestOut.close();
	try
	{
		repository.storeNewPlant(plant1);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}

	try
	{
		repository.updatePlant(plant1);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}

	try
	{
		repository.removePlant(string("asd"));
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}

	try
	{
		repository.setFile(string("ASD"));
		repository.storeNewPlant(plant1);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
	repository.setFile("testFile_2535234622");
	remove("testFile_2535234622");
	/*
	try
	{
		repository.storeNewPlant(plant1);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}*/
	testTextFileRepoCreateNewFile();
}

void testCsvInput()
{
	FileManagerMyList* manager = new CsvFileManagerMyList{ string("testCSV.csv") };
	ofstream testFile("testCSV.csv");
	testFile << "1,1,1,1\n";
	testFile << "a,b,2,c\n";
	testFile << "d,e,3,f\n";
	testFile.close();

	vector<Plant> vectorTestReading = manager->readFile();
	assert(vectorTestReading.size() == 3);

	vectorTestReading.push_back(Plant{"h","i",4,"j"});

	manager->saveToFile(Plant{ "h","i",4,"j" });

	assert(manager->readFile() == vectorTestReading);

	//manager->openFile();

	delete manager;
	remove("testCSV.csv");
}

void testHTMLInput()
{
	FileManagerMyList* manager = new HTMLFileManagerMyList{ string("testhtml.html") };
	ofstream testFile("testhtml.html");
	testFile << "<!DOCTYPE html>\n";
	testFile << "<html>\n";
	testFile << "\t<head>\n";
	testFile << "\t\t<title>TestTable</title>\n";
	testFile << "\t</head>\n";
	testFile << "\t<body>\n";
	testFile << "\t\t<table border=\"1\">\n";
	testFile << "\t\t<tr>\n";
	testFile << "\t\t\t<td>Code Name</td>\n";
	testFile << "\t\t\t<td>Species</td>\n";
	testFile << "\t\t\t<td>Age in months</td>\n";
	testFile << "\t\t\t<td>Digitized Scan</td>\n";
	testFile << "\t\t</tr>\n";
	testFile << "\t\t<tr>\n";
	testFile << "\t\t\t<td>IFAfasdf1</td>\n";
	testFile << "\t\t\t<td>Barack</td>\n";
	testFile << "\t\t\t<td>2</td>\n";
	testFile << "\t\t\t<td>23426rgfsf</td>\n";
	testFile << "\t\t</tr>\n";

	testFile << "\t\t<tr>\n";
	testFile << "\t\t\t<td>jajdejo</td>\n";
	testFile << "\t\t\t<td>ALMA</td>\n";
	testFile << "\t\t\t<td>100</td>\n";
	testFile << "\t\t\t<td>dfg324fdsf</td>\n";
	testFile << "\t\t</tr>\n";



	testFile << "\t\t</table>\n";
	testFile << "\t</body>\n";
	testFile << "</html>\n";

	testFile.close();

	vector<Plant> testPlants = manager->readFile();
	assert(testPlants.size() == 2);

	manager->saveToFile(Plant{ "malac","malac",3,"malac" });

	//manager->openFile();

	remove("testhtml.html");
	delete manager;
}


void testControllerFakeRepo()
{
	FakePlantRepository FakeRepository;
	FakeValidator fakeValidator;

	AppController TestController{FakeRepository,fakeValidator};
	string ValidCodeName = "a";
	string ValidSpecies = "b";
	int ValidAge = 1;
	string ValidScan = "d";

	TestController.SetMode(string("B"));

	try
	{
		TestController.AddNewPlant(ValidCodeName, ValidSpecies, ValidAge, ValidScan);
		assert(false);

	}
	catch (ServiceException&)
	{
		assert(true);
	}


	TestController.ApplyFileLocation(string("fakeFile"));

	try
	{
		TestController.AddNewPlant(ValidCodeName, ValidSpecies, ValidAge, ValidScan);
		assert(false);

	}
	catch (ServiceException&)
	{
		assert(true);
	}

	try
	{
		TestController.DeletePlant(string("a"));
		assert(false);

	}
	catch (ServiceException&)
	{
		assert(true);
	}

	try
	{
		TestController.listAll();
		assert(false);

	}
	catch (ServiceException&)
	{
		assert(true);
	}

	try
	{
		TestController.UpdatePlant(ValidCodeName, ValidSpecies, ValidAge, ValidScan);
		assert(false);

	}
	catch (ServiceException&)
	{
		assert(true);
	}

	TestController.SetMode(string("A"));

	TestController.AddNewPlant(ValidCodeName, ValidSpecies, ValidAge, ValidScan);
	assert(TestController.listAll().size() == 1);
	TestController.DeletePlant(string("a"));
	TestController.AddNewPlant(ValidCodeName, ValidSpecies, ValidAge, ValidScan);
	TestController.UpdatePlant(ValidCodeName, string("b"), 2, string("c"));

	assert(TestController.listAll()[0].getCodeName() == "a");
	assert(TestController.listAll()[0].getSpecies() == "b");
	assert(TestController.listAll()[0].getAgeInMonths() == 2);
	assert(TestController.listAll()[0].getDigitizedScan() == "c");

	TestController.AddNewPlant(string("b"), ValidSpecies, ValidAge, ValidScan);


	try
	{
		TestController.displayPlantClutersByAgeAndSpecies(string(""), 5);
		assert(false);
	}
	catch (ServiceException&)
	{
		assert(true);
	}

	TestController.SetMode(string("B"));
	assert(TestController.displayPlantClutersByAgeAndSpecies(string("b"), 3).size() == 2);
}

void testAll()
{
	/*testDomain();
	testRepoMemory();
	testValidator();
	testUtilities();
	testService();
	testTextFileRepo();
	testCsvInput();
	testHTMLInput();
	testControllerFakeRepo();
	*/
}
