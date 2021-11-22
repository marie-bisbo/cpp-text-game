#include "game_elements.h"
#include "character.h"
#include "game.h"
#include "map.h"
#include "room_event.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

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
        RoomEvent roomEvent = RoomEvent(playerController);
        roomEvent.PrintAvailableOptions();
        roomEvent.ChooseNextAction();
    }

    return 0;
}

