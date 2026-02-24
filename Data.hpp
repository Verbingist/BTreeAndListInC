#ifndef DATA_HPP 
#define DATA_HPP

#include <string>
#include <ctime>

class Data
{
public:
    Data(time_t time, float price, std::string name);
    time_t getTime();
    float getPrice();
    std::string getName();
    void setTime(time_t time);
    void setPrice(float price);
    void setName(std::string name);

private:
    time_t start_task_time;
    float task_price;
    std::string task_name;
};

#endif