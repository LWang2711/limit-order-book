#include "../include/order.hpp"

#include "../include/trade.hpp"

// there might be transitive includes in header files referencing here which I think is just bad practice

bool isValidTrade(Order new_order, Order old_order) // don't think that it matters if we use pointers of not since we are just checking?

// or rather the function could just alter everything directly in global memory if finding valid trade? I think that is bad though
// so for now we just create a function which had the ability detection and leave the altering to another function

{

    // looks like some repetition here
    if (new_order.side == old_order.side)
    {
        return false;
    }

    // in case of new_order being a buy and old.order being a sell
    if (new_order.side == "b" && old_order.side == "s")
    {
        // reject the trade if bid price is lower than the ask price
        if (new_order.price < old_order.price)
        {
            return false;
        }
    } else if (new_order.side == "s" && old_order.side == "b") // this line might be redundant since there are only two possiblities
    {
        // in case of new_order being a sell and old.order being a buy

        // reject the trade if bid price is lower than ask price
        if (new_order.price > old_order.price)
        {
            return false;
        }
    }

    // if the control path can make it past all invalid trade blocks, then there is a valid trade
    return true;
}

// need to recompile trade with a debug symbol
