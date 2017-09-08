#ifndef EXPLOSIVE_H
#define EXPLOSIVE_H

#include "Weapon.h"

using namespace std;

class Explosive : public Weapon {

private:
	int maxSplashDamage;
	float maxSplashRange;

	int minSplashDamage;
	float minSplashRange;

public:
	//calculation functions
	float calcSplashDamage(int);

	//overloaded file operations
	bool setFromFile(string);	//accepts file name as input, file name should be weapon name
	bool saveToFile(string);	//accepts file name as input, file name should be weapon name

	//accessor functions

	//mutator functions

};

#endif