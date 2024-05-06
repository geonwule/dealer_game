#include <iostream>
#include <fstream>

void printFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::string line;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else
    {
        std::cerr << "Error: Could not open file" << std::endl;
    }
}

#define SCRIPTS_PATH "srcs/scripts/"
#define SCR_00 "00_explain"

std::string getScriptPath(const std::string& scriptName)
{
    return std::string(SCRIPTS_PATH) + scriptName;
}

void prompt(const std::string& message) {
    std::cout << message;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#define HEIGHT 30
#define WIDTH 50

int interface[HEIGHT][WIDTH];

void printInterface()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            std::cout << interface[i][j];
        }
        std::cout << std::endl;
    }
}

#include "round.hpp"
#include "AItem.hpp"
#include "Item_portion.hpp"

int main()
{
    printFile(getScriptPath(SCR_00));
    prompt("\nPress Enter to continue...");
    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);

    Round round(playerName);
    while(1)
    {
        round.showInterface();
        round.equipItem(round.generateItem());
        std::cout << "Input use Item number: ";
        std::string index;
        std::getline(std::cin, index);
        round.useItem(std::stoi(index));
    }
    return 0;
}