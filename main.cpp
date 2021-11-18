#include "game_elements.h"
#include "character.h"
#include "game.h"
#include "map.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>


std::map<int, Game::Room*> GetAvailableRooms(const Game::PlayerController& controller)
{
    std::map<int, Game::Room*> roomOptions;
    for (size_t i = 0; i < controller.currentRoom->adjoiningRooms.size(); ++i)
    {
        roomOptions[i] = controller.currentRoom->adjoiningRooms[i];
    }

    return roomOptions;
}

void PrintAvailableRooms(const std::map<int, Game::Room*>& availableRooms)
{
    for (auto const& [index, room] : availableRooms)
    {
        std::cout << "[" << index << "] " << room->name << std::endl;
    }
}


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
    std::map<int, Game::Room*> rooms = GetAvailableRooms(playerController);
    PrintAvailableRooms(rooms);
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

