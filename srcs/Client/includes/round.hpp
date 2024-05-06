#ifndef ROUND_HPP
#define ROUND_HPP

#include <cstdlib> // std::rand, std::srand
#include <ctime>   // std::time
#include "player.hpp"
#include <iostream>
#include "AItem.hpp"
#include "Item_portion.hpp"

class Round
{
private:
    Player dealer, player;
    Round();

public:
    Round(const std::string& player_name);
    ~Round();

    void showInterface();
    int getRandomNumber()
    {
        std::srand(std::time(0));       // 현재 시간을 기반으로 난수 생성기를 초기화합니다.
        return std::rand(); // 랜덤한 값을 생성합니다.
    }

    void equipItem(AItem *item)
    {
        player.setItem(item);
    }

    AItem *generateItem()
    {
        return new Item_portion();
        // int random = getRandomNumber() % 2;
        // if (random == 0)
        // {
        //     player.setItem(new Item_portion());
        // }
    }

    void useItem(int index)
    {
        player.useItem(index);
    }
};

Round::Round(const std::string& player_name) : dealer("Dealer"), player(player_name)
{
}

Round::~Round()
{
}

void Round::showInterface()
{
    player.damaged();

    std::cout << "========" << dealer.getName() << "========" << std::endl;
    std::cout << "HP: " << dealer.getHp() << std::endl;
    dealer.showItem();


    std::cout << "========" << player.getName() <<"========" << std::endl;
    std::cout << "HP: " << player.getHp() << std::endl;
    player.showItem();
}

#endif // ROUND_HPP