#include "character.h"
#include "game_elements.h"
#include <iostream>
#include <string>
#include <vector>

Character::Character(std::string name, std::vector<Item> inventory, Item weapon)
    : m_Name(name), m_Inventory(inventory), m_Weapon(weapon) 
    {
        m_Inventory.reserve(20);
        m_Inventory.push_back(weapon);
    }

void Character::AddItemToInventory(const Item& item)
{
    m_Inventory.emplace_back(item);
}

Fighter::Fighter(std::string name, std::vector<Item> inventory, Item weapon) 
    : Character(name, inventory, weapon)
{
    std::cout << "I am a Fighter!\n";
}

Mage::Mage(std::string name, std::vector<Item> inventory, Item weapon, std::vector<Spell> spells)
    : Character(name, inventory, weapon), m_Spells(spells)
{
    std::cout << "I am a Mage!\n";
}
