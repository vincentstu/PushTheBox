//
// Created by Vincent Stute on 14.04.25.
//

#include "Board.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Wall.h"
#include "Entity.h"
#include "Player.h"
#include <vector>
#include "Box.h"
#include "Goal.h"
#include "Button.h"
#include "ResetButton.h"
#include "Graphic.h"
#include "RandomGuy.h"

Board::Board() {
    level = 0;
    menuActive = true;
    levelSelectionActive = false;
    won = false;
    gameFont.openFromFile("Fonts/ARCADECLASSIC.TTF");
};

void Board::horizontalLine(int xStart, int xEnd, int y) {
    for (int i = (xStart-1)*tileSize; i < xEnd * tileSize; i += tileSize) {
        Wall w((float)i, (float)(y-1)*tileSize);
        walls.push_back(w);
    }
}

void Board::verticalLine(int yStart, int yEnd, int x) {
    for (int i = (yStart-1)*tileSize; i < yEnd * tileSize; i += tileSize) {
        Wall w((float)(x-1)*tileSize, (float)i);
        walls.push_back(w);
    }
}

void Board::wallSetup(int level) {
    switch (level){
        case 0:
            //create all horizontal walls
            horizontalLine(11, 14, 2);
            horizontalLine(8, 11, 3);
            horizontalLine(14, 16, 4);
            horizontalLine(7, 11, 7);
            horizontalLine(13, 16, 7);
            horizontalLine(10, 13, 10);
            horizontalLine(7, 10, 13);
            horizontalLine(12, 16, 14);
            horizontalLine(10, 12, 12);
            horizontalLine(15, 16, 10);

            //create all vertical walls
            verticalLine(8, 12, 7);
            verticalLine(4, 6, 8);
            verticalLine(5, 6, 11);
            verticalLine(5, 6, 16);
            verticalLine(8, 9, 15);
            verticalLine(11, 13, 16);

            //create left over single walls
            horizontalLine(10, 10, 9);
            horizontalLine(14, 14, 12);
            horizontalLine(12, 12, 13);
            horizontalLine(14, 14, 3);
        break;
        case 1:
            horizontalLine(4, 8, 2);
            horizontalLine(8, 11, 4);
            horizontalLine(11, 13, 5);
            horizontalLine(10, 13, 9);
            horizontalLine(7, 11, 13);
            horizontalLine(3, 7, 11);
            horizontalLine(3, 4, 4);
            horizontalLine(7, 8, 8);

            verticalLine(5, 10, 3);
            verticalLine(6, 9, 13);
            verticalLine(10, 12, 11);
            verticalLine(6, 7, 7);

            horizontalLine(4, 4, 3);
            horizontalLine(8, 8, 3);
            horizontalLine(6, 6, 4);
            horizontalLine(5, 5, 7);
            horizontalLine(5, 5, 9);
            horizontalLine(7, 7, 12);
            horizontalLine(7, 7, 10);
            horizontalLine(9, 9, 6);
            horizontalLine(9, 9, 11);
            horizontalLine(11, 11, 7);
        break;
        case 2:
            horizontalLine(3, 6, 4);
        horizontalLine(9, 13, 4);
        horizontalLine(13, 17, 6);
        horizontalLine(6, 9, 5);
        horizontalLine(12, 13, 7);
        horizontalLine(14, 17, 9);
        horizontalLine(4, 7, 9);
        horizontalLine(9, 12, 9);
        horizontalLine(3, 7, 12);
        horizontalLine(7, 11, 11);
        horizontalLine(10, 14, 12);
        horizontalLine(9, 10, 8);
        horizontalLine(6, 7, 7);

        verticalLine(5, 11, 3);
        verticalLine(7, 8, 17);
        verticalLine(5, 11, 3);
        verticalLine(10, 11, 14);

        horizontalLine(13, 13, 5);
        horizontalLine(10, 10, 7);
    }
}

void Board::playerSetup(int level, Player &p1, Player &p2) {
    p1.setPos(this->player1Locations[level].first, this->player1Locations[level].second);
    p2.setPos(this->player2Locations[level].first, this->player2Locations[level].second);
}

void Board::boxSetup(int level, Box &box) {
    box.setPos(this->boxLocations[level].first, this->boxLocations[level].second);
}

void Board::goalSetup(int level, Goal &goal) {
    goal.setPos(this->goalLocations[level].first, this->goalLocations[level].second);
}

//remove Player 2
void Board::drawAll(Player p1, Player p2, Box box, Goal goal, std::vector<Wall> &walls, sf::RenderWindow &window) {
    for (Wall w : walls) {
        w.drawEntity(window);
    }
    goal.drawEntity(window);
    box.drawEntity(window);
    p1.drawEntity(window);
    //p2.drawEntity(window);
}

bool Board::checkGoal(Box &box) {
    if (box.getPosX() == goalLocations[level].first && box.getPosY() == goalLocations[level].second) {
        return true;
    }
    return false;
}

void Board::levelSetup(int level, Player &p1, Player &p2, Box &box, Goal &goal) {
    std::cout << level;
    walls.clear();

    playerSetup(level, p1, p2);
    boxSetup(level, box);
    goalSetup(level, goal);
    wallSetup(level);
}

