#include <iostream>
#include <fstream>
#include "Option1.h"
#include "Option2.h"
#include "Option3.h"
#include "frequency.h"
#include "nCharString.h"



using namespace std;

void MenuOptions() { //prints out menu options
	cout << endl;
	cout << nCharString(27, '-') << endl;
	cout << "Option 1:" << endl;	
	cout << "Search for specific item" << endl;
	cout << nCharString(27, '-') << endl;
	cout << "Option 2:" << endl;
	cout << "List of all items" << endl;
	cout << nCharString(27, '-') << endl;
	cout << "Option 3:" << endl;
	cout << "Histogram" << endl;
	cout << nCharString(27, '-') << endl;
	cout << "Option 4:" << endl;
	cout << "Quit" << endl;
	cout << nCharString(27, '-') << endl;
	cout << endl;
	cout << "Choose a number 1-4: ";
}

struct excpt : std::exception { // exception thrown
	const char* what() const noexcept { return "Invalid Input, needs to be a number between 1-4: "; }
};






int main() {
	ifstream inFile; //input file
	ofstream outFile; //output file

	int UserInput = 0;
	string userWord;
	string currentWord;
	
	frequency UserFrequencyOriginal;//object userFrequencyOriginal

	inFile.open("CS210_Project_Three_Input_File.txt");//opens file for reading
	outFile.open("frequency.dat");//opens file for writing

	if (!inFile.is_open()) {//checks if infile is open
		cout << "Could Not Open File." << endl;
	}
	while (!inFile.eof()) {//loops until end of file

		inFile >> currentWord; //sets current word to current word in file

		if (!inFile.fail()) { // if file doesn't fail setMap function
			UserFrequencyOriginal.setMap(currentWord);
		}

	}
	
	if (!outFile.is_open()) { //checks if outFiles is open
		cout << "Could not Open outFile"<< endl;
	}
	else { //writes map to out file
		for (map<string, int>::iterator it = UserFrequencyOriginal.getMap().begin(); it != UserFrequencyOriginal.getMap().end(); ++it) {
			outFile << it->first << " " << it->second << endl;
		}
	}


	inFile.close(); //closes in file
	outFile.close(); // closes out file

	MenuOptions(); //function MenuOptions
	cin >> UserInput;//request input

	while (UserInput != 4) {//loops until user inputs 4

		try { //exception catching
			if (cin.fail()) {//if input is not correct throws excepion
				throw excpt();
			}

			else if (UserInput == 1) { // if user input is 1 
				Option1(UserFrequencyOriginal);//calls function option1
				MenuOptions();
				cin >> UserInput;//requests new input
				cout << endl;
			}
			else if (UserInput == 2) {//if user input is 2
				Option2(UserFrequencyOriginal);//calls function option2
				MenuOptions();
				cin >> UserInput;//request new input
				cout << endl;
			}
			else if (UserInput == 3) {//if user input is 3
				Option3(UserFrequencyOriginal);//calls function option3
				MenuOptions();
				cin >> UserInput;//requests new input
				cout << endl;
			}
			else if (UserInput == 4) { //breaks if user input is 4
				break;
			}
			
			else {//requests new input if any number but 1-4 is inputted
				cout << endl;
				cout << "Only numbers 1-4 can be chosen: " ;
				cin.clear();
				cin >> UserInput;
			}
		}
		catch (std::exception& excpt) { //catches exception
			cout << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << excpt.what();
			cin >> UserInput;//requests new input
		}


	}





	return 0;
}