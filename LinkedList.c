#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
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
      ptr->data = new_data;
      ptr->next = NULL;
    }
    else // if there is data where ptr in pointing
    {
      ptr->next = (struct Node*)malloc(sizeof(struct Node));
      ptr->next->data = (struct Personne *)malloc(sizeof(struct Personne));
      ptr->next->data = new_data;
      ptr->next->next = NULL;
    }
}


void _list_delete(struct Node **_first, struct Node *_node)
{
  struct Node *_ptr = _node;

  // First in the list
  if (_ptr == *_first)
  {
    printf("Log: if\n");
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
	struct Node *_ptr = _first;
  // Showing the list
  while (_ptr != NULL)
  {
    if (_ptr->data != NULL)
    {
      printf("%d     %s  %s  %s\n", _ptr->data->identifiant,
                                _ptr->data->nom,
                                _ptr->data->prenom,
                                _ptr->data->cin);
    }
    _ptr = _ptr->next;
  }
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
  fwrite(&_last_id, sizeof(int), 1, file);    // savind the last id

	do
	{
		// Check if the data pointer is pointing on a struct and is not pointing on NULL
		if (ptr->data != NULL)
		{
			fwrite(ptr->data, sizeof(struct Personne), 1, file);
		}

    ptr = ptr->next;
	}while(ptr != NULL);

	fclose(file);
	//free(file);
}



struct Node *_list_search_by_id(struct Node *_first, int _id)
{
  struct Node *_ptr = _first;

	while( (_ptr != NULL) && (_id != _ptr->data->identifiant) )
	{
		_ptr = _ptr->next;
	}

	if ( (_ptr == NULL) || (_id != _ptr->data->identifiant) )
	{
	  return NULL;
	}
	else
	{
    return _ptr;
	}
}

struct Node *_list_search_by_cin(struct Node *_first, char *_cin)
{
  struct Node *_ptr = _first;

	while(_ptr != NULL)
	{
    if (strcmp(_cin, _ptr->data->cin) != 0)
    {
		  _ptr = _ptr->next;
    }
    else
    {
      break;
    }
    
	}

	if (_ptr == NULL)
	{
	  return NULL;
	}
	else
	{
    return _ptr;
	}
}

void _list_sort_by_id(struct Node *_first)
{
  struct Node *_ptr = _first;
  struct Node *_data;
  int minId;

  while (_first->next != NULL)
  {
    _ptr = _first;
    minId = _first->data->identifiant;
    _data = _first;

    while (_ptr != NULL)
    {
      if (_ptr->data->identifiant < minId)
      {
        minId = _ptr->data->identifiant;
        _data = _ptr;
      }

      _ptr = _ptr->next;
    }

    if (_first->data->identifiant != minId)
    {
      struct Personne *temp;
      temp = _data->data;
      _data->data = _first->data;
      _first->data = temp;

    }

    _first = _first->next;
  }
}

void _list_sort_by_name(struct Node *_first)
{
  struct Node *_ptr = _first;
  struct Node *_data;
  char *_name;
  char *_last_name;

  while (_first->next != NULL)
  {
    _ptr = _first;
    _name = _ptr->data->nom;
    _last_name = _ptr->data->prenom;;
    _data = _first;

    while (_ptr != NULL)
    {
      if (strcmp(_name, _ptr->data->nom) > 0)
      {
        _name = _ptr->data->nom;
        _last_name = _ptr->data->prenom;
        _data = _ptr;
      }
      else if (strcmp(_name, _ptr->data->nom) == 0)
      {
        if (strcmp(_last_name, _ptr->data->prenom) > 0)
        {
          _name = _ptr->data->nom;
          _last_name = _ptr->data->prenom;
          _data = _ptr;
        }
      }

      _ptr = _ptr->next;
    }

    if ((_first->data->nom != _name) || (_first->data->prenom != _last_name))
    {
      struct Personne *temp;
      temp = _data->data;
      _data->data = _first->data;
      _first->data = temp;
    }

    _first = _first->next;
  }
}


// Load list from file
void _list_load(struct Node **_first)
{
  FILE *file;
  file = fopen(FILE_NAME, "rb");

  *_first = _list_create();

  //struct Node *_new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Personne *_new_data = (struct Personne*)malloc(sizeof(struct Personne));

  

  if (file != NULL)
  {
    if (fread(&_last_id, sizeof(int), 1, file) == 0)
    {
      _last_id = 0;
    }
    while(fread(_new_data, sizeof(struct Personne), 1, file) != 0)
    {
      _list_add(*_first, _new_data);
      _new_data = (struct Personne*)malloc(sizeof(struct Personne));
    }
  }

}

void _list_update(struct Node *_first, struct Node *_old_data, struct Personne *_new_data)
{
  struct Node *ptr = _first;

  while((ptr != _old_data) && (ptr != NULL))
  {
    ptr = ptr->next;
  }

  if (ptr == _old_data)
  {
    _old_data->data = _new_data;
  }
}


struct Node *_list_search_by_first_name(struct Node *_first, char *_first_name)
{
  struct Node *_nodes = _list_create();
  struct Node *_ptr = _first;

	while (_ptr != NULL && _ptr->data != NULL)
	{
	  if (strcmp(_first_name, _ptr->data->prenom) != 0)
	  {
		  _ptr = _ptr->next;
	  }
	  else
	  {
      _list_add(_nodes, _ptr->data);
      _ptr = _ptr->next;
	  	//return _ptr;
	  }
  }

  return _nodes;
  
}


struct Node *_list_search_by_last_name(struct Node *_first, char *_last_name)
{
  struct Node *_nodes = _list_create();
  struct Node *_ptr = _first;

	while (_ptr != NULL && _ptr->data != NULL)
	{
	  if (strcmp(_last_name, _ptr->data->nom) != 0)
	  {
		  _ptr = _ptr->next;
	  }
	  else
	  {
      _list_add(_nodes, _ptr->data);
      _ptr = _ptr->next;
	  	//return _ptr;
	  }
  }

  return _nodes;
}

struct Node *_list_intersect(struct Node *_first_one, struct Node *_first_two)
{
  struct Node *_intersection = _list_create();
  struct Node *_ptr_one = _first_one;
  struct Node *_ptr_two = _first_two;

  while (_ptr_one != NULL)
  {
    _ptr_two = _first_two;

    while (_ptr_two != NULL)
    {
      if (_ptr_two->data == _ptr_one->data)
      {
        _list_add(_intersection, _ptr_two->data);
      }
      _ptr_two = _ptr_two->next;
    }
    
    _ptr_one = _ptr_one->next;
  }

  if (_intersection->data == NULL)
  {
    return NULL;
  }

  return _intersection;
  
}

struct Node *_list_show_and_select(struct Node *_first)
{
  struct Node *_ptr = _first;
  int selection = 1;
  int currentSelection = 1;
  
  while (_ptr != NULL && _ptr->data != NULL)
  {
    printf("%d. %s  %s  cin: %s\n", currentSelection, _ptr->data->nom, _ptr->data->prenom, _ptr->data->cin);
    currentSelection++;
    _ptr = _ptr->next;
  }

  printf("select: ");
  scanf("%d", &selection);

  currentSelection = 1;
  _ptr = _first;
  while (_ptr != NULL && currentSelection < selection)
  {
    currentSelection++;
    _ptr = _ptr->next;
  }

  return _ptr;
}
