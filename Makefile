#-*-Makefile-*-

all: test

test: element_driver.o
	g++ -o test element_driver.o

element_driver.o: element_driver.cpp hash_table.cpp hash_table.o
3	g++ -c element_driver.cpp