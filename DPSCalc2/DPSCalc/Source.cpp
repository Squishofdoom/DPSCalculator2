#include <string>
#include <iostream>

#include "Weapon.h"

int main() {

	Weapon weapon;

	weapon.setFromFile("debug.txt");
	weapon.saveToFile("debug2.txt");

	int range = 12;
	float damage;

	damage = weapon.calcDamageAtRange(range);

	cout << damage << endl;
}