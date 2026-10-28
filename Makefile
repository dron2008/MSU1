all: thirteenth_program

thirteenth_program: thirteenth_program.o sum_func.o
	gcc thirteenth_program.o sum_func.o -o thirteenth_program

thirteenth_program.o: thirteenth_program.c sum_func.h
	gcc -c thirteenth_program.c

sum_func.o: sum_func.c sum_func.h
	gcc -c sum_func.c
