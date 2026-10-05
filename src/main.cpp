#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>


struct Order
{
    long ID {};
    std::string side {};
    float price {};
    long quantity {};
    std::chrono::system_clock::time_point time {}; 
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

    // ask the user what operation would they like to undertake today?

    while (true) 
    {
        std::cout << "What operation would you like to perform today?" << "\n";

        // need to make this caps proof

        std::cout << "Press \"O\" to create a new order" << "\n";

        std::cout << "Press \"E\" to exit" << "\n";

        std::string command {};

        std::cin >> command;

        if (command == "E") {break;}
    }

    addOrder(&order_book); 

    addOrder(&order_book);

    printResting(&order_book);

    return 0; // return proper error message
}

void addOrder(Book* p_order_book) 
{
    // check if run out of space first before resizing the vector at a later stage tbh

    // if run out of space resize the resting orders of an order book to be slightly larger than it's existing capacity to make space for the new order via assert

    int curr_resting_size = p_order_book -> resting_orders.size(); // how does the int narrowing work here

    p_order_book -> resting_orders.resize(curr_resting_size + 1); // resize to exactly only one size bigger for now

    static long ID {0};

    Order new_order {};

    new_order.ID = ++ID; // get to 

    // need to add terminal input safe guards for all of these

    std::cout << "Is this a buy or sell order? Please enter b/s for buy/sell respectively." << "\n";

    std::cin >> new_order.side;

    // replace with string variable

    if (new_order.side == "b") {
        std::cout << "Please enter the bid price at which this order is willing to be traded at." << "\n"; // bid is maximum price which buyer is willing to buy
    } else if (new_order.side == "s"){
        std::cout << "Please enter the ask price at which this order is willing to be traded at." << "\n"; // ask price is min price which seller is willing to sell
    }    
    
    std::cin >> new_order.price;

    // replace with same string variable 

    if (new_order.side == "b") {
        std::cout << "Please enter the number of units you would like to buy." << "\n";
    } else if (new_order.side == "s") {
        std::cout << "Please enter the number of units you would like to sell." << "\n";
    }

    std::cin >> new_order.quantity;


    new_order.time = std::chrono::system_clock::now();

    p_order_book->resting_orders[curr_resting_size] = new_order;

    // return successful exit code if adding an order is successful
}

void printOrder(Book* p_order_book, int order_ind)
{
    auto target_order = (p_order_book -> resting_orders[order_ind]); // using the order which is specified

    // make the heading display the current time form chrono format

    std::cout << "Here are the details of all resting orders on the book as at the current time." << "\n";

    std::cout << "Order ID: " << std::to_string(target_order.ID) << "\n";

    if (target_order.side == "b") {
        std::cout << "Order type: buy order" << "\n";
    } else if (target_order.side == "s") {
        std::cout << "Order type: sell order" << "\n";
    }

    std::cout << "Price per unit: $" << std::to_string(target_order.price) << "\n";

    // replace with string variable

    if (target_order.side == "b") {
        std::cout << "Total number of units that will be bought: " << std::to_string(target_order.quantity) << "\n";
    } else if (target_order.side == "s") {
        std::cout << "Total number of units that will be sold: " << std::to_string(target_order.quantity) << "\n";
    }

    // get total time in seconds till start of epoch

    std::time_t raw_time = std::chrono::system_clock::to_time_t(target_order.time);

    // get into local time format from seconds till start of epoch

    std::tm format_time = *std::localtime(&raw_time);

    // format as standard put time which allows to be printed out directly

    std::cout << "The time at which this order was placed was: " << std::put_time(&format_time, "%c") << "\n";
}

void printResting(Book* p_order_book)
{
    // repetition to for getting the size of the resting part of order book

   int curr_resting_size = p_order_book -> resting_orders.size();

   for (int i = 0; i < curr_resting_size; i++) {
    
    printOrder(p_order_book, i);

    }
}
