all:program4 run memcheck

program4: tournament.o program4.o
	gcc tournament.o program4.o -o program4

program4.o:program4.c tournament.h
	gcc -c program4.c -o program4.o

tournament.o:tournament.c tournament.h
	gcc -c tournament.c -o tournament.o

run:
	./program4

memcheck:
	valgrind ./program4


