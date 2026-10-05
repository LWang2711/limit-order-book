# limit-order-book

## The Need for Order Matching in Modern Finanical Markets

In a financial market with financial instruments, securities are traded with a buyer side and seller price. When they put their offers onto the market, they are willing to accept a range of prices above or below their acceptable limit. For a buyer, this limit is the bid price; for the seller, the ask price. There needs to exist infrastructure which matches these orders together and executes a trade satisfying the limits of both parties. In times of old, a manual broker or trader would facilitate these trades manually, but in the 21st century, almost all trading is done electronically. This has birthed the modern quantitative trading market which is supported by many modern electronic trading platforms. A limit order book one of these fundamental platforms, and aims to automate and optimise what manual human brokers did in times of old.

## Limit Order Book in Summary

A limit order book essentially matches sell and buy orders in chronological order which must satisfy the order price of both the seller and buyer. This means that the order will only be fulfilled if two sides can be fulfilled such that there is an overlap between the bid and ask price. Without finance terms, this means below the highest price that a buyer is willing to pay for a security and above the lowest price which a seller is willing to sell for, or the bid and ask overlap respectively. The overlap is called the bid-ask spread.

It is somewhat important to know that the buyer of underlying securities bears the loss of the bid-ask spread, and hence the seller reaps the profit in equal amount. In our definition of a perfect market (assumptions to be deteremined later), a trade is a zero-sum game.

Something which needs to be understood is that bid and asks will sit in the book, or called when an order rests in a book. So one party may put orders on the book and it will rest until filled by an opposite part where there is a positive bid-ask spread. No negative is allowed since the limit means that all order prices must be limited to below the bid and above the ask.

There are many ways to match the actual orders themselves, we will use price-time priority order matching. Meaning that the order quantity will be matched based on the best bid-ask spread, and and the tie breaker in case of same bid-ask spread will be determined by FIFO system; first equivalent bid-ask spread order is fulfilled first. 

Since quantities will not match perfectly, orders may rest in the book not fully complete and await until there are valid counterparts to complete the order's entire quantity. A crucial distinction is that although there is a bid-ask spread for each valid match (or rather valid matching for highest bid and lowest ask), the order is fulfilled at the exact price of the resting side and the resting party makes the effective capital of the bid-ask spread while the new side trades within their acceptable margin.

## Minimum Specifications and Functionality

The limit order book must be able to intake bid and ask orders from buyers and sellers respectively. These orders are to sit in the book where they are said to be at rest. When a match is found, the highest bid-ask spread or tie broken via FIFO order will be fulfilled, where then the book will move onto the next order or the same order in likely case that the quantity cannot be fully filled.

There must also be cancel functionality (although not in the very first prototype), meaning that a buyer or seller must be able to cancel their order, trashing it and taking it off the rest portion of the book. Note that an order in a trade can clearly not be cancelled, except in the case of cancelling partial trades which may be added later.

The book will have two main functions, displaying the state of the book and displaying the trades which have already been executed. So the book must be able to know which resting orders are currently in the book, and the history of all trades which have occured. Including the orders within each trade by ID number and the price and quantity.

Hence, a trade will directly affect the resting state of the book and also the order history which the book must track. This is the main idea of this order book. Note that clearly, trades will automatically be executed once valid within the book itself and will not wait for any manual trade execution.  

## Required Information to be Stored

- Bid price per stock of the buyer and the quantity of securities.
- Ask price per stock of the seller and quantity of securities.
- Each order must have an associated order ID to track it.
- The time at which the order was placed.
- The lowest or under FIFO tiebreaking bid order.
- The highest or under FIFO tiebreaking ask order.
- The details of a trade which are the order numbers from both sides and the price and quantity filled.

## Abstract Objects within V0

- Order
- Trade
- Book Resting state
- Book history log
- 

## Operations that are Required for V0

- Record bid and ask orders into the order book by ID, price and quantity
- Execute a trade by matching the order with the highest bid-ask spread based on new existing orders and the resting state of the book.
- Alter resting state of the book and trade history log after a trade.

## Out of Scope for V0

- Order cancelling for now?
- Partial order cancelling?
- Multiple financial instruments.
- Stop loss limits for traders.
- Networking.
- Multithreading.
- Most if not all optimisation techniques.

## Appendix

Project will be mainly written in C++ running C++ 20 for now to get all of the major features of modern C++ without overcomplicating with gratuitous post modern features. There will be limited other languages here, but there may be supporting languages such as Make or Cmake, otherwise the project is to mainly develop fundamental C++ implementation skills.

Other from this, there may be certain other tooling parts like the following:

- Make
- CMake
- Bash and Zsh shell
- Shel script for error checking
- Git and Github
- lldb and Visual Studio Code debugging wrapper
