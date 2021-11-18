#include "game_elements.h"
#include "character.h"
#include "game.h"
#include "map.h"
#include <iostream>
#include <string>
#include <vector>


int main()
{
    Game::PlayerController playerController;
    Game::ChoseCharacter(playerController);
    Game::Wait();
    system("clear");
    Game::StartIntro();
    Game::Wait();
    playerController.currentRoom = &Map::foyer;
    std::cout << "You are in the " << playerController.currentRoom->name << "." << std::endl;
    std::cout << "Where would you like to go next?" << std::endl;
    for (size_t i = 0; i < playerController.currentRoom->adjoiningRooms.size(); ++i)
    {
        std::cout << "[" << i << "] " << playerController.currentRoom->adjoiningRooms[i]->name << std::endl;
    }
    int playerChoice;
    std::cin >> playerChoice;
    if (playerChoice == 0)
    {
        playerController.currentRoom = &Map::library;
        std::cout << "You are in the library" << std::endl;
    }
    Game::Wait();
        

    return 0;
}

