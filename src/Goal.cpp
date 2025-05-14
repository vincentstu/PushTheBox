//
// Created by Vincent Stute on 18.04.25.
//

#include "Goal.h"

Goal::Goal(){
    sprite.setTexture(getTexture("Textures/Goal.png"));
}

sf::Texture& Goal::getTexture(std::string file) {
    static sf::Texture texture;
    static bool loaded = false;
    if (!loaded) {
        texture.loadFromFile(file);
        loaded = true;
    }
    return texture;
}
