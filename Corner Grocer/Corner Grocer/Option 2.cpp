#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "Option2.h" 


using namespace std;







void Option2(frequency& userFrequency) {//refrence of object userFrequencyOriginal


	for (map<string, int>::iterator it = userFrequency.getMap().begin(); it != userFrequency.getMap().end(); ++it) {//iterates from begining of map to end
		cout << it->first << " " << it->second << endl;//prints key and value of map
	}
	






}