default: clean LLP LinkedList String BO
Tree:
	g++ Tree.cpp -ggdb -std=c++11 -O3 -o tree
BO:
	g++ Bitops.cpp -std=c++11 -O3 -o bitops
	gcc Endianess.c -O3 -o ed
LLP:
	g++ LLP.cpp -std=c++11 -O3 -ggdb -o LL
LinkedList:
	g++ Linked-List-Practice.cpp -std=c++11 -O3 -ggdb -o LLP
String:
	g++ StringFunctions.cpp -std=c++11 -O3 -ggdb -o String
clean:
	rm -rf LLP
	rm -rf LL
	rm -rf a.out
	rm -rf String
	rm -rf ed
	rm -rf bitops
	rm -rf tree
	rm -rf *.core
	rm -rf *.vgcore