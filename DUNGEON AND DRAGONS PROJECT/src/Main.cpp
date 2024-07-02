#pragma once
#include "Functions.h"
#include "Races.h"
#include "Namespaces.h"
#include "Sounds.h"
#include "Monster.h"

int main()
{	
	Sound* mmenu = new Sound("./music/Main_Menu.wav");
	StartPlaying(mmenu);

	//mmenu->SetupDevice();
	//mmenu->PlaySound();

	start();
	if (IntroScene())  /// raspundem daca vrem sau nu sa jucam
	{
		Entity* player = CreateCharacterRace(); // se creeaza jucatorul pe heap, prin intermediul unui Entity*
		Monster* monster = nullptr;
		logChoice(player);
		mmenu->StopSound();
		mmenu = changeFilePath("./music/Exploring.wav");
		StartPlaying(mmenu);
		Wait();
		if (checkContinue())
		{
			monster = CrossRoadsScene(); //returneaza un monstru automat, in functie de path ul ales
			ChestFindingScene(player); //automat fara ptr
			
			//battleScene()
			mmenu->StopSound();
			mmenu = changeFilePath("./music/BattleFinal.wav");
			StartPlaying(mmenu);
			
			BattleScene(monster, player);
		}
			else
			{
				sleep_for(5s);
				if (secondCheck())
				{
					monster = CrossRoadsScene(); //returneaza un monstru in mod automat, in functie de path ul ales
					ChestFindingScene(player); //automat fara ptr

					mmenu->StopSound();
					mmenu = changeFilePath("./music/BattleFinal.wav");
					StartPlaying(mmenu);

					BattleScene(monster, player);
				}
				else
				{
					std::cout << "You've quit the game successfully!" << std::endl;
					exit(0);
				}
			}
	}
	else
	{
		std::cout << "You've quit the game successfully!" << std::endl;
	}

	mmenu->~Sound();
	return 0;

	

}


