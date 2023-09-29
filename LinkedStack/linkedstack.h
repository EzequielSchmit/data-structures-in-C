#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <stdbool.h>
#include "../DoublyLinkedList/DoublyLinkedList.h"

typedef struct linkedstack_struct {
    DLList * lista;
} LStack;

LStack * linkedstack_create();

void linkedstack_push(LStack * myStack, TElement elem);

TElement* linkedstack_pop(LStack * myStack);

TElement* linkedstack_top(LStack * myStack);

bool linkedstack_isEmpty(LStack * myStack);

int linkedstack_size(LStack * myStack);

void linkedstack_destroy(LStack * myStack);

#endif // LINKEDSTACK_H
