#pragma once
#include <iostream>
#include <iomanip>
#include "Monster.h"
#include "Races.h"

void start();
bool IntroScene();
void Wait();
bool checkContinue();
bool secondCheck();
Monster* CrossRoadsScene();
void BattleScene(Monster* mob, Entity* pl);



