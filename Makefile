#-*-Makefile-*-

all: test

test: driver.o
	g++ -o test driver.o

driver.o: driver.cpp graph.cpp graph.o
	g++ -c driver.cpp

