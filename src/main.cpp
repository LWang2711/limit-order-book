#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>

// this is already becoming a mess, we might need to use headers and helper source files earlier than I thought

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

void addOrder(Book* p_order_book);
void printResting(Book* p_order_book);

int main(void)
{
    Book order_book {};

    addOrder(&order_book); // have the ability to add exactly one order to the book

    printResting(&order_book); // have the ability to print exactly the first resting order in the book

    // local controlled test




    return 0; // for now unless specificed otherwise
}

void addOrder(Book* p_order_book) // setup must be to pass pointer to an order book
{
    // check if run out of space first before resizing the vector

    // if run out of space resize the resting orders of an order book to be slightly larger than it's existing capacity to make space for the new order
    p_order_book->resting_orders.resize(1); // hard coded for now, also derefence pointer to get what is actually at that address

    static long ID {0};

    Order new_order {};

    new_order.ID = ++ID; // needs to be pre-decrement

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

    p_order_book->resting_orders[0] = new_order; // hard coded for now

    // for now just always return a successful exit code using a void function
}

/*

*/
void printResting(Book* p_order_book)
{
    auto target_order = (p_order_book->resting_orders[0]);

    // make the heading display the current time later on
    std::cout << "Here are the details of all resting orders on the book as at the current time." << "\n";

    // some better way to loop through the whole order instead of one at a time later
    std::cout << "Order ID: " << std::to_string(target_order.ID) << "\n";

    if (target_order.side == "b") {
        std::cout << "Order type: buy order" << std::to_string(target_order.quantity) << "\n";
    } else if (target_order.side == "s") {
        std::cout << "Order type: sell order" << std::to_string(target_order.quantity) << "\n";
    }

    std::cout << "Price per unit: $" << std::to_string(target_order.price) << "\n";

    // this is some repetition again since should really just use some way to know which side is being ordered
    if (target_order.side == "b") {
        std::cout << "Total number of units that will be bought: " << std::to_string(target_order.quantity) << "\n";
    } else if (target_order.side == "s") {
        std::cout << "Total number of units that will be sold: " << std::to_string(target_order.quantity) << "\n";
    }

    // we want to extract the 24 hour time, date, month, year

    // get total time in seconds till epoch start

    std::time_t raw_time = std::chrono::system_clock::to_time_t(target_order.time);

    // get into local time format from seconds till epoch

    std::tm format_time = *std::localtime(&raw_time); // takes address of the raw time, and also returns an address

    // then format it as put time which should be an unspecified type

    std::cout << "The time at which this order was placed was: " << std::put_time(&format_time, "%c") << "\n";
}