void Board::nextLevel(Player &p1, Player &p2, Box &box, Goal &goal) {
    std::cout << "Next Level Reached!" << std::endl;
    level++;
    //walls.clear();

    levelSetup(level, p1, p2, box, goal);
}

void Board::menu() {
    menuActive = true;
}


void Board::startGame() {
    sf::RenderWindow window(sf::VideoMode({width*tileSize, height*tileSize}), title, sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(frameRate);

    Graphic title({tileSize, 3*tileSize});
    Button play("Play", {300, 60}, {7*tileSize, 6*tileSize}, gameFont, sf::Color::Black, sf::Color::Red);
    Button levelSelection("Level Selection", {300, 60}, {7*tileSize, 8*tileSize}, gameFont, sf::Color::Black, sf::Color::Red);
    RandomGuy rando("Textures/Title.png");

    Button level1("1", {75, 75}, {7*tileSize, 6*tileSize}, gameFont, sf::Color::Black, sf::Color::Red);
    Button level2("2", {75, 75}, {9*tileSize, 6*tileSize}, gameFont, sf::Color::Black, sf::Color::Red);
    Button level3("3", {75, 75}, {11*tileSize, 6*tileSize}, gameFont, sf::Color::Black, sf::Color::Red);

    ResetButton reset({950, 0});

    Player p1("Textures/Player.png");
    Player p2("Textures/Player.png");
    Box box;
    Goal goal;

    sf::Text wonText(gameFont, "You Won!", 100);
    wonText.setPosition({6.5*tileSize, 6*tileSize});

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    !menuActive ? menuActive = true : menuActive = false;
                }
            }
            if (const auto* mouseClick = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseClick->button == sf::Mouse::Button::Left) {
                    if (reset.isMouseOver(window) && !menuActive) {
                        levelSetup(level, p1, p2, box, goal);
                    } else if (play.isMouseOver(window) && menuActive && !levelSelectionActive) {
                        std::cout << "play";
                        menuActive = false;
                        levelSetup(level, p1, p2, box, goal);
                    } else if (levelSelection.isMouseOver(window) && menuActive && !levelSelectionActive) {
                        levelSelectionActive = true;
                    } else if (levelSelectionActive && level1.isMouseOver(window)) {
                        menuActive = false;
                        levelSelectionActive = false;
                        level = 0;
                        levelSetup(level, p1, p2, box, goal);
                    }else if (levelSelectionActive && level2.isMouseOver(window)) {
                        menuActive = false;
                        levelSelectionActive = false;
                        level = 1;
                        levelSetup(level, p1, p2, box, goal);
                    }else if (levelSelectionActive && level3.isMouseOver(window)) {
                        menuActive = false;
                        levelSelectionActive = false;
                        level = 2;
                        levelSetup(level, p1, p2, box, goal);
                    }
                }
            }
        }

        window.clear(sf::Color(98,98,114));

        if (menuActive) {
            if (!levelSelectionActive) {
                //rando.drawGuy(window);
                title.drawGraphic(window);
                play.drawButton(window);
                levelSelection.drawButton(window);
            } else {
                level1.drawButton(window);
                level2.drawButton(window);
                level3.drawButton(window);
            }
        }else {
            if (won) {
                window.draw(wonText);
            }else {
                if (moveClock.getElapsedTime().asSeconds() >= moveDelay) {
                    if (isKeyPressed(sf::Keyboard::Key::W)) {
                        p1.move(p2, box, walls, Directions::UP, tileSize);
                        moveClock.restart();
                    }
                    if (isKeyPressed(sf::Keyboard::Key::S)) {
                        p1.move(p2, box, walls, Directions::DOWN, tileSize);
                        moveClock.restart();
                    }
                    if (isKeyPressed(sf::Keyboard::Key::A)) {
                        p1.move(p2, box, walls, Directions::LEFT, tileSize);
                        moveClock.restart();
                    }
                    if (isKeyPressed(sf::Keyboard::Key::D)) {
                        p1.move(p2, box, walls, Directions::RIGHT, tileSize);
                        moveClock.restart();
                    }
                }

                if (moveClock.getElapsedTime().asSeconds() >= moveDelay) {
                    if (isKeyPressed(sf::Keyboard::Key::Up)) {
                        p2.move(p1, box, walls, Directions::UP, tileSize);
                        moveClock.restart();
                    }
                    if (isKeyPressed(sf::Keyboard::Key::Down)) {
                        p2.move(p1, box, walls, Directions::DOWN, tileSize);
                        moveClock.restart();
                    }
                    if (isKeyPressed(sf::Keyboard::Key::Left)) {
                        p2.move(p1, box, walls, Directions::LEFT, tileSize);
                        moveClock.restart();
                    }
                    if (isKeyPressed(sf::Keyboard::Key::Right)) {
                        p2.move(p1, box, walls, Directions::RIGHT, tileSize);
                        moveClock.restart();
                    }
                }

                if (checkGoal(box)) {
                    if (level == 2) {
                        won = true;
                    }else {
                        nextLevel(p1, p2, box, goal);
                    }
                }

                reset.drawButton(window);
                drawAll(p1, p2, box, goal, walls, window);
            }
        }

        window.display();
    }
}
