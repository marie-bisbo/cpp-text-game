#include <iostream>
#include <vector>
#include "game.h"

namespace Map {

    extern Game::Room foyer;
    extern Game::Room library;

    Game::Room foyer = Game::Room{"Foyer", std::vector<Item>{Item{"Key", "I wonder what this may open."}}, std::vector<Game::Room*>{&library}};
    Game::Room library = Game::Room{"Library", std::vector<Item>{Item{"Letter", "Who could have written this?"}}, std::vector<Game::Room*>()};
}

