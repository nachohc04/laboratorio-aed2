#include <stdlib.h>
#include <assert.h>

#include "stack.h"

struct _s_stack {
	stack_elem elem;
	struct _s_stack  *next;
};

stack stack_empty() {
    stack s = NULL;
	return s;
}

stack stack_push(stack s, stack_elem e) {
	stack s_aux = s;
	s = malloc(sizeof(struct _s_stack));
	s->elem = e;
	s->next = s_aux; 
	return s;
}

stack stack_pop(stack s) {
	assert(s!=NULL);
	stack s_aux = s;

	s = s->next;
	free(s_aux);
	s_aux = NULL;

	return s;
}

unsigned int stack_size(stack s) {
	unsigned int size = 0u;

	if (s!=NULL) {
		stack s_aux = s;

		while (s_aux->next!=NULL) {
			s_aux = s_aux->next;
			size++;
		}
	}

	
	return size;
}

stack_elem stack_top(stack s) {
	assert(s!=NULL);	
	return s->elem;
}

bool stack_is_empty(stack s){
	return s==NULL;	
}

stack_elem *stack_to_array(stack s) {
	stack s_aux=s;
	unsigned int size = stack_size(s);
	stack_elem *arr = calloc(size,sizeof(stack_elem));
	for (unsigned int i = 0u;i<=size;++i){
		arr[i] = s_aux->elem;
		s_aux=s_aux->next;
	}
	return arr;
}

stack stack_destroy(stack s) {
	while (!stack_is_empty(s)) {
		stack_pop(s);
	}
	s = NULL;
	return s;
}
