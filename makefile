CC=gcc
AR=ar
FLAGS= -Wall -g

all: libmyEx3.a isort txtfind
txtfind: txtfind.o libmyEx3.a
	$(CC) $(FLAGS) -o txtfind txtfind.o libmyEx3.a
isort: isort.o libmyEx3.a
	$(CC) $(FLAGS) -o isort isort.o libmyEx3.a
libmyEx3.a: txtfind.o isort.o
	$(AR) -rcs libmyEx3.a txtfind.o isort.o 
txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c $< -o $@
isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c $< -o $@
.PHONY: clean all
clean:
	rm *.o *.a