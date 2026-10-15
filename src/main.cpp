#include <iostream>
#include "../include/book.hpp"
#include "../include/order.hpp"
#include "../include/trade.hpp" // for the main implementation file, these must be actual header files themselves

// make sure to have directory search functionality into make later on for readability

int main(void)
{
    Book order_book {};

    // ask the user what operation would they like to undertake

    while (true) 
    {
        std::cout << "What operation would you like to perform today?: " << "\n";

        // TODO: make caps proof

        std::cout << "Press \"O\" to create a new order." << "\n";

        std::cout << "Press \"E\" to exit." << "\n";

        std::string command {};

        std::cin >> command;

        if (command == "E") {break;}
        else if (command == "O") {
            addOrder(&order_book);
        }
    }

    printResting(&order_book);

    isValidTrade(order_book.resting_orders[0], order_book.resting_orders[1]); // right since this uses valid trade or not, so this is part of trade functionality

    return 0; // TODO: return proper error message and make sure that have successful exit code
}
