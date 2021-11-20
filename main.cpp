#include "game_elements.h"
#include "character.h"
#include "game.h"
#include "map.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

#define OUT

void MoveToRoom(const std::map<int, Game::Room*>& rooms, OUT Game::PlayerController& controller)
{
    int playerChoice;
    std::cin >> playerChoice;
    if (rooms.find(playerChoice) != rooms.end()) // C++20 use .contains
    {
        controller.currentRoom = rooms.at(playerChoice);
        std::cout << "You are in the " << controller.currentRoom->name << ".\n";
    }
    else
    {
        std::cout << "You did not choose a valid room\n";
    }
}

int main()
{
    bool gameRunning = true;
    Game::PlayerController playerController;
    Game::ChoseCharacter(playerController);
    Game::Wait();
    system("clear");
    Game::StartIntro();
    Game::Wait();
    playerController.currentRoom = &Map::foyer;
    std::cout << "You are in the " << playerController.currentRoom->name << ".\n";
    std::cout << "Where would you like to go next?\n";
    while (gameRunning)
    {
        std::map<int, Game::Room*> rooms = Game::GetAvailableRooms(playerController);
        Game::PrintAvailableRooms(rooms);
        MoveToRoom(rooms, playerController);
    }

    return 0;
}

