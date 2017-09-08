#include <fstream>

#include "Explosive.h"

float Explosive::calcSplashDamage(int range) {

	float damage;

	if (range >= maxSplashRange && range <= minSplashRange) {

		damage = maxSplashDamage - (range - maxSplashRange) / (minSplashRange - maxSplashRange) * (maxSplashDamage - minSplashDamage);

		return damage;
	}
	else if (range < minSplashRange) {

		return 0;
	}

	else return maxSplashDamage;
}

bool Explosive::setFromFile(string fileName) {

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
	file >> weaponName;
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

	/*Debug console outputs
	cout << maxDamage << endl;
	cout << minDamage << endl;
	*/

	file.close();

	return true;

}

bool Explosive::saveToFile(string fileName) {

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