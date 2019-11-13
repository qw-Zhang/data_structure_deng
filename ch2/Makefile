vector.out:vector_main.o
	g++ -g -Wall vector_main.o -o vector.out

vector.o:vector.cpp
	g++ -c -Wall vector.h vector.cpp -o vector.o

vector_main.o:vector_main.cpp
	g++ -c -Wall vector_main.cpp -o vector_main.o

clean:
	rm vector.o vector_main.o ../build/vector
	echo "CLEAN DONE"
