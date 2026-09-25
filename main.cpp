#include <iostream>
#include <vector>
#include <string>
#include <chrono>

// what other standard libraries do we need to include here? I don't even know the basics what the fuck.

struct Order
{
    long ID {};
    std::string side {};
    float price {};
    long quantity {};
    std::chrono::system_clock::time_point time {}; // part of chrono scope, and system clock scope with type time_point
};

struct Trade
{
    Order buyer {};
    Order seller {};
    std::chrono::system_clock::time_point date {};
};

struct Book
{
    std::vector<Order> resting_orders{};
    std::vector<Trade> trade_history{};
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
    // check if run out of space first before resizing the vector

    // if run out of space resize the resting orders of an order book to be slightly larger than it's existing capacity to make space for the new order
    order_book.resting_orders.resize(1); // hard coded for now

    static long ID {0};

    // create new order to be added
    Order new_order {};

    new_order.ID = ID++;

    // need to add terminal input safe guards for all of these

    std::cout << "Is this a buy or sell order? Please enter b/s for buy/sell respectively." << "\n";

    std::cin >> new_order.side;

    // could use only one recurring variable string variable and a format string but fine for now
    if (new_order.side == "b") {
        std::cout << "Please enter the bid price at which this order is willing to be traded at." << "\n"; // bid is maximum price which buyer is willing to buy
    } else if (new_order.side == "s"){
        std::cout << "Please enter the ask price at which this order is willing to be traded at." << "\n"; // ask price is min price which seller is willing to sell
    }    
    
    std::cin >> new_order.price;

    // replace with format string if wanted as above
    if (new_order.side == "b") {
        std::cout << "Please enter the number of units you would like to buy." << "\n";
    } else if (new_order.side == "s") {
        std::cout << "Please enter the number of units you would like to sell." << "\n";
    }

    std::cin >> new_order.quantity;

    // get the time of when order is placed

    new_order.time = std::chrono::system_clock::now();

    // add this order to the new first slot of the book's resting place

    order_book.resting_orders[0] = new_order; // hard coded for now

    // for now just always return a successful exit code
}
