#ifndef BOOK_HPP
#define BOOK_HPP

#include <vector>

struct Order;
struct Trade;

struct Book;

void printResting(Book* p_order_book);

struct Book
{
    std::vector<Order> resting_orders{}; // needs to know the specific contents of what an order is?
    std::vector<Trade> trade_history{}; // needs to know the specific contents of what a trade is?
};

#endif
