#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty() {
    stack s = malloc(sizeof(struct _s_stack));
    s->capacity = 10;
    s->elems = calloc(s->capacity, sizeof(stack_elem));
    s->size = 0;
    return s;
}

stack stack_push(stack s, stack_elem e) {
    if (s->capacity==s->size) {
        // debo realocar memoria (2*capacidad actual)
        s->elems = realloc(s->elems, sizeof(stack_elem)*s->capacity*2);
        // agrego nuevo elemento a la pila
        s->elems[s->size] = e;
    }
    else {
        s->elems[s->size] = e;
    }

    return s;
}

stack stack_pop(stack s) {
    s->size--;
    return s;
}

unsigned int stack_size(stack s) {
    return s->size;
}

stack_elem stack_top(stack s) {
    return s->elems[(s->size)-1];
}

bool stack_is_empty(stack s) {
    return s->size == 0;
}

stack_elem *stack_to_array(stack s) {
    stack_elem *sta = calloc(s->size, sizeof(stack_elem));

    for (unsigned int i =0u;i<s->size;++i) {
        sta[i] = s->elems[i];
    }

    return sta;
}

stack stack_destroy(stack s) {
    free(s->elems);
    s = NULL;
    return s;
}