#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AItem.hpp"
#include <iostream>
#include <algorithm>
#define MAX_HP 5
#define SLOT_SIZE 4

class Player
{
private:
    std::string _name;
    int _hp;
    AItem *slots[SLOT_SIZE];
    Player();

public:
    Player(const std::string &name);
    ~Player();

    std::string& getName() { return _name; };
    int getHp() const { return _hp; };
    void showItem();

    void recoverd() { _hp = std::min(MAX_HP, _hp + 1); };
    void damaged() { _hp = std::max(0, _hp - 1); };

    void setItem(AItem *item);
    void useItem(int index);
};

Player::Player(const std::string &name) : _name(name), _hp(MAX_HP)
{
    for (int i = 0; i < SLOT_SIZE; i++)
    {
        slots[i] = nullptr;
    }
}

Player::~Player()
{
}

void Player::showItem()
{
    for (int i = 0; i < SLOT_SIZE; i++)
    {
        std::cout << i << ". ";
        if (slots[i] != nullptr)
        {
            std::cout << slots[i]->getName();
        }
        else
            std::cout << "Empty";
        std::cout << " | ";
    }
    std::cout << std::endl;
}

void Player::setItem(AItem *item)
{
    for (int i = 0; i < SLOT_SIZE; i++)
    {
        if (slots[i] == nullptr)
        {
            item->setPlayer(this);
            slots[i] = item;
            break;
        }
    }
}

void Player::useItem(int index)
{
    if (!(index >= 0 && index < SLOT_SIZE) ||  slots[index] == nullptr)
    {
        std::cout << "Empty slot" << std::endl;
        return;
    }
    std::cout << slots[index]->getName() << " used" << std::endl;
    slots[index]->use();
    delete slots[index];
    slots[index] = nullptr;
}

#endif // PLAYER_HPP
