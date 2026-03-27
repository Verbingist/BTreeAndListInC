#include "../Data.hpp"

class HashMapNode
{
public:
    HashMapNode();
    Data *getData();
    void setData(Data *data);
    void setState(int state);
    short getState();
    long getNumberOfAddressGenerations();
    void incrementNumberOfAddressGenerations();
    long getAddress();
    void setAddress(long address);

private:
    Data *task;
    short state;
    long numberOfAddressGenerations;
    long address;
};