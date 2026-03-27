#include "Graphics.hpp"
#include "./BinTree/TreeGraph.hpp"
#include "./LinkedList/ListGraph.hpp"

MainWindow::MainWindow() : window(sf::VideoMode(2048, 1152), "Data structures")
{
    font.loadFromFile("./Assets/VMVSegaGenesis-Regular.otf");
}

void MainWindow::menuOutput()
{
    while (window.isOpen())
    {
        sf::RectangleShape listChoose(sf::Vector2f(500.f, 400.f));
        listChoose.setFillColor(sf::Color::Black);
        listChoose.setPosition(137.f, 150.f);

        sf::Text listText;
        listText.setFont(font);
        listText.setString("Linked\n\n list");
        listText.setCharacterSize(48);
        listText.setFillColor(sf::Color::White);
        listText.setPosition(237.f, 270.f);

        sf::RectangleShape treeChoose(sf::Vector2f(500.f, 400.f));
        treeChoose.setFillColor(sf::Color::Black);
        treeChoose.setPosition(774.f, 150.f);

        sf::Text binText;
        binText.setFont(font);
        binText.setString("Binary\n\n tree");
        binText.setCharacterSize(48);
        binText.setFillColor(sf::Color::White);
        binText.setPosition(874.f, 270.f);

        sf::RectangleShape awlChoose(sf::Vector2f(500.f, 400.f));
        awlChoose.setFillColor(sf::Color::Black);
        awlChoose.setPosition(1411.f, 150.f);

        sf::Text awlText;
        awlText.setFont(font);
        awlText.setString("AVL\n\ntree");
        awlText.setCharacterSize(48);
        awlText.setFillColor(sf::Color::White);
        awlText.setPosition(1570.f, 270.f);

        sf::RectangleShape hashChoose(sf::Vector2f(500.f, 400.f));
        hashChoose.setFillColor(sf::Color::Black);
        hashChoose.setPosition(470.f, 620.f);

        sf::Text hashText;
        hashText.setFont(font);
        hashText.setString("HashMap");
        hashText.setCharacterSize(48);
        hashText.setFillColor(sf::Color::White);
        hashText.setPosition(550.f, 780.f);

        sf::RectangleShape BTreeChoose(sf::Vector2f(500.f, 400.f));
        BTreeChoose.setFillColor(sf::Color::Black);
        BTreeChoose.setPosition(1107.f, 620.f);

        sf::Text BTreeText;
        BTreeText.setFont(font);
        BTreeText.setString("B-Tree");
        BTreeText.setCharacterSize(48);
        BTreeText.setFillColor(sf::Color::White);
        BTreeText.setPosition(1200.f, 780.f);

        window.clear(sf::Color::White);
        window.draw(listChoose);
        window.draw(treeChoose);
        window.draw(listText);
        window.draw(binText);
        window.draw(awlChoose);
        window.draw(awlText);
        window.draw(hashChoose);
        window.draw(hashText);
        window.draw(BTreeChoose);
        window.draw(BTreeText);
        window.display();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                if (listChoose.getGlobalBounds().contains(mousePos))
                {
                    startList();
                }
                if (treeChoose.getGlobalBounds().contains(mousePos))
                {
                    startTree();
                }
                if (awlChoose.getGlobalBounds().contains(mousePos))
                {
                    startAWL();
                }
                if (hashChoose.getGlobalBounds().contains(mousePos))
                {
                    startHash();
                }
                if (BTreeChoose.getGlobalBounds().contains(mousePos))
                {
                    startBTree();
                }
            }
        }
    }
}

void MainWindow::startList()
{
    ListGraph *graph = new ListGraph(window);
    graph->run();
    delete graph;
}

void MainWindow::startTree()
{
    TreeGraph *graph = new TreeGraph(window);
    graph->run();
    delete graph;
}

void MainWindow::startAWL()
{
    AWLGraph *graph = new AWLGraph(window);
    graph->run();
    delete graph;
}

void MainWindow::startHash()
{
    HashGraph *graph = new HashGraph(window);
    graph->run();
    delete graph;
}

void MainWindow::startBTree()
{
    // AWLGraph *graph = new AWLGraph(window);
    // graph->run();
    // delete graph;
}