all: random.o
	gcc random.o

random.o: random.c
	gcc -c random.c

run:
	./a.out

clean:
	rm *.o
	rm file.txt
	rm a.out
