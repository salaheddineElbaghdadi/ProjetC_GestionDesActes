
main: main.o LinkedList.o Personne.o Menu.o
	gcc main.o LinkedList.o Personne.o Menu.o -o main

main.o:
	gcc -c main.c

Personne.o:
	gcc -c Personne.c

LinkedList.o:
	gcc -c LinkedList.c

Menu.o:
	gcc -c Menu.c

clean:
	rm *.o