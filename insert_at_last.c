#include "inverted_search.h"
extern char* fname;
int insert_at_last(Wlist** head, char* data)
{
    //creating new node
    Wlist* new = malloc(sizeof(Wlist));
    //validating new
    if (new == NULL)
        return  FAILURE;

    //updating fields of new
    new->file_count = 1;
    strcpy(new->word, data);
    new->Tlink = NULL;
    new->link = NULL;

    //call function to create the link table
    update_link_table(&new);

    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    Wlist* temp = *head;
    //traverse till last node
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

int update_link_table(Wlist** head)
{
    //creating new link table node
    Ltable* new_link_table = malloc(sizeof(Ltable));
    //error check
    if (new_link_table == NULL)
        return FAILURE;
    //Updating link table values
    strcpy(new_link_table->filename, fname);    
    new_link_table->word_count = 1;
    new_link_table->table_link = NULL; 

    // establish the link between wlist node and link table
    (*head)->Tlink = new_link_table;
    return SUCCESS;     
}
