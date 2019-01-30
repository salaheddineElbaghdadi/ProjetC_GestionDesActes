#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Personne.h"
#include "LinkedList.h"
#include "const.h"

// Read "Personne" data
struct Personne *_personne_read(struct Node *_first)
{
    struct Personne *_new_data = (struct Personne*)malloc(sizeof(struct Personne));
    struct Personne *_familly_data = (struct Personne*)malloc(sizeof(struct Personne));
    _new_data->pere = NULL;
    _new_data->mere = NULL;

    _last_id++;
    _new_data->identifiant = _last_id;

    printf("Nom: ");
    scanf("%s", _new_data->nom);

    printf("Prenom: ");
    scanf("%s", _new_data->prenom);

    printf("CIN: ");
    scanf("%s", _new_data->cin);

    printf("Sexe (%d. FEMME  %d. HOMME): ", FEMME, HOMME);
    int sexe;
    scanf("%d", &sexe);
    if (sexe == FEMME)
        _new_data->sexe = Femme;
    else if (sexe == HOMME)
        _new_data->sexe = Homme;
    else
        printf("Erreur.");
    
   

    int j;
    int m;
    int a;
    printf("Date de naissance (jj/mm/aaaa): \n");
    //scanf("%d/%d/%d", &_new_data->dateDeNaissance.jour, &_new_data->dateDeNaissance.mois, &_new_data->dateDeNaissance.annee);
    printf("    Jour: ");
    scanf("%d", &j);
    _new_data->dateDeNaissance[0] = j;
    printf("    Mois: ");
    scanf("%d", &m);
    _new_data->dateDeNaissance[1] = m;
    printf("    Annee: ");
    scanf("%d", &a);
    _new_data->dateDeNaissance[2] = a;

    printf("Lieu de naissance: \n");
    printf("    Pays: ");
    scanf("%s", _new_data->lieuDeNaissance.pays);
    printf("    Ville: ");
    scanf("%s", _new_data->lieuDeNaissance.ville);

    int choix;
    int choix2;
    printf("Parents: \n");
    printf("Ajouter les donnees des parent maintenant %d. OUI   %d. NON: ", OUI, NON);
    scanf("%d", &choix);
    if (choix == OUI)
    {
        printf("1.Pere  2.Mere  3.Les deux: ");
        scanf("%d", &choix);
        if (choix == 1)
        {
            // fonction pour la lecture des donnes du pere
            recherchePere:
            printf("Recherche Pere: \n");
            _familly_data = _personne_search(_first);
            if (_familly_data == NULL)
            {
                printf("LOG: NULL\n");
                printf("Personne non trouvee\n");
                printf("1.Recommencer la recherche  2.Annuler: ");
                scanf("%d", &choix2);
                if (choix2 == 1)
                {
                    goto recherchePere;
                }
            }
            else
            {
                printf("LOG: NOT NULL\n");
                _new_data->pere = (struct Personne*)malloc(sizeof(struct Personne));
                _new_data->pere = _familly_data;
                _familly_data = NULL;
            }
            
        }
        else if (choix == 2)
        {
            // fonction pour la lecture des donnees de la mere
            rechercheMere:
            printf("Recherche Mere: \n");
            _familly_data = _personne_search(_first);
            if (_familly_data == NULL)
            {
                printf("Personne non trouvee\n");
                printf("1.Recommencer la recherche  2.Annuler: ");
                scanf("%d", &choix2);
                if (choix2 == 1)
                {
                    goto rechercheMere;
                }
            }
            else
            {
                _new_data->pere = _familly_data;
                _familly_data = NULL;
            }
            
        }
        else if (choix == 3)
        {
            // fonction pour la lecture des donnes du pere
            recherchePereDeux:
            printf("Recherche Pere: \n");
            _familly_data = _personne_search(_first);
            if (_familly_data == NULL)
            {
                printf("LOG: NULL\n");
                printf("Personne non trouvee\n");
                printf("1.Recommencer la recherche  2.Annuler: ");
                scanf("%d", &choix2);
                if (choix2 == 1)
                {
                    goto recherchePereDeux;
                }
            }
            else
            {
                //printf("LOG: NOT NULL\n");
                _new_data->pere = (struct Personne*)malloc(sizeof(struct Personne));
                _new_data->pere = _familly_data;
                _familly_data = NULL;
            }
            // fonction pour la lecture des donnees de la mere
            rechercheMereDeux:
            printf("Recherche Mere: \n");
            _familly_data = _personne_search(_first);
            if (_familly_data == NULL)
            {
                printf("Personne non trouvee\n");
                printf("1.Recommencer la recherche  2.Annuler: ");
                scanf("%d", &choix2);
                if (choix2 == 1)
                {
                    goto rechercheMereDeux;
                }
            }
            else
            {
                _new_data->pere = _familly_data;
                _familly_data = NULL;
            }
        }
    }

    int nombreEnfants;
    printf("Nombre d'enfants: ");
    scanf("%d", &nombreEnfants);
    _new_data->nombreEnfants = nombreEnfants;
    if (nombreEnfants > 0)
    {
        printf("Ajouter les donnees des enfants maintenant %d. OUI  %d. NON: ", OUI, NON);
        scanf("%d", &choix);
        if (choix == OUI)
        {
            for (int i = 0; i < nombreEnfants; i++)
            {
                // fonction pour la lecture des donnes des enfants
                printf("Le cin de l'enfant %d: ", i);
                scanf("%s", &_new_data->enfants[i]);
            }
        }
    }

    return _new_data;
}

// show "Personne" data
void _personne_show(struct Personne *_personne)
{
    system(CLEAR_SCREEN);
    printf("Nom: %s\n",  _personne->nom);
    printf("Prenom: %s\n", _personne->prenom);
    printf("CIN: %s\n", _personne->cin);
    printf("Date de naissance: %d/%d/%d\n", _personne->dateDeNaissance[0], 
                                          _personne->dateDeNaissance[1], 
                                          _personne->dateDeNaissance[2]);

    printf("Lieu de naissance: \n");
    printf("    Pays: %s\n", _personne->lieuDeNaissance.pays);
    printf("    Ville: %s\n", _personne->lieuDeNaissance.ville);

    if (_personne->sexe == Homme)
    {
        printf("Sexe: Homme\n");
    }
    else
    {
        printf("Sexe: Femme\n");
    }
    
    if (_personne->pere != NULL)
    {
        printf("Pere: %s %s\n", _personne->pere->nom, _personne->pere->prenom);
    }
    if (_personne->mere != NULL)
    {
        printf("Mere: %s %s\n", _personne->mere->nom, _personne->mere->prenom);
    }

    printf("Nombre d'enfants: %d\n", _personne->nombreEnfants);

    printf("Les enfants: \n");
    for (int i = 0; i < _personne->nombreEnfants; i++)
    {
        printf("    %s\n", _personne->enfants[i]);
    }
}

struct Personne *_personne_search(struct Node *_first)
{
    int choix;
    char cin[CIN_SIZE];
    char nom[NAME_SIZE];
    char prenom[NAME_SIZE];
    struct Node *_node = (struct Node*)malloc(sizeof(struct Node));

    printf("Chercher par 1. Nom/Prenom  2. CIN: ");
    scanf("%d", &choix);
    if (choix == 1)
    {
        printf("Nom: ");
        scanf("%s", nom);
        printf("Prenom: ");
        scanf("%s", prenom);
        struct Node *_nodes_by_first_name = _list_search_by_first_name(_first, prenom);
        struct Node *_nodes_by_last_name = _list_search_by_last_name(_first, nom);
        struct Node *_nodes = _list_intersect(_nodes_by_first_name, _nodes_by_last_name);

        if (_nodes == NULL)
        {
            return NULL;
        }
        _node = _list_show_and_select(_nodes);
    }
    else if (choix == 2)
    {
        printf("cin: ");
        scanf("%s", cin);
        _node = _list_search_by_cin(_first, cin);

        if (_node == NULL)
        {
            return NULL;
        }
    }
    

    return _node->data;
}


void _personne_modify(struct Node *_first, struct Personne *_personne)
{
    int choix;

    printf("1.Nom\n");
    printf("2.Prenom\n");
    printf("3.Date de naissance\n");
    printf("4.CIN\n");
    printf("5.Lieu de naissance\n");
    printf("6.Pere\n");
    printf("7.Mere\n");
    printf("8.Nombre d'enfants\n");
    printf("9.Enfants\n");
    printf(">>> ");
    scanf("%d", &choix);

    char nom[NAME_SIZE];
    char prenom[NAME_SIZE];
    int date[3];
    char cin[CIN_SIZE];
    char pays[NAME_SIZE];
    char ville[NAME_SIZE];
    struct Personne *_pere = NULL;
    struct Personne *_mere = NULL;

    switch (choix)
    {
        // Nom
        case 1:
            //char nom[NAME_SIZE];
            printf("Nouveau Nom: ");
            scanf("%s", nom);
            strcpy(_personne->nom, nom);
            break;
        // Prenom
        case 2:
            printf("Nouveau Prenom: ");
            scanf("%s", prenom);
            strcpy(_personne->prenom, prenom);
            break;
        // Date de naissance
        case 3:
            //int date[3];
            printf("Nouvelle date de naissance: \n");
            printf("    Jour: ");
            scanf("%d", &date[0]);
            _personne->dateDeNaissance[0] = date[0];
            printf("    Mois: ");
            scanf("%d", &date[1]);
            _personne->dateDeNaissance[1] = date[1];
            printf("    Annee: ");
            scanf("%d", &date[2]);
            _personne->dateDeNaissance[2] = date[2];
            break;
        // CIN
        case 4:
            //char cin[CIN_SIZE];
            printf("Nouveau CIN: ");
            scanf("%s", cin);
            strcpy(_personne->cin, cin);
            break;
        // Lieu de naissance
        case 5:
            //char pays[NAME_SIZE];
            //char ville[NAME_SIZE];
            printf("Nouveau Pays: ");
            scanf("%s", pays);
            printf("Nouvelle ville: ");
            scanf("%s", ville);
            strcpy(_personne->lieuDeNaissance.pays, pays);
            strcpy(_personne->lieuDeNaissance.ville, ville);
            break;
        // Pere
        case 6:
            //struct Personne *_pere = NULL;
            printf("Changer le pere: ");
            _pere = _personne_search(_first);
            if (_pere != NULL)
            {
                _personne->pere = _pere;
            }
            break;
        // Mere
        case 7:
            //struct Personne *_mere = NULL;
            printf("Changer la mere: ");
            //_mere = _personne_search(_first);
            if (_mere != NULL)
            {
                _personne->mere = _mere;
            }
            break;
        // Nombre enfants
        case 8:
            printf("Nouveau nombre d'enfant: ");
            scanf("%d", &_personne->nombreEnfants);
            break;
        // Enfants
        case 9:
            //char cin[CIN_SIZE];
            printf("Les nouveaux cin des enfants: \n");
            for (int i = 0; i < _personne->nombreEnfants; i++)
            {
                printf("Le nouveau cin de l'enfant %d: ", i);
                scanf("%s", cin);
                strcpy(_personne->enfants[i], cin);
            }
            break;
    }
}