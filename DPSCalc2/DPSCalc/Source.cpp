#include <string>
#include <iostream>

#include "Weapon.h"
#include "Explosive.h"

int main() {

	Weapon weapon;
	string junk;

	weapon.setFromFile("debug.txt");
	weapon.saveToFile("debug2.txt");

	weapon.display();

	system("pause");

	return 0;
}