#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

ArrayList * arraylist_create_with(int initialCapacity){
    ArrayList * myList = (ArrayList*)malloc(sizeof(ArrayList));
    if (myList != NULL){
        myList->size = 0;
        myList->maxCapacity = initialCapacity;
        myList->elements = (TElement *)malloc(sizeof(TElement)*(myList->maxCapacity));
    }
    return myList;
}
ArrayList * arraylist_create(){
    ArrayList * myList = (ArrayList*)malloc(sizeof(ArrayList));
    if (myList != NULL){
        myList->size = 0;
        myList->maxCapacity = 10;
        myList->elements = (TElement *)malloc(sizeof(TElement)* myList->maxCapacity);
    }
    return myList;
}

bool resize(ArrayList * lista){
    bool wasResized = false;
    if (lista != NULL){
        TElement * newElements = (TElement*)realloc(lista->elements,lista->maxCapacity * 2);
        if (newElements != NULL){
            lista->maxCapacity *= 2;
            lista->elements = newElements;
            wasResized = true;
        }
    }
    return wasResized;
}

void arraylist_add(ArrayList * lista, TElement elem){
    if (lista != NULL){
        bool canBeAdded = true;
        if (lista->size == lista->maxCapacity){
            canBeAdded = resize(lista);
        }
        if (canBeAdded)
            lista->elements[lista->size++] = elem;
    }
}

void drag_elements_leftward(ArrayList * lista, unsigned int pos){
    if (lista != NULL && pos < lista->size){
        for (int i = pos; i - 1 < lista->size; i++){
            lista->elements[i] = lista->elements[i+1];
        }
        lista->elements[lista->size - 1] = NULL;
        lista->size--;
    }
}

bool arraylist_remove_elem(ArrayList * lista, TElement elem){
    bool isInTheList = false;
    if (lista != NULL){
        for (int i = 0; i < lista->size && !isInTheList; i++){
            if (lista->elements[i] == elem){
                isInTheList = true;
                drag_elements_leftward(lista, i);
            }
        }
    }
    return isInTheList;
}

TElement * arraylist_remove_pos(ArrayList * lista, unsigned int pos){
    TElement * elem = NULL;
    if (lista != NULL && pos < lista->size){
        elem = &(lista->elements[pos]);
        drag_elements_leftward(lista, pos);
    }
    return elem;
}

TElement* arraylist_get(ArrayList * lista, unsigned int pos){
    TElement* aux = NULL;
    if (lista != NULL && pos < lista->size){
        aux = lista->elements[pos];
    }
    return aux;
}

TElement* arraylist_last(ArrayList * lista){
    TElement* aux = NULL;
    if (lista != NULL && lista->size > 0)
        aux = lista->elements[lista->size - 1];
    return aux;
}

TElement* arraylist_first(ArrayList * lista){
    TElement* aux = NULL;
    if (lista != NULL && lista->size > 0)
        aux = lista->elements[0];
    return aux;
}

int arraylist_size(ArrayList * lista){
    return lista != NULL ? lista->size : -1;
}

void arraylist_destroy(ArrayList * lista){
    if (lista != NULL){
        free(lista->elements);
        free(lista);
    }
}

int arraylist_get_pos(ArrayList * lista, TElement elem){
    if (lista != NULL){
        bool encontre = false;
        int i;
        for (i = 0; i < lista->size && !encontre; i++)
            if (arraylist_get(lista,i) == elem)
                return i;
    }
    return -1;
}
