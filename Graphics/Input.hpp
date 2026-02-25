#include <SFML/Graphics.hpp>
#include <string>

class Input {
public:
    Input(sf::Font& font, sf::Vector2f pos, sf::Vector2f size);
    void handleEvent( sf::Event& event);
    void draw(sf::RenderWindow& window);
    std::string getValue();

private:
    sf::RectangleShape box;
    sf::Text text;
    std::string input;
    bool focused;
};
