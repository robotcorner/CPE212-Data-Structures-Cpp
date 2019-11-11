queue_driver: queue_driver.o queue.o 
	g++ queue_driver.o queue.o -o queue_driver
queue_driver.o: queue_driver.cpp queue.h
	g++ -c queue_driver.cpp
queue.o:      queue.cpp queue.h
	c++ -c queue.cpp
clean:	
	rm *.o

