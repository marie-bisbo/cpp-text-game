#pragma once

#include "game_elements.h"
#include <string>
#include <vector>

class Character
{
protected:
    std::string m_Name;
    std::vector<Item> m_Inventory;
    Item m_Weapon;

public:
    Character();

    Character(std::string name, std::vector<Item> inventory, Item weapon);

    void PrintInventory() const;
};

class Fighter : public Character
{
public:
    Fighter(std::string name, std::vector<Item> inventory, Item weapon);
};

class Mage : public Character
{
private:
    std::vector<Spell> m_Spells;

public:
    Mage(std::string name, std::vector<Item> inventory, Item weapon, std::vector<Spell> spells);
};