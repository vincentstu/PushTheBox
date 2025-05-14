//
// Created by Vincent Stute on 15.04.25.
//

#include "Entity.h"

Entity::Entity() : sprite(texture){
    name = "Entity";
    setPos(50, 50);
}
Entity::Entity(float x, float y) : sprite(texture){
    name = "Entity";
    setPos(x, y);
}

void Entity::drawEntity(sf::RenderWindow &window) {
    window.draw(sprite);
}
float Entity::getPosX() const {
    return sprite.getPosition().x;
};
float Entity::getPosY() const {
    return sprite.getPosition().y;
};
void Entity::setPos(float x, float y) {
    sprite.setPosition({x,y});
}

sf::Texture& Entity::getTexture(std::string file) {
    static sf::Texture texture;
    static bool loaded = false;
    if (!loaded) {
        texture.loadFromFile(file);
        loaded = true;
    }
    return texture;
}
