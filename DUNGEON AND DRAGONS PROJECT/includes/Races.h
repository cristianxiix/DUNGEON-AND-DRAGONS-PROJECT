#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "ConsoleColors.h"

enum Races {
	RACE_TYPE_WARRIOR = 1,
	RACE_TYPE_WIZARD,
	RACE_TYPE_ROGUE,
	RACE_TYPE_MAX
};

class Item
{
	std::string m_item_name;
public:
	Item();
	Item(std::string itmName);
	std::string returnItemName();
};

class Entity
{
protected:
	int level;
	std::string playerName;
	std::vector<Item*> m_item_inventory;
public:
	Entity(std::string pName);
	Entity();
	~Entity();

	friend Entity* CreateCharacterRace();
	friend void logChoice(Entity*& e);
	const virtual int getCharRace();
	friend void AddChestItemsToInventory(Entity*& p, std::vector<Item*>* ptr);
	friend std::vector<Item*>* ChestFindingScene(Entity* p);
	friend void logFoundItems(Entity* p);
};


Entity* CreateCharacterRace();  ////function definition inside Races.cpp
void logChoice(Entity*& e); ////function definition inside Functions.cpp
void AddChestItemsToInventory(Entity*& p, std::vector<Item*>* ptr);
std::vector<Item*>* ChestFindingScene(Entity* p);
void logFoundItems(Entity* p);


class Warrior : public Entity
{
public:
	Warrior();
	Warrior(std::string pName);
	~Warrior();
	const int getCharRace();
};

class Wizard : public Entity
{
public:
	Wizard();
	Wizard(std::string pName);
	~Wizard();
	const int getCharRace();
};

class Rogue : public Entity
{
public:
	Rogue();
	Rogue(std::string pName);
	~Rogue();
	const int getCharRace();
};