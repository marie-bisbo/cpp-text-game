#pragma once

#include "game.h"
#include <map>

#define OUT

class RoomEvent
{
private:
    OUT Game::PlayerController& m_Controller;
    std::map<int, Game::Room*> m_AdjoiningRooms; 

    std::map<int, Game::Room*> GetAdjoiningRooms() const;

    void ExploreRoom(Game::PlayerController& controller);

public:
    RoomEvent(Game::PlayerController& controller);

    void PrintAvailableOptions();
    void ChooseNextAction();
};
