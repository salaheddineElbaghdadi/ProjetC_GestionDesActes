#ifndef PERSONNE_H
#define PERSONNE_H

#include "const.h"
#include "LinkedList.h"

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
	//struct Date dateDeNaissance;
	int dateDeNaissance[3];
	struct Lieu	lieuDeNaissance;
	int identifiant;
	char cin[CIN_SIZE];

	struct Personne *pere;
	struct Personne *mere;

	// Ici ajouter nombre d'enfants et leurs identifiants
	int nombreEnfants;
	//int enfants[NOMBRE_ENFANTS_MAX];
	char enfants[NOMBRE_ENFANTS_MAX][CIN_SIZE];
};


// Prototype
struct Personne *_personne_read(struct Node*);
void _personne_show(struct Personne*);
struct Personne *_personne_search(struct Node*);
void _personne_modify(struct Node*, struct Personne*);


// Global variables
int _last_id;

#endif
