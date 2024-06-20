#pragma once
#include "Monster.h"
#include <random>


Monster::Monster() { Monster::hp = 0; Monster::dmg = 0; }
Monster::~Monster() {}
void Monster::Attack() {}
const int Monster::ReturnMonsterType()
{
	return RACE_TYPE_MMAX;
}


 Goblin::Goblin(std::string Name)
 {
	 Name = name;
	 hp = 100;
	 dmg = 15;
 }
Goblin::Goblin() {}
Goblin::~Goblin() {}
void Goblin::Attack()
{
	std::string attack = "";

	std::random_device rd;
		std::default_random_engine generator(rd());
		std::uniform_int_distribution<int> distrib(0, 2);
		int randomC = distrib(generator);
	

		switch (randomC)
		{
			case 0:
			{
				attack = "Big Boulder"; break;
			}
			case 1:
			{
				attack = "Acidic Spit"; break;
			}
			case 2:
			{
				attack = "Flying kick"; break;
			}
		}
}
const int Goblin::ReturnMonsterType()
{
	return RACE_TYPE_GOBLIN;
}


Orc::Orc() {}
Orc::Orc(std::string Name)
{
	hp = 100;
	dmg = 15;
	Name = this->name;
}
Orc::~Orc() {}
void Orc::Attack()
{
	std::string attack = "";

	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> distrib(0, 2);
	int randomC = distrib(generator);


	switch (randomC)
	{
		case 0:
		{
			attack = "Bare Foot"; break;
		}
		case 1:
		{
			attack = "Axe Swing"; break;
		}
		case 2:
		{
			attack = "Dark horror"; break;
		}
	}
}
const int Orc::ReturnMonsterType()
{
	return RACE_TYPE_ORC;
}


Troll::Troll() { }
Troll::Troll(std::string Name)
{
	hp = 100;
	dmg = 15;
	Name = this->name;
}
Troll::~Troll() {}
void Troll::Attack()
{
	std::string attack = "";

	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> distrib(0, 2);
	int randomC = distrib(generator);


	switch (randomC)
	{
		case 0:
		{
			attack = "Vicious strike"; break;
		}
		case 1:
		{
			attack = "Jaw of the Troll"; break;
		}
		case 2:
		{
			attack = "Stinky Smell"; break;
		}
	}
}
const int Troll::ReturnMonsterType()
{
	return RACE_TYPE_TROLL;
}



Monster* createMonster(int path)
{
	Monster* m = nullptr;
	std::string monsterNames[] = {"Stinky", "Horror", "Bambulas", "Porisip"};
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> distrib(0, 3);
	int randomC = distrib(generator);

	switch (path)
	{
		case 1:
		{
			m = new Goblin(monsterNames[randomC]);
			break;
		}
		case 2:
		{
			m = new Orc(monsterNames[randomC]);
			break;
		}
		case 3:
		{
			m = new Troll(monsterNames[randomC]);
			break;
		}
	}
	return m;
}