#-*-Makefile-*-

all: test

test: test_graph.o
	g++ -o test test_graph.o

test_graph.o: test_graph.cpp graph.cpp graph.o
	g++ -c test_graph.cpp

graph.o: graph.cpp graph.h
	g++ -c graph.cpp