#include <string>
using namespace std;

class Weapon {

private:

string weaponType;

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

	//Mutators
	void setFromFile(string);	//accepts file name as input, file name should be weapon name

	//Accessors

};