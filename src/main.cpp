// these I think that for right now we can just leave alone

// just use one header file for now which is for order and order book operations

// what about all the the structs themselves and all the other setup

// only this part should have be within main and everything else should all be within different header and implementation files

#include <iostream>
#include "book.hpp"
#include "order.hpp"
#include "trade.hpp"

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

// now how to make this all work and compile via headers and forward declarations
