#include <iostream>
#include <string>
#include <vector>

void Wait()
{
    std::cin.ignore();
    std::cin.get();
}
enum class CharacterType 
{
    Fighter,
    Mage
};

struct Item
{
    std::string name;
    std::string description;
};

struct Spell
{
};

class Character
{
protected:
    std::string m_Name;
    std::vector<Item> m_Inventory;
    Item m_Weapon;

public:
    Character();

    Character(std::string name, std::vector<Item> inventory, Item weapon)
        : m_Name(name), m_Inventory(inventory), m_Weapon(weapon)
    {
        m_Inventory.reserve(10);
        m_Inventory.push_back(weapon);
    }

    void PrintInventory() const
    {
        for (auto& item : m_Inventory)
        {
            std::cout << "[" << item.name << ": " << item.description << "]" << std::endl;
        }
    }
};

class Fighter : public Character
{
public:
    Fighter(std::string name, std::vector<Item> inventory, Item weapon) 
        : Character(name, inventory, weapon)
    {
        std::cout << "I am a Fighter!" << std::endl;
    }
};

class Mage : public Character
{
private:
    std::vector<Spell> m_Spells;

public:
    Mage(std::string name, std::vector<Item> inventory, Item weapon, std::vector<Spell> spells)
        : Character(name, inventory, weapon), m_Spells(spells)
    {
        std::cout << "I am a Mage!" << std::endl;
    }
};

Character* character;

void ChoseCharacter();
void StartIntro();

int main()
{
    ChoseCharacter();
    std::cout << "Press enter to continue..." << std::endl;
    Wait();
    system("clear");
    StartIntro();
    Wait();
    std::cout << "Your current items are: \n" << std::endl;
    character->PrintInventory();

    return 0;
}

void ChoseCharacter()
{
    CharacterType chosenCharacter;
    bool hasChosenCharacter = false;
    std::cout << "Choose a character type" << std::endl;
    std::cout << "[" << static_cast<int>(CharacterType::Fighter) << "] Fighter" << std::endl;
    std::cout << "[" << static_cast<int>(CharacterType::Mage) << "] Mage" << std::endl;
    while (!hasChosenCharacter)
    {
        int characterChoice;
        std::cin >> characterChoice;
        switch (characterChoice)
        {
            case 0:
                std::cout << "You chose to be a Fighter" << std::endl;
                chosenCharacter = CharacterType::Fighter;
                hasChosenCharacter = true;
                break;
            case 1:
                std::cout << "You chose to be a Mage" << std::endl;
                chosenCharacter = CharacterType::Mage;
                hasChosenCharacter = true;
                break;
            default:
                std::cout << "You did not chose a valid character type" << std::endl;
        }
    }
    Item sword = Item{"Sword", "A trusty friend in battle"};
    Item staff = Item{"Staff", "Great for casting spells, or a good thwack on the head"};
    if (chosenCharacter == CharacterType::Fighter)
        character = new Fighter("Bob", std::vector<Item>(), sword);
    if (chosenCharacter == CharacterType::Mage)
        character = new Mage("Alice", std::vector<Item>(), staff, std::vector<Spell>());
}

void StartIntro()
{
    std::cout << "You have just woken up. Your memory of recent events is gone. You stand before a great castle..." << std::endl;
}