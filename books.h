#ifndef BOOK_CHAPTER
#define BOOK_CHAPTER

struct book {
    char chapter[256];
    int page; 
    struct book *next;
};

struct book *new_book(char *chapter, int page);
void modify_book(struct book *p);
void print_book(struct book *p);
void print_list(struct book *p);
struct book *insert_front(struct book *p, char* chapter, int page);
struct book *remove_node(struct book *p, char* chapter);
struct book *free_list(struct book *p);

#endif