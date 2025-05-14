//
// Created by Vincent Stute on 25.04.25.
//

#ifndef RESETBUTTON_H
#define RESETBUTTON_H
#include "SFML/Graphics.hpp"
#include "Button.h"



class ResetButton {
public:
    ResetButton(sf::Vector2f pos);
    void setPosition(sf::Vector2f pos);
    void drawButton(sf::RenderWindow &window);
    bool isMouseOver(sf::RenderWindow &window);
private:
    sf::Texture texture = sf::Texture("Textures/ResetButton.png");
    sf::Sprite sprite = sf::Sprite(texture);
};




#endif //RESETBUTTON_H
