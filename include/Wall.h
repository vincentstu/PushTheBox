//
// Created by Vincent Stute on 14.04.25.
//

#ifndef WALL_H
#define WALL_H
#include "Entity.h"



class Wall : public Entity{
public:
    Wall();
    Wall(float x, float y);
    Wall(std::string filename, float x, float y);

    sf::Texture& getTexture(std::string file);
    std::string name = "Wall";
};



#endif //WALL_H
