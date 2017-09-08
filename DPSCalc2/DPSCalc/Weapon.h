#include <string>
using namespace std;

class Weapon {

private:

string weaponType;
string weaponName;

int fireRate;
int velocity;

float headshotMultiplier;
float moveSpeedMultiplier;

int maxDamage;
int maxDamageRange;

int minDamage;
int minDamageRange;

float shortReload;
float longReload;

int magazineSize;
int totalAmmo;

public:

	//Calculations
	float calcDamageAtRange(int);

	//File operations
	bool setFromFile(string);	//accepts file name as input, file name should be weapon name
	bool saveToFile(string);	//accepts file name as input, file name should be weapon name

	//Mutators
	

	//Accessors

};