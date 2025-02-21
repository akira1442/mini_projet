CFLAGS = -g -Wall -Wextra -Wno-unused-parameter
LDFLAGS = -lm
PROGRAMS = main

all: $(PROGRAMS)

main: biblioH.o biblioLC.o entreeSortieLC.o entreeSortieH.o main.o
	gcc -o $@ $(CFLAGS) $^ $(LDFLAGS)

test_liste: biblioLC.o entreeSortieLC.o test.o
	gcc -o $@ $(CFLAGS) $^ $(LDFLAGS)
	
entreeSortieLC.o: entreeSortieLC.c
	gcc $(CFLAGS) -c entreeSortieLC.c

entreeSortieH.o: entreeSortieH.c
	gcc $(CFLAGS) -c entreeSortieH.c

biblioLC.o: biblioLC.c 
	gcc $(CFLAGS) -c biblioLC.c

biblioH.o: biblioH.c
	gcc $(CFLAGS) -c biblioH.c

main.o: main.c
	gcc $(CFLAGS) -c main.c

test.o: test.c
	gcc $(CFLAGS) -c test.c
	
clean:
	rm -f *.o *~ $(PROGRAMS)
