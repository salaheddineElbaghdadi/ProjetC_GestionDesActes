#include <stdio.h>
#include "Personne.h"


// show "Personne" data
void _personne_show(struct Personne *_personne)
{
    printf("Nom: %s\n",  _personne->nom);
    printf("Prenom: %s\n", _personne->prenom);
    printf("Identifiant: %d\n", _personne->identifiant);
    printf("Date de naissance: %d/%d/%d\n", _personne->dateDeNaissance.jour, 
                                          _personne->dateDeNaissance.jour, 
                                          _personne->dateDeNaissance.mois);

    if (_personne->sexe == Homme)
        printf("Sexe: Homme\n");
    else
        printf("Sexe: Femme\n");
    
    printf("Nombre d'enfants: %d\n", _personne->nombreEnfants);
}
