#include <string>
#include <fstream>
#include <iostream>
#include <istream>

#include "Weapon.h"

using namespace std;

bool Weapon::setFromFile(string fileName){

	ifstream file;	//input file
	string temp;	//temp variable to store input data before output, for debugging purposes

	//appends the data folder to the name of the file, so it accesses the right place
	fileName = "Data/" + fileName;

	file.open(fileName);

	/* Debug console output

	while (file >> temp) {

		cout << temp << endl;
	}
	*/

	file >> weaponType;
	getline(file, temp);//eats the end-of-line from the previous cin
	getline(file, weaponName);//gets the actual line once the end-of-line has been taken
	file >> fireRate;
	file >> velocity;
	file >> headshotMultiplier;
	file >> moveSpeedMultiplier;
	file >> maxDamage;
	file >> maxDamageRange;
	file >> minDamage;
	file >> minDamageRange;
	file >> shortReload;
	file >> longReload;
	file >> magazineSize;
	file >> totalAmmo;

	/*Debug console outputs
	cout << maxDamage << endl;
	cout << minDamage << endl;
	*/

	file.close();

	return true;

}

bool Weapon::saveToFile(string fileName) {

	ofstream file;

	fileName = "Data/" + fileName;

	file.open(fileName);

	file << weaponType << endl;
	file << weaponName << endl;
	file << fireRate << endl;
	file << velocity << endl;
	file << headshotMultiplier << endl;
	file << moveSpeedMultiplier << endl;
	file << maxDamage << endl;
	file << maxDamageRange << endl;
	file << minDamage << endl;
	file << minDamageRange << endl;
	file << shortReload << endl;
	file << longReload << endl;
	file << magazineSize << endl;
	file << totalAmmo << endl;

	file.close();

	return true;
}

void Weapon::calculate(int range, float accuracy) {

	//
	//Calculates damage at range, then calls sub-functions to do other minor calculations
	//

	float damage;

	if (range > maxDamageRange) {

		damage = (maxDamage - (range - maxDamageRange) / (minDamageRange - maxDamageRange) * (maxDamage - minDamage));

		damageAtRange = damage;
	}

	else damageAtRange = maxDamage;


	//
	//Begin calculating other numbers using sub-functions.
	//

	calcIdealDPS();
	calcDPS(accuracy);
	calcTTK();

}

void Weapon::calcIdealDPS() {
	float fireRatePerSecond = fireRate / 60;
	idealDPS = damageAtRange * fireRatePerSecond;
}

void Weapon::calcDPS(float accuracy) {

	accuracy = accuracy / 100;

	DPS = idealDPS * accuracy;
 }

void Weapon::calcTTK() {

	float nanoweaveDPS = DPS - (DPS * .20);

	TTK = 1000 / DPS;
	nanoweaveTTK = 1000 / nanoweaveDPS;
}

void Weapon::display() {

	int accuracy;
	int range;

	cout << "Please input average accuracy, in percentage." << endl;
	cin >> accuracy;

	cout << "Please input range from target, in meters." << endl;
	cin >> range;

	calculate(range, accuracy);

	cout << "Damage to target at " << range << " meters is " << damageAtRange << endl;
	cout << "Ideal DPS is " << idealDPS << " DPS" << endl;
	cout << "Actual DPS, accounting for accuracy, is " << DPS << endl;
	cout << "Time To Kill: " << TTK << " seconds." << endl;
	cout << "TTK against Nanoweave: " << nanoweaveTTK << " seconds." << endl;
}

/////////////////////
//MUTATOR FUNCTIONS//
/////////////////////

void Weapon::setWeaponType(string input) { weaponType = input; }
void Weapon::setWeaponName(string input){	weaponName = input;}
void Weapon::setFireRate(int input){fireRate = input;}
void Weapon::setVelocity(int input){velocity = input;}
void Weapon::setHeadShotMultiplier(float input){headshotMultiplier = input;}
void Weapon::setMoveSpeedMultiplier(float input){moveSpeedMultiplier = input;}
void Weapon::setMaxDamage(int input){maxDamage = input;}
void Weapon::setMaxRange(int input){maxDamageRange = input;}
void Weapon::setMinDamage(int input){minDamage = input;}
void Weapon::setMinRange(int input){minDamageRange = input;}
void Weapon::setShortReload(float input){shortReload = input;}
void Weapon::setLongReload(float input){longReload = input;}
void Weapon::setMagazineSize(int input){magazineSize = input;}
void Weapon::setTotalAmmo(int input){totalAmmo = input;}

//////////////////////
//ACCESSOR FUNCTIONS//
//////////////////////

string Weapon::getWeaponType() { return weaponType; }
string Weapon::getWeaponName() { return weaponName ; }
int Weapon::getFireRate() { return fireRate ; }
int Weapon::getVelocity() { return velocity ; }
float Weapon::getHeadShotMultiplier() { return headshotMultiplier ; }
float Weapon::getMoveSpeedMultiplier() { return moveSpeedMultiplier ; }
int Weapon::getMaxDamage() { return maxDamage ; }
int Weapon::getMaxRange() { return maxDamageRange ; }
int Weapon::getMinDamage() { return minDamage ; }
int Weapon::getMinRange() { return minDamageRange ; }
float Weapon::getShortReload() { return shortReload ; }
float Weapon::getLongReload() { return longReload ; }
int Weapon::getMagazineSize() { return magazineSize ; }
int Weapon::getTotalAmmo() { return totalAmmo ; }

///////////////////////
//VALIDATOR FUNCTIONS//
///////////////////////

bool Weapon::check(string input) {


	
		if (input == "" || input == " ") {
			cout << "That input is incorrect. Please try again." << endl;
			return false;
		}
		else{

			return true;
		}
	
}

bool Weapon::check(int input) {



	if (input <= 0) {
		cout << "That input is incorrect. Please try again." << endl;
		return false;
	}
	else {

		return true;
	}

}

bool Weapon::check(float input) {



	if (input <= 0) {
		cout << "That input is incorrect. Please try again." << endl;
		return false;
	}
	else {

		return true;
	}

}