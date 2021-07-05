test : SmalltoBig.o SmalltoBigfunc.o
	gcc -o test SmalltoBig.o SmalltoBigfunc.o
SmalltoBig.o : SmalltoBig.c com.h
	gcc -c SmalltoBig.c

SmalltoBigfunc.o : SmalltoBigfunc.c com.h
	gcc -c SmalltoBigfunc.c
