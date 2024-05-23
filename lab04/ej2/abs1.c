#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x>=0) {
        y=x;
    }
    else {
        y= (-1)*x;
    }
}

int main(void) {
    int a=-10, res=0;
    
    absolute(a, res);
    // deberia mostrar 10
    printf("res=%d\n", res);

    return EXIT_SUCCESS;
}

// el programa analogo a este del teorico deberia retornar res=10, sin embargo este retorna res=0