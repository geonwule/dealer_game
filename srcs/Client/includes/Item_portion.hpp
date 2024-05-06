#ifndef ITEM_PORTION_HPP
#define ITEM_PORTION_HPP

#include "AItem.hpp"
#include "player.hpp"

class Item_portion : public AItem
{
private:
    Player* _player;

public:
    Item_portion();
    ~Item_portion();
    void use() override
    {
        _player->recoverd();
    }
    std::string &getName() override { return _name; };

    void setPlayer(Player *player) override  { _player = player; };
};

Item_portion::Item_portion() : AItem("Portion"), _player(nullptr)
{

}

Item_portion::~Item_portion()
{

}

#endif // ITEM_PORTION_HPP