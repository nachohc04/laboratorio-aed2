#include <assert.h>
#include <stdlib.h>

#include "pair.h"

pair_t pair_new(int x, int y) {
    pair_t p;
    p.values[0] = x;
    p.values[1] = y;
    // POS
    assert(p.values[0]==x && p.values[1]==y);
    return p; 
}

int pair_first(pair_t p) {
    // PRE
    assert(&(p.values[0])!=NULL && &(p.values[1])!=NULL); // verifico que el par ordenado (x,y) este definido
    int fst = p.values[0];
    // POS
    assert(p.values[0] == fst);
    return fst;
}

int pair_second(pair_t p) {
    assert(&(p.values[0])!=NULL && &(p.values[1])!=NULL); // verifico que el par ordenado (x,y) este definido
    int snd = p.values[1];
    // POS
    assert(p.values[1] == snd);
    return snd;
}

pair_t pair_swapped(pair_t p) {
    assert(&(p.values[0])!=NULL && &(p.values[1])!=NULL); // verifico que el par ordenado (x,y) este definido

    pair_t q;
    q.values[0] = p.values[1];
    q.values[1] = p.values[0];

    assert(p.values[0]==q.values[1] && p.values[1]==q.values[0]);
    return q;
}

pair_t pair_destroy(pair_t p) {
    return p; // skip
}