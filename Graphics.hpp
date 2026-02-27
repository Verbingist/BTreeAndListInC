#include <SFML/Graphics.hpp>
#include "./LinkedList/LinkedList.hpp"
#include "./BinTree/BinTree.hpp"

class MainWindow
{
public:
    MainWindow();
    void menuOutput();
    void startList();
    void startTree();
    void startAWL();
    sf::RenderWindow window;

private:
    sf::Font font;
};