#include <iostream>
#include "room_event.h"
#include "game.h"

RoomEvent::RoomEvent(Game::PlayerController& controller)
    : m_Controller(controller), m_AdjoiningRooms(GetAdjoiningRooms()) {}

std::map<int, Game::Room*> RoomEvent::GetAdjoiningRooms() const
{
    std::map<int, Game::Room*> roomOptions;
    for (size_t i = 0; i <m_Controller.currentRoom->adjoiningRooms.size(); ++i)
    {
        roomOptions[i] = m_Controller.currentRoom->adjoiningRooms[i];
    }

    return roomOptions;
}

void RoomEvent::ExploreRoom()
{
    std::vector<Item> itemsInRoom = m_Controller.currentRoom->items;
    for (const auto& item : itemsInRoom)
    {
        std::cout << item.name << '\n';
        std::cout << item.description << '\n';
        m_Controller.character->AddItemToInventory(item);
    }
}

void RoomEvent::PrintAvailableActions()
{
    for (auto const& [index, room] : m_AdjoiningRooms)
    {
        std::cout << "[" << index << "] " << "Go to " << room->name << '\n';
    }
    if (!m_Controller.currentRoom->isExplored)
        std::cout << "[" << m_AdjoiningRooms.size() << "] Explore Room\n";
}

void RoomEvent::ChooseNextAction()
{
    int playerChoice;
    std::cin >> playerChoice;
    if (m_AdjoiningRooms.find(playerChoice) != m_AdjoiningRooms.end()) // C++20 use contains
    {
        m_Controller.currentRoom = m_AdjoiningRooms.at(playerChoice);
        std::cout << "You are in the " << m_Controller.currentRoom->name << ".\n";
    }
    else if (playerChoice == m_AdjoiningRooms.size() && !m_Controller.currentRoom->isExplored)
    {
        ExploreRoom();
        m_Controller.currentRoom->isExplored = true;
    }
    else
        std::cout << "Oops, seems like you can't do that\n";
}
