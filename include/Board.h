//
// Created by Vincent Stute on 14.04.25.
//

#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Wall.h"
#include <vector>

#include "Goal.h"


class Board {
public:
    sf::RenderWindow window;
    const std::string title = "Push the Box";
    unsigned int width = 20;
    unsigned int height = 15;
    static const int tileSize = 50;

    Board();
    void startGame();
    void horizontalLine(int xStart, int xEnd, int y);
    void verticalLine(int yStart, int yEnd, int x);
    void wallSetup(int level);
    void playerSetup(int level, Player &p1, Player &p2);
    void goalSetup(int level, Goal &goal);
    void drawAll(Player p1, Player p2, Box box, Goal goal, std::vector<Wall> &walls, sf::RenderWindow &window);
    bool checkGoal(Box &box);
    void nextLevel(Player &p1, Player &p2, Box &box, Goal &goal);
    void boxSetup(int level, Box &box);
    void levelSetup(int level, Player &p1, Player &p2, Box &box, Goal &goal);
    void menu();

private:
    sf::Font gameFont;
    int level;
    bool menuActive;
    bool won;
    bool levelSelectionActive;
    std::vector<std::pair<int, int>> goalLocations = {{12*tileSize, 7*tileSize},{3*tileSize,9*tileSize}, {11*tileSize, 7*tileSize}};
    std::vector<std::pair<int, int>> player1Locations = {{8*tileSize, 5*tileSize},{3*tileSize,4*tileSize}, {10*tileSize, 5*tileSize}};
    std::vector<std::pair<int, int>> player2Locations = {{0.f, 0},{0,0}};
    std::vector<std::pair<int, int>> boxLocations = {{10*tileSize, 3*tileSize},{8*tileSize,6*tileSize}, {10*tileSize, 6*tileSize}};
    sf::Clock moveClock;
    const int frameRate = 60;
    const float moveDelay = 0.15f;
    std::vector<Wall> walls;
};



#endif //BOARD_H
