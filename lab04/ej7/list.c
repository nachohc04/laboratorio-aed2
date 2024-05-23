#include <assert.h>


#include <stdio.h>



#include <stdbool.h>
#include <stdlib.h>

#include "list.h"


list empty() {
    list l = NULL;
    return l;
}

list addl(list_element e, list l) {
    list p = malloc(sizeof(struct _Node));
    if (p!=NULL) {
        p->elem=e;
        p->next=l;
        l=p;
    }
    return p;
}

bool is_empty(list l) {
    bool b;
    b = (l == NULL);
    return b;
}

list_element head(list l) {
    list_element e;
    e = l->elem;
    return e;
}

list tail(list l) {
    list aux = l->next;
    free(l);
    l=aux;
    return l;
}

list addr(list l, list_element e) {
    // creo nuevo elemento
    list new_elem = malloc(sizeof(struct _Node));
    new_elem->elem = e;
    new_elem->next = NULL;
    
    if (!is_empty(l)) {
        // Recorro la lista para obtener direccion del ultimo elemento
        list p = l;
        while(p->next!=NULL) {
            p=p->next;
        }
        // Modifico el ultimo elemento de l para que apunte a mi nuevo elemento
        p->next = new_elem;
    }
    else {
        l = new_elem;
    }

    return l;
}

unsigned int length(list l) {
    unsigned int c;
    c = 0;
    if (!is_empty(l)) {
    
        list p = l;
        while(p!=NULL) {
            c++;
            p=p->next;
        }
    }
    return c;
}

list concat(list l1, list l2) {
    if (is_empty(l1)) {
        l1 = l2;
    }
    else {
        // Recorro la lista para obtener direccion del ultimo elemento
        list p = l1;
        while(p->next!=NULL) {
            p=p->next;
        }
        
        p->next = l2;
    }
    return l1;
}

list_element index(list l, unsigned int n) {
    list_element e;

    list p = l;

    for (unsigned int i = 1u;i<n;++i) {
        p=p->next;
    }

    e = p->elem;
    return e;
}

list take(list l, unsigned int n) {
    if (!is_empty(l)) {
        list p = l;
        // hago que p llegue al n-esimo elemento
        for (unsigned int i = 1u;i<n;++i) {
            p=p->next;
        }
        // guardo referencia al n+1-esimo elemento
        list nplus_elem = p->next;
        // hago que mi n-esimo elemento apunte a NULL
        p->next = NULL;
        // libero la memoria del n+1-esimo elemento en adelante
        destroy(nplus_elem);
    }
    return l;
}

list drop(list l, unsigned int n) {
    if (!is_empty(l)) {
        for (unsigned int i = 1u;i<=n;++i) {
            list current_elem_ref = l;
            l=l->next;
            free(current_elem_ref);
        }
    }

    return l;
}

list copy_list(list l) {
    list copy = empty();
    list p = l;
    if (!is_empty(l)) {
        while (p!=NULL) {
            copy = addr(copy, p->elem);
            p = p->next;
        }
    }

    return copy;
}

list destroy(list l) {
    if (!is_empty(l)) {
        while(l!=NULL) {
            list current_elem_ref = l;
            l=l->next;
            free(current_elem_ref);
        }
    }
    return l;
}