#include "inverted_search.h"
void search_database(Wlist* head, char* word)
{
    if (head==NULL)
    {
	    printf("Search word is not found, list is empty\n");	  
    }

    while (head)
    {
        if (!(strcmp(head->word,word)))
        {           
            printf("Word %s is present in %d file/s\n", head->word, head->file_count);
            
	    Ltable *Thead = head->Tlink;
            while (Thead)
            {
                printf("In the file : %s\t%d times\n",Thead->filename, Thead->word_count);
                Thead = Thead->table_link;
            }
	    printf("\n");
            return;
        }
        head = head->link;
    }
    //if we come out of while loop that means word not present in database
    printf("Search word is not found in the list\n");
}
