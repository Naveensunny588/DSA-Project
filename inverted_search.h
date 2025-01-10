#ifndef _INVERTED_H
#define INVERTED_H
//header files 
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//macros
#define FNAME_SIZE 20
#define WORD_SIZE 15
#define FAILURE -1
#define SUCCESS 0
#define FILE_EMPTY -2
#define FILE_NOT_AVAILABLE -3
#define REPITITION -4

//structure declarations

//1. file linked list
typedef struct node 
{
    char f_name[FNAME_SIZE];
    struct node* link; 
}Flist;

//2. Link Table 
typedef struct linkTable
{
    int word_count;
    char filename[FNAME_SIZE];
    struct linkTable* table_link;
}Ltable;

//3. Word List
typedef struct w_node
{
    int file_count;
    char word[WORD_SIZE];
    Ltable* Tlink;
    struct w_node* link;
}Wlist;

//function  prototypes

//validating the file
void file_validation_n_file_list(Flist** f_head, char* argv[]);
int is_file_empty(char* filename);
int file_insert (Flist** head, char* filename);

//create database
void create_database (Flist* f_head, Wlist* head[]);
void read_datafile(Flist* file, Wlist* head[], char* filename);
int insert_at_last(Wlist** head, char* data);
int update_link_table(Wlist** head);
int update_word_count(Wlist** head, char* file_name);

//display database
void display_database (Wlist* head[]);
int print_word_count(Wlist *head);

//update database
void update_database(Wlist* head[], Flist** f_head);

//search database
void search_database(Wlist* head, char* word);

//save database
void save_database(Wlist* head[]);
#endif
