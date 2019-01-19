
main: main.o Personne.o LinkedList.o
	gcc -o main main.o LinkedList.o Personne.o

main.o:
	gcc -c main.c

Personne.o:
	gcc -c Personne.c

LinkedList.o:
	gcc -c LinkedList.c
