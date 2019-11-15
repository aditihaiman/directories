all: directories.o
	gcc -o a.out directories.o

directories.o: directories.c
	gcc -c directories.c

run:
	./a.out