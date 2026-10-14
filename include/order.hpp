#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <chrono>

struct Book;

void addOrder(Book* p_order_book);
void printOrder(Book* p_order_book, int order_ind);

struct Order
{
    long ID {};
    std::string side {};
    float price {};
    long quantity {};
    std::chrono::system_clock::time_point time {}; 
};

#endif
