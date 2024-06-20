#pragma once
#include "Races.h"
#include "Namespaces.h"
#include <random>


Item::Item(std::string itmName) : m_item_name(itmName) {}
Item::Item() {}
std::string Item::returnItemName() { return this->m_item_name; }


Entity::Entity(std::string pName) 
{
    Entity::playerName = pName; 
    Entity::level = 0; 
    Entity::dmg = 35; 
    Entity::HealthPoints = 0;
}
Entity::Entity()
{
    if (playerName.empty())
        playerName = "undefined";

    Entity::level = 0;
    Entity::dmg = 35; 
    Entity::HealthPoints = 0;
}
Entity::~Entity() {}
const int Entity::getCharRace() { return 4; }

Warrior::Warrior(std::string pName) { Warrior::playerName = pName;  Warrior::level = 0; Warrior::dmg = 35; Warrior::HealthPoints = 100; }
Warrior::Warrior() {}
Warrior::~Warrior() {}
const int Warrior::getCharRace() { return 1; }

Wizard::Wizard(std::string pName) { Wizard::playerName = pName; Wizard::level = 0; Wizard::dmg = 35; HealthPoints = 100; }
Wizard::Wizard() {}

Wizard::~Wizard() {}
const int Wizard::getCharRace() { return 2; }

Rogue::Rogue(std::string pName) { Rogue::playerName = pName; Rogue::level = 0; Rogue::dmg = 35; HealthPoints = 100; }
Rogue::Rogue() {}
Rogue::~Rogue() {}
const int Rogue::getCharRace() { return 3; }



Entity* CreateCharacterRace()  ///setup player
{
    int choice = 0;
    std::string charName;
    Entity* e;

    unsigned short x = 0;

    std::cout << std::setw(70) << "Please choose your player name:" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, charName);


    std::cout << std::right << std::setw(80) << R"(Now you should choose the class you want to be.)" << '\n' <<
        std::right << std::setw(70) << R"(Your options are as follows :)" << '\n' << ANSI_COLOR_RESET <<
        ANSI_COLOR_RED << std::right << std::setw(60) << "1.Warrior" << '\n' << ANSI_COLOR_RESET <<
        ANSI_COLOR_GREEN << std::right << std::setw(59) << "2.Wizard" << '\n' << ANSI_COLOR_RESET <<
        ANSI_COLOR_YELLOW << std::right << std::setw(58) << "3.Rogue" << '\n' << ANSI_COLOR_RESET <<
        std::right << std::setw(80) << R"(Please choose the number according to your choice.)" << std::endl;

    std::cin >> choice;


    switch (choice)
    {
        case 1: //warrior
        {
            e = new Warrior(charName);
            std::cout << std::right << std::setw(80) << "Your character has been created. Entering world soon." << std::endl;
            sleep_for(2s);
            break;
        }
        case 2:
        {
            e = new Wizard(charName);
            std::cout << std::right << std::setw(80) << "Your character has been created. Entering world soon." << std::endl;
            sleep_for(2s);
            break;
        }
        case 3:
        {
            e = new Rogue(charName);
            std::cout << std::right << std::setw(80) << "Your character has been created. Entering world soon." << std::endl;
            sleep_for(2s);
            break;
        }
        default:
        {
            std::cout << R"(INPUT ERROR. You'll be able to create your name and char again,
                                but if you fail to do so, the program will exit.)" << std::endl;
            while (x < 1)
            {
                CreateCharacterRace();
            }
            exit(0);
        }
    }
    e->level = 1;
    return e;

}

void logChoice(Entity*& e)
{
    std::string classType = "";

    switch (e->getCharRace())
    {
    case 1: classType = "WARRIOR"; break;
    case 2: classType = "WIZARD"; break;
    case 3: classType = "ROGUE"; break;
    }

    std::cout << std::setw(60) << std::right << "Your name is " << e->playerName << '\n';
    sleep_for(2s);
    std::cout << std::setw(56) << std::right << "CLASS is " << classType << '\n';
    sleep_for(2s);
    std::cout << std::setw(56) << std::right << "LEVEL is " << e->level << std::endl;
    sleep_for(2s);
    std::cout << std::setw(53) << std::right << "HP is " << e->HealthPoints << std::endl;
    sleep_for(2s);
    std::cout << std::setw(53) << std::right << "Damage is " << e->dmg << " per attack" << std::endl;

}

void AddChestItemsToInventory(Entity*& p, std::vector<Item*>* ptr)
{
    for (int i = 0; i < ptr->size(); i++)
    {
        p->m_item_inventory.push_back(ptr->at(i));
    }

}

void ChestFindingScene(Entity* p)
{

    std::vector<Item*>* ptr = new std::vector<Item*>;
    std::cout << "You have found a chest!" << std::endl;
    sleep_for(2s);

    if (!p)
    {
        std::cout << "Program exits due to an exception being thrown inside ChestFindingScene function, referenced in Races.cpp file." << std::endl;
        return;
    }

    if (p->getCharRace() >= Races::RACE_TYPE_MAX)
    {
        std::cout << "Error. Program terminates." << std::endl;
        return;
    }
    
    char temp = '\0';
    std::cout << "Do you wish to open it? Y/N" << std::endl;
    std::cin >> temp;
    if (temp == 'Y')
    {
        switch (p->getCharRace())
        {
            case Races::RACE_TYPE_WARRIOR:
            {
                ptr->push_back(new Item("Shield"));
                ptr->push_back(new Item("Armor"));
                ptr->push_back(new Item("One Handed Sword"));
                break;
            }
            case Races::RACE_TYPE_WIZARD:
            {
                ptr->push_back(new Item("Robe"));
                ptr->push_back(new Item("SpellBook"));
                ptr->push_back(new Item("Staff"));
                break;
            }
            case Races::RACE_TYPE_ROGUE:
            {
                ptr->push_back(new Item("Dagger"));
                ptr->push_back(new Item("Chain mail"));
                ptr->push_back(new Item("Speed Boots"));
                break;
            }
            default:
            {
                std::cout << "UNHANDLED RACE TYPE : X" << std::endl;
                return;
            }
        }

        p->level++;
        p->dmg += 25;
        std::cout << std::right << std::setw(15) << "-Congrats! You advanced to level " << p->level << std::endl;
        sleep_for(2s);
        std::cout << std::right << std::setw(15) << "Your damage also increased by 25 points. " << std::endl;
    }
    else
    {
        std::cout << std::right << std::setw(75) << "Alrighty, Almighty! You're off with no items!" << std::endl;
        return;
    }
    logFoundItems(p);
    AddChestItemsToInventory(p, ptr);


   
}

void logFoundItems(Entity* p)
{
    std::cout << std::right << std::setw(75) << "You have found the following items:" << std::endl;
    for (int i = 0; i < p->m_item_inventory.size(); i++)
    {
        std::cout << std::right << std::setw(60) << p->m_item_inventory[i]->returnItemName() << std::endl;
        sleep_for(2s);
    }


}

void GrantBonuses(Entity* p)
{
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distrib(0, p->m_item_inventory.size()-1);
    


    for (int i = 0; i < p->m_item_inventory.size(); i++)
    {
        int randomC = distrib(generator);
        switch(randomC)
        {
        case ItemType::ITEM_TYPE_WEAPON:
            {
            std::cout << "Due to your " << p->m_item_inventory[randomC] << ", the elder gods have granted you some of their power\n" <<
                "permanently increasing your damage by 40 points" << std::endl;
            p->dmg += 40;
            break;
            }
        case ItemType::ITEM_TYPE_ARMOR:
            {
            std::cout << 
            }
        }

    }//////////////
}