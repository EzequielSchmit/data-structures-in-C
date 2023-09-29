#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <stdbool.h>

typedef void* TElement;
typedef struct nodo_struct TNodo;
struct nodo_struct{
    TElement * elem;
    TNodo *next, *prev;
};

typedef struct dllist_struct {
    int size;
    TNodo *head, *tail;
} DLList;

DLList * dllist_create();

TNodo* dllist_add(DLList * lista, TElement elem);

TNodo* dllist_add_first(DLList * lista, TElement elem);

TNodo* dllist_add_at(DLList * lista, TElement elem, unsigned int pos);

bool dllist_remove_elem(DLList * lista, TElement elem);

TElement * dllist_remove_pos(DLList * lista, unsigned int pos);

TElement* dllist_get(DLList * lista, unsigned int pos);

TElement* dllist_last(DLList * lista);

TElement* dllist_first(DLList * lista);

int dllist_size(DLList * lista);

void dllist_destroy(DLList * lista);

TNodo* dllist_get_pos(DLList * lista, TElement elem);

TNodo* dllist_get_pos_at(DLList * lista, unsigned int pos);

TNodo* dllist_prev(DLList * lista, TNodo* nodo);

TNodo* dllist_next(DLList * lista, TNodo* nodo);



#endif // DOUBLYLINKEDLIST_H
