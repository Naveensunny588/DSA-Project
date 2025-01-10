#include "inverted_search.h"
void update_database(Wlist* head[], Flist** f_head)
{
        char file_name[FNAME_SIZE];
       // __fpurge(stdin);
        printf("Enter the filename you want to add in Database: ");
        scanf("%s", file_name);
        
        //validate the file
        int empty = is_file_empty(file_name);
        if (empty == FILE_NOT_AVAILABLE)
        {
            printf("The file %s is not available\nHence we are not adding this into File Linked List\n", file_name);
            return;
        }
        else if (empty == FILE_EMPTY)
        {
            printf("The file %s is Empty\nHence we are not adding %s into File Linked List\n", file_name, file_name);
            return;
        }
        else
        {
            //valid file. Hence adding it to the linked list
            int result = file_insert (f_head, file_name);
            if (result == SUCCESS)
            {
                printf("Successful in Inserting file %s into the File Linked List\n",file_name);
            }
            else if (result == REPITITION)
            {
                printf("This file %s is Repeated\nHence we are not adding %s into file Linked List\n", file_name, file_name);
                return;
            }
            else
            {
                printf("Failed to add the file into the File Linked List");
                return;
            }
        }

        //after successful insertion of file into the file linked list
        Flist* f_temp = *f_head;
        while (f_temp)
        {
            if (!strcmp(f_temp->f_name, file_name))
            {
                create_database(f_temp, head);
                return;
            }
            f_temp = f_temp->link;
        }
        printf("Database updated successfully!!\n");
}
