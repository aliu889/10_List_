#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "books.h"

int main(){
    struct book *Alice_in_Wonderland = NULL;
    char c1[] = "Down the Rabbit Hole";
    char c2[] = "The Pool of Tears";
    char c3[] = "A Caucus Race and a Long Tale";
    char c4[] = "The Rabbit Sends in a Little Bill";
    char c5[] = "Advice from a Caterpillar";

    printf("Printing empty list: \n");
    print_list(Alice_in_Wonderland);
    printf("\n");

    printf("Adding chapter 1 to list: \n");
    Alice_in_Wonderland = insert_front(Alice_in_Wonderland, c1, 60);
    print_list(Alice_in_Wonderland);
    printf("\n");

    printf("Adding rest of chapters to list: \n");
    Alice_in_Wonderland = insert_front(Alice_in_Wonderland, c2, 60);
    Alice_in_Wonderland = insert_front(Alice_in_Wonderland, c3, 60);
    Alice_in_Wonderland = insert_front(Alice_in_Wonderland, c4, 60);
    Alice_in_Wonderland = insert_front(Alice_in_Wonderland, c5, 60);
    print_list(Alice_in_Wonderland);
    printf("\n");

    printf("Removing chapter 3 from list: \n");
    Alice_in_Wonderland = remove_node(Alice_in_Wonderland, c3);
    print_list(Alice_in_Wonderland);
    printf("\n");
    
    printf("Removing last chapter from list: \n");
    Alice_in_Wonderland = remove_node(Alice_in_Wonderland, c5);
    print_list(Alice_in_Wonderland);
    printf("\n");

    printf("Freeing remaining chapters: \n");
    Alice_in_Wonderland = free_list(Alice_in_Wonderland);
    print_list(Alice_in_Wonderland);  
}