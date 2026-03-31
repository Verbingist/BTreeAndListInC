#include "BloomFilter.hpp"
#include <math.h>

BloomFilter::BloomFilter(long size, long expectedElements) : bloomfiltermap(size, 0)
{
    this->size = size;
    this->numberExpectedElements = numberExpectedElements;
    this->numberHashFunctions = (int)round(((float)size / (float)expectedElements) * log(2));
}

long BloomFilter::hashFunction(long key)
{
    return (key + 1239) * 654321 % size;
}

long BloomFilter::hash(long key, long hashNumber)
{
    return hashFunction(key + hashNumber);
}

void BloomFilter::addToFilter(long key)
{
    for (int i = 0; i < numberHashFunctions; i++)
    {
        bloomfiltermap[hash(key, i)] = 1;
    }
}

bool BloomFilter::checkIsNotEntryToFilter(long key)
{
    for (int i = 0; i < numberHashFunctions; i++)
    {
        if (bloomfiltermap[hash(key, i)] == 0)
        {
            return true;
        }
    }
    return false;
}

bool BloomFilter::checkIsEntryToFilter(long key)
{
    for (int i = 0; i < numberHashFunctions; i++)
    {
        if (bloomfiltermap[hash(key, i)] == 0)
        {
            return false;
        }
    }
    return true;
}