#include "ListGraph.hpp"
#include <string>

ListGraph::ListGraph(sf::RenderWindow &window) : window(window),
                                                 searchInput(font, {110.f, 160.f}, {280.f, 50.f}),
                                                 addInputTime(font, {510, 150.f}, {280.f, 40.f}),
                                                 addInputPrice(font, {510, 195}, {280, 40}),
                                                 addInputName(font, {510, 240}, {280, 40}),
                                                 deleteInputTime(font, {910, 160}, {280, 50}),
                                                 updateInputTime(font, {1310, 150}, {280, 40}),
                                                 updateInputPrice(font, {1310, 195}, {280, 40}),
                                                 updateInputName(font, {1310, 240}, {280, 40}),
                                                 inputToFileName(font, {1710, 690}, {280, 50}),
                                                 inputFromFileName(font, {1710, 930}, {280, 50})
{
    font.loadFromFile("./Assets/VMVSegaGenesis-Regular.otf");

    searchBox.setSize(sf::Vector2f(300.f, 300.f));
    searchBox.setFillColor(sf::Color::Black);
    searchBox.setPosition(100.f, 100.f);

    searchText.setFont(font);
    searchText.setString("Search");
    searchText.setCharacterSize(32);
    searchText.setFillColor(sf::Color::White);
    searchText.setPosition(110.f, 110.f);

    addBox.setSize(sf::Vector2f(300.f, 300.f));
    addBox.setFillColor(sf::Color::Black);
    addBox.setPosition(500.f, 100.f);

    addText.setFont(font);
    addText.setString("Add");
    addText.setCharacterSize(32);
    addText.setFillColor(sf::Color::White);
    addText.setPosition(510.f, 110.f);

    deleteBox.setSize(sf::Vector2f(300.f, 300.f));
    deleteBox.setFillColor(sf::Color::Black);
    deleteBox.setPosition(900.f, 100.f);

    deleteText.setFont(font);
    deleteText.setString("Delete");
    deleteText.setCharacterSize(32);
    deleteText.setFillColor(sf::Color::White);
    deleteText.setPosition(910.f, 110.f);

    updateBox.setSize(sf::Vector2f(300.f, 300.f));
    updateBox.setFillColor(sf::Color::Black);
    updateBox.setPosition(1300.f, 100.f);

    updateText.setFont(font);
    updateText.setString("Update");
    updateText.setCharacterSize(32);
    updateText.setFillColor(sf::Color::White);
    updateText.setPosition(1310.f, 110.f);

    timeField.setSize(sf::Vector2f(300.f, 200.f));
    timeField.setFillColor(sf::Color::Black);
    timeField.setPosition(1700.f, 100.f);

    timeText.setFont(font);
    timeText.setString("Time of\nexecution");
    timeText.setCharacterSize(32);
    timeText.setFillColor(sf::Color::White);
    timeText.setPosition(1710.f, 110.f);

    timeOutputText.setFont(font);
    timeOutputText.setString("  0 uS");
    timeOutputText.setCharacterSize(32);
    timeOutputText.setFillColor(sf::Color::White);
    timeOutputText.setPosition(1710.f, 200.f);

    listInfo.setSize(sf::Vector2f(300.f, 200.f));
    listInfo.setFillColor(sf::Color::Black);
    listInfo.setPosition(1700.f, 350.f);

    infoText.setFont(font);
    infoText.setString("Info");
    infoText.setCharacterSize(32);
    infoText.setFillColor(sf::Color::White);
    infoText.setPosition(1710.f, 360.f);

    infoOutputText.setFont(font);
    infoOutputText.setCharacterSize(32);
    infoOutputText.setFillColor(sf::Color::White);
    infoOutputText.setPosition(1710.f, 420.f);

    loadFromFileBox.setSize(sf::Vector2f(300.f, 200.f));
    loadFromFileBox.setFillColor(sf::Color::Black);
    loadFromFileBox.setPosition(1700.f, 600.f);

    loadFromFileText.setFont(font);
    loadFromFileText.setString("Load From\nFile");
    loadFromFileText.setCharacterSize(32);
    loadFromFileText.setFillColor(sf::Color::White);
    loadFromFileText.setPosition(1710.f, 610.f);

    saveToFileBox.setSize(sf::Vector2f(300.f, 200.f));
    saveToFileBox.setFillColor(sf::Color::Black);
    saveToFileBox.setPosition(1700.f, 850.f);

    saveToFileText.setFont(font);
    saveToFileText.setString("Save To\nFile");
    saveToFileText.setCharacterSize(32);
    saveToFileText.setFillColor(sf::Color::White);
    saveToFileText.setPosition(1710.f, 860.f);

    searchButton.setSize(sf::Vector2f(280.f, 70.f));
    searchButton.setFillColor(sf::Color::White);
    searchButton.setPosition(110.f, 310.f);

    searchButtonText.setFont(font);
    searchButtonText.setString("Find");
    searchButtonText.setCharacterSize(32);
    searchButtonText.setFillColor(sf::Color::Black);
    searchButtonText.setPosition(185.f, 330.f);

    addButton.setSize(sf::Vector2f(280.f, 70.f));
    addButton.setFillColor(sf::Color::White);
    addButton.setPosition(510.f, 310.f);

    addButtonText.setFont(font);
    addButtonText.setString("Add");
    addButtonText.setCharacterSize(32);
    addButtonText.setFillColor(sf::Color::Black);
    addButtonText.setPosition(600.f, 330.f);

    deleteButton.setSize(sf::Vector2f(280.f, 70.f));
    deleteButton.setFillColor(sf::Color::White);
    deleteButton.setPosition(910.f, 310.f);

    deleteButtonText.setFont(font);
    deleteButtonText.setString("Delete");
    deleteButtonText.setCharacterSize(32);
    deleteButtonText.setFillColor(sf::Color::Black);
    deleteButtonText.setPosition(945.f, 330.f);

    updateButton.setSize(sf::Vector2f(280.f, 70.f));
    updateButton.setFillColor(sf::Color::White);
    updateButton.setPosition(1310.f, 310.f);

    updateButtonText.setFont(font);
    updateButtonText.setString("Update");
    updateButtonText.setCharacterSize(32);
    updateButtonText.setFillColor(sf::Color::Black);
    updateButtonText.setPosition(1345.f, 330.f);

    loadFromFileButton.setSize(sf::Vector2f(280.f, 40.f));
    loadFromFileButton.setFillColor(sf::Color::White);
    loadFromFileButton.setPosition(1710.f, 750.f);

    loadFromFileButtonText.setFont(font);
    loadFromFileButtonText.setString("Load");
    loadFromFileButtonText.setCharacterSize(26);
    loadFromFileButtonText.setFillColor(sf::Color::Black);
    loadFromFileButtonText.setPosition(1795.f, 750.f);

    saveToFileButton.setSize(sf::Vector2f(280.f, 50.f));
    saveToFileButton.setFillColor(sf::Color::White);
    saveToFileButton.setPosition(1710.f, 990.f);

    saveToFileButtonText.setFont(font);
    saveToFileButtonText.setString("Save");
    saveToFileButtonText.setCharacterSize(26);
    saveToFileButtonText.setFillColor(sf::Color::Black);
    saveToFileButtonText.setPosition(1795.f, 1000.f);
}

void ListGraph::run()
{
    while (window.isOpen())
    {
        if (eventTest())
        {
            return;
        }
        infoOutput();
        render();
    }
}

bool ListGraph::eventTest()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                return true;
            }
        }
        searchInput.handleEvent(event);
        addInputTime.handleEvent(event);
        addInputPrice.handleEvent(event);
        addInputName.handleEvent(event);
        deleteInputTime.handleEvent(event);
        updateInputName.handleEvent(event);
        updateInputPrice.handleEvent(event);
        updateInputTime.handleEvent(event);
        inputToFileName.handleEvent(event);
        inputFromFileName.handleEvent(event);
    }
    return false;
}

void ListGraph::infoOutput()
{
    int size = list.getSize();
    infoOutputText.setString("Size " + std::to_string(size));
}

void ListGraph::render()
{
    window.clear(sf::Color::White);
    window.draw(searchBox);
    window.draw(addBox);
    window.draw(deleteBox);
    window.draw(updateBox);
    window.draw(timeField);
    window.draw(listInfo);
    window.draw(searchText);
    window.draw(addText);
    window.draw(deleteText);
    window.draw(updateText);
    window.draw(timeText);
    window.draw(infoText);
    window.draw(loadFromFileBox);
    window.draw(loadFromFileText);
    window.draw(saveToFileBox);
    window.draw(saveToFileText);
    searchInput.draw(window);
    addInputTime.draw(window);
    addInputPrice.draw(window);
    addInputName.draw(window);
    deleteInputTime.draw(window);
    updateInputName.draw(window);
    updateInputPrice.draw(window);
    updateInputTime.draw(window);
    inputFromFileName.draw(window);
    inputToFileName.draw(window);
    window.draw(timeOutputText);
    window.draw(infoOutputText);
    window.draw(searchButton);
    window.draw(addButton);
    window.draw(deleteButton);
    window.draw(updateButton);
    window.draw(saveToFileButton);
    window.draw(loadFromFileButton);
    window.draw(searchButtonText);
    window.draw(addButtonText);
    window.draw(deleteButtonText);
    window.draw(updateButtonText);
    window.draw(loadFromFileButtonText);
    window.draw(saveToFileButtonText);
    window.display();
}