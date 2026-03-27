#include <SFML/Graphics.hpp>
#include "HashMap.hpp"
#include "../Timer.hpp"
#include "../Graphics/Input.hpp"
#include <vector>
#include <format>

class HashGraph
{
public:
    HashGraph(sf::RenderWindow &window);
    void run();
    void render();
    bool eventTest();
    void hashOutput();
    void timerOutput();

private:
    HashMap hashmap;
    int pageNumber;
    std::vector<HashMapNode *> page;

    sf::RenderWindow &window;
    sf::Font font;
    sf::RectangleShape searchBox;
    sf::RectangleShape addBox;
    sf::RectangleShape deleteBox;
    sf::RectangleShape updateBox;
    sf::RectangleShape timeField;
    sf::RectangleShape hashInfo;
    sf::RectangleShape loadFromFileBox;
    sf::RectangleShape saveToFileBox;

    sf::Text searchText;
    sf::Text addText;
    sf::Text deleteText;
    sf::Text updateText;
    sf::Text timeText;
    sf::Text infoText;
    sf::Text loadFromFileText;
    sf::Text saveToFileText;

    Input searchInput;
    Input addInputTime;
    Input addInputPrice;
    Input addInputName;
    Input deleteInputTime;
    Input updateInputTime;
    Input updateInputPrice;
    Input updateInputName;
    Input inputToFileName;
    Input inputFromFileName;

    Timer timer;

    sf::RectangleShape searchButton;
    sf::RectangleShape addButton;
    sf::RectangleShape deleteButton;
    sf::RectangleShape updateButton;
    sf::RectangleShape loadFromFileButton;
    sf::RectangleShape saveToFileButton;

    sf::RectangleShape resetButton;
    sf::Text resetButtonText;

    sf::Text searchButtonText;
    sf::Text addButtonText;
    sf::Text deleteButtonText;
    sf::Text updateButtonText;
    sf::Text loadFromFileButtonText;
    sf::Text saveToFileButtonText;

    sf::Text timeOutputText;
    sf::Text infoOutputText;

    sf::RectangleShape HashNode1;
    sf::RectangleShape HashNode2;
    sf::RectangleShape HashNode3;

    sf::Text HashNodeText1;
    sf::Text HashNodeText2;
    sf::Text HashNodeText3;

    sf::RectangleShape arrow1;
    sf::RectangleShape arrow2;
    sf::RectangleShape arrow3;

    sf::Text textLeft;
    sf::Text textRight;
    sf::Text textMiddle;

    bool stopUpdating;
};
