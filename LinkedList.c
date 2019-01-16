#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// Adds new node with the given data to the end of the linked list
void _list_add(struct Node *_first, void *new_data)
{
    struct Node *ptr = _first;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    // When ptr->next == NULL
    ptr->next = (struct Node*)malloc(sizeof(struct Node));
    ptr->next->data = (void *)malloc(sizeof(void));
    ptr->next->data = new_data;
    ptr->next->next = NULL;
}


// 
void _list_delete()
{

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


