#include <stdio.h>

#include "stack.h"

#define N 4

void dump_stack(stack s) {
	unsigned int size = stack_size(s);
	stack_elem *arr = stack_to_array(s);
	for (unsigned int i = 0u;i<size;++i){
		printf("%d-er elemento: %d\n",i ,arr[i]);
	}}

int main(void) {
	stack s = stack_empty();
	stack_elem e;
	for (unsigned int i = 0u;i<N;++i){
		printf("Ingrese un elem: \n");
		scanf("%d",&e);
		s = stack_push(s,e);
	}
	// antes
	dump_stack(s);		
	
	stack_pop(s);

	//despues
	dump_stack(s);
	return 0;
}
