#include "TreeGraph.hpp"

TreeGraph::TreeGraph(sf::RenderWindow &window) : window(window)
{
    font.loadFromFile("./Assets/VMVSegaGenesis-Regular.otf");
}

void TreeGraph::run()
{
    while (window.isOpen())
    {
        eventTest();
        render();
    }
}

void TreeGraph::eventTest()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void TreeGraph::render()
{
    window.clear(sf::Color::White);
    window.display();
}