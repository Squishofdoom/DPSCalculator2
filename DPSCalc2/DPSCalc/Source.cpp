#include <string>
#include <iostream>

#include "Weapon.h"
#include "Explosive.h"

Weapon weapon;

void menu();
void import();
void manualInput();

int main() {

	menu();

	system("pause");

	return 0;
}

void menu() {

	int input;
	bool loop = true;

	while (loop == true) {
		cout << "Welcome to the Planetside 2 Damage Calculator." << endl;
		cout << "Please choose an option." << endl;
		cout << "1. Import a weapon from file" << endl;
		cout << "2. Manually input a weapon" << endl;
		cout << "3. Exit" << endl;

		cin >> input;

		if (input == 1) {
			loop = false;
			import();
		}
		else if (input == 2) {
			loop = false;
			manualInput();
		}
		else if (input == 3) {
			loop = false;
			return;
		}
		else {
			cout << "That input is not valid. Please try again." << endl;
		}
	}
}

void import() {
	
	string fileName;

	cout << "Please input the file name. File name should be the same as the weapon's name." << endl;

	cin.ignore();
	getline(cin, fileName);

	fileName += ".txt";

	weapon.setFromFile(fileName);

	weapon.display();
}

void manualInput() {

	string weaponName;
	string temp;//storage string
	int temp2;//storage int
	float temp3;//storage float

	cin.ignore();

	cout << "Please input the following data: " << endl;

	//weapon name
	bool val = false;
	do {
		cout << "Weapon name: ";
		getline(cin, weaponName);
		cout << endl;

		val = weapon.check(weaponName);
	} while (val == false);

	weapon.setWeaponName(weaponName);

	//fire rate
	val = false;
	do {
		cout << "Fire rate (per minute): ";
		cin >> temp2;
		cout << endl;

		val = weapon.check(temp2);

	} while (val == false);

	weapon.setFireRate(temp2);

	//velocity
	val = false;
	do {
		cout << "Velocity in Meters Per Second: ";
		cin >> temp2;
		cout << endl;

		val = weapon.check(temp2);

	} while (val == false);

	weapon.setVelocity(temp2);

	//headshot damage
	val = false;
	do {
		cout << "Headshot damage multiplier: ";
		cin >> temp3;
		cout << endl;

		val = weapon.check(temp3);

	} while (val == false);

	weapon.setVelocity(temp3);

	//movespeed multiplier
	val = false;
	do {
		cout << "Move speed multiplier while scoped: ";
		cin >> temp3;
		cout << endl;

		val = weapon.check(temp3);

	} while (val == false);

	weapon.setMoveSpeedMultiplier(temp3);

	//maximum damage
	val = false;
	do {
		cout << "Maximum damage: ";
		cin >> temp2;
		cout << endl;

		val = weapon.check(temp2);

	} while (val == false);

	weapon.setMaxDamage(temp2);
	
	//falloff start range
	val = false;
	do {
		cout << "Falloff start range: ";
		cin >> temp2;
		cout << endl;

		val = weapon.check(temp2);

	} while (val == false);

	weapon.setMaxRange(temp2);

	//minimum damage
	val = false;
	do {
		cout << "Minimum damage: ";
		cin >> temp2;
		cout << endl;

		val = weapon.check(temp2);

	} while (val == false);

	weapon.setMinDamage(temp2);

	//end falloff range
	val = false;
	do {
		cout << "Falloff end range: ";
		cin >> temp2;
		cout << endl;

		val = weapon.check(temp2);

	} while (val == false);

	weapon.setMinRange(temp2);

	//short reload time
	val = false;
	do {
		cout << "Short(partial) reload time: ";
		cin >> temp3;
		cout << endl;

		val = weapon.check(temp3);

	} while (val == false);

	weapon.setShortReload(temp3);

	//long reload time
	val = false;
	do {
		cout << "Long(full) reload time: ";
		cin >> temp3;
		cout << endl;

		val = weapon.check(temp3);

	} while (val == false);

	weapon.setLongReload(temp3);

	//magazine size:
	val = false;
	do {
		cout << "Magazine size: ";
		cin >> temp2;
		cout << endl;

		val = weapon.check(temp2);

	} while (val == false);

	weapon.setMagazineSize(temp2);

	//reserve ammo
	val = false;
	do {
		cout << "Total ammo, NOT including currently loaded: ";
		cin >> temp2;
		cout << endl;

		val = weapon.check(temp2);

	} while (val == false);

	weapon.setTotalAmmo(temp2);


		cout << "Weapon type(\"infantry\" for infantry and non-planetside weapons: ";
		cin >> temp;
		cout << endl;

		if (temp == "infantry" || "Infantry") {

			weapon.setWeaponType("Infantry");
		}

		else {

			weapon.setWeaponType(temp);

		}

	//append .txt to the end of weapon name, to it can be fed to the save to file as the filename, then saves it to file
	weaponName = weaponName.append(".txt");
	weapon.saveToFile(weaponName);

	//display weapon statistics
	weapon.display();

}
