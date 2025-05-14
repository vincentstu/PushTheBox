//
// Created by Vincent Stute on 15.04.25.
//
#include "Player.h"
#include "Board.h"
#include <iostream>
#include "Box.h"


Player::Player() {
    sprite.setTexture(getTexture("Textures/Player.png"));
    name = "Player";
    facing = Directions::LEFT;
}
Player::Player(std::string textureFile) {
    sprite.setTexture(getTexture(textureFile));
    name = "Player";
    this->facing = Directions::LEFT;
}
Player::Player(std::string name, std::string textureFile, float x, float y) {
    sprite.setTexture(getTexture(textureFile));
    this->name = name;
    setPos(x, y);
    facing = Directions::LEFT;
}
Player::Player(std::string name, float x, float y) {
    texture = sf::Texture("Textures/Player.png");
    sprite.setTexture(texture);
    this->name = name;
    setPos(x, y);
    facing = Directions::LEFT;
}

sf::Texture& Player::getTexture(std::string file) {
    static sf::Texture texture;
    static bool loaded = false;
    if (!loaded) {
        texture.loadFromFile(file);
        loaded = true;
    }
    return texture;
}

bool Player::outOfMap(float x, float y) {
    Board board;
    if (x >= ((float)board.width) * Board::tileSize ||
        y >= ((float)board.height) * Board::tileSize ||
        x < 0 || y < 0)
    {
        return true;
    }
    return false;
}

void Player::flip(Directions d) {
    if (d == Directions::LEFT) {
        sprite.setOrigin({50.f,0.f});
        sprite.setScale({1.f, 1.f});
    }else if (d == Directions::RIGHT) {
        sprite.setOrigin({0.f,0.f});
        sprite.setScale({-1.f,1.f});
    }
}

bool Player::collision(Player &p, Box &box, std::vector<Wall> &walls, float x, float y, Directions d, int step) {
    if (p.getPosX() == x && p.getPosY() == y) {
        return true;
    }
    if (box.getPosX() == x && box.getPosY() == y) {
        if (box.move(*this, p, walls, d, step)) {
            return false;
        }
        return true;
    }
    for (Entity w : walls) {
        if (w.getPosX() == x && w.getPosY() == y) {
            return true;
        }
    }
    return false;
}
void Player::move(Player &p, Box &box, std::vector<Wall> &walls, Directions d, int stepSize) {
    int xStep = 0;
    int yStep = 0;
    switch (d) {
        case Directions::UP:
            yStep -= stepSize;
        break;
        case Directions::DOWN:
            yStep += stepSize;
        break;
        case Directions::LEFT:
            //flip(d);
            xStep -= stepSize;
        break;
        case Directions::RIGHT:
            //flip(d);
            xStep += stepSize;
        break;

    }
    float newPosX = getPosX() + (float)xStep;
    float newPosY = getPosY() + (float)yStep;
    if (!outOfMap(newPosX, newPosY) && !collision(p, box, walls, newPosX, newPosY, d, stepSize)) {
        setPos(newPosX, newPosY);
    }
}


