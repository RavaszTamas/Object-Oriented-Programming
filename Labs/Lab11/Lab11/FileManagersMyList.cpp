#include "FileManagersMyList.h"
#include <fstream>
#include "Utilities.h"
#include <sstream>
#include "myexceptions.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

CsvFileManagerMyList::CsvFileManagerMyList(std::string newFileName) :FileManagerMyList{ newFileName }
{

}

void CsvFileManagerMyList::openFile()
{
	//stringstream stream;
	//stream << "C:\\Program Files (x86)\\Notepad++\\notepad++.exe" << this->filename;
	//system(stream.str().c_str());
	//system(this->filename.c_str());
	string file = this->filename.c_str();
	//LPCSTR command = (LPCSTR)"open";
	//ShellExecuteA(NULL, command, file ,NULL, NULL , SW_SHOWNORMAL);
	file = "\"" + file;
	file = file + "\"";

	system(file.c_str());

}

std::vector<Plant> CsvFileManagerMyList::readFile()
{
	ifstream inputStream{ this->filename };
	vector<Plant> returnPlants;
	stringstream stringStreamForInput;
	string CodeName;
	string DigitizedScan;
	string Months;
	string Species;
	Plant auxilliaryInputPlant{};
	while (inputStream.good())
	{
		getline(inputStream, CodeName, ',');
		getline(inputStream, Species, ',');
		getline(inputStream, Months, ',');
		getline(inputStream, DigitizedScan, '\n');
		if (CodeName != "")
		{
			stringStreamForInput << CodeName << " " << Species << " " << Months << " " << DigitizedScan << endl;
			stringStreamForInput >> auxilliaryInputPlant;
			returnPlants.push_back(auxilliaryInputPlant);
		}	
	}
	inputStream.close();
	return returnPlants;

}

void CsvFileManagerMyList::saveToFile(Plant elementToSave)
{
	{
		vector<Plant> currentElemets = this->readFile();
		if (find(currentElemets.begin(), currentElemets.end(), elementToSave) != currentElemets.end())
			throw RepositoryException("Plant is already in the uproot list!");

	}

	ofstream outPutStream{ this->filename, ios::app};

	if (!outPutStream)
	{
		throw RepositoryException{"Can't open the file for writing, mylist"};
	}
	
	stringstream outPutData;
	outPutData << elementToSave.getCodeName() << "," << elementToSave.getSpecies() << "," << elementToSave.getAgeInMonths() << "," << elementToSave.getDigitizedScan() << endl;

	outPutStream << outPutData.str();

	outPutStream.close();

}

void CsvFileManagerMyList::removeFromFile(Plant elementToRemove)
{
	
	vector<Plant> currentElemets = this->readFile();
	auto iter = find(currentElemets.begin(), currentElemets.end(), elementToRemove);
	if(iter == currentElemets.end())
		throw RepositoryException("Plant not in the uproot list!");

	currentElemets.erase(iter);
	

	ofstream outPutStream{ this->filename };

	if (!outPutStream)
	{
		throw RepositoryException{ "Can't open the file for writing, mylist" };
	}

	for (auto iterator : currentElemets)
	{
		outPutStream << iterator.getCodeName() << "," << iterator.getSpecies() << "," << iterator.getAgeInMonths() << "," << iterator.getDigitizedScan() << endl;
	}

	outPutStream.close();
}

FileManagerMyList::FileManagerMyList(std::string newFileName) :filename{ newFileName }
{
}


std::string HTMLFileManagerMyList::HTMLTableRow(Plant & PlantToConvert)
{
	stringstream cellToReturn;
	cellToReturn << "\t\t<tr>\n";
	cellToReturn << "\t\t\t<td>";
	cellToReturn << PlantToConvert.getCodeName();
	cellToReturn << "</td>\n";
	cellToReturn << "\t\t\t<td>";
	cellToReturn << PlantToConvert.getSpecies();
	cellToReturn << "</td>\n";
	cellToReturn << "\t\t\t<td>";
	cellToReturn << PlantToConvert.getAgeInMonths();
	cellToReturn << "</td>\n";
	cellToReturn << "\t\t\t<td>";
	cellToReturn << PlantToConvert.getDigitizedScan();
	cellToReturn << "</td>\n";
	return cellToReturn.str();


}

HTMLFileManagerMyList::HTMLFileManagerMyList(std::string newFileName) : FileManagerMyList{ newFileName }
{
}

void HTMLFileManagerMyList::openFile()
{

	string file = this->filename.c_str();
	//LPCSTR command = (LPCSTR)"open";
	//ShellExecuteA(NULL, command, file, NULL, NULL, SW_SHOWNORMAL);
	file = "\"" + file;
	file = file + "\"";

	system(file.c_str());

}

