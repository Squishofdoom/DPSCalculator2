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

	if (!file.is_open()) {

		return false;
	}

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
	file >> maxSplashDamage;
	file >> maxSplashRange;
	file >> minSplashDamage;
	file >> minSplashRange;

	if (maxSplashDamage > 0) {
		isExplosive = true;
	}

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
	file << maxSplashDamage << endl;
	file << maxSplashRange << endl;
	file << minSplashDamage << endl;
	file << minSplashRange << endl;

	file.close();

	return true;
}

void Weapon::calculate(int range, float accuracy, float headshots) {

	//
	//Calculates damage at range, then calls sub-functions to do other minor calculations
	//

	float damage;

	if (range > maxDamageRange && range < minDamageRange) {

		damage = (maxDamage - ((range - maxDamageRange) / (minDamageRange - maxDamageRange)) * (maxDamage - minDamage));

		damageAtRange = damage;
	}

	else if (range < maxDamageRange) { damageAtRange = maxDamage; }
	else { damageAtRange = minDamage; }


	//
	//Begin calculating other numbers using sub-functions.
	//

	calcIdealDPS();
	calcDPS(accuracy, headshots);
	calcTTK();

}

void Weapon::calcIdealDPS() {
	float fireRatePerSecond = fireRate / 60;
	idealDPS = damageAtRange * fireRatePerSecond;
}

void Weapon::calcDPS(float accuracy, float headshots) {

	accuracy /= 100;
	headshots /= 100;

	float headShotDamage;
	int headShotRate;
	float fireRatePerSecond = fireRate / 60;

	headShotDamage = damageAtRange * headshotMultiplier;
	headShotRate = fireRatePerSecond * headshots;
	headShotRate *= (headShotDamage - damageAtRange);
	
	DPS = (idealDPS + headShotRate) * accuracy;
 }

void Weapon::calcTTK() {

	float nanoweaveDPS = DPS - (DPS * .20);

	TTK = 1000 / DPS;
	nanoweaveTTK = 1000 / nanoweaveDPS;

	BTK = 1000 / damageAtRange;
	nanoweaveBTK = 1000 / (damageAtRange - (damageAtRange * .20));

	BTK = ceil(BTK);
	nanoweaveBTK = ceil(nanoweaveBTK);
}

void Weapon::calcSplash(float miss) {


	

	float splash;

	if (miss > maxSplashRange && miss < minSplashRange) {

		splash = (maxSplashDamage - ((miss - maxSplashRange) / (minSplashRange - maxSplashRange)) * (maxSplashDamage - minSplashDamage));

		splashDamage = splash;
	}

	else if (miss < maxDamageRange) { splashDamage = maxSplashDamage; }
	else { splashDamage = 0; }
}

void Weapon::display() {

	bool val = false;
	string input;
	int accuracy;
	int range = 0;
	float headshots;
	float miss = 0;

	cout << "Input Y if you would like to view the base weapon statistics, or N if you would only like to view calculated statistics." << endl;
	cin >> input;

	if (input == "y" || input == "Y") {

		displayMore();
	}

	if (isExplosive) {
		val = false;
		while (val == false) {
			cout << "How far from your target did your weapon hit? 0 for direct hit: ";
			cin >> miss;
			cout << endl;

			if (miss >= 0) {
				val = true;
			}

			else {
				cout << "That input is not valid. Please input a number greater than 0." << endl;
			}
		}
	}
	
	val = false;
	while (val == false) {
		cout << "Please input average accuracy, in percentage." << endl;
		cin >> accuracy;

		if (accuracy >= 0 && accuracy <= 100) {

			val = true;
		}
		else {

			cout << "That input is not valid. Please input a number between 0 and 100." << endl;
		}
	}

	val = false;
	while (val == false) {
		cout << "Please input range from target, in meters." << endl;
		cin >> range;

		if (range >= 0) {
			val = true;
		}

		else {
			cout << "That input is not valid. Please input a number greater than 0." << endl;
		}
	}

	val = false;
	while (val == false) {
		cout << "Please input headshot rate, in percentage: ";
		cin >> headshots; cout << endl;

		if (headshots >= 0 && headshots <= 100) {

			val = true;
		}
		else {

			cout << "That input is not valid. Please input a number between 0 and 100." << endl;
		}
	}

	calculate(range, accuracy, headshots);
	calcSplash(miss);

	cout << "Damage to target at " << range << " meters is " << damageAtRange << endl;
	cout << "Ideal DPS is " << idealDPS << " DPS" << endl;
	cout << "Actual DPS, accounting for accuracy, and headshots, is " << DPS << endl;
	cout << "Time To Kill: " << TTK << " seconds." << endl;
	cout << "TTK against Nanoweave: " << nanoweaveTTK << " seconds." << endl;
	cout << "Bullets to Kill: " << BTK << " rounds. " << endl;
	cout << "BTK against Nanoweave: " << nanoweaveBTK << " rounds." << endl;
	if (isExplosive) {
		cout << "Splash damage dealt: " << splashDamage << ", " << miss << " meters from the target." << endl;
	}
}

void Weapon::displayMore() {

	cout << "Weapon name: " << weaponName << endl;
	cout << "Damage type: " << weaponType << endl;
	cout << "Fire rate: " << fireRate << " rounds per minute" << endl;
	cout << "Muzzle velocity: " << velocity << " m/s" << endl;
	cout << "Headshot multiplier: " << headshotMultiplier << "x" << endl;
	cout << "Sighted movement speed multiplier: " << moveSpeedMultiplier << "x" << endl;
	cout << "Maximum damage: " << maxDamage << endl;
	cout << "Falloff start range: " << maxDamageRange << "m" << endl;
	cout << "Minimum damage: " << minDamage << endl;
	cout << "Falloff end range: " << minDamageRange << "m" << endl;
	cout << "Partial reload: " << shortReload << "s" << endl;
	cout << "Full reload: " << longReload << "s" << endl;
	cout << "Magazine size: " << magazineSize << endl;
	cout << "Total ammo: " << totalAmmo << endl;

	if (isExplosive) {

		cout << "Maximum splash damage: " << maxSplashDamage << endl;
		cout << "Splash falloff start range: " << maxSplashRange << "m" << endl;
		cout << "Minimum splash damage: " << minSplashDamage << endl;
		cout << "Splash falloff end range: " << minSplashRange << "m" << endl;

	}
}

/////////////////////
//MUTATOR FUNCTIONS//
/////////////////////

void Weapon::setExplosive(bool input) { isExplosive = input; }
void Weapon::setMaxSplashDamage(float input) { maxSplashDamage = input; }
void Weapon::setMaxSplashRange(float input) { maxSplashRange = input; }
void Weapon::setMinSplashDamage(float input) { minSplashDamage = input; }
void Weapon::setMinSplashRange(float input) { minSplashRange = input; }

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

bool Weapon::getExplosive() { return isExplosive; }
float Weapon::getMaxSplashDamage() { return maxSplashDamage; }
float Weapon::getMinSplashDamage() { return minSplashDamage; }
float Weapon::getMaxSplashRange() { return maxSplashRange; }
float Weapon::getMinSplashRange() { return minSplashRange; }

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