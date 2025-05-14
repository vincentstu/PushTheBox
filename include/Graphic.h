//
// Created by Vincent Stute on 26.04.25.
//

#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <iostream>

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"


class Graphic {
public:
    Graphic(sf::Vector2f pos);
    Graphic(std::string file, sf::Vector2f pos);
    void drawGraphic(sf::RenderWindow &window);
    void setPos(sf::Vector2f pos);
private:
    sf::Texture texture = sf::Texture("Textures/Title.png");
    sf::Sprite sprite = sf::Sprite(texture);
};



#endif //GRAPHIC_H
