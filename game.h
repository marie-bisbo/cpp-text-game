#pragma once

#include "character.h"
#include <iostream>
#include <string>
#include <map>

#define OUT 

namespace Game{

    struct PlayerController;
    static void Wait();
    enum class CharacterType;
    static CharacterType ChoseCharacter();
    static void StartIntro();
    struct Room;

    struct Room
    {
        std::string name;
        std::vector<Item> items;
        std::vector<Room*> adjoiningRooms;
        bool isExplored = false;
    };

    struct PlayerController
    {
        CharacterType characterType;
        Character* character;
        Room* currentRoom;
    };

    static void Wait()
    {
        std::cout << "Press enter to continue...\n";
        std::cin.ignore();
        std::cin.get();
    }

    enum class CharacterType 
    {
        Fighter,
        Mage
    };

    static void ChoseCharacter(OUT PlayerController& playerController)
    {
        CharacterType chosenCharacter;
        bool hasChosenCharacter = false;
        std::cout << "Choose a character type\n";
        std::cout << "[" << static_cast<int>(CharacterType::Fighter) << "] Fighter\n";
        std::cout << "[" << static_cast<int>(CharacterType::Mage) << "] Mage\n";
        while (!hasChosenCharacter)
        {
            int characterChoice;
            std::cin >> characterChoice;
            switch (characterChoice)
            {
                case 0:
                    std::cout << "You chose to be a Fighter\n";
                    chosenCharacter = CharacterType::Fighter;
                    hasChosenCharacter = true;
                    break;
                case 1:
                    std::cout << "You chose to be a Mage\n";
                    chosenCharacter = CharacterType::Mage;
                    hasChosenCharacter = true;
                    break;
                default:
                    std::cout << "You did not chose a valid character type\n";
            }
        }
        Item sword = Item{"Sword", "A trusty friend in battle"};
        Item staff = Item{"Staff", "Great for casting spells, or a good thwack on the head"};
        Character* character;
        if (chosenCharacter == CharacterType::Fighter)
            character = new Fighter("Bob", std::vector<Item>(), sword);
        if (chosenCharacter == CharacterType::Mage)
            character = new Mage("Alice", std::vector<Item>(), staff, std::vector<Spell>());

        playerController.characterType = chosenCharacter;
        playerController.character = character;
    }

    static void StartIntro()
    {
        std::cout << "You have just woken up. Your memory of recent events is gone. You stand before a great castle...\n";
    }
}
