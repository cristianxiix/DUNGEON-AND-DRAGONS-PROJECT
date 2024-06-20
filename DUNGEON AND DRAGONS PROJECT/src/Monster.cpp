#pragma once
#include "Monster.h"
#include <random>
#include <iomanip>


Monster::Monster() { Monster::hp = 0; Monster::dmg = 0; }
Monster::~Monster() {}
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
//int Goblin::Attack()
//{
//	std::string attack = "";
//
//	std::random_device rd;
//		std::default_random_engine generator(rd());
//		std::uniform_int_distribution<int> distrib(0, 2);
//		int randomC = distrib(generator);
//	
//
//		switch (randomC)
//		{
//			case 0:
//			{
//				attack = "Big Boulder"; break;
//			}
//			case 1:
//			{
//				attack = "Acidic Spit"; break;
//			}
//			case 2:
//			{
//				attack = "Flying kick"; break;
//			}
//		}
//}
const int Goblin::ReturnMonsterType()
{
	return RACE_TYPE_GOBLIN;
}
int Goblin::returnMonsterHp()
{
	return hp;
}


Orc::Orc() {}
Orc::Orc(std::string Name)
{
	hp = 100;
	dmg = 15;
	Name = this->name;
}
Orc::~Orc() {}
const int Orc::ReturnMonsterType()
{
	return RACE_TYPE_ORC;
}
int Orc::returnMonsterHp()
{
	return hp;
}


Troll::Troll() { }
Troll::Troll(std::string Name)
{
	hp = 100;
	dmg = 15;
	Name = this->name;
}
Troll::~Troll() {}
const int Troll::ReturnMonsterType()
{
	return RACE_TYPE_TROLL;
}
int Troll::returnMonsterHp()
{
	return hp;
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

int AttackPlayer(Entity* p, Monster* m)
{

	std::vector<std::string> attacks;

	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> distrib(0, 2);
	int randomC = distrib(generator);


	switch (m->ReturnMonsterType())
	{
		case MonsterRaces::RACE_TYPE_GOBLIN:
		{
			attacks.push_back("Big Boulder");
			attacks.push_back("Acidic Spit");
			attacks.push_back("Jumping kick");
		}
		case MonsterRaces::RACE_TYPE_TROLL:
		{
			attacks.push_back("Vicious Strike");
			attacks.push_back("Jaw of the Troll");
			attacks.push_back("Holy Spirit");
		}
		case MonsterRaces::RACE_TYPE_ORC:
		{
			attacks.push_back("Bare Food");
			attacks.push_back("Axe Swing");
			attacks.push_back("Dark Horror");
		}
	}

	std::cout << std::right << std::setw(55) << "You've struck the PLAYER with your " << attacks[randomC] << " for " << m->dmg << "health points." << std::endl;
	return m->dmg;
}