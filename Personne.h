#define CMAX 30
#define TAILLE_IDENTIFIANT 5

// Definition date
struct Date
{
	int jour;
	int mois;
	int annee;
} Date;


// Definition sex
enum Sexe { Homme, Femme, Autre }  Sexe;

// Definition structure personne
typedef struct Personne
{
	char nom[CMAX];
	char prenom[CMAX];
	enum Sexe sexe;
	struct Date dateDeNaissance;
	char Identifiant[TAILLE_IDENTIFIANT];

	// Ici ajouter nombre d'enfants et leurs identifiants
} Personne;