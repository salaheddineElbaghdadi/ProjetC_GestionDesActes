#ifndef CONST_H
#define CONST_H

#define NAME_SIZE 30 
#define IDENTIFIANT_SIZE 5
#define CIN_SIZE 10
#define NOMBRE_ENFANTS_MAX 20
#define FILE_NAME "fichier.bin"

// Operating system macros
#define OS_LINUX

#ifdef OS_LINUX
    #define CLEAR_SCREEN "clear"
#else
    #define CLEAR_SCREEN "cls"
#endif

// Menu macros
#define OUI 1
#define NON 2
#define ANNULER 3

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_ENTER 10

#define NOM 1
#define PRENOM 2
#define NOM_PRENOM 3

#define FEMME 0
#define HOMME 1

#define AJOUTER 1
#define SUPPRIMER 2
#define MODIFIER 3
#define CONSULTER 4
#define CHERCHER_PERSONNE_PAR_NOM_PRENOM 5
#define CHERCHER_PERSONNE_PAR_IDENTIFIANT 6
#define TRIER_LISTE_PERSONNE_PAR_IDENTIFIANT 7
#define TRIER_LISTE_PERSONNE_PAR_NOM 8
#define AFFICHER 9
#define IMPRIMER 10
#define SAUVEGADER 10
#define QUITER 11

#endif
