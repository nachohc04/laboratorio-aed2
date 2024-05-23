#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>


typedef struct _Node *list; // pointer to Node
typedef int list_element;

struct _Node {
    list_element elem;
    list next;
};

/* Constructors */
list empty();
/*
 * DESC: Creates an empty list.
 */

list addl(list_element e, list l);
/*
 * DESC: Adds an element to the beggining of the list.
 */


/* Operations */
bool is_empty(list l);
/*
 * DESC: Returns true if l is an empty list.
 */

list_element head(list l);
/*
 * DESC: Returns the first element of l.
 */

list tail(list l);
/*
 * DESC: Deletes the first element of l.
 *
 * PRE: {!is_empty(l)}
 * 
 */

list addr(list l, list_element e);
/*
 * DESC: Adds element e to the right of list l.
 */

unsigned int length(list l);
/*
 * DESC: Returns the ammount of elements of l. 
 */

list concat(list l1, list l2);
/*
 * DESC: Adds elements of l2 to the end of l1. 
 */

list_element index(list l, unsigned int n);
/*
 * DESC: Returns the n-th element of l.
 *
 * PRE: {length(l)>n} 
 */

list take(list l, unsigned int n);
/*
 * DESC: Modifies l to be the initial segment from 0 to the n-th element.
 */

list drop(list l, unsigned int n);
/*
 * DESC: Deletes the first n elements of l. 
 */

list copy_list(list l);
/*
 * DESC: Returns a copy of l. 
 */


/* Destroy */
list destroy(list l);
/*
 * DESC: Frees memory if necessary.
 */

#endif