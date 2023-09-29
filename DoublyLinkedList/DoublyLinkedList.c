#include "DoublyLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

DLList * dllist_create(){
    DLList * myList = (DLList*)malloc(sizeof(DLList));
    if (myList == NULL){
        printf("Error. Insufficient memory.\n");
        exit(1);
    }
    myList->size = 0;
    myList->head = (TNodo*)malloc(sizeof(TNodo));
    myList->tail = (TNodo*)malloc(sizeof(TNodo));
    if (myList->head == NULL || myList->tail == NULL){
        printf("Error. Insufficient memory.\n");
        exit(1);
    }
    myList->head->elem = NULL;
    myList->tail->elem = NULL;
    myList->head->next = myList->tail;
    myList->head->prev = NULL;
    myList->tail->next = NULL;
    myList->tail->prev = myList->head;

    return myList;
}

TNodo* dllist_add(DLList * lista, TElement elem){
    if (lista != NULL && elem != NULL){
        TNodo* newPos = (TNodo*)malloc(sizeof(TNodo));
        if (newPos != NULL){
            newPos->elem = elem;
            lista->tail->prev->next = newPos;
            newPos->prev = lista->tail->prev;
            newPos->next = lista->tail;
            lista->tail->prev = newPos;
            lista->size++;
        }
        return newPos;
    } else return NULL;
}

bool dllist_remove_elem(DLList * lista, TElement elem){
    bool isInTheList = false;
    if (lista != NULL && elem != NULL){
        TNodo* aux = lista->head;
        while(aux->next != NULL && !isInTheList){
            aux = aux->next;
            if (aux->elem == elem){
                isInTheList = true;
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                free(aux);
                lista->size--;
            }
        }
    }
    return isInTheList;
}

TElement * dllist_remove_pos(DLList * lista, unsigned int pos){
    TElement * elem = NULL;
    if (lista != NULL && pos < lista->size){
        int i = 0;
        TNodo* aux = lista->head->next;
        for (int i = 0; i < pos; i++)
            aux = aux->next;
        elem = aux->elem;
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
        free(aux);
        lista->size--;
    }
    return elem;
}

TElement* dllist_get(DLList * lista, unsigned int pos){
    TElement * elem = NULL;
    if (lista != NULL && pos < lista->size){
        TNodo* aux = lista->head->next;
        for (int i = 0; i < pos; i++)
            aux = aux->next;
        elem = aux->elem;
    }
    return elem;
}

TElement* dllist_last(DLList * lista){
    if (lista != NULL && lista->size > 0)
        return lista->tail->prev->elem;
    else return NULL;
}

TElement* dllist_first(DLList * lista){
    if (lista != NULL && lista->size > 0)
        return lista->head->next->elem;
    else return NULL;
}

int dllist_size(DLList * lista){
    if (lista != NULL)
        return lista->size;
    else
        return -1;
}

void dllist_destroy(DLList * lista){
    TNodo *aux = lista->head, *prev;
    for (int i = 0; i <= lista->size; i++){
        prev = aux;
        aux = aux->next;
        free(prev);
    }
    free(lista->tail);
    free(lista);
}

TNodo* dllist_get_nodo(DLList * lista, TElement elem){
    if (lista != NULL && elem != NULL && lista->size > 0){
        TNodo* aux = lista->head;

        while (aux->next != NULL){
            aux = aux->next;
            if (aux->elem == elem)
                return aux;
        }
    }
    return NULL;

};

TNodo* dllist_prev(DLList * lista, TNodo* nodo);

TNodo* dllist_next(DLList * lista, TNodo* nodo);

