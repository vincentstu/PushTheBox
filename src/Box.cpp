//
// Created by Vincent Stute on 17.04.25.
//

#include "Box.h"
#include <iostream>
#include "Player.h"
#include "Board.h"

Box::Box(){
    sprite.setTexture(getTexture("Textures/Box.png"));
}

Box::Box(float x, float y) {
    sprite.setTexture(getTexture("Textures/Box.png"));
    setPos(x, y);
}

sf::Texture& Box::getTexture(std::string file) {
    static sf::Texture texture;
    static bool loaded = false;
    if (!loaded) {
        texture.loadFromFile(file);
        loaded = true;
    }
    return texture;
}

bool Box::collision(Player &p1, Player &p2, std::vector<Wall> &walls, float x, float y) {
    if (p1.getPosX() == x && p1.getPosY() == y || p2.getPosX() == x && p2.getPosY() == y) {
        return true;
    }
    for (Entity w : walls) {
        if (w.getPosX() == x && w.getPosY() == y) {
            return true;
        }
    }
    return false;
}
bool Box::outOfMap(float x, float y) {
    Board board;
    if (x >= ((float)board.width) * Board::tileSize ||
        y >= ((float)board.height) * Board::tileSize ||
        x < 0 || y < 0)
    {
        return true;
    }
    return false;
}
bool Box::move(Player &p1, Player &p2, std::vector<Wall> &walls, Directions d, int stepSize) {
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
            xStep -= stepSize;
        break;
        case Directions::RIGHT:
            xStep += stepSize;
        break;

    }
    float newPosX = getPosX() + (float)xStep;
    float newPosY = getPosY() + (float)yStep;
    if (!outOfMap(newPosX, newPosY) && !collision(p1, p2, walls, newPosX, newPosY)) {
        setPos(newPosX, newPosY);
        return true;
    }
    else {
        std::cout << "Out of Map";
        return false;
    }
}