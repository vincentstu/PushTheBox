//
// Created by Vincent Stute on 15.04.25.
//

#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include "Directions.h"



class Entity {
public:
    std::string name;

    explicit Entity();
    Entity(float x, float y);
    void drawEntity(sf::RenderWindow &window);
    float getPosX() const;
    float getPosY() const;
    void setPos(float x, float y);

    sf::Texture& getTexture(std::string file);

protected:
    sf::Texture texture = sf::Texture("Textures/Entity.png");
    sf::Sprite sprite;
};



#endif //ENTITY_H
