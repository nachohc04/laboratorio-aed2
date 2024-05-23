#include <assert.h>
#include <stdlib.h>

#include "pair.h"

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y) {
    pair_t p = malloc(sizeof(struct s_pair_t));
    if (p!=NULL) {
        p->fst = x;
        p->snd = y;
    }
    // POS
    assert(p->fst==x && p->snd==y);
    return p; 
}

elem pair_first(pair_t p) {
    // PRE
    assert(&(p->fst)!=NULL && &(p->snd)!=NULL); // verifico que el par ordenado (x,y) este definido
    elem fst = p->fst;
    // POS
    assert(p->fst == fst);
    return fst;
}

elem pair_second(pair_t p) {
    assert(&(p->fst)!=NULL && &(p->snd)!=NULL); // verifico que el par ordenado (x,y) este definido
    elem snd = p->snd;
    // POS
    assert(p->snd == snd);
    return snd;
}

pair_t pair_swapped(pair_t p) {
    assert(&(p->fst)!=NULL && &(p->snd)!=NULL); // verifico que el par ordenado (x,y) este definido

    pair_t q = malloc(sizeof(struct s_pair_t));
    q->fst = p->snd;
    q->snd = p->fst;

    assert(p->fst==q->snd && p->snd==q->fst);
    return q;
}

pair_t pair_destroy(pair_t p) {
    free(p); // libero la memoria utilizada por malloc
    p=NULL; // reinicio el puntero
    return p;
}

/*
    d) Esta implementacion si logra encapsulamiento, ya que solo cambio donde se define el struct, pero el usuario seguira sin tener que depender de la implementacion para utilizar el TAD.
*/