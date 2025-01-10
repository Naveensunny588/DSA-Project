/*Name : Naveen ps
Title  : Inverted Search*/
#include "inverted_search.h"

int main(int argc, char* argv[])
{
    system("clear");
    
       if (argc == 1)									//validating Command Line Arguments (if only 1 CLA passed then throw an error)
    {
        printf("Enter valid number of Command Line Arguments\n./Slist.exe f1.txt f2.txt f3.txt\n");  
        return 0;
    }
   
    Flist* f_head = NULL;								 //Declare a head pointer for file linked list
    file_validation_n_file_list(&f_head, argv);
    if (f_head == NULL)
    {
        printf("No files are available in the file list\nHence the process is terminated\n");
        return 1;
    }
   
    int choice;
    char option;
    Wlist* head[27] = {NULL};
    char word[WORD_SIZE];
    do
    {
        printf("1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
       
        case 1:
            create_database(f_head, head);					 //create database function call
            break;
            
        case 2:
                display_database(head);						//display
                break;
           
        case 3:
                update_database(head, &f_head);					 //update    
                break;
          
        case 4:
                //clearing input buffer
               // __fpurge(stdin);
                printf("Enter the word you want to search: ");			//search      
                scanf("%s",word);
                search_database(head[tolower(word[0])%97],word);
                break;
        
        case 5:
                save_database(head);						//save database
                break;        
        default:
            break;
        }

        printf("Do you want to continue (y/n): ");
        getchar();
        scanf("%c",&option);
    } while (option == 'Y'|| option == 'y');
    
}
