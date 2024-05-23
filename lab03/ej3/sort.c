/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    bool res;
    
    if (x.rank<=y.rank) {
        res = true;
    } 
    else {
        res = false;
    }

    return res;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t a[], unsigned int i, unsigned int j) {
    player_t aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

unsigned int partition(player_t a[], unsigned int lft, unsigned int rgt) {
    unsigned int ppiv = lft;
    unsigned int i = lft +1;
    unsigned int j = rgt;

    while(i<=j) {
        if (goes_before(a[i],a[ppiv])) {
            i++;
        }
        else if(goes_before(a[ppiv], a[j])) {
            j--;
        }
        else {
            swap(a,i,j);
            j--;
            i++;
        }
    }
    swap(a,j,ppiv);
    ppiv=j;
    
    return ppiv;
}

void quick_sort_rec(player_t a[], unsigned int lft, unsigned int rgt) {
    unsigned int ppiv;
    if (lft<rgt) {
        ppiv = partition(a,lft,rgt);

        if (ppiv>lft) {
            quick_sort_rec(a,lft, ppiv-1);
        }
        
        if (ppiv<rgt) {
            quick_sort_rec(a,ppiv+1,rgt);
        }
    }
}

void sort(player_t a[], unsigned int length) {
    quick_sort_rec(a,0,length-1);
}

