test: main.o
	gcc -g -o test main.o

main.o: main.c
	gcc -c main.c

run: test
	./test

clean:
	rm *.o