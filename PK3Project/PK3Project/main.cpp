#include "stdafx.h"
#include "filesSupport.h"
#include "Interface.h"
#include "ListOfComplaints.h"

#include <iostream>
#include <string>
#include <cstdlib>


const int defaultParam = 1;
const std::string configFile = "config.txt";

void setParams(const int&, char**, std::string&, std::string&);

int main(int argc, char** argv) {
	
	system("title System Obslugi Reklamacji");

	std::string inFileName = "";
	std::string outFileName = "";

	if (argc > defaultParam) { //jeżeli podano jakieś parametry wywołania to zostaną one sprawdzone przez funkcję setParams(...)
		
		setParams(argc, argv, inFileName, outFileName);
	}
	else { //jeżeli nie podano parametrów wywołania to zostanie użyty domyślny plik
		
		inFileName = configFile;
		outFileName = configFile;
	}

	ListOfComplaints list;

	filesSupport file(inFileName, outFileName); 
	
	file.readFromFile(list);

	while(Interface::menu(list, file)) {

		system("cls");		

	}

	file.saveToFile(list);


    return 0;
}

void setParams(const int &argc, char** argv, std::string &inFileName, std::string &outFileName) {

	if (argc != 5) {

		std::cout << "Nieprawidlowa liczba parametrow wywolania programu!\nZostanie uzyty domyslny plik konfiguracyjny.\n\n";

		system("pause");

		return;
	}

	if (argv[1][0] != '-' || argv[1][1] != 'i' || argv[3][0] != '-' || argv[3][1] != 'o') {

		std::cout << "Nieprawidlowe przelaczniki!\nZostanie uzyty plik domyslny.\n\n";

		system("pause");

		return;

	}

	inFileName = argv[2];
	outFileName = argv[4];

}