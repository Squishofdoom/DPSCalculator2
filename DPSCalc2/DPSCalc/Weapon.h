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

float maxDamage;
float maxDamageRange;

float minDamage;
float minDamageRange;

float shortReload;
float longReload;

int magazineSize;
int totalAmmo;

////////////////////////////////////
//Explosive weapon stats, optional//
////////////////////////////////////

bool isExplosive = false;
float maxSplashDamage;
float maxSplashRange;

float minSplashDamage;
float minSplashRange;

///////////////////
//Calculated data//
///////////////////

float damageAtRange;	//damage with falloff calculation
float splashDamage;		//splash damage dealt
float idealDPS;			//ideal DPS, assuming 100% accuracy and falloff calculation
float DPS;				//DPS, assuming user-input accuracy and falloff calculation
float TTK;				//Time to Kill, assuming the target has default 1000 health
float nanoweaveTTK;		//Time To Kill, assuming the target has default 1000 health and 20% damage reduction
float BTK;				//Bullets to Kill
float nanoweaveBTK;		//Bullets to Kill, assuming 20% damage reduction



//Calculations
void calculate(int, float, float);	//range and accuracy arguments
void calcIdealDPS();//no arguments
void calcDPS(float, float);	//accuracy argument, nested into calculate
void calcTTK();	//time to kill, assuming that the target has 1000 hp, which is the default
void calcSplash(float);


public:

	

	//File operations
	bool setFromFile(string);	//accepts file name as input, file name should be weapon name
	bool saveToFile(string);	//accepts file name as input, file name should be weapon name

	//Mutators
	void setExplosive(bool);
	void setMaxSplashDamage(float);
	void setMinSplashDamage(float);
	void setMaxSplashRange(float);
	void setMinSplashRange(float);

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
	void displayMore();

	bool getExplosive();
	float getMaxSplashDamage();
	float getMinSplashDamage();
	float getMaxSplashRange();
	float getMinSplashRange();

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

	//validators
	bool check(string);
	bool check(int);
	bool check(float);
};

#endif