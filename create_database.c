#include "inverted_search.h"
char* fname;
void create_database (Flist* f_head, Wlist* head[])
{
  
    while (f_head)							  //repeat till the end of the list
    {
        read_datafile(f_head, head, f_head->f_name);
        f_head = f_head->link;
    }
}

void read_datafile(Flist* file, Wlist* head[], char* filename)
{
    fname = filename;							//store the filename
    FILE* fptr = fopen(filename, "r");					//open the file in read only mode
    if (fptr == NULL)							// validate
    {
        printf("Error in Openning %s file\n", filename);
    }

    //declare an array to store the word
    char word[WORD_SIZE];
    
    while (fscanf(fptr, "%s", word) != EOF)
    {
        int flag = 1;
        								//extarcting first letter of word justr read from file and finding the position of word in between a - z
        int index = tolower(word[0]) % 97;
        								//other than alphabets
        if ( !(index >= 0 && index <= 25) )
            index = 26;
        								//check whether words are repeated 
        if (head[index] != NULL)
        {
            Wlist* temp = head[index];
            while (temp)
            {
                if(!(strcmp(temp->word, word)))
                {
                    update_word_count(&temp,filename);
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
        }
        if (flag == 1)    
           								 //if words are different   
            insert_at_last (&head[index], word); 
    }
    printf("Successful in creating database for %s file\n", filename);
}

int update_word_count(Wlist** head, char* file_name)
{
    									//if word is in same file --> increment word count
    									//if word is in different file --> increment file count and add link table node
    Ltable* temp = (*head)->Tlink;
    Ltable *prev = NULL;
    
    while (temp)
    {
        if (!strcmp(temp->filename, file_name))
        {
            								//update word count
            temp->word_count++;
            return SUCCESS;
        }
        prev = temp;
        temp = temp->table_link;
    }
    									//If we come out of while loop that means the repeated word is not from the already listed files  									
    (*head)->file_count++;						//updating file count    
    Ltable* new = malloc(sizeof(Ltable));				//adding new node in link table
      
    if (new == NULL)							 //error check
        return FAILURE;
        
    strcpy(new->filename, file_name);   				//Updating link table values    
    new->word_count = 1;
    new->table_link = NULL;  
    prev->table_link = new;						//establishing the link between prev and 

    return SUCCESS;
}
