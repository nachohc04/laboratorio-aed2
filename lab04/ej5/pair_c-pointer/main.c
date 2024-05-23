#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

static
void show_pair(pair_t p) {
    printf("(%d, %d)\n", p->fst, p->snd);
}

int main(void) {
    pair_t p, q;
    // Nuevo par p
    p = pair_new(3, 4);
    // Se muestra el par por pantalla
    printf("p = ");
    show_pair(p);
    // Nuevo para q con elementos de p intercambiados
    q = pair_swapped(p);
    // Se muestra q
    printf("q = ");
    show_pair(q);
    // Se destruyen p y q
    p = pair_destroy(p);
    q = pair_destroy(q);
    return EXIT_SUCCESS;
}

/*
    c) Esta implementacion no logra encapsulamiento ya que depende de la implementacion y no de la especificacion del TAD, como se observa en la funcion show_pair se hace referencia a p->fst y p->snd, lo cual podria dejar de funcionar si se cambia la implementacion del TAD para que no use punteros, para que haya encapsulamiento deberia usar las funciones pair_first y pair_second en cambio. 
*/