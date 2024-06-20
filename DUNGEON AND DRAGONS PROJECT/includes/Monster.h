#pragma once
#include <iostream>


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
	virtual void Attack() = 0;
	const virtual int ReturnMonsterType();
	friend Monster* createMonster(int path);
};
 Monster* createMonster(int path);



class Goblin : public Monster
{
public:
	Goblin();
	Goblin(std::string Name);
	~Goblin();
	void Attack();
	const int ReturnMonsterType();

};

class Troll : public Monster
{
public:
	Troll();
	Troll(std::string Name);
	~Troll();
	void Attack();
	const int ReturnMonsterType();

};
class Orc : public Monster
{
public:
	Orc();
	Orc(std::string Name);
	~Orc();
	void Attack();
	const int ReturnMonsterType();

};