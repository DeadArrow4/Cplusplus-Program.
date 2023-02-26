#include <iostream>
#include <fstream>
#include "Option1.h"

using namespace std;

string userWord;
bool keepERGoin = true;
bool yesORno = true;
string userResponse;


void Option1(frequency& userFrequency) {//refrence of object userFrequencyOriginal
	while (keepERGoin) { //loops while boolean  keepERGoin is true
		yesORno = true;


		cout << endl;
		cout << "Input item or word you would like to search for: ";
		cin >> userWord;//request input
		cout << endl;
		if (userFrequency.getMap().count(userWord) == 1) {//if userWord is in map 
			cout << userWord << " " << userFrequency.getMap().at(userWord) << endl; //orints user word with value in map
			cout << endl;
		}
		else {//invalid item
			cout << "item not avialble." << endl;
			cout << endl;
		}


		cout << "Search again?(yes or no): ";
		cin >> userResponse;//requests input
		cout << endl;
		while (yesORno) {//loops while yesORno is true


			if (userResponse == "no") {//goes back to menu options
				yesORno = false;
				return;
			}
			else if (userResponse == "yes") {//asks for item again
				yesORno = false;
			}
			else {//invalid item
				cout << "Input needs to be yes or no: ";
				cin >> userResponse; //request new input

			}
		}

	}

	return;
}