#include <SFML/Graphics.hpp>
#include "BinTree.hpp"
#include "../Timer.hpp"

class TreeGraph
{
public:
    TreeGraph(sf::RenderWindow &window);
    void run();
    void render();
    void eventTest();

private:
    BinTree tree;
    sf::RenderWindow &window;
    sf::Font font;
    Timer timer;
};
