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
	string temp;
	int temp2;
	float temp3;

	cin.ignore();

	cout << "Please input the following data: " << endl;
	cout << "Weapon name: "; getline(cin, weaponName); weapon.setWeaponName(weaponName); cout << endl;

	cout << "Fire rate (per minute): "; cin >> temp2; weapon.setFireRate(temp2); cout << endl;

	cout << "Velocity: "; cin >> temp2; weapon.setVelocity(temp2); cout << endl;

	cout << "Headshot multiplier: "; cin >> temp3; weapon.setHeadShotMultiplier(temp3); cout << endl;

	cout << "Move speed multiplier: "; cin >> temp3; weapon.setMoveSpeedMultiplier(temp3); cout << endl;

	cout << "Max damage: "; cin >> temp2; weapon.setMaxDamage(temp2); cout << endl;

	cout << "Minimum falloff range: "; cin >> temp2; weapon.setMaxRange(temp2); cout << endl;

	cout << "Minimum damage: "; cin >> temp2; weapon.setMinDamage(temp2); cout << endl;

	cout << "Maximum falloff range: "; cin >> temp2; weapon.setMinRange(temp2); cout << endl;

	cout << "Short reload time: "; cin >> temp3; weapon.setShortReload(temp3); cout << endl;

	cout << "Long reload time: "; cin >> temp3; weapon.setLongReload(temp3); cout << endl;

	cout << "Magazine size: "; cin >> temp2; weapon.setMagazineSize(temp2); cout << endl;

	cout << "Total reserve ammo: "; cin >> temp2; weapon.setTotalAmmo(temp2); cout << endl;

	weapon.setWeaponType("Infantry");

	weaponName = weaponName.append(".txt");

	weapon.saveToFile(weaponName);

	weapon.display();

}