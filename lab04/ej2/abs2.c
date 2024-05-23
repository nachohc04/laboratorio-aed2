#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x>=0) {
        *y=x;
    }
    else {
        *y= (-1)*x;
    }
}

int main(void) {
    int a=-10, res=0;
    
    absolute(a, &res);

    printf("res=%d\n", res);

    assert(res >= 0 && (res == a || res == -a));
    
    return EXIT_SUCCESS;
}

/*
En este caso la respuesta es equivalente a la del programa del Teorico, ya que se imita el comportamiento de un procedimiento
*/

/*
    c) 1- Es una pregunta tramposa ya que los parametros de las funciones en c son copias de lo que se les pasa originalmente, asi que en principio ningun parametro es de tipo in/out, y todos son de tipo in, por lo tanto int *y de absolute() tambien lo es. Sin embargo al estar imitando el comportamiento de un procedimiento del teorico artificialmente, logramos que nuestro parametro simule ser de tipo in/out teniendo un comportamiento similar.
       2- Como se mencione en la respuesta anterior, solo existen parametros de tipo in en C.
*/