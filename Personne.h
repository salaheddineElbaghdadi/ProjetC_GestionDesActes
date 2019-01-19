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
	char nom[NAME_SIZE];
	char prenom[NAME_SIZE];
	enum Sexe sexe;
	struct Date dateDeNaissance;
	int Identifiant;

	// Ici ajouter nombre d'enfants et leurs identifiants
	int nombreEnfants;
	int enfants[NOMBRE_ENFANTS_MAX];
};

#endif
