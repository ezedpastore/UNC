#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

struct _list {
    list_elem e;
    list next;
};

list empty(void){
    list l = NULL;

    return l;
}

list addl(list l, list_elem x){
    if(is_empty(l)){
        l = malloc(sizeof(list));
        l->e = x;
    }
    else{
        list l2 = empty();
        l2 = malloc(sizeof(list));
        l2 -> e = x;
        l2 -> next = l;
        l = l2;
        l2 = NULL;
    }

    return l;
}

list destroy(list l){
    if(!is_empty(l)){
        list aux = empty();
        while(l->next != NULL){
            aux = l;
            l = l->next;
            free(aux);
        }
        aux = NULL;
    }
    else{
        l = NULL;
    }
    
    return l;
}

bool is_empty(list l){
    bool b;
    if(l == NULL){
        b = true;
    }
    else{
        b = false;
    }

    return b;
}

list_elem head(list l){
    list_elem first_elem;
    first_elem = l->e;

    return first_elem;
}

list tail(list l){
    list p = empty();
    p = l;
    l = l->next;
    free(p);

    return l;
}

list addr(list l, list_elem x){
    list p = empty();
    list q = empty();
    q = malloc(sizeof(list));
    q->e = x;
    q->next = NULL;
    
    if(!is_empty(l)){
        p = l;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = q;
    }
    else{
        l = q;
    }

    return l;
}

unsigned int length(list l){
    unsigned int n;
    n = 0;
    
    if(!is_empty(l)){
        list p = empty();
        p = l;
        while(p != NULL){
            n = n + 1;       
            p = p->next;
        }
    }

    return n;
}

list concat(list l1, list l2){
    if(is_empty(l1)){
        l1 = l2;
    }
    else{
        list p = empty();
        p = l1;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = l2;
    }

    return l1;
}

list_elem index(list l, unsigned int n){
    assert(length(l) <= n);
    unsigned int i;
    i = 0;
    list p = empty();
    p = l;
    while(i < n){
        p = p->next;
        i = i + 1;
    }
    list_elem e2 = p->e;
    p = NULL;

    return e2;
}

list take(list l, unsigned int n){
    if(length(l) >= n){
        unsigned int i = 0;
        list p = empty();
        list q = empty();
        p = l;

        while(i < n){
            p = p->next;
            i = i + 1;
        }

        if(p->next != NULL){
            q = p->next;
            if(q->next != NULL){
                p = q->next;
                while(p != NULL){
                    free(q);
                    q = p;
                    p = p->next;
                }
                free(q);
                free(p);
            }
            free(q);
        }
        p = NULL;
        q = NULL;
    }
    
    return l;
}

list drop(list l, unsigned int n){
    if(length(l) <= n){
        list p = empty();
        list q = empty();
        p = l;
        while(p != NULL){
            q = p;
            p = p->next;
            free(q);
        }
        l = p;
    }
    else{
        unsigned int i = 0;
        list p = empty();
        list q = empty();
        p = l;
        while(i < n){
            q = p;
            p = p->next;
            free(q);
            i = i + 1;
        }
        l = p;
        p = NULL;
    }

    return l;
}

list copy_list(list l){
    list l2 = empty();
    
    list aux = empty();
    aux = l;
    
    while(aux != NULL){
        l2 = addr(l2, aux->e);
        aux = aux->next;
    }
    
    return l2;
}