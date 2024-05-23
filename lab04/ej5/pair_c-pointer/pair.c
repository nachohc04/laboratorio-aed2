#include <assert.h>
#include <stdlib.h>

#include "pair.h"

pair_t pair_new(int x, int y) {
    pair_t p = malloc(sizeof(struct s_pair_t));
    if (p!=NULL) {
        p->fst = x;
        p->snd = y;
    }
    // POS
    assert(p->fst==x && p->snd==y);
    return p; 
}

int pair_first(pair_t p) {
    // PRE
    assert(&(p->fst)!=NULL && &(p->snd)!=NULL); // verifico que el par ordenado (x,y) este definido
    int fst = p->fst;
    // POS
    assert(p->fst == fst);
    return fst;
}

int pair_second(pair_t p) {
    assert(&(p->fst)!=NULL && &(p->snd)!=NULL); // verifico que el par ordenado (x,y) este definido
    int snd = p->snd;
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