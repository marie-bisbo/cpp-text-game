#pragma once

#include <iostream>
#include <vector>
#include "game.h"

namespace Map {

    extern Game::Room foyer;
    extern Game::Room library;
    extern Game::Room office;
    extern Game::Room diningRoom;

    Game::Room foyer = Game::Room{"Foyer", std::vector<Item>{Item{"Key", "I wonder what this may open."}}, std::vector<Game::Room*>{&library, &office, &diningRoom}};
    Game::Room library = Game::Room{"Library", std::vector<Item>{Item{"Letter", "Who could have written this?"}}, std::vector<Game::Room*>{&foyer}};
    Game::Room office = Game::Room{"Office", std::vector<Item>{Item{"Letter", "Who could have written this?"}}, std::vector<Game::Room*>{&foyer}};
    Game::Room diningRoom = Game::Room{"Dining Room", std::vector<Item>{Item{"Letter", "Who could have written this?"}}, std::vector<Game::Room*>{&foyer}};
}

