//
// Created by Vincent Stute on 26.04.25.
//

#include "Graphic.h"

Graphic::Graphic(sf::Vector2f pos){
    setPos(pos);
}
Graphic::Graphic(std::string file, sf::Vector2f pos) {
    texture.loadFromFile(file);
    setPos(pos);
}

void Graphic::drawGraphic(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Graphic::setPos(sf::Vector2f pos) {
    sprite.setPosition(pos);
}
