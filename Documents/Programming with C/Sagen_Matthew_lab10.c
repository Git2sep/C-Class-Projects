/*
 *Matthew Sagen
 *4/27/17
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELEMENT_FILENAME "element_db.csv"

typedef struct {//This structure stores data for each element
    int atomic_number;
    char symbol[4];
    char name[25];
    float atomic_weight;
    char state[25];
    char bonding_type[25];
    char discovered[25];
} element_t;

element_t * find_element( element_t * list, char * symbol );

int main(int argc, char * argv[]){//The main fuction
    if (argc < 2){//IF there is no arguments, exit the program
        printf(" ERROR: Please provide at least one program argument.\n");
        return 0;
    }
    element_t * elements = (element_t *)calloc( 118 , sizeof( element_t ) );    
    FILE * element_file = fopen( ELEMENT_FILENAME, "r" );
    if ( element_file != NULL ){//If the file is not empty, extract the data
        char line[100];
        while( fgets(line, 100, element_file ) != NULL ){//While there is a next line, get the data from each line
            char * nl = strchr( line, '\n' );
            if (nl){//remove the newline character from line                
                 *nl = '\0';
            }
            printf("line = %s\n", line);
            element_t e;
            char * str = strtok( line, ",");
            int col = 0;
            while ( str != NULL ){//while there is a comma, extract data before the comma
                switch(col)
                {//gets the data at each position in the list to store in the element data structure
                    case 0:
                        e.atomic_number = atoi(str);
                        break;
                    case 1:
                        strcpy( e.symbol, str);
                        break;
                    case 2:
                        strcpy( e.name, str);
                        break;
                    case 3:
                        e.atomic_weight = atoi(str);
                        break;
                    case 4:
                        strcpy(e.state, str);
                        break;
                    case 5:
                        strcpy(e.bonding_type, str);
                        break; 
                    case 6:
                        e.discovered = atof(str);
                        break;
                 }
                 str = strtok(NULL,",");
                 col++;
             }
             elements[ e.atomic_number - 1 ] = e;
             printf(" %s\n", elements[ e.atomic_number - 1].symbol );
             }
             fclose(element_file);
         }
         FILE * output_f = NULL;
         //process program aguments.
         int i;
         for(i = 1; i < argc; i++){//loops for the number, argc
            if(i == 1) // check for filename
            {
               char * dot = strchr( argv[i], '.');
               if(dot){//if there is a period, open the file
                  output_f = fopen( argv[i], "w" );
                  continue;
               }
            }// Look up this elemet
            element_t * ele = find_element( elements, argv[i] );
            if (ele){//if the element exists print it
              printf("%d %s\n", ele->atomic_number, ele->symbol);
            }
         }
         return 0;
      }

element_t * find_element( element_t * list, char * symbol ){//method to find an element
    int i;
    for(i = 0; i < 118; i++){//loops for the total number of possible elements
       if (strcmp(list[i].symbol, symbol) == 0){//if the element is found return it
           element_t * result = &list[i];
           return result;
       }
    }
    return NULL;
} 
