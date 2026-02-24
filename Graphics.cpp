#include "Graphics.hpp"
#include <iostream>

MainWindow::MainWindow() : window(sf::VideoMode(2048, 1152), "Структуры данных")
{
    font.loadFromFile("./Assets/VMVSegaGenesis-Regular.otf");
}

void MainWindow::menuOutput()
{
    while (window.isOpen())
    {
        sf::RectangleShape listChoose(sf::Vector2f(500.f, 400.f));
        listChoose.setFillColor(sf::Color::Black);
        listChoose.setPosition(300.f, 376.f);

        sf::Text listText;
        listText.setFont(font);
        listText.setString("Linked\n\n list");
        listText.setCharacterSize(48);
        listText.setFillColor(sf::Color::White);
        listText.setPosition(400.f, 500.f);

        sf::RectangleShape treeChoose(sf::Vector2f(500.f, 400.f));
        treeChoose.setFillColor(sf::Color::Black);
        treeChoose.setPosition(1248.f, 376.f);

        sf::Text binText;
        binText.setFont(font);
        binText.setString("Binary\n\n tree");
        binText.setCharacterSize(48);
        binText.setFillColor(sf::Color::White);
        binText.setPosition(1350.f, 500.f);

        window.clear(sf::Color::White);
        window.draw(listChoose);
        window.draw(treeChoose);
        window.draw(listText);
        window.draw(binText);
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
                }
            }
        }
    }
}

void MainWindow::startList()
{
    while (window.isOpen())
    {
        testEventsList();
        renderList();
    }
}

void MainWindow::testEventsList()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void MainWindow::renderList()
{
    window.clear(sf::Color::White);
    window.display();
}