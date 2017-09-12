#ifndef WEAPON_H
#define WEAPON_H

#include <string>
using namespace std;

class Weapon {

protected:
////////////////
//Weapon stats//
////////////////
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

///////////////////
//Calculated data//
///////////////////

float damageAtRange;	//damage with falloff calculation
float idealDPS;			//ideal DPS, assuming 100% accuracy and falloff calculation
float DPS;				//DPS, assuming user-input accuracy and falloff calculation
float TTK;				//Time to Kill, assuming the target has default 1000 health
float nanoweaveTTK;		//Time To Kill, assuming the target has default 1000 health and 20% damage reduction



//Calculations
void calculate(int, float);	//range and accuracy arguments
void calcIdealDPS();//no arguments
void calcDPS(float);	//accuracy argument, nested into calculate
void calcTTK();	//time to kill, assuming that the target has 1000 hp, which is the default


public:

	

	//File operations
	bool setFromFile(string);	//accepts file name as input, file name should be weapon name
	bool saveToFile(string);	//accepts file name as input, file name should be weapon name

	//Mutators
	void setWeaponType(string);
	void setWeaponName(string);
	void setFireRate(int);
	void setVelocity(int);
	void setHeadShotMultiplier(float);
	void setMoveSpeedMultiplier(float);
	void setMaxDamage(int);
	void setMaxRange(int);
	void setMinDamage(int);
	void setMinRange(int);
	void setShortReload(float);
	void setLongReload(float);
	void setMagazineSize(int);
	void setTotalAmmo(int);

	//Accessors
	void display();

	string getWeaponType();
	string getWeaponName();
	int getFireRate();
	int getVelocity();
	float getHeadShotMultiplier();
	float getMoveSpeedMultiplier();
	int getMaxDamage();
	int getMaxRange();
	int getMinDamage();
	int getMinRange();
	float getShortReload();
	float getLongReload();
	int getMagazineSize();
	int getTotalAmmo();
};

#endif