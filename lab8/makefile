# Makefile for Graphs Assignment

# Graph Driver
graph_driver:  LList.o queue.o stack.o graph_driver.o
	g++  LList.o queue.o stack.o graph_driver.o -o graph_driver

# Dependencies for Graph Driver
graph.o: graph.cpp.cpp graph.h # This could be messy here
	g++ -Wall -c -g graph.cpp

queue.o: queue.cpp queue.h
	g++ -Wall -c -g queue.cpp

stack.o: stack.cpp stack.h
	g++ -Wall -c -g stack.cpp

LList.o: LList.cpp LList.h
	g++ -Wall -c -g LList.cpp

# Remove the .o Files to Clean Directory
clean:
	rm *.o

# templated classes like graph must be explicitly included
# in the driver files that are using them because the g++ compiler needs to know 
# which template types are used so it can compiler appropriate versions of the
# templated class (for example, int, char, float, bool,