#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <stdbool.h>

typedef void* TElement;

typedef struct arraylist_struct {
    int size;
    TElement * elements;
    int maxCapacity;
} ArrayList;


ArrayList * arraylist_create_with(int initialCapacity);

ArrayList * arraylist_create();

void arraylist_add(ArrayList * lista, TElement elem);

bool arraylist_remove_elem(ArrayList * lista, TElement elem);

TElement * arraylist_remove_pos(ArrayList * lista, unsigned int pos);

TElement* arraylist_get(ArrayList * lista, unsigned int pos);

TElement* arraylist_last(ArrayList * lista);

TElement* arraylist_first(ArrayList * lista);

int arraylist_size(ArrayList * lista);

void arraylist_destroy(ArrayList * lista);

int arraylist_get_pos(ArrayList * lista, TElement elem);

#endif // ARRAYLIST_H
