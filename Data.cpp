#include "Data.hpp"

Data::Data(time_t time, float price, std::string name)
{
    this->setTime(time);
    this->setPrice(price);
    this->setName(name);
}

time_t Data::getTime()
{
    return this->start_task_time;
}

float Data::getPrice()
{
    return this->task_price;
}

std::string Data::getName()
{
    return this->task_name;
}

void Data::setTime(time_t time)
{
    this->start_task_time = time;
}

void Data::setPrice(float price)
{
    this->task_price = price;
}

void Data::setName(std::string name)
{
    this->task_name = name;
}