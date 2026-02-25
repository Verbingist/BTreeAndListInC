#include "Input.hpp"

Input::Input(sf::Font &font, sf::Vector2f pos, sf::Vector2f size)
{
    box.setSize(size);
    box.setFillColor(sf::Color::White);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(2.f);
    box.setPosition(pos);

    text.setFont(font);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::Black);
    text.setPosition(pos.x + 5.f, pos.y + 5.f);

    focused = false;
}

void Input::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2f mouse(event.mouseButton.x, event.mouseButton.y);
        focused = box.getGlobalBounds().contains(mouse);
    }

    if (focused && event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode == 8)
        {
            if (!input.empty())
            {
                input.erase(input.size() - 1);
            }
        }
        else if (event.text.unicode < 128)
        {
            if (input.size() < 15)
            {
                input += static_cast<char>(event.text.unicode);
            }
        }
        text.setString(input);
    }
}

void Input::draw(sf::RenderWindow &window)
{
    window.draw(box);
    window.draw(text);
}

std::string Input::getValue()
{
    return input;
}
