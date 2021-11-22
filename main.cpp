#include "game_elements.h"
#include "character.h"
#include "game.h"
#include "map.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

#define OUT

void ExploreRoom(Game::PlayerController& controller);
void ChooseNextAction(const std::map<int, Game::Room*>& rooms, OUT Game::PlayerController& controller);
void EnterRoom();

void EnterRoom()
{
    // To do later
    // If there are enemies, combat starts
    // When all enemies are dead, options are move to different room or explore

    // To do now 
    // ChooseNextAction();
}

void ChooseNextAction(const std::map<int, Game::Room*>& rooms, OUT Game::PlayerController& controller)
{
    int playerChoice;
    std::cin >> playerChoice;
    if (rooms.find(playerChoice) != rooms.end()) // C++20 use contains
    {
        controller.currentRoom = rooms.at(playerChoice);
        std::cout << "You are in the " << controller.currentRoom->name << ".\n";
    }
    else if (playerChoice == rooms.size() && !controller.currentRoom->isExplored)
    {
        ExploreRoom(controller);
        controller.currentRoom->isExplored = true;
    }
    else
        std::cout << "Oops, seems like you can't do that\n";
}

void ExploreRoom(Game::PlayerController& controller)
{
    std::vector<Item> itemsInRoom = controller.currentRoom->items;
    for (const auto& item : itemsInRoom)
    {
        std::cout << item.name << '\n';
        std::cout << item.description << '\n';
        controller.character->AddItemToInventory(item);
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
        Game::PrintAvailableOptions(rooms, playerController);
        ChooseNextAction(rooms, playerController);
    }

    return 0;
}

