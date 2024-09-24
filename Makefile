
output: main.o messageHandler.o
	g++ main.o messageHandler.o -o output

messageHandler.o: messageHandler.cpp messageHandler.h
	g++ -c messageHandler.cpp

main.o: main.cpp
	g++ -c main.cpp
	
clean: 
	rm *.o output