#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Personne.h"
#include "const.h"

// Create new list from data
struct Node *_list_create()
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = NULL;
  new_node->next = NULL;

  return new_node;
}

// Adds new node with the given data to the end of the linked list
void _list_add(struct Node *_first,struct Personne *new_data)
{
    struct Node *ptr = _first;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    // When ptr->next == NULL
    if (ptr->data == NULL) // if the first ptr point to first and there is still no data
    {
      printf("if\n");
      //ptr->data = (struct Personne*)malloc(sizeof(struct Personne));
      printf("in data\n");
      ptr->data = new_data;
      printf("after data\n");
      ptr->next = NULL;
      printf("after next\n");
    }
    else // if there is data where ptr in pointing
    {
      printf("else\n");
      ptr->next = (struct Node*)malloc(sizeof(struct Node));
      ptr->next->data = (struct Personne *)malloc(sizeof(struct Personne));
      ptr->next->data = new_data;
      ptr->next->next = NULL;
    }


    //printf("%d\n", ptr->next->data->Identifiant);

    printf("Log: added to the list\n");
}


void _list_delete(struct Node **_first, struct Node *_node)
{
  struct Node *_ptr = _node;

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



void _list_show(struct Node *_first)
{
  // Pointing on the first node
	struct Node *ptr = _first;
  // Showing the list
  do
  {
    Personne = ptr->Personne;
    printf("Le nom est : %s \n",Personne.nom);
    printf("Le prenom est : %s \n",Personne.prenom);
    //Here add sex
    //printf("Le sex est :\n");
    printf("La date de naissance :\n");
    printf("Le jour : %d \n",Personne->dateDeNaissance.jour);
    printf("Le mois : %d \n",Personne->dateDeNaissance.mois);
    printf("L annee : %d \n",Personne->dateDeNaissance.annee);
    printf("L ide est : %d \n",Personne.Identifiant);
    //Here add the number of children and their id
    //printf("Le nombre d'enfants et leurs id :\n");
    ptr = ptr->next;
  }
  while(ptr != NULL);
}


// Save list in file
void _list_save(struct Node *_first)
{
	// Opening the file
	FILE *file;
	file = fopen(FILE_NAME, "wb");

	// Pointing the first node of the list
	struct Node *ptr = _first;

	// Writing on the file
	do
	{
		printf("Log: entered while loop\n");
		// Check if the data pointer is pointing on a struct and is not pointing on NULL
		if (ptr->data != NULL)
		{
			fwrite(ptr->data, sizeof(struct Personne), 1, file);
			printf("Log: data not null\n");
		}
    if (ptr->next != NULL)
    {
		  ptr = ptr->next;
    }
    printf("after ptr->next in while loop\n");
	}while(ptr->next != NULL && ptr != NULL);

	fclose(file);
	free(file);

	printf("Log: saved to file\n");
}



void _search_by_id(struct Node *_first)
{
	int id;
	printf("Entrer l'id de la personne recherchee : \n ");
	scanf("%d",&id);
	struct Node *ptr = _first;
	Personne = ptr->Personne;
	while( (ptr !=NULL) && (id != Personne.Identifiant) )
	{
		ptr = ptr->next;
	}
	if ( (ptr == NULL) || (id != Personne.Identifiant) )
	{
				return NULL;
	}
	else
	{
		printf("Le nom est : %s \n",Personne.nom);
		printf("Le prenom est : %s \n",Personne.prenom);
		//Here add sex
		//printf("Le sex est :\n");
		printf("La date de naissance :\n");
		printf("Le jour : %d \n",Personne->dateDeNaissance.jour);
		printf("Le mois : %d \n",Personne->dateDeNaissance.mois);
		printf("L annee : %d \n",Personne->dateDeNaissance.annee);
		printf("L ide est : %d \n",Personne.Identifiant);
		//Here add the number of children and their id
		//printf("Le nombre d'enfants et leurs id :\n");
	}
}




// Load list from file
void _list_load()
{

}
