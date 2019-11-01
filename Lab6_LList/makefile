LListdriver: LListdriver.o LList.o
	g++ LListdriver.o LList.o -o LListdriver
LListdriver.o: LListdriver.cpp LList.h LList.cpp
	g++ -c LListdriver.cpp
LList.o:	LList.cpp LList.h
	g++ -c LList.cpp
clean:
	rm *.o
