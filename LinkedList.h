#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Personne.h"

// Node structur
struct Node 
{
   void *data;
   struct Node *next;
};


// Prototypes
void _list_add(struct Node*, struct Personne*);
void _list_delete(struct Node**, struct Node*);
void _list_show(struct Node*);


#endif