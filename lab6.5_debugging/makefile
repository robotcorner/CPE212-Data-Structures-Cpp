CC = g++ -fprofile-arcs -ftest-coverage -g
#CC = g++ -Wall -g
test1:    test1.o queue_driver.o queue.o
	$(CC)  test1.o queue_driver.o queue.o -o test1
test1.o:  test1.cpp
	$(CC)  -c test1.cpp
queue_driver.o: queue_driver.cpp queue.h
	$(CC)  -c queue_driver.cpp
queue.o:      queue.cpp queue.h
	$(CC) -c queue.cpp
clean:	
	rm *.o




