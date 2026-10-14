#ifndef TRADE_HPP
#define TRADE_HPP

struct Order;

#include <chrono>

bool isValidTrade(Order new_order, Order old_order); // need to know just what an order is? or need to know what is specifically inside of it?

// right need the definition of an order, include the order tag

struct Trade
{
    Order buyer {};
    Order seller {};
    std::chrono::system_clock::time_point date {};
};

#endif
