#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Personne.h"
#include "Menu.h"


void main()
{
    //struct Node *list = (struct Node*)malloc(sizeof(struct Node));
    struct Node *_first_node = _list_create();

    _menu_show(&_first_node);

    // data for testing the save and load funtions
    struct Personne p;
    
    strcpy(p.nom, "EL BAGHDADI");
    strcpy(p.prenom, "Salah-Eddine");
    p.identifiant = 00132;
    p.dateDeNaissance.jour = 17;
    p.dateDeNaissance.mois = 4;
    p.dateDeNaissance.annee = 1998;
    p.sexe = Homme;
    p.nombreEnfants = 0;

    struct Personne p2;
    
    strcpy(p2.nom, "nomP2");
    strcpy(p2.prenom, "prenomP2");
    p2.identifiant = 22222;
    p2.dateDeNaissance.jour = 17;
    p2.dateDeNaissance.mois = 4;
    p2.dateDeNaissance.annee = 1998;
    p2.sexe = Homme;
    p2.nombreEnfants = 0;
    
    _list_add(_first_node, &p);
    p.identifiant = 12982;
    _list_add(_first_node, &p);
    p.identifiant = 48930;
    _list_add(_first_node, &p2);
    printf("Log: list before load\n");
    _list_show(_first_node);

    _list_save(_first_node);

    _list_load(&_first_node);
    printf("Log: list after load\n");
    _list_show(_first_node);

    _list_delete(&_first_node, _first_node);
    printf("Log: list after delete\n");
    _list_show(_first_node);

    printf("Log: End of main function\n");
}
