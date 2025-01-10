#include "inverted_search.h"
void save_database(Wlist* head[])
{
    //file in which database will be saved
    char file_name[FNAME_SIZE];
    
    printf("Enter the filename in which you want to save the database: ");
    scanf("%s", file_name);
        
    FILE* fptr = fopen(file_name, "w");				//opening file in append mode
       
    fprintf(fptr,"[index] [word] filecount file/s : file_name word_count\n");
    fprintf(fptr,"\n--------------------------------------------------\n");
    
    for (int i = 0; i < 27; i++)
    {
        Wlist* temp = head[i];
        while (temp != NULL)
        {
            fprintf(fptr,"[%d] [%s] %d files:\t", tolower(temp->word[0]) %97, temp->word, temp->file_count);           
	    Ltable* l_temp = temp->Tlink;            
	    while (l_temp != NULL)
            {
                fprintf(fptr,"%s %d\t",l_temp->filename, l_temp->word_count);
                l_temp = l_temp->table_link;
            }            
	    fprintf(fptr,"\n");            
	    temp = temp->link;				 //moving temp to next node
        }
    }
    fprintf(fptr,"\n--------------------------------------------------\n");
    printf("Database saved successfully in %s\n", file_name);
    fclose(fptr);
}
