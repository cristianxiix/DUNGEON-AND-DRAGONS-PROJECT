#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "ConsoleColors.h"
#include "Monster.h"

enum Races {
	RACE_TYPE_WARRIOR = 1,
	RACE_TYPE_WIZARD,
	RACE_TYPE_ROGUE,
	RACE_TYPE_MAX
};
enum ItemType
{
	ITEM_TYPE_WEAPON = 0,
	ITEM_TYPE_ARMOR,
	ITEM_TIME_ADDITIONAL
};
class Item
{
	std::string m_item_name = 0;
	int m_item_type = 0;
public:
	Item();
	Item(std::string itmName, int m_type);
	std::string returnItemName();
};

class Entity
{
protected:
	int level;
	int HealthPoints;
	int dmg;
	std::string playerName;
	std::vector<Item*> m_item_inventory;
public:
	Entity(std::string pName);
	Entity();
	~Entity();
	virtual int getHealthPoints() = 0;
	virtual int getDmgPoints();
	virtual int setNewHP(int amount);


	const virtual int getCharRace();
	friend Entity* CreateCharacterRace();
	friend void logChoice(Entity*& e);
	friend void AddChestItemsToInventory(Entity*& p, std::vector<Item*>* ptr);
	friend void ChestFindingScene(Entity* p);
	friend void logFoundItems(std::vector<Item*>* inv);
	friend void GrantBonuses(Entity* p); 
    friend int Attack(Entity* p, Monster* m);
	
};


Entity* CreateCharacterRace();  ////function definition inside Races.cpp
void logChoice(Entity*& e); ////function definition inside Functions.cpp
void AddChestItemsToInventory(Entity*& p, std::vector<Item*>* ptr);
void ChestFindingScene(Entity* p);
void logFoundItems(std::vector<Item*>* inv);
void GrantBonuses(Entity* p);
int Attack(Entity* p, Monster* m);

class Warrior : public Entity
{
public:
	Warrior();
	Warrior(std::string pName);
	~Warrior();
	const int getCharRace();
    int getHealthPoints();
	int setNewHP(int amount);


};

class Wizard : public Entity
{
public:
	Wizard();
	Wizard(std::string pName);
	~Wizard();
	const int getCharRace();
	int getHealthPoints();
	int setNewHP(int amount);
};

class Rogue : public Entity
{
public:
	Rogue();
	Rogue(std::string pName);
	~Rogue();
	const int getCharRace();
	int getHealthPoints();
	int setNewHP(int amount);
};