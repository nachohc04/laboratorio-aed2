#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_SIZE 7

static void
print_array(int a[], size_t length) {
    assert(length > 0);
    printf("[ %d", a[0]);
    for (size_t i=1; i<length; i++) {
        printf(", %d", a[i]);
    }
    printf("]\n");
}

int main(void) {
    int arr[ARRAY_SIZE] = {7, 4, 1, 3, 9, 3, 5};
    int *p=NULL;
    printf("before: ");
    print_array(arr, ARRAY_SIZE);

    p = arr; // inicializo el puntero como el primer elemento del arreglo utilizando la abreviatura de &arr[0] para no usar el operador '&' 
    for (unsigned int i=0u; i < ARRAY_SIZE; i++) {
        p[i] = 0;   // Utilizo el operador de indexacion de punteros para inicializar cada valor del arreglo sin utilizar el operador '*'
    }

    /* -------------------------------------------------------------------- */
    printf("after : ");
    print_array(arr, ARRAY_SIZE);

    return EXIT_SUCCESS;
}

