bst: driver.o
	g++ driver.o -o bst

driver.o: driver.cpp binary_search_tree.cpp
	g++ -c driver.cpp

clean:
	rm *.o