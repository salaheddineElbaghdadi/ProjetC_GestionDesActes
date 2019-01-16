#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Node structur
struct Node 
{
   void *data;
   struct Node *next;
};


// Prototypes
void _list_add(struct Node*, void*);
void _list_show(struct Node*);


#endif