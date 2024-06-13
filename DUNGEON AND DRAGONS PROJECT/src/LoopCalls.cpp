#pragma once
#include "Functions.h"
#include "Races.h"
#include "Namespaces.h"
#include "Sounds.h"


void prompt()
{
	//char a
	std::cout << "EXIT GAME -> press E." << std::endl;
}
bool running = true;

void GameLoop()//////////////
{
	while (running)
	{
		Sound* mmenu = new Sound("./music/Main_Menu.wav");
		StartPlaying(mmenu);

		std::vector<Item*>* ptr = nullptr;
		start();
		if (IntroScene())  /// raspundem daca vrem sau nu sa jucam
		{
			Entity* player = CreateCharacterRace(); // se creeaza jucatorul pe heap, prin intermediul unui Entity*
			logChoice(player);
			mmenu->StopSound();
			mmenu = changeFilePath("./music/Exploring.wav");
			StartPlaying(mmenu);

				if (checkContinue())
				{
					CrossRoadsScene(); /////////////////////////

					ptr = ChestFindingScene(player); //automat fara ptr
					AddChestItemsToInventory(player, ptr); // de intrebart
					delete ptr;
					logFoundItems(player);

					//battleScene()
					mmenu->StopSound();
					mmenu = changeFilePath("./music/BattleFinal.wav");
					StartPlaying(mmenu);
				}
				else
				{
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
					}
				}
		}
		else
		{
			std::cin.get();
		}
		mmenu->~Sound();
	}

	
}


