//
// Created by Vincent Stute on 14.04.25.
//

#include "Wall.h"
#include "Board.h"

Wall::Wall() {
    sprite.setTexture(getTexture("Textures/Wall.png"));
    setPos(50, 50);
}
Wall::Wall(float x, float y) {
    sprite.setTexture(getTexture("Textures/Wall.png"));
    setPos(x, y);
}
Wall::Wall(std::string filename, float x, float y) {
    sprite.setTexture(getTexture(filename));
    setPos(x, y);
}

sf::Texture& Wall::getTexture(std::string file) {
    static sf::Texture texture;
    static bool loaded = false;
    if (!loaded) {
        texture.loadFromFile(file);
        loaded = true;
    }
    return texture;
}