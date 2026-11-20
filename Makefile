all: array
	./array

array: array.o main_array.o
	gcc array.o main_array.o -o array -lm

array.o: array.c array.h
	gcc -c array.c

main_array.o: main_array.c array.h
	gcc -c main_array.c

clean:
	rm -f *.o array
