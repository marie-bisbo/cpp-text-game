#include "game_elements.h"
#include "character.h"
#include "game.h"
#include "map.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>


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
    std::map<int, std::string> roomOptions;
    for (size_t i = 0; i < playerController.currentRoom->adjoiningRooms.size(); ++i)
    {
        roomOptions[i] = playerController.currentRoom->adjoiningRooms[i]->name;
        std::cout << "[" << i << "] " << playerController.currentRoom->adjoiningRooms[i]->name << std::endl;
    }
    int playerChoice;
    std::cin >> playerChoice;
    if (roomOptions.find(playerChoice) != roomOptions.end())
    {
        playerController.currentRoom = &Map::library;
        std::cout << "You are in the library" << std::endl;
    }
    else
    {
        std::cout << "You did not choose a valid room" << std::endl;
    }
    Game::Wait();
        

    return 0;
}

