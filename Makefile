CC = gcc
FLAGS = -Wall -g

all: cmp copy encode decode stshell

stshell: stshell.o
	$(CC) $(FLAGS) stshell.o -o stshell

decode: decode.o codecA.so codecB.so
	$(CC) $(FLAGS) decode.o codecA.so codecB.so -o decode 

encode: encode.o codecA.so codecB.so
	$(CC) $(FLAGS) encode.o codecA.so codecB.so -o encode 

copy: copy.o
	$(CC) $(FLAGS) copy.o -o copy

cmp: cmp.o
	$(CC) $(FLAGS) cmp.o -o cmp

cmp.o: cmp.c
	$(CC) $(FLAGS) -c cmp.c -o cmp.o

copy.o: copy.c
	$(CC) $(FLAGS) -c copy.c -o copy.o

codecA.so: codecA.o
	$(CC) -shared codecA.o -o codecA.so

codecB.so: codecB.o
	$(CC) -shared codecB.o -o codecB.so

codecA.o: codecA.c codecA.h
	$(CC) $(FLAGS) -fPIC -c codecA.c -o codecA.o

codecB.o: codecB.c codecB.h
	$(CC) $(FLAGS) -fPIC -c codecB.c -o codecB.o

encode.o: encode.c
	$(CC) $(FLAGS) -c encode.c -o encode.o

decode.o: decode.c
	$(CC) $(FLAGS) -c decode.c -o decode.o

stshell.o: stshell.c
	$(CC) $(FLAGS) -c stshell.c -o stshell.o

clean:
	rm *.o *.so cmp copy encode decode stshell
