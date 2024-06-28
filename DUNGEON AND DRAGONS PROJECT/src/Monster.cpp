#pragma once
#include "Monster.h"


Monster::Monster() { Monster::hp = 0; Monster::dmg = 0; }
Monster::~Monster() {}
const int Monster::ReturnMonsterType()
{
	return RACE_TYPE_MMAX;
}
std::string Monster::ReturnMonsterBaseName()
{
	return 0;
}
int Monster::setNewMonsterHp(int amount)
{
	if (amount >= this->hp)
	{
		this->hp = 0;
		return this->hp;
	}
	this->hp -= amount;
	return this->hp;
}



 Goblin::Goblin(std::string Name)
 {
	 name = Name;
	 hp = 100;
	 dmg = 15;
 }
Goblin::Goblin() {}
Goblin::~Goblin() {}
const int Goblin::ReturnMonsterType()
{
	return 1;
}
int Goblin::returnMonsterHp()
{
	if (hp == 0)
	{
		return NULL;
	}
	return hp;
}
std::string Goblin::ReturnMonsterBaseName()
{
	return this->name;
}
int Goblin::setNewMonsterHp(int amount)
{
	if (amount >= this->hp)
	{
		this->hp = 0;
		return this->hp;
	}
	this->hp -= amount;
	return this->hp;
}




Orc::Orc() {}
Orc::Orc(std::string Name)
{
	hp = 100;
	dmg = 15;
	name = Name;
}
Orc::~Orc() {}
const int Orc::ReturnMonsterType()
{
	return 2;
}
int Orc::returnMonsterHp()
{
	if (hp == 0)
	{
		return NULL;
	}
	return hp;
	
}
std::string Orc::ReturnMonsterBaseName()
{
	return this->name;
}
int Orc::setNewMonsterHp(int amount)
{
	if (amount >= this->hp)
	{
		this->hp = 0;
		return this->hp;
	}
	this->hp -= amount;
	return this->hp;
}

Troll::Troll() { }
Troll::Troll(std::string Name)
{
	hp = 100;
	dmg = 15;
	name = Name;
}
Troll::~Troll() {}
const int Troll::ReturnMonsterType()
{
	return 3;
}
int Troll::returnMonsterHp()
{
	if (hp == 0)
	{
		return NULL;
	}
	return hp;
}
std::string Troll::ReturnMonsterBaseName()
{
	return this->name;
}
int Troll::setNewMonsterHp(int amount)
{
	if (amount >= this->hp)
	{
		this->hp = 0;
		return this->hp;
	}
	this->hp -= amount;
	return this->hp;
}



Monster* createMonster(int path)
{
	Monster* m = nullptr;
	std::vector<std::string> monsterNames = {"Stinky", "Horror", "Bambulas", "Porisip"};
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> distrib(0, monsterNames.size()-1);
	int randomC = distrib(generator);

	switch (path)
	{
		case 1:
		{
			m = new Goblin(monsterNames[randomC].substr());
			break;
		}
		case 2:
		{
			m = new Orc(monsterNames[randomC].substr());
			break;
		}
		case 3:
		{
			m = new Troll(monsterNames[randomC].substr());
			break;
		}
	}
	return m;
}

