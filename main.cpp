#include <string>

struct Time
{
    int day {};
    int month {};
    int year {};
};

struct Order
{
    long ID {};
    std::string side {};
    float price {};
    long quantity {};
    Time date {};
};

struct Trade
{
    Order buyer {};
    Order seller {};
    Time date {};
};

int main(void)
{

    return 0; // for now unless specificed otherwise
}
