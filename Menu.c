#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "Menu.h"
#include "LinkedList.h"



// Prototypes
void _menu_ajouter_personne(struct Node*);
void _menu_supprimer_personne(struct Node**);
void _menu_consulter(struct Node*);
void _menu_modifier(struct Node*);
void _menu_sauvegarder(struct Node*);
int _menu_quiter(struct Node*);
void _menu_trier_liste_par_identifiants(struct Node*);
void _menu_trier_liste_par_noms(struct Node*);

void _menu_show(struct Node **_first_node)
{
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
        printf("%d. Imprimer les donnees d'une personne\n", IMPRIMER);
        printf("%d. Afficher les information sur les enfants d'une personne\n", AFFICHER_INFO_ENFANT);
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

                break;
            case CHERCHER_PERSONNE_PAR_IDENTIFIANT:
                
                break;
            case TRIER_LISTE_PERSONNE_PAR_IDENTIFIANT:
                printf("Trier la list par identifiants: \n");
                _menu_trier_liste_par_identifiants(*_first_node);
                break;
            case TRIER_LISTE_PERSONNE_PAR_NOM:
                printf("Trier la list par noms: \n");
                _menu_trier_liste_par_noms(*_first_node);
                break;
            case IMPRIMER:

                break;
            case AFFICHER_INFO_ENFANT:

                break;
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
    char sexe[10];
    
    printf("Nom: ");
    scanf("%s", _new_data->nom);
    printf("Prenom: ");
    scanf("%s", _new_data->prenom);
    printf("Identifiant: ");
    scanf("%d", &_new_data->identifiant);
    printf("Date de naissance (jj/mm/aaaa): ");
    scanf("%d/%d/%d", &_new_data->dateDeNaissance.jour, &_new_data->dateDeNaissance.mois, &_new_data->dateDeNaissance.annee);
    printf("Sexe: ");
    scanf("%s", sexe);
    printf("Nombre d'enfants: ");
    scanf("%d", &_new_data->nombreEnfants);

    for (int i = 0; i < _new_data->nombreEnfants; i++)
    {
        printf("Identifiant de l'enfant $d: ", i);
        scanf("%d", &_new_data->enfants[i]);
    }

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
        scanf("%d/%d/%d", &_new_data->dateDeNaissance.jour, &_new_data->dateDeNaissance.mois, &_new_data->dateDeNaissance.annee);
        printf("Sexe: ");
        scanf("%s", sexe);
        printf("Nombre d'enfants: ");
        scanf("%d", &_new_data->nombreEnfants);

        for (int i = 0; i < _new_data->nombreEnfants; i++)
        {
            printf("Identifiant de l'enfant $d: ", i);
            scanf("%d", &_new_data->enfants[i]);
        }

        // Ici: modifier les donnees de la personne dans la list
        _list_update(_first_node, data, _new_data);
        _data_saved = 0;
    }

}

void _menu_consulter(struct Node *_first_node)
{
    printf("\n");
    _list_show(_first_node);
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