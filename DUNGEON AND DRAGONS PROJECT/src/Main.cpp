#pragma once
#include "Functions.h"
#include "Races.h"
#include "Namespaces.h"
#include "Sounds.h"
#include "Monster.h"

int main()
{	
	/*int i = 0;
	std::cin >> i;
	for (; i > 5; i--)
	{
		std::cout << "hehe";
	}*/
	Sound* mmenu = new Sound("./music/Main_Menu.wav");
	StartPlaying(mmenu);

	//mmenu->SetupDevice();
	//mmenu->PlaySound();

	start();
	if (IntroScene())  /// raspundem daca vrem sau nu sa jucam
	{
		Entity* player = CreateCharacterRace(); // se creeaza jucatorul pe heap, prin intermediul unui Entity*
		
		logChoice(player);
		mmenu->StopSound();
		mmenu = changeFilePath("./music/Exploring.wav");
		StartPlaying(mmenu);
		Wait();
		if (checkContinue())
		{
			CrossRoadsScene(); //returneaza un int cu alegerea automata a monstrului
			ChestFindingScene(player); //automat fara ptr
			//AddChestItemsToInventory(player, ptr); // de intrebart
			
			/////////////////////////
			//battleScene()
			mmenu->StopSound();
			mmenu = changeFilePath("./music/BattleFinal.wav");
			StartPlaying(mmenu);
		}
		else
		{/*
			sleep_for(5s);
			if (secondCheck())
			{
				ptr = ChestFindingScene(player);
				AddChestItemsToInventory(player, ptr);
				delete ptr;
				logFoundItems(player);
			}
			else
			{
				exit(0);
			}*/
		}
	}
	else
	{
		std::cin.get();
	}

	mmenu->~Sound();
	return 0;

	

}


