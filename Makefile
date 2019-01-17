
main: Personne.o LinkedList.o
	gcc -o main Personne.o LinkedList.o

Personne.o:
	gcc -c Personne.c

LinkedList.o:
	gcc -c LinkedList.c