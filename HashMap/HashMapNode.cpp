#include "HashMapNode.hpp"

HashMapNode::HashMapNode()
{
    this->state = 0;
    this->numberOfAddressGenerations = 0;
    this->task = nullptr;
}

Data *HashMapNode::getData()
{
    return this->task;
}

void HashMapNode::setData(Data *data)
{
    this->task = data;
}

void HashMapNode::setState(int state)
{
    this->state = state;
}

short HashMapNode::getState()
{
    return this->state;
}

long HashMapNode::getNumberOfAddressGenerations()
{
    return this->numberOfAddressGenerations;
}

long HashMapNode::getAddress()
{
    return this->address;
}

void HashMapNode::setAddress(long address)
{
    this->address = address;
}

void HashMapNode::incrementNumberOfAddressGenerations() {
    numberOfAddressGenerations++;
}