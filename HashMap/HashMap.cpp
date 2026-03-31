#include "HashMap.hpp"

HashMap::HashMap(long size) : bloomfilter(size * 10, size)
{
    this->tableSize = size;
    this->hashTable = new HashMapNode[tableSize];
    lastID = 0;
}

long HashMap::hash(time_t timekey)
{
    return (timekey << 8) + 9518422 % tableSize;
}

bool HashMap::addElem(time_t time, float price, std::string name)
{
    bloomfilter.addToFilter(time);
    for (int i = 0; i < tableSize; i++)
    {
        long address = (hash(time) + i) % tableSize;
        hashTable[address].incrementNumberOfAddressGenerations();
        if (hashTable[address].getState() != 1)
        {
            hashTable[address].setData(new Data(time, price, name, lastID));
            hashTable[address].setState(1);
            hashTable[address].setAddress(address);
            lastID++;
            return true;
        }
    }
    return false;
}

HashMapNode *HashMap::find(time_t timekey)
{
    if (bloomfilter.checkIsNotEntryToFilter(timekey))
    {
        return nullptr;
    }

    for (int i = 0; i < tableSize; i++)
    {
        long address = (hash(timekey) + i) % tableSize;

        if (hashTable[address].getState() == 0)
        {
            return nullptr;
        }

        if (hashTable[address].getState() == 1 && hashTable[address].getData()->getTime() == timekey)
        {
            return &hashTable[address];
        }
    }
    return nullptr;
}

bool HashMap::deleteElem(time_t timekey)
{
    if (bloomfilter.checkIsNotEntryToFilter(timekey))
    {
        return false;
    }
    for (int i = 0; i < tableSize; i++)
    {
        long address = (hash(timekey) + i) % tableSize;
        if (hashTable[address].getState() == 1 && hashTable[address].getData()->getTime() == timekey)
        {
            hashTable[address].setState(2);
            return true;
        }
    }
    return false;
}

bool HashMap::updateElem(time_t time, float price, std::string name)
{
    if (bloomfilter.checkIsNotEntryToFilter(time))
    {
        return false;
    }
    for (int i = 0; i < tableSize; i++)
    {
        long address = (hash(time) + i) % tableSize;
        if (hashTable[address].getState() == 1 && hashTable[address].getData()->getTime() == time)
        {
            hashTable[address].getData()->setPrice(price);
            hashTable[address].getData()->setName(name);
            return true;
        }
    }
    return false;
}

long HashMap::getSize()
{
    long numberOfElements = 0;
    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i].getState() == 1)
        {
            numberOfElements++;
        }
    }
    return numberOfElements;
}

long HashMap::getMaxSize()
{
    return this->tableSize;
}

void HashMap::memoryClear()
{
    delete[] this->hashTable;
    hashTable = nullptr;
}

bool HashMap::loadFromFile(std::string filePath)
{
    std::ifstream inFile(filePath);
    if (!inFile)
    {
        return false;
    }

    std::string file_time = "";
    std::string file_price = "";
    std::string file_name = "";
    std::string subString = "";

    try
    {
        while (std::getline(inFile, file_time) && std::getline(inFile, file_price) && std::getline(inFile, file_name) && std::getline(inFile, subString))
        {
            addElem(std::stoll(file_time), std::stof(file_price), file_name);
        }
    }

    catch (...)
    {
        std::cout << "ERROR WHILE READING FILE" << std::endl;
        return false;
    }

    inFile.close();
    return true;
}

bool HashMap::saveToFile(std::string filePath)
{
    std::ofstream outFile(filePath);
    if (!outFile)
    {
        return false;
    }

    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i].getState() == 1)
        {
            outFile << hashTable[i].getData()->getTime() << "\n"
                    << hashTable[i].getData()->getPrice() << "\n"
                    << hashTable[i].getData()->getName() << "\n"
                    << hashTable[i].getAddress() << "\n"
                    << hashTable[i].getNumberOfAddressGenerations() << "\n"
                    << hashTable[i].getState() << "\n"
                    << std::endl;
        }
    }

    outFile.close();
    return true;
}

bool HashMap::saveAddressesToCSV(std::string filePath)
{
    std::ofstream outFile(filePath);
    if (!outFile)
    {
        return false;
    }

    outFile << "address,numberOfAddressGenerations\n";

    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i].getState() == 1)
        {
            outFile << hashTable[i].getAddress() << ","
                    << hashTable[i].getNumberOfAddressGenerations()
                    << "\n";
        }
    }

    outFile.close();
    return true;
}

std::vector<HashMapNode *> HashMap::getPageELements(int pageNumber)
{
    std::vector<HashMapNode *> page(3, nullptr);

    if (pageNumber < 1)
    {
        page[0] = &hashTable[0];
        page[1] = &hashTable[1];
        page[2] = &hashTable[2];
        return page;
    }

    if ((pageNumber * 3 - 1) > tableSize)
    {
        page[0] = &hashTable[tableSize - 3];
        page[1] = &hashTable[tableSize - 2];
        page[2] = &hashTable[tableSize - 1];
        return page;
    }

    page[0] = &hashTable[pageNumber * 3 - 3];
    page[1] = &hashTable[pageNumber * 3 - 2];
    page[2] = &hashTable[pageNumber * 3 - 1];
    return page;
}
