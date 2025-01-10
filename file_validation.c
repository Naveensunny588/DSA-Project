#include "inverted_search.h"

void file_validation_n_file_list(Flist** f_head, char* argv[])
{
    //Read file 1 by 1
    int i = 1, empty, ret_val;
    
    while (argv[i] != NULL)
    {
        empty = is_file_empty(argv[i]);
        
	if (empty == FILE_NOT_AVAILABLE)
        {
            printf("The file %s is not available\nHence we are not adding this into File Linked List\n", argv[i]);
            i++;
        }
        else if (ret_val == FILE_EMPTY)
        {
            printf("The file %s is Empty\nHence we are not adding %s into File Linked List\n", argv[i], argv[i]);
            i++;
        }
        else
        {
            //valid file. Hence adding it to the linked list
            ret_val = file_insert (f_head, argv[i]);
            
	    if (ret_val == SUCCESS)
            {
                printf("Successful in Inserting file %s into the File Linked List\n",argv[i]);
            }
            
	    else if (ret_val == REPITITION)
            {
                printf("This file %s is Repeated\nHence we are not adding %s into file Linked List\n", argv[i], argv[i]);
            }
            
	    else
            {
                printf("Failed to add the file into the File Linked List");
            }
            i++;
        }
    }
}

/*
    Check whether the file is available or not
    File not available --> FILE_NOT_A`66VAILABLE macro
    File is available --> whether file empty or not
    File empty --> FILE_EMPTY
*/
int is_file_empty(char* filename)
{
    							
    FILE* fptr = fopen(filename, "r");			//opening the file read only mode
   							
    if (fptr == NULL)					//validating fptr. If fprt NULL then file not available
    {
        return FILE_NOT_AVAILABLE;
    }
    						
    fseek(fptr, 0L, SEEK_END);				//check if file empty or not
    
    if (ftell(fptr) == 0)
    {
        return FILE_EMPTY;
    }
     
    return SUCCESS;					//if ftell(fptr) not 0 that means file has some data so return SUCCESS
}

/*
    insert the file in Flist
    1. file already there --> return FILE_REPITIION
    2. insert file in Flist
*/
int file_insert (Flist** head, char* filename)
{
    Flist* temp = *head;
    while (temp != NULL)
    {
        if (strcmp(temp->f_name, filename) == 0)
        {
            return REPITITION;
        }
        temp = temp->link;
    }

    //creating new node
    Flist* new_file = malloc(sizeof(Flist));
    
    //validating new
    if (new_file == NULL)
    {
        return FAILURE;
    }

    //updating filename and link part
    strcpy(new_file->f_name, filename);
    
    new_file->link = NULL;
    
    if (*head == NULL)
    {
        *head = new_file;
         return SUCCESS;
    }

    temp = *head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new_file;
    
    return  SUCCESS;
}
