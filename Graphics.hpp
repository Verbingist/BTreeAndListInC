#include <SFML/Graphics.hpp>
#include "./LinkedList/LinkedList.hpp"

class MainWindow
{
public:
    MainWindow();
    void menuOutput();
    void startList();
    void testEventsList();
    void renderList();
    sf::RenderWindow window;
private:
    LinkedList list;
    // BinTree tree;
    sf::Font font;
};