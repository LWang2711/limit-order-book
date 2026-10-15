# should make sure that the build directory even exists first on the users' machine

build/limit-order-book : main.o book.o order.o trade.o
	clang++ -g main.o book.o order.o trade.o -o build/limit-order-book

# source file and also whatever header files need to be within the actual src file itself to ensure safety?

# make sure to compile without linking here for each object file update

main.o : src/main.cpp include/book.hpp include/order.hpp include/trade.hpp
	clang++ -c src/main.cpp

# each src into object file needs to also check for updates in the header files which it depends on

book.o : src/book.cpp include/book.hpp include/order.hpp
	clang++ -c src/book.cpp

order.o : src/order.cpp include/order.hpp include/book.hpp
	clang++ -c src/order.cpp

trade.o : src/trade.cpp include/trade.hpp include/order.hpp
	clang++ -c src/trade.cpp

clean : 
	rm main.o book.o order.o trade.o
