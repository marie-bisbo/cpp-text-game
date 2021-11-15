#include <iostream>

enum class CharacterType 
{
    Fighter,
    Mage
};


int main()
{
    bool hasChosenCharacter = false;
    while (!hasChosenCharacter)
    {
        std::cout << "Choose a character type" << std::endl;
        std::cout << "[" << static_cast<int>(CharacterType::Fighter) << "] Fighter" << std::endl;
        std::cout << "[" << static_cast<int>(CharacterType::Mage) << "] Mage" << std::endl;
        int characterChoice;
        std::cin >> characterChoice;
        switch (characterChoice)
        {
            case 0:
                std::cout << "You chose to be a Fighter" << std::endl;
                hasChosenCharacter = true;
                break;
            case 1:
                std::cout << "You chose to be a Mage" << std::endl;
                hasChosenCharacter = true;
                break;
            default:
                std::cout << "You did not chose a valid character type" << std::endl;
        }
    }

    return 0;
}