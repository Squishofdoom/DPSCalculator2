#include <string>
#include <fstream>
#include <iostream>

#include "Weapon.h"

using namespace std;

void Weapon::setFromFile(string fileName){

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

}