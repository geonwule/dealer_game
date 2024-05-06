#ifndef AITEM_HPP
#define AITEM_HPP

#include <iostream>

class Player;

class AItem
{
protected:
    std::string _name;
    AItem();
    
public:
    AItem(const std::string &name);
    virtual ~AItem();
    virtual std::string &getName() = 0;
    virtual void setPlayer(Player *player) = 0;
    virtual void use() = 0;
};

AItem::AItem(const std::string &name) : _name(name)
{
}

AItem::~AItem()
{

}

#endif // AITEM_HPP