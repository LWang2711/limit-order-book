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

    // need to make 2 things: 
        //addOrder needs to resize to one bigger for now is fine
        //printResting need to be able to print the first two at least 

    addOrder(&order_book); // just replaced it since it's hard coded for now

    printResting(&order_book); // only prints the first one

    return 0; // for now unless specificed otherwise
}

void addOrder(Book* p_order_book) // setup must be to pass pointer to an order book
{
    // check if run out of space first before resizing the vector at a later stage tbh

    // if run out of space resize the resting orders of an order book to be slightly larger than it's existing capacity to make space for the new order
    
    // resize resting orders to exactly one larger than the current size of resting orders

    // need to get the size of the vector of the order book -> use the std size or the vector method size

    int curr_resting_size = p_order_book -> resting_orders.size(); // so is int or got narrowed? check documentation later

    p_order_book -> resting_orders.resize(curr_resting_size + 1); // works for now by resizing

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

    // since is zero indexed I think

    p_order_book->resting_orders[curr_resting_size] = new_order; // curr_resting_size is only fixed the next time around

    // for now just always return a successful exit code using a void function
}


// the structure is that we have the ability to print out one order, then need to loop index through every other order to print it out, so maybe
// a helper function is needed first for printing out just one order

void printOrder(Book* p_order_book, int order_ind)
{
    auto target_order = (p_order_book -> resting_orders[order_ind]); // using the order which is specified

    // make the heading display the current time later on
    std::cout << "Here are the details of all resting orders on the book as at the current time." << "\n";

    // some better way to loop through the whole order instead of one at a time later
    std::cout << "Order ID: " << std::to_string(target_order.ID) << "\n";

    if (target_order.side == "b") {
        std::cout << "Order type: buy order" << "\n";
    } else if (target_order.side == "s") {
        std::cout << "Order type: sell order" << "\n";
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

void printResting(Book* p_order_book)
{
    // there is going to be some repetition in getting the current size of the order book

   int curr_resting_size = p_order_book -> resting_orders.size();

    // what does this need to do? -> loop the print singualr order function for all of the orders
    for (int i = 0; i < curr_resting_size; i++) {

        printOrder(p_order_book, i);

    }
}
