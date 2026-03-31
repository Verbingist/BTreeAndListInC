#include "BTree.hpp"
#include <SFML/Graphics.hpp>
#include "../Timer.hpp"
#include "../Graphics/Input.hpp"
#include <vector>
#include <format>

class BTreeGraph
{
public:
    BTreeGraph(sf::RenderWindow &window);
    void run();
    void render();
    bool eventTest();
    void treeOutput();
    void timerOutput();
    void updatePages();

private:
    BTree tree;
    int pageNumber;
    std::vector<BTreeNode *> page;

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

    sf::RectangleShape treeNode1;
    sf::RectangleShape treeNode2;
    sf::RectangleShape treeNode3;
    sf::RectangleShape treeNode4;
    sf::RectangleShape treeNode5;

    sf::Text treeNodeText1;
    sf::Text treeNodeText2;
    sf::Text treeNodeText3;
    sf::Text treeNodeText4;
    sf::Text treeNodeText5;

    sf::RectangleShape arrow1;
    sf::RectangleShape arrow11;
    sf::RectangleShape arrow2;
    sf::RectangleShape arrow3;
    sf::RectangleShape arrow4;
    sf::RectangleShape arrow44;

    sf::Text textLeft;
    sf::Text textUp;
    sf::Text textRight;

    bool stopUpdating;
};