std::vector<Plant> HTMLFileManagerMyList::readFile()
{
	vector<Plant> vectorOfReadElements;

	ifstream inputFile{ this->filename };

	string InputLine;
	string CodeName;
	string Species;
	string AgeInMonths;
	string DigitzedScan;

	inputFile >> InputLine;
	while (InputLine != "<table" && inputFile.good())
	{
		inputFile >> InputLine;
	}

	while (InputLine != "</tr>" && inputFile.good())
	{
		inputFile >> InputLine;
	}

	while (InputLine != "</table>" && inputFile.good())
	{
		if (InputLine == "<tr>")
		{
			inputFile >> CodeName;
			inputFile >> Species;
			inputFile >> AgeInMonths;
			inputFile >> DigitzedScan;
			CodeName.erase(CodeName.begin(), CodeName.begin() + 4);
			CodeName.erase(CodeName.end()-5, CodeName.end());
			Species.erase(Species.begin(), Species.begin() + 4);
			Species.erase(Species.end() - 5, Species.end());
			AgeInMonths.erase(AgeInMonths.begin(), AgeInMonths.begin() + 4);
			AgeInMonths.erase(AgeInMonths.end() - 5, AgeInMonths.end());
			DigitzedScan.erase(DigitzedScan.begin(), DigitzedScan.begin() + 4);
			DigitzedScan.erase(DigitzedScan.end() - 5, DigitzedScan.end());
			vectorOfReadElements.push_back(Plant{CodeName,Species,stoi(AgeInMonths),DigitzedScan});
		}
		inputFile >> InputLine;
	}
	inputFile.close();
	return vectorOfReadElements;
}

void HTMLFileManagerMyList::saveToFile(Plant elementToSave)
{
	vector<Plant> currentElemets = this->readFile();

	if (find(currentElemets.begin(), currentElemets.end(), elementToSave) != currentElemets.end())
		throw RepositoryException("Plant is already in the uproot list!");

	currentElemets.push_back(elementToSave);


	ofstream outPutFile{ this->filename };
	outPutFile << "<!DOCTYPE html>\n";
	outPutFile << "<html>\n";
	outPutFile << "\t<head>\n";
	outPutFile << "\t\t<title>TestTable</title>\n";
	outPutFile << "\t</head>\n";
	outPutFile << "\t<body>\n";
	outPutFile << "\t\t<table border=\"1\">\n";
	outPutFile << "\t\t<tr>\n";
	outPutFile << "\t\t\t<td>Code Name</td>\n";
	outPutFile << "\t\t\t<td>Species</td>\n";
	outPutFile << "\t\t\t<td>Age in months</td>\n";
	outPutFile << "\t\t\t<td>Digitized Scan</td>\n";
	outPutFile << "\t\t</tr>\n";

	for (auto iterator : currentElemets)
	{
		outPutFile << this->HTMLTableRow(iterator);
	}

	outPutFile << "\t\t</table>\n";
	outPutFile << "\t</body>\n";
	outPutFile << "</html>\n";
	outPutFile.close();

}

void HTMLFileManagerMyList::removeFromFile(Plant elementToRemove)
{
	vector<Plant> currentElemets = this->readFile();
	auto iter = find(currentElemets.begin(), currentElemets.end(), elementToRemove);
	if (iter == currentElemets.end())
		throw RepositoryException("Plant not in the uproot list!");

	currentElemets.erase(iter);


	ofstream outPutFile{ this->filename };
	outPutFile << "<!DOCTYPE html>\n";
	outPutFile << "<html>\n";
	outPutFile << "\t<head>\n";
	outPutFile << "\t\t<title>TestTable</title>\n";
	outPutFile << "\t</head>\n";
	outPutFile << "\t<body>\n";
	outPutFile << "\t\t<table border=\"1\">\n";
	outPutFile << "\t\t<tr>\n";
	outPutFile << "\t\t\t<td>Code Name</td>\n";
	outPutFile << "\t\t\t<td>Species</td>\n";
	outPutFile << "\t\t\t<td>Age in months</td>\n";
	outPutFile << "\t\t\t<td>Digitized Scan</td>\n";
	outPutFile << "\t\t</tr>\n";

	for (auto iterator : currentElemets)
	{
		outPutFile << this->HTMLTableRow(iterator);
	}

	outPutFile << "\t\t</table>\n";
	outPutFile << "\t</body>\n";
	outPutFile << "</html>\n";
	outPutFile.close();
}

MemoryMyList::MemoryMyList(std::string newFileName) : FileManagerMyList{ newFileName }
{
}

void MemoryMyList::openFile()
{
}

std::vector<Plant> MemoryMyList::readFile()
{

	return mylist;
}

void MemoryMyList::saveToFile(Plant elementToSave)
{
	auto iter = find(mylist.begin(), mylist.end(), elementToSave);
	if (iter != mylist.end())
		throw RepositoryException("Plant is in the uproot list!");

	mylist.push_back(elementToSave);
}

void MemoryMyList::removeFromFile(Plant elementToRemove)
{
	//vector<Plant> currentElemets = this->readFile();
	auto iter = find(mylist.begin(), mylist.end(), elementToRemove);
	if (iter == mylist.end())
		throw RepositoryException("Plant not in the uproot list!");

	mylist.erase(iter);

}
