#include <SFML/Graphics.hpp>
#include "./LinkedList/LinkedList.hpp"
#include "./BinTree/BinTree.hpp"
#include "./AWLTree/AWLGraph.hpp"
#include "./HashMap/HashGraph.hpp"
#include "./BTree/BTreeGraph.hpp"

class MainWindow
{
public:
    MainWindow();
    void menuOutput();
    void startList();
    void startTree();
    void startAWL();
    void startHash();
    void startBTree();
    sf::RenderWindow window;

private:
    sf::Font font;
};