#include "HashMapNode.hpp"
#include "BloomFilter.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class HashMap
{
public:
    HashMap(long size);
    HashMapNode *find(time_t timekey);
    bool addElem(time_t time, float price, std::string name);
    bool deleteElem(time_t timekey);
    bool updateElem(time_t time, float price, std::string name);
    long getSize();
    long getMaxSize();
    bool loadFromFile(std::string filePath);
    bool saveToFile(std::string filePath);
    bool saveAddressesToCSV(std::string filePath);
    void memoryClear();
    std::vector<HashMapNode*> getPageELements(int page);

private:
    long lastID;
    long hash(time_t timekey);
    long tableSize;
    HashMapNode *hashTable;
    BloomFilter bloomfilter;
};