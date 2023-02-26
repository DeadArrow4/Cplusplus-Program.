#include "frequency.h"


frequency::frequency() {//default constructor
	userFrequency = {};
}


void frequency::setMap(string currentWord) { //mutator
	if (userFrequency.count(currentWord) == 0) { //if map doesn't have current word 
		userFrequency.emplace(currentWord, 1);//adds key of current word and sets value to 1
	}
	else if (userFrequency.count(currentWord) == 1) {//if map has current word
		userFrequency.at(currentWord)++;//adds 1 to value of current word
	}
}



