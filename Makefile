# should make sure that the build directory even exists first on the users' machine

build/limit-order-book : main.o book.o order.o trade.o
	clang++ -g main.o book.o order.o trade.o -o build/limit-order-book

# source file and also whatever header files need to be within the actual src file itself to ensure safety?

# make sure to compile without linking here for each object file update for clarity and compile efficiency

main.o : src/main.cpp include/book.hpp include/order.hpp include/trade.hpp
	clang++ -g -c src/main.cpp -o main.o

# each src into object file needs to also check for updates in the header files which it depends on

book.o : src/book.cpp include/book.hpp include/order.hpp
	clang++ -g -c src/book.cpp -o book.o

order.o : src/order.cpp include/order.hpp include/book.hpp
	clang++ -g -c src/order.cpp -o order.o

trade.o : src/trade.cpp include/trade.hpp include/order.hpp
	clang++ -g -c src/trade.cpp -o trade.o

# try this part first

clean : 
	rm main.o book.o order.o trade.o

# just keep build for now I think is fine but also need to be able to make the build directory and clean it automatically later on
