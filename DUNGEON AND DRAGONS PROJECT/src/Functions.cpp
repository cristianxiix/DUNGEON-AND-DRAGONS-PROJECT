#pragma once
#include "ConsoleColors.h"
#include "Functions.h"
#include "Monster.h"
#include "Namespaces.h"
#include "Races.h"
#include "Namespaces.h"

void start()
{
    std::cout << ANSI_COLOR_GREEN << R"(
                           __        _____  ____  _     ____     ___  _____              
                           \ \      / / _ \|  _ \| |   |  _ \   / _ \|  ___|             
                            \ \ /\ / / | | | |_) | |   | | | | | | | | |_                
                             \ V  V /| |_| |  _ <| |___| |_| | | |_| |  _|               
                             _\_/\_/  \___/|_| \_\_____|____/   \___/|_| ____            
                           | ____| |   |  _ \ / _ \|  _ \|_ _|  / \     / ___|   _     _   
                           |  _| | |   | | | | | | | |_) || |  / _ \   | |     _| |_ _| |_ 
                           | |___| |___| |_| | |_| |  _ < | | / ___ \  | |__  |_   _|_   _|
                           |_____|_____|____/ \___/|_| \_\___/_/   \_\  \____|  |_|   |_|  )" << std::endl;
    std::cout << '\n' << ANSI_COLOR_RESET << std::endl;
}

bool IntroScene() ///INTRO SCENE
{
    
    std::cout << ANSI_COLOR_MAGENTA << std::right << std::setw(65) << R"(In the realm of Eldoria, where ancient dragons soar above enchanted forests and kingdoms of men and elves stand united,)" << '\n' <<
        std::right << std::setw(65) << R"(magic flows as freely as rivers.Forgotten ruins whisper secrets of lost civilizations,)" << '\n' <<
        std::right << std::setw(65) << R"(and heroes embark on epic quests to vanquish dark forces, seeking glory, power, and the favor of the gods.Welcome to Eldoria.)" << '\n' << std::endl;


    std::cout << std::right << std::setw(75) << "Are you sure you want to play this game?" << std::endl;
    std::cout << std::right << std::setw(70) << "Input Y for YES or N for NO:" << std::endl;
    ANSI_COLOR_RESET;
    char x;
    std::cin >> x;
    if (x == 'Y')
    {
        return true;
    }
    else if (x == 'N')
    {
        return false;
    }
    else
    {
        std::cout << "Due to your input being anything other than Y or N, the program exits." << std::endl;
        exit(0);
    }
}

void Wait()
{
    
    sleep_for(5s);
    std::cout << ANSI_COLOR_YELLOW << std::right << R""(
                 In the Realm of Eldoria everything is possible, from flying horses to self-healing swords
                From losers to Kings, dust becoming gold flakes, creatures such as Goblins, Trolls, Cyclops
                            Fighting each other over who s a greater fighter
                                             WELCOME TO ELDORIA.
    )"" << ANSI_COLOR_RESET << std::endl;
    std::cout << "\n\n";
    
    sleep_for(3s);
}

bool checkContinue()
{
    short choice;
    std::cout << std::right << std::setw(70) << "You've been walking for so long" << std::endl;
    sleep_for(2s);
    std::cout << std::right << std::setw(70) << "Are you not tired yet?" << std::endl;
    sleep_for(2s);

    std::cout << std::right << std::setw(60) << "1.Yes, I am" << std::endl;
    std::cout << std::right << std::setw(64) << "2.No, I am not!" << std::endl;
    std::cin >> choice;
    if (choice == 2)
    {
        std::cout << std::right << std::setw(85) << "Courageous adventurer, you have chosen the harder path!" << std::endl;
        return true;
    }
    else if(choice == 1)
    {
        std::cout << std::right << std::setw(93) << "You've been given the night to rest, but stay aware of the dangers!" << std::endl;
        return false;
    }
    else
    {
        return false;
    }

}

