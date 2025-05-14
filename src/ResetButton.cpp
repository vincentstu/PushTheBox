//
// Created by Vincent Stute on 25.04.25.
//

#include "ResetButton.h"

ResetButton::ResetButton(sf::Vector2f pos) {
    setPosition(pos);
}

void ResetButton::setPosition(sf::Vector2f pos) {
    sprite.setPosition(pos);
}

void ResetButton::drawButton(sf::RenderWindow &window) {
    window.draw(sprite);
}

bool ResetButton::isMouseOver(sf::RenderWindow &window) {
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float buttonX = sprite.getPosition().x;
    float buttonY = sprite.getPosition().y;

    if (mouseX >= buttonX && mouseX <= (buttonX + sprite.getLocalBounds().size.x) && mouseY >= buttonY && mouseY <= (buttonY + sprite.getLocalBounds().size.y)) {
        return true;
    }
    return false;
}
