#include "character.h"
#include "game_elements.h"
#include <iostream>
#include <string>
#include <vector>

Character::Character(std::string name, std::vector<Item> inventory, Item weapon)
    : m_Name(name), m_Inventory(inventory), m_Weapon(weapon) 
    {
        m_Inventory.reserve(10);
        m_Inventory.push_back(weapon);
    }

void Character::PrintInventory() const 
{
    for (const Item& item : m_Inventory)
    {
        std::cout << "[" << item.name << ": " << item.description << "]" << std::endl;
    }
}

Fighter::Fighter(std::string name, std::vector<Item> inventory, Item weapon) 
    : Character(name, inventory, weapon)
{
    std::cout << "I am a Fighter!" << std::endl;
}

Mage::Mage(std::string name, std::vector<Item> inventory, Item weapon, std::vector<Spell> spells)
    : Character(name, inventory, weapon), m_Spells(spells)
{
    std::cout << "I am a Mage!" << std::endl;
}