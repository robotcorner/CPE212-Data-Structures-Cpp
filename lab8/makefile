# Makefile for Graphs Assignment

# Graph Driver
graph_driver:  graph_driver.o LList.o queue.o stack.o
	g++  graph_driver.o LList.o queue.o stack.o -o graph_driver

graph_driver.o: graph_driver.cpp graph.h	# This could be messy here
	g++ -Wall -c -g graph_driver.cpp

# ---- Kulick's GRAPH DRIVER -----------------------------------------
# graph_by_list_driver:  LList.o queue.o stack.o graph_by_list_driver.o 
# 	 g++ -g LList.o queue.o stack.o graph_by_list_driver.o -o graph_by_list_driver
# graph_by_list.o: graph_by_list.cpp graph_by_list.h
#	 g++ --g Wall -c -g graph_by_list.cpp
# --------------------------------------------------------------------

# Dependencies for Graph Driver
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