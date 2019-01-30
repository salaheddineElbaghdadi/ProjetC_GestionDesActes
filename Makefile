
main: main.o LinkedList.o Personne.o Menu.o login.o
	gcc main.o LinkedList.o Personne.o Menu.o login.o -o main

main.o:
	gcc -c main.c

Personne.o:
	gcc -c Personne.c

LinkedList.o:
	gcc -c LinkedList.c

Menu.o:
	gcc -c Menu.c

login.o:
	gcc -c login.c

clean:
	rm *.o