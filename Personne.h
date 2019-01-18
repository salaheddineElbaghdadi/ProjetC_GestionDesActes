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


// Definition sex
enum Sexe { Homme, Femme }  Sexe;

// Definition structure personne
struct Personne
{
	char nom[CMAX];
	char prenom[CMAX];
	enum Sexe sexe;
	struct Date dateDeNaissance;
	char Identifiant[TAILLE_IDENTIFIANT];

	// Ici ajouter nombre d'enfants et leurs identifiants
};

#endif
