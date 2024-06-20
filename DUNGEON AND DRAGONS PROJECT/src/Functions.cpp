#pragma once
#include "Functions.h"
#include "Namespaces.h"
#include "ConsoleColors.h"
#include "Monster.h"

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

int CrossRoadsScene()
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
    return choice;
}
///
//adauga hp si damage in functie de iteme (shield + 100 aparare, sabie + 100 damage, boots + 30 movement speed
// 
// 
//void BattleScene() ->>encounter enemy



