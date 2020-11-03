all: books.o main.o
	gcc -o main books.o main.o
main.o: main.c books.h
	gcc -c main.c
books.o: books.c books.h
	gcc -c books.c
run: 
	./main
clean:
	-rm *.o