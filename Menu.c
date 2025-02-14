#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "Menu.h"
#include "LinkedList.h"
#include "Personne.h"
#include "login.h"



// Prototypes
void _menu_ajouter_personne(struct Node*);
void _menu_supprimer_personne(struct Node**);
void _menu_consulter(struct Node*);
void _menu_chercher_par_nom_prenom(struct Node*);
void _menu_chercher_par_identifiant(struct Node*);
void _menu_modifier(struct Node*);
void _menu_sauvegarder(struct Node*);
int _menu_quiter(struct Node*);
void _menu_trier_liste_par_identifiants(struct Node*);
void _menu_trier_liste_par_noms(struct Node*);
void _menu_afficher_info_personne(struct Node*);
void _menu_imprimer_acte(struct Node*);

void _menu_show(struct Node **_first_node)
{
    int log;
    do {
        log = _login();
    } while (log != 1);


    int input;
    _data_saved = 1;
    do
    {   
        system(CLEAR_SCREEN);
        puts("**************************************************************************");
        puts("*                                                                        *");
        puts("*                        GESTION DES ACTES                               *");
        puts("*                                                                        *");
        puts("**************************************************************************");

        printf("%d. Ajouter une personne\n", AJOUTER);
        printf("%d. Supprimer une personne\n", SUPPRIMER);
        printf("%d. Modifier une Personne\n", MODIFIER);
        printf("%d. Consulter la liste des personnes\n", CONSULTER);
        printf("%d. Chercher une personne par son Nom et Prenom\n", CHERCHER_PERSONNE_PAR_NOM_PRENOM);
        printf("%d. Chercher une personne par son identifiant\n", CHERCHER_PERSONNE_PAR_IDENTIFIANT);
        printf("%d. Trier la liste des personne par identifiants\n", TRIER_LISTE_PERSONNE_PAR_IDENTIFIANT);
        printf("%d. Trier la liste des personne par noms\n", TRIER_LISTE_PERSONNE_PAR_NOM);
        printf("%d. Afficher les donnees d'une personne\n", AFFICHER);
        //printf("%d. Imprimer l'acte d'une personne\n", IMPRIMER);
        printf("%d. Sauvegarder\n", SAUVEGADER);
        printf("%d. Quiter\n", QUITER);
        printf(">>> ");
        scanf("%d", &input);


        switch (input)
        {
            case AJOUTER:
                printf("Ajouter une personne: \n");
                _menu_ajouter_personne(*_first_node);
                break;
            case SUPPRIMER:
                printf("Supprimer une personne: \n");
                _menu_supprimer_personne(_first_node);
                break;
            case MODIFIER:
                printf("Modifier les donnees d'une personne: \n");
                _menu_modifier(*_first_node);
                break;
            case CONSULTER: 
                printf("Consulater la liste des personnes: \n");
                _menu_consulter(*_first_node);
                break;
            case CHERCHER_PERSONNE_PAR_NOM_PRENOM:
                printf("Recherche de personne par nom et prenom: \n");
                _menu_chercher_par_nom_prenom(*_first_node);
                break;
            case CHERCHER_PERSONNE_PAR_IDENTIFIANT:
                printf("Recherche par identifiant: \n");
                _menu_chercher_par_identifiant(*_first_node);
                break;
            case TRIER_LISTE_PERSONNE_PAR_IDENTIFIANT:
                printf("Trier la list par identifiants: \n");
                _menu_trier_liste_par_identifiants(*_first_node);
                break;
            case TRIER_LISTE_PERSONNE_PAR_NOM:
                printf("Trier la list par noms: \n");
                _menu_trier_liste_par_noms(*_first_node);
                break;
            case AFFICHER:
                printf("Info personne: \n");
                _menu_afficher_info_personne(*_first_node);
                break;
            //case IMPRIMER:

                //break;
            case SAUVEGADER:
                _menu_sauvegarder(*_first_node);
                break;
            case QUITER:
                input = _menu_quiter(*_first_node);
                break;
        }

    } while (input != QUITER);
}


void _menu_ajouter_personne(struct Node *_first_node)
{
    struct Personne *_new_data = (struct Personne *)malloc(sizeof(struct Personne));
    //_new_data = _personne_read(_first_node);
    /*int sexe;
    
    printf("Nom: ");
    scanf("%s", _new_data->nom);
    printf("Prenom: ");
    scanf("%s", _new_data->prenom);
    printf("Identifiant: ");
    scanf("%d", &_new_data->identifiant);
    printf("Date de naissance (jj/mm/aaaa): ");
    scanf("%d/%d/%d", &_new_data->dateDeNaissance.jour, &_new_data->dateDeNaissance.mois, &_new_data->dateDeNaissance.annee);
    printf("Sexe (0. Homme/1. Femme): ");
    scanf("%d", sexe);
    printf("Nombre d'enfants: ");
    scanf("%d", &_new_data->nombreEnfants);

    for (int i = 0; i < _new_data->nombreEnfants; i++)
    {
        printf("Identifiant de l'enfant $d: ", i);
        scanf("%d", &_new_data->enfants[i]);
    }
    
    if (sexe == 0)
    {
        _new_data->sexe = Homme;
    }
    else
    {
        _new_data->sexe = Femme;
    }
    */

   _new_data = _personne_read(_first_node);

    _list_add(_first_node, _new_data);
    _data_saved = 0;
    
}

void _menu_supprimer_personne(struct Node **_first_node)
{
    int id;
    printf("Identifiant de la personne a supprimer: ");
    scanf("%d", &id);

    struct Node *data = _list_search_by_id(*_first_node, id);
    _list_delete(_first_node, data);
    _data_saved = 0;
}

void _menu_modifier(struct Node *_first_node)
{
    struct Personne *_personne = NULL;
    char cin[CIN_SIZE];

    //printf("Donner le cin de la personne a modifier: ");
    //scanf("%s", cin);

    _personne = _personne_search(_first_node);
    if (_personne != NULL)
    {
        _personne_modify(_first_node, _personne);
    }
    /*
    int id;
    printf("Identifiant de la personne a modifier: ");
    scanf("%d", &id);

    struct Node *data = _list_search_by_id(_first_node, id);

    if (data == NULL)
    {
        printf("Erreur pas de personne avec l'id %d", id);
        getchar();
        getchar();
    }
    else
    {
        struct Personne *_new_data = (struct Personne *)malloc(sizeof(struct Personne));
        char sexe[10];
        
        printf("Nom: ");
        scanf("%s", _new_data->nom);
        printf("Prenom: ");
        scanf("%s", _new_data->prenom);
        printf("Identifiant: ");
        scanf("%d", &_new_data->identifiant);
        printf("Date de naissance (jj/mm/aaaa): ");
        scanf("%d/%d/%d", &_new_data->dateDeNaissance[0], &_new_data->dateDeNaissance[1], &_new_data->dateDeNaissance[2]);
        printf("Sexe: ");
        scanf("%s", sexe);
        printf("Nombre d'enfants: ");
        scanf("%d", &_new_data->nombreEnfants);

        for (int i = 0; i < _new_data->nombreEnfants; i++)
        {
            printf("Identifiant de l'enfant $d: ", i);
            scanf("%d", &_new_data->enfants[i]);
        }

        if (sexe == 0)
        {
            _new_data->sexe = Homme;
        }
        else
        {
            _new_data->sexe = Femme;
        }   

        // Ici: modifier les donnees de la personne dans la list
        _list_update(_first_node, data, _new_data);
        */
        _data_saved = 0;

}

void _menu_consulter(struct Node *_first_node)
{
    printf("\n");
    _list_show(_first_node);
    getchar();
    getchar();
}

void _menu_chercher_par_nom_prenom(struct Node *_first)
{
    struct Node *_nodes;
    int choix;
    char nom[NAME_SIZE];
    char prenom[NAME_SIZE];

    printf("%d. Nom   %d. Prenom   %d. Nom et prenom\n", NOM, PRENOM, NOM_PRENOM);
    printf(">>> ");
    scanf("%d", &choix);


    switch (choix)
    {
        case NOM:
            printf("Donnez le nom: ");
            scanf("%s", nom);

            // search by last name
            _nodes = _list_search_by_last_name(_first, nom);
            _list_show(_nodes);

            // wait for input
            getchar();
            getchar();
            break;

        case PRENOM:
            printf("Donnez le prenom: ");
            scanf("%s", prenom);

            // search by first name
            _nodes = _list_search_by_first_name(_first, prenom);
            _list_show(_nodes);

            // wait for input
            getchar();
            getchar();
            break;

        case NOM_PRENOM:
            printf("Donnez le nom: ");
            scanf("%s", nom);
            printf("Donnew le prenom: ");
            scanf("%s", prenom);
            
            // search by first and last name
            struct Node *_nodes_by_first_name = _list_search_by_first_name(_first, prenom);
            struct Node *_nodes_by_last_name = _list_search_by_last_name(_first, nom);
            _nodes = _list_intersect(_nodes_by_first_name, _nodes_by_last_name);
            _list_show(_nodes);

            // wait for input
            getchar();
            getchar();
            break;
    }
}

void _menu_chercher_par_identifiant(struct Node *_first)
{
    int id;
    printf("Donner l'identifiant: ");
    scanf("%d", &id);

    struct Node *_data = _list_search_by_id(_first, id);
    _menu_afficher_info_personne(_data);

    getchar();
    getchar();
}

void _menu_trier_liste_par_identifiants(struct Node *_first_node)
{
    _list_sort_by_id(_first_node);
}

void _menu_trier_liste_par_noms(struct Node *_first_node)
{
    _list_sort_by_name(_first_node);
}

void _menu_afficher_info_personne(struct Node *_first_node)
{

    char cin[CIN_SIZE];
    struct Node *_data;
    printf("Donnez le cin de la personne: ");
    scanf("%s", cin);

    _data = _list_search_by_cin(_first_node, cin);
    if (_data != NULL)
    {
        _personne_show(_data->data);
    }
    else
    {
        printf("Personne non trouvee.\n");
    }
    

    /*
    if (_data == NULL)
    {
        printf("Erreur: pas de personne avec l'identifiant: %d", id);
    }
    else
    {
        system(CLEAR_SCREEN);
        printf("============================================================\n");
        printf("|  Nom:                 %s\n", _data->data->nom);
        printf("|  Prenom:              %s\n", _data->data->prenom);
        printf("|  Identifiant:         %s\n", _data->data->identifiant);
        printf("|  Date de naissance:   %d/%d/%d\n", _data->data->dateDeNaissance.jour
                                                     ,_data->data->dateDeNaissance.mois
                                                     ,_data->data->dateDeNaissance.annee);
    }
    */
    getchar();
    getchar();

}

void _menu_sauvegarder(struct Node *_first_node)
{
    _list_save(_first_node);
    _data_saved = 1;
}

int _menu_quiter(struct Node *_first_node)
{
    if (_data_saved == 1)
    {
        return QUITER;
    }
    else
    {
        int choix;
        printf("Les donnees ne sans pas enregistrees\n");
        printf("voulez enregister les donnees avant de quiter?\n");
        printf("    %d. Oui", OUI);
        printf("    %d. Nom", NON);
        printf("    %d. Annuler\n", ANNULER);
        printf("    >>> ");
        scanf("%d", &choix);
        
        if (choix == OUI)
        {
            _list_save(_first_node);
            return QUITER;
        }
        else if (choix == NON)
        {
            return QUITER;
        }
        else if (choix == ANNULER)
        {
            return 0;
        }
        else
        {
            printf("Choix non valide");
            return 0;
        }
    }
}


void _menu_imprimer_acte(struct Node *_first)
{
    
}