inventory: main.o f.o readline.o
	gcc -o inventory main.o f.o readline.o
main.o: main.c f.h struct.h debug_f.h
	gcc -c main.c
f.o: f.c f.h readline.h struct.h debug_f.h
	gcc -c f.c
readline.o: readline.c readline.h debug_f.h
	gcc -c readline.c