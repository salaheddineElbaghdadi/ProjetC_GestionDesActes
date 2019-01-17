#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// Adds new node with the given data to the end of the linked list
void _list_add(struct Node *_first, Personne *new_data)
{
    struct Node *ptr = _first;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    // When ptr->next == NULL
    ptr->next = (struct Node*)malloc(sizeof(struct Node));
    ptr->next->data = (Personne *)malloc(sizeof(Personne));
    ptr->next->data = new_data;
    ptr->next->next = NULL;
}


void _list_delete(struct Node **_first, struct Node *_node)
{
  struct Node *_node = _ptr;

  // First in the list
  if (_ptr == *_first)
  {
    *_first = _ptr->next;
    free(_ptr);
  }
  // Last in the list
  else if (_ptr->next == NULL)
  {
    struct Node *_index = *_first;
    while (_index->next != _node)
    {
      _index = _index->next;
    }
    _index->next = NULL;
    free(_ptr);
  }
  // In the middle of the liste
  else
  {
    struct Node *_point = *_first;
    while (_point->next != _node)
    {
      _point = _point->next;
    }
     _point->next = _node->next;
    free(_ptr);
  }
}


// Show the list
void _list_show(struct Node *_first)
{
    while (_first->next != NULL)
    {
        printf("Log: shown");
        _first++;
    }
    printf("Log: shown");
}
