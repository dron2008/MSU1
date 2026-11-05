all: twenty_third_program.o relation_func.o
gcc twenty_third_program.o relation_func.o -o twenty_third_program

twenty_third_program.o: twenty_third_program.c
gcc -c twenty_third_program.c

relation_func.o: relation_func.c
gcc -c relation_func.c
