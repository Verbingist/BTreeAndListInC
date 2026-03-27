#include <vector>

class BloomFilter
{
public:
    BloomFilter(long size, long numberExpectedElements);
    void addToFilter(long key);
    bool checkIsNotEntryToFilter(long key);
    bool checkIsEntryToFilter(long key);

private:
    long size;
    long numberExpectedElements;
    long hashFunction(long key);
    long hash(long key, long hashNumber);
    std::vector<long> bloomfiltermap;
    int numberHashFunctions;
};