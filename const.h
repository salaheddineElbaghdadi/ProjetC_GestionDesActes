#ifndef CONST_H
#define CONST_H

#define NAME_SIZE 30 
#define IDENTIFIANT_SIZE 5
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
#define AJOUTER 1
#define SUPPRIMER 2
#define MODIFIER 3
#define CONSULTER 4
#define CHERCHER_PERSONNE_PAR_NOM_PRENOM 5
#define CHERCHER_PERSONNE_PAR_IDENTIFIANT 6
#define TRIER_LISTE_PERSSONE 7
#define IMPRIMER 8
#define AFFICHER_INFO_ENFANT 9
#define SAUVEGADER 10
#define QUITER 11

#endif
