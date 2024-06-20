#pragma once
#include <iostream>
#include "Races.h"

enum MonsterRaces {
	RACE_TYPE_GOBLIN = 1,
	RACE_TYPE_ORC,
	RACE_TYPE_TROLL,
	RACE_TYPE_MMAX
};

class Monster
{
protected:
	int hp = 0;
	int dmg = 0;
	std::string name;

public:
	Monster();
	Monster(std::string Name);
	~Monster();
	friend int AttackPlayer(Entity* p, Monster* m);
	const virtual int ReturnMonsterType();
	friend Monster* createMonster(int path);
	virtual std::string ReturnMonsterBaseName() = 0;
	virtual int returnMonsterHp();

};
 Monster* createMonster(int path);
 int AttackPlayer(Entity* p, Monster* m);


class Goblin : public Monster
{
public:
	Goblin();
	Goblin(std::string Name);
	~Goblin();
	//int Attack();
	const int ReturnMonsterType();
	std::string ReturnMonsterBaseName();
	int returnMonsterHp();

};

class Troll : public Monster
{
public:
	Troll();
	Troll(std::string Name);
	~Troll();
	//int Attack();
	const int ReturnMonsterType();
	std::string ReturnMonsterBaseName();
	int returnMonsterHp();

};
class Orc : public Monster
{
public:
	Orc();
	Orc(std::string Name);
	~Orc();
	//int Attack();
	const int ReturnMonsterType();
	std::string ReturnMonsterBaseName();
	int returnMonsterHp();

};