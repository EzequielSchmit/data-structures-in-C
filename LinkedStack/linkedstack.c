#include "linkedstack.h"

#include <stdbool.h>
#include <stdlib.h>
#include "../DoublyLinkedList/DoublyLinkedList.h"
#include "../DoublyLinkedList/DoublyLinkedList.c"



LStack * linkedstack_create(){
    LStack * myStack = (LStack*)malloc(sizeof(LStack));
    myStack->lista = dllist_create();
    return myStack;
}

void linkedstack_push(LStack * myStack, TElement elem){
    dllist_add_first(myStack->lista,elem);
}

TElement* linkedstack_pop(LStack * myStack){
    return dllist_remove_pos(myStack->lista,0);
}

TElement* linkedstack_top(LStack * myStack){
    return dllist_first(myStack->lista);
}

bool linkedstack_isEmpty(LStack * myStack){
    return linkedstack_size(myStack) == 0;
}

int linkedstack_size(LStack * myStack){
    return dllist_size(myStack->lista);
}

void linkedstack_destroy(LStack * myStack){
    dllist_destroy(myStack->lista);
    free(myStack);
}
