#include <iostream>
#include <vector>
#include <string>

// what other standard libraries do we need to include here? I don't even know the basics what the fuck.

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
    std::vector<Order> resting_orders{};
    std::vector<Trade> trade_history{}; // these are vectors which are initally with length 0 and capacity 0?
};

void addOrder(Book order_book);

int main(void)
{
    Book order_book {};

    addOrder(order_book); // have the ability to add exactly one order to the book

    return 0; // for now unless specificed otherwise
}

void addOrder(Book order_book)
{
    // check if run out of space first before resizing the vector (poor choice of wording)

    // if run out of space resize the resting orders of an order book to be slightly larger than it's existing capacity to make space for the new order
    order_book.resting_orders.resize(1);

    // create new order variable

    static long ID {0};

    Order new_order {};

    new_order.ID = ID++;

    // need string literal here but not variable I think

    std::cout << "Is this a buy or sell order? Please enter b/s for buy/sell respectively." << "\n";

    // should probably use a string variable here or maybe just a character variable

    // need to actually retain all of this info so maybe put into the actual structure first

    std::cin >> new_order.side;

    // price of per security (will ask for bid or ask price depending on before)

    // time of order placed

    // put order into the new slot of the order book

    // (maybe return a successful and also maybe an unsuccessful exit code?)
}
