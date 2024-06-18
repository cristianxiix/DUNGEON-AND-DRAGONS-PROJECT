#include "Monster.h"
#include <random>


Monster::Monster() {}
Monster::~Monster() {}
void Monster::Attack() {}

Goblin::Goblin() {}
Goblin::~Goblin() {}
void Goblin::Attack()
{
	std::string attack;
		std::random_device rd;
		std::mt19937 gen(rd);

		std::uniform_int_distribution<> distrib(0, 2);
		int randomC = distrib(gen);

		switch (randomC)
		{
			case 1:
			{
				attack = "Big Boulder"; break;
			}
			case 2:
			{
				attack:
			}
		}
}

