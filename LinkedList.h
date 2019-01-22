#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Personne.h"

// Node structur
struct Node 
{
   struct Personne *data;
   struct Node *next;
};


// Prototypes
void _list_add(struct Node*, struct Personne*);
void _list_delete(struct Node**, struct Node*);
void _list_show(struct Node*);
void _list_save(struct Node*);
void _list_load(struct Node**);
struct Node *_list_create();
struct Node *_list_search_by_id(struct Node*, int);
void _list_update(struct Node*, struct Node*, struct Node*);


#endif
