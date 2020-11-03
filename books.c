#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"

struct book *new_book(char *chapter, int page) {
    struct book *nu;
    nu = malloc( sizeof(struct book) );
    nu->page = page;
    strncpy(nu->chapter, chapter, sizeof(nu->chapter)-1);
    return nu; 
}

void modify_book(struct book *p){
    p->page++;
}

void print_book(struct book *p){
    printf("Chapter: %s\n", p->chapter);
    printf("Page: %d\n", p->page);
}

void print_list(struct book *p){
    printf("[\n");
    while (p) {
        printf("%s: %d \n", p->chapter, p->page);
        p = p->next;
    }
    printf("]\n");
}

struct book *insert_front(struct book *p, char *chapter, int page) {
    struct book *np = new_book(chapter, page);
    np->next = p;
    return np;
}

struct book *free_list(struct book *p) {
    struct book *np = p;
    while(np) {
        struct book *next = np->next;
        free(np);
        np = next;
    }
    return np;
}

struct book *remove_node(struct book *p, char *chapter) {
    struct book *np = p;
    if (strcmp(np->chapter, chapter)) {
        np = p->next;
        free(p);
        return np;
    }

    struct book *prev = p;
    while(np) {
        if (strcmp(np->chapter, chapter)) {
            if (np->next) {
                prev->next = np->next;
            }
            else {
                prev->next = 0;   
            }
            free(np);
        }
        prev = np;
        np = np->next;
    }
    return p;
}