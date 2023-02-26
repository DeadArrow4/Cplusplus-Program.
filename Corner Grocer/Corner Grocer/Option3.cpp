#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "Option3.h" 
#include "nCharString.h"

using namespace std;







void Option3(frequency& userFrequency) {//refrence of object userFrequencyOriginal
	
	for (map<string, int>::iterator it = userFrequency.getMap().begin(); it != userFrequency.getMap().end(); ++it) {//iterates from begining of map to end
		cout << it->first << " " << nCharString(it->second, '*') << endl;////prints key and value of map using nCharString to make histogram
	}



}