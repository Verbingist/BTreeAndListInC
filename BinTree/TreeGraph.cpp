#include "TreeGraph.hpp"

TreeGraph::TreeGraph(sf::RenderWindow &window) : window(window),
                                                 searchInput(font, {110.f, 160.f}, {280.f, 50.f}),
                                                 addInputTime(font, {510, 150.f}, {280.f, 40.f}),
                                                 addInputPrice(font, {510, 195}, {280, 40}),
                                                 addInputName(font, {510, 240}, {280, 40}),
                                                 deleteInputTime(font, {910, 160}, {280, 50}),
                                                 updateInputTime(font, {1310, 150}, {280, 40}),
                                                 updateInputPrice(font, {1310, 195}, {280, 40}),
                                                 updateInputName(font, {1310, 240}, {280, 40}),
                                                 inputToFileName(font, {1710, 930}, {280, 50}),
                                                 inputFromFileName(font, {1710, 690}, {280, 50})
{
    font.loadFromFile("./Assets/VMVSegaGenesis-Regular.otf");
    pageNumber = 0;
    page = tree.getPageElements(pageNumber, nullptr);

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

    resetButton.setSize(sf::Vector2f(280.f, 70.f));
    resetButton.setFillColor(sf::Color::White);
    resetButton.setPosition(110.f, 230.f);

    resetButtonText.setFont(font);
    resetButtonText.setString("Reset");
    resetButtonText.setCharacterSize(32);
    resetButtonText.setFillColor(sf::Color::Black);
    resetButtonText.setPosition(170.f, 250.f);

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

    textUp.setFont(font);
    textUp.setString("Up");
    textUp.setCharacterSize(32);
    textUp.setFillColor(sf::Color::Black);
    textUp.setPosition(830.f, 1050.f);

    textLeft.setFont(font);
    textLeft.setString("<- Left");
    textLeft.setCharacterSize(32);
    textLeft.setFillColor(sf::Color::Black);
    textLeft.setPosition(400.f, 1050.f);

    textRight.setFont(font);
    textRight.setString("Right ->");
    textRight.setCharacterSize(32);
    textRight.setFillColor(sf::Color::Black);
    textRight.setPosition(1100.f, 1050.f);

    stopUpdating = false;
}

void TreeGraph::run()
{
    while (window.isOpen())
    {
        if (eventTest())
        {
            return;
        }
        render();
        treeOutput();
    }
}

bool TreeGraph::eventTest()
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
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
            if (addButton.getGlobalBounds().contains(mousePos))
            {
                timer.startTimer();
                tree.addNode(Data(std::stoll(addInputTime.getValue()), std::stof(addInputPrice.getValue()), addInputName.getValue()));
                timer.endTimer();
                timerOutput();
                updatePages();
            }
            if (deleteButton.getGlobalBounds().contains(mousePos))
            {
                timer.startTimer();
                tree.deleteNode(std::stoll(deleteInputTime.getValue()));
                timer.endTimer();
                timerOutput();
                updatePages();
            }
            if (updateButton.getGlobalBounds().contains(mousePos))
            {
                timer.startTimer();
                tree.updateNode(std::stoll(updateInputTime.getValue()), Data(std::stoll(updateInputTime.getValue()), std::stof(updateInputPrice.getValue()), updateInputName.getValue()));
                timer.endTimer();
                timerOutput();
                updatePages();
            }
            if (searchButton.getGlobalBounds().contains(mousePos))
            {
                timer.startTimer();
                TreeNode *found = tree.getNode(std::stoll(searchInput.getValue()));
                timer.endTimer();
                timerOutput();
                page[0] = found;
                page[1] = nullptr;
                page[2] = nullptr;
                stopUpdating = true;
            }
            if (resetButton.getGlobalBounds().contains(mousePos))
            {
                stopUpdating = false;
                page = tree.getPageElements(pageNumber, nullptr);
            }
            if (saveToFileButton.getGlobalBounds().contains(mousePos))
            {
                timer.startTimer();
                tree.saveToFile(inputToFileName.getValue());
                timer.endTimer();
                timerOutput();
                pageNumber = 0;
            }
            if (loadFromFileButton.getGlobalBounds().contains(mousePos))
            {
                timer.startTimer();
                tree.loadFromFile(inputFromFileName.getValue());
                timer.endTimer();
                timerOutput();
                pageNumber = 0;
                page = tree.getPageElements(pageNumber, nullptr);
            }
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Left)
            {
                pageNumber = -1;
                if (!stopUpdating)
                {
                    page = tree.getPageElements(pageNumber, page[0]);
                }
            }
            if (event.key.code == sf::Keyboard::Right)
            {
                pageNumber = 1;
                if (!stopUpdating)
                {
                    page = tree.getPageElements(pageNumber, page[0]);
                }
            }
            if (event.key.code == sf::Keyboard::Up)
            {
                pageNumber = 0;
                if (!stopUpdating)
                {
                    page = tree.getPageElements(pageNumber, page[0]);
                }
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

void TreeGraph::timerOutput()
{
    timeOutputText.setString("  " + std::to_string(timer.getTime()) + "uS");
}

void TreeGraph::updatePages()
{
    page = tree.getPageElements(pageNumber, page[0]);
}

void TreeGraph::treeOutput()
{

    treeNode1.setFillColor(sf::Color::White);
    treeNode2.setFillColor(sf::Color::White);
    treeNode3.setFillColor(sf::Color::White);
    arrow1.setFillColor(sf::Color::White);
    arrow2.setFillColor(sf::Color::White);

    treeNode1.setSize(sf::Vector2f(450.f, 250.f));
    treeNode1.setFillColor(sf::Color::Black);
    treeNode1.setPosition(650.f, 500.f);

    treeNodeText1.setFont(font);
    treeNodeText1.setCharacterSize(24);
    treeNodeText1.setFillColor(sf::Color::White);
    treeNodeText1.setPosition(660.f, 510.f);

    if (page[0] != nullptr)
    {
        treeNodeText1.setString(
            "Time " + std::to_string(page[0]->getData().getTime()) +
            "\n\nPrice " + std::to_string(page[0]->getData().getPrice()) +
            "\n\nName " + page[0]->getData().getName());
    }
    else
    {
        treeNodeText1.setString("NULLPTR");
    }

    arrow1.setSize(sf::Vector2f(50.f, 30.f));
    arrow1.setFillColor(sf::Color::Black);
    arrow1.setPosition(600.f, 720.f);

    treeNode2.setSize(sf::Vector2f(450.f, 250.f));
    treeNode2.setFillColor(sf::Color::Black);
    treeNode2.setPosition(150.f, 720.f);

    treeNodeText2.setFont(font);
    treeNodeText2.setCharacterSize(24);
    treeNodeText2.setFillColor(sf::Color::White);
    treeNodeText2.setPosition(160.f, 730.f);

    if (page[1] != nullptr)
    {
        treeNodeText2.setString(
            "Time " + std::to_string(page[1]->getData().getTime()) +
            "\n\nPrice " + std::to_string(page[1]->getData().getPrice()) +
            "\n\nName " + page[1]->getData().getName());
    }
    else
    {
        treeNodeText2.setString("NULLPTR");
    }

    arrow2.setSize(sf::Vector2f(50.f, 30.f));
    arrow2.setFillColor(sf::Color::Black);
    arrow2.setPosition(1100.f, 720.f);

    treeNode3.setSize(sf::Vector2f(450.f, 250.f));
    treeNode3.setFillColor(sf::Color::Black);
    treeNode3.setPosition(1150.f, 720.f);

    treeNodeText3.setFont(font);
    treeNodeText3.setCharacterSize(24);
    treeNodeText3.setFillColor(sf::Color::White);
    treeNodeText3.setPosition(1160.f, 730.f);

    if (page[2] != nullptr)
    {
        treeNodeText3.setString(
            "Time " + std::to_string(page[2]->getData().getTime()) +
            "\n\nPrice " + std::to_string(page[2]->getData().getPrice()) +
            "\n\nName " + page[2]->getData().getName());
    }
    else
    {
        treeNodeText3.setString("NULLPTR");
    }
}

void TreeGraph::render()
{
    int size = tree.getSize();
    int depth = tree.getDepth();
    int leafs = tree.getNumberOfLeafs();
    infoOutputText.setString(
        "Size " + std::to_string(size) +
        "\nDepth " + std::to_string(depth) +
        "\nLeafs " + std::to_string(leafs));

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
    window.draw(treeNode1);
    window.draw(treeNode2);
    window.draw(treeNode3);
    window.draw(treeNodeText1);
    window.draw(treeNodeText2);
    window.draw(treeNodeText3);
    window.draw(arrow1);
    window.draw(arrow2);
    window.draw(textLeft);
    window.draw(textRight);
    window.draw(resetButton);
    window.draw(resetButtonText);
    window.draw(textUp);
    window.display();
}