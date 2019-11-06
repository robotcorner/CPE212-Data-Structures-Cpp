BSTreeDriver:  BSTree.o BSTreedriver.o
	g++ BSTree.o BSTreedriver.o -o BSTreeDriver

BSTreedriver.o:  BSTreedriver.cpp BSTree.h
	g++ -c BSTreedriver.cpp

BSTree.o: BSTree.cpp BSTree.h
	g++ -c BSTree.cpp

clean:
	rm *.o

