#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Personne.h"


void main()
{
    //struct Node *list = (struct Node*)malloc(sizeof(struct Node));
    struct Node *_first_node = _list_create();
    printf("Log: list created\n");
    //_first_node.data = (struct Personne*)malloc(sizeof(struct Personne));

    //_first_node->next = NULL;
    //list = &_first_node;
    //list->next = NULL;

    struct Personne p1;
    strcpy(p1.nom, "NomP1");
    strcpy(p1.prenom, "PrenomP1");
    p1.sexe = Homme;
    struct Date DateDeNaissanceP1 = {17, 4, 1998};
    p1.dateDeNaissance = DateDeNaissanceP1;
    p1.Identifiant = 12345;
    p1.nombreEnfants = 0;

    _list_add(_first_node, &p1);
    printf("Log: after list add:%d\n", _first_node->data->Identifiant);
    _list_save(_first_node);
    printf("Log: after list save:%d\n", _first_node->data->Identifiant);
    //_list_show(first);

    _list_add(_first_node, &p1);
    _list_save(_first_node);
    printf("Log: after list save:%d\n", _first_node->next->data->Identifiant);

    printf("Log: End of main function\n");
}
