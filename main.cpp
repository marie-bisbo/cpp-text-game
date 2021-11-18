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
    std::map<int, Game::Room*> rooms = Game::GetAvailableRooms(playerController);
    Game::PrintAvailableRooms(rooms);
    int playerChoice;
    std::cin >> playerChoice;
    if (rooms.find(playerChoice) != rooms.end())
    {
        playerController.currentRoom = rooms[playerChoice];
        std::cout << "You are in the " << playerController.currentRoom->name << "." << std::endl;
    }
    else
    {
        std::cout << "You did not choose a valid room" << std::endl;
    }
    Game::Wait();
        

    return 0;
}

