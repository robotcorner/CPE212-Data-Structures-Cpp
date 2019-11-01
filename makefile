#Makefile for graphs assignment 19 

graph_driver:  graph_driver.o queue.o stack.o
	g++  graph_driver.o queue.o stack.o -o graph_driver

graph_driver.o: graph_driver.cpp
	g++ -Wall -c -g graph_driver.cpp

queue.o: queue.cpp queue.h
	g++ -Wall -c -g queue.cpp

stack.o: stack.cpp stack.h
	g++ -Wall -c -g stack.cpp

clean:
	rm *.o

# graph_byList_driver LList.o quque.o stack.o