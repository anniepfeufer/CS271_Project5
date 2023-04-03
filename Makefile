#-*-Makefile-*-

all: test

test: driver.o
	g++ -o test driver.o

element_driver.o: element_driver.cpp graph.cpp graph.o
	g++ -c driver.cpp