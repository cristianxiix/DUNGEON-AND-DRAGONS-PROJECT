#pragma once
#include <iostream>



class Monster
{
protected:
	int hp = 0;
	int dmg = 0;

public:
	Monster();
	~Monster();
	virtual void Attack();
};



class Goblin : public Monster
{
	Goblin();
	~Goblin();
	void Attack();
};

class Troll : public Monster
{
	Troll();
	~Troll();
	void Attack();
};
class Orc : public Monster
{
	Orc();
	~Orc();
	void Attack();
};