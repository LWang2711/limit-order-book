#include <string>

// what other standard libraries do we need to include here?

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

struct Book
{
    
}


int main(void)
{


    addOrder(); // have the ability to add exactly one order to the book

    return 0; // for now unless specificed otherwise
}

void addOrder
