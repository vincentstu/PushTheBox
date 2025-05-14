//
// Created by Vincent Stute on 23.04.25.
//

#ifndef BUTTON_H
#define BUTTON_H
#include "SFML/Graphics.hpp"


class Button {
public:
    Button();
    Button(std::string txt, sf::Vector2f size, sf::Vector2f pos, sf::Font& font, sf::Color buttonColor, sf::Color textColor): text(font, txt, 28) {
        this->text.setFillColor(textColor);

        this->button.setSize(size);
        this->button.setFillColor(buttonColor);
        setPosition(pos.x, pos.y);
    }

    void setPosition(float x, float y) {
        button.setPosition({x, y});

        float textX = (x + button.getLocalBounds().size.x / 2) - (text.getLocalBounds().size.x / 2);
        float textY = (y + button.getLocalBounds().size.y / 2) - (text.getLocalBounds().size.y / 2) - 10;
        text.setPosition({textX, textY});
    }
    void drawButton(sf::RenderWindow &window) {
        window.draw(button);
        window.draw(text);
    }

    bool isMouseOver(sf::RenderWindow &window) {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float buttonX = button.getPosition().x;
        float buttonY = button.getPosition().y;

        if (mouseX >= buttonX && mouseX <= (buttonX + button.getSize().x) && mouseY >= buttonY && mouseY <= (buttonY + button.getSize().y)) {
            return true;
        }
        return false;
    }

private:
    sf::RectangleShape button;
    sf::Text text;
};



#endif //BUTTON_H
