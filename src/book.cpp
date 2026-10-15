#include "../include/book.hpp"

#include "../include/order.hpp"

void printResting(Book* p_order_book)
{
    // TODO: pass through the size of resting vector

   int curr_resting_size = p_order_book -> resting_orders.size();

   for (int i = 0; i < curr_resting_size; i++) {
    
    printOrder(p_order_book, i);

    }
}
