#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

struct info {
    int id;
};


void main()
{
    struct Node *first;
    struct info info1;
    struct info info2;

    info1.id = 1;
    info2.id = 2;

    first->data = (void*)malloc(sizeof(struct Node));
    first->data = (void*)&info1;
    first->next = NULL;

    _list_add(first, (void*)&info2);
    _list_show(first);
}