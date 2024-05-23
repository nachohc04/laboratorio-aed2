#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

static
void show_pair(pair_t p) {
    printf("(%d, %d)\n", pair_first(p), pair_second(p));
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
    I) Falla porque cambio la forma en la que esta implementado pair_t, ahora se guarda en un arreglo dentro de una tupla, antes se guardaba en campos de la tupla.
    II) Para que funcione tuve que modificar la funcion show pair para que muestre los valores del arreglo values en los que ahora se guardan fst y snd (utilizando las funciones pair_first y pair_second provistas por el TAD).
    III) El diseño de este TAD logra encapsulamiento, ya que mediante las funciones pair_first y pair_second abstrae al usuario de la implementacion, y aunque cambie la forma en la que se implemento pair_t, no se tendran que modificar las funciones que lo utilizan.
*/