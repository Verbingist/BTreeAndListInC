#include <SFML/Graphics.hpp>
#include "LinkedList.hpp"
#include "../Timer.hpp"
#include "../Graphics/Input.hpp"
#include <vector>
#include <format>

class ListGraph
{
public:
    ListGraph(sf::RenderWindow &window);
    void run();
    void render();
    bool eventTest();
    void listOutput();
    void timerOutput();

private:
    LinkedList list;
    int pageNumber;
    std::vector<ListNode *> page;

    sf::RenderWindow &window;
    sf::Font font;
    sf::RectangleShape searchBox;
    sf::RectangleShape addBox;
    sf::RectangleShape deleteBox;
    sf::RectangleShape updateBox;
    sf::RectangleShape timeField;
    sf::RectangleShape listInfo;
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
    Input updateInputId;
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

    sf::RectangleShape listNode1;
    sf::RectangleShape listNode2;
    sf::RectangleShape listNode3;

    sf::Text listNodeText1;
    sf::Text listNodeText2;
    sf::Text listNodeText3;

    sf::RectangleShape arrow1;
    sf::RectangleShape arrow2;
    sf::RectangleShape arrow3;

    sf::Text textLeft;
    sf::Text textRight;

    bool stopUpdating;
};
