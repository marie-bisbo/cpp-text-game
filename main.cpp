#include "game_elements.h"
#include "character.h"
#include "game.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    Game::PlayerInfo playerInfo;
    Game::ChoseCharacter(playerInfo);
    Game::Wait();
    system("clear");
    Game::StartIntro();
    Game::Wait();

    return 0;
}

