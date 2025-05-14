//
// Created by Vincent Stute on 17.04.25.
//

#ifndef BOX_H
#define BOX_H
#include "Entity.h"
#include "Wall.h"
//#include "Player.h"

class Player;

class Box : public Entity{
public:
    Box();
    Box(float x, float y);
    static bool outOfMap(float x, float y);
    bool collision(Player &p1, Player &p2, std::vector<Wall> &walls,float x, float y);
    bool move(Player &p1, Player &p2, std::vector<Wall> &walls, Directions d, int stepSize);
    sf::Texture& getTexture(std::string file);
};



#endif //BOX_H
