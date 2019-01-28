#ifndef PERSONNE_H
#define PERSONNE_H

#include "const.h"

// Definition date
struct Date
{
	int jour;
	int mois;
	int annee;
} Date;

// Definition Lieu
struct Lieu
{
	char pays[NAME_SIZE];
	char ville[NAME_SIZE];
};


// Definition sex
enum Sexe { Homme, Femme }  Sexe;

// Definition structure personne
struct Personne
{
	char nom[NAME_SIZE];
	char prenom[NAME_SIZE];
	enum Sexe sexe;
	struct Date dateDeNaissance;
	struct Lieu	lieuDeNaissance;
	int identifiant;

	struct Personne *pere;
	struct Personne *mere;

	// Ici ajouter nombre d'enfants et leurs identifiants
	int nombreEnfants;
	int enfants[NOMBRE_ENFANTS_MAX];
};


// Prototypes
void _personne_show(struct Personne*);

#endif
