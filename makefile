test : main.o print.o input.o
	gcc -o test main.o print.o input.o

main.o : main.c common.h
	gcc -c main.c
print.o : print.c common.h
	gcc -c print.c
input.o : input.c common.h
	gcc -c input.c