bool secondCheck()
{
    bool choice;
    std::cout << std::right << std::setw(70) << "Are you ready to continue the journey?" << std::endl;
    std::cout << std::right << std::setw(60) << "1.Yes, I am!" << std::endl;
    std::cout << std::right << std::setw(63) << "2.No, I am not!" << std::endl;
    std::cin >> choice;

    if (choice)
    {
        std::cout << std::right << std::setw(90) << "Courageous adventurer, good luck on this mysterious journey!" << std::endl;
        return true;
    }
    else
    {
        std::cout << std::right << std::setw(90) << "Cowards are not allowed a third chance!" << std::endl;
        exit(0);
    }
}

Monster* CrossRoadsScene()
{
    sleep_for(3s);
    int choice = 0;
    std::cout << std::right << std::setw(85) << "You're at a crossroads! Your choices are as follows:" << std::endl;
    std::flush(std::cout);
    sleep_for(2s);
    std::cout << std::right << std::setw(95) << "1.Take the path towards THE CAVE that is guarded by an elder Orc" << std::endl;
    sleep_for(3s);
    std::cout << std::right << std::setw(92) << "2.Walk head-on towards THE FOREST that is guarded by a Goblin" << std::endl;
    sleep_for(3s);
    std::cout << std::right << std::setw(105) << "3.Ride courageously towards the village where a fiery Troll is waiting for you" << std::endl;
    sleep_for(3s);

    std::flush(std::cout);
    std::cin >> choice;


    std::cout << std::right << std::setw(75) << "Great choice, adventurer! GOOD LUCK!" << std::endl;
    Monster* m = createMonster(choice);
    return m;
}

void BattleScene(Monster* mob, Entity* pl)
{

    std::cout << std::right << std::setw(65) << "GRRRRAAAAH!!! I am the Mighty " << mob->ReturnMonsterBaseName() << " of this land!" << std::endl;
    std::cout << std::right << std::setw(65) << "Turn back or face me!" << std::endl;

    int choice = 0;
    std::cout << "1.I feel ready to fight this!" << std::endl;
    std::cout << "2.Maybe some other time." << std::endl;
    std::cin >> choice;

    int mobRes = 0;
    int pRes = 0;
    while (choice == 1)
    {
        if (mob->returnMonsterHp() != 0 || pl->getHealthPoints() != 0)
        {

            mobRes = AttackPlayer(mob);
            pl->setNewHP(mobRes);
            std::cout << "PLAYER's new hp is:  " << pl->getHealthPoints() << std::endl;
            pRes = Attack(pl, mob);
            mob->setNewMonsterHp(pRes);
            std::cout << "MONSTER's new hp is:  " << mob->returnMonsterHp() << std::endl;

            sleep_for(3s);
        }
        if (mob->returnMonsterHp() == 0)
            break;
    }

            if (mob->returnMonsterHp() == 0)
            {
                std::cout << std::setw(65) << "Player has won!" << std::endl;
                return;
            }
            else if (pl->getHealthPoints() == 0)
            {

                std::cout << std::setw(65) << "Game's over, coward" << std::endl;
                std::cout << std::setw(65) << "Monster has won!" << std::endl;
                return;
            }
        
}
       
    




////MONSTER BASE NAME CAN BE DELETED
int AttackPlayer(Monster* m)
{
    if (m->hp == 0)
    {
        return -1;
    }
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
            break;
	    }
	    case MonsterRaces::RACE_TYPE_TROLL:
	    {
		    attacks.push_back("Vicious Strike");
		    attacks.push_back("Jaw of the Troll");
		    attacks.push_back("Holy Spirit");
            break;
	    }
	    case MonsterRaces::RACE_TYPE_ORC:
	    {
		    attacks.push_back("Bare Food");
		    attacks.push_back("Axe Swing");
		    attacks.push_back("Dark Horror");
            break;
	    }
	}

	std::cout << std::right << std::setw(65) << "The MONSTER has struck the PLAYER with " << attacks[randomC] << " for " << m->dmg << " health points." << '\n' << std::endl;
	return m->dmg;
}