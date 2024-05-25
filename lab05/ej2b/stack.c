#include <stdlib.h>
#include <assert.h>

#include "stack.h"

// Nodos
struct _s_stack {
	stack_elem elem;
	struct _s_stack  *next;
};
// Stack
struct stack {
	unsigned int size;
	struct _s_stack *stack;
};


stack stack_empty() {
	stack s = malloc(sizeof(struct stack));

	s->size = 0;
	s->stack = NULL;

	return s;
}

stack stack_push(stack s, stack_elem e) {
	struct _s_stack *s_aux = s->stack;
	s->stack = malloc(sizeof(struct _s_stack));
	s->stack->elem = e;
	s->stack->next = s_aux;
	s->size++;
	return s;
}

stack stack_pop(stack s) {
	assert(s->stack!=NULL);
	struct _s_stack *s_aux = s->stack;

	s->stack = s->stack->next;
	s->size--;

	free(s_aux);
	s_aux = NULL;

	return s;
}

unsigned int stack_size(stack s) {
	return s->size;
}

stack_elem stack_top(stack s) {
	assert(s->stack!=NULL);	
	return s->stack->elem;
}

bool stack_is_empty(stack s){
	return s->size==0;	
}

stack_elem *stack_to_array(stack s) {
	struct _s_stack *s_aux=s->stack;
	unsigned int size = stack_size(s);
	stack_elem *arr = calloc(size,sizeof(stack_elem));
	for (unsigned int i = 0u;i<size;++i){
		arr[i] = s_aux->elem;
		s_aux=s_aux->next;
	}
	return arr;
}

stack stack_destroy(stack s) {
	while (!stack_is_empty(s)) {
		stack_pop(s);
	}
	s->stack = NULL;
	return s;
}
