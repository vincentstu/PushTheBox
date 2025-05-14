//
// Created by Vincent Stute on 18.04.25.
//

#ifndef GOAL_H
#define GOAL_H
#include "Entity.h"



class Goal : public Entity {
public:
    Goal();
    sf::Texture& getTexture(std::string file);
};



#endif //GOAL_H
