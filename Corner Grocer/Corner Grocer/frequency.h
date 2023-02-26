#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <string>
#include <map>
using namespace std;

class frequency {//class frequency
private:
	map<string, int> userFrequency; //map userFrequency

public:
	frequency();
	void setMap(string currentWord);
	auto& const getMap(){ return userFrequency;} //returns map

};




#endif 


