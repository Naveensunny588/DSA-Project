#include "inverted_search.h"

void display_database (Wlist* head[])
{
    printf("[index]\t[word]\tfilecount\tfile/s: file_name word_count\n");
    printf("\n--------------------------------------------------\n");
    
    for (int i = 0 ; i < 27; i++)
    {
	if(head[i] != NULL)
	{
	     print_word_count(head[i]);
	}
     }
}

int print_word_count(Wlist *head)
{	     
	while (head != NULL)						//traverse through the Wlist
        {
            printf("[%d]\t[%s]\t%d\tfiles:\t", tolower(head->word[0]) %97, head->word, head->file_count);

            Ltable *Thead = head->Tlink;
            
	    while (Thead)
            {
                printf("File : %s\t%d ",Thead->filename, Thead->word_count);
                Thead = Thead->table_link;
            }
            printf("\n");            
            head = head->link;						//moving temp to next node
        }    
    	printf("\n--------------------------------------------------\n");
}
