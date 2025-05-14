//
// Created by Vincent Stute on 15.04.25.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Box.h"
#include "Entity.h"
#include "Wall.h"

class Box;

class Player : public Entity {
public:
    Player();
    Player(std::string name, float x, float y);
    Player(std::string textureFile);
    Player(std::string name, std::string textureFile, float x, float y);

    static bool outOfMap(float x, float y);
    bool collision(Player &p, Box &box, std::vector<Wall> &walls,float x, float y, Directions d, int step);
    void move(Player &p, Box &box, std::vector<Wall> &walls, Directions d, int stepSize);
    void flip(Directions d);
    sf::Texture& getTexture(std::string file);
    Directions facing;
};



#endif //PLAYER_H
