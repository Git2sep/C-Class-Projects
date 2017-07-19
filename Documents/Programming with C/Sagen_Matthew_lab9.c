#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_ELEMENTS 20

struct element_t;
struct list;
void scan_element(struct element_t element);
void print_element(struct element_t element, int N);

struct element_t{//This is the structure that contains data from user input
   int atomicNum[MAX_ELEMENTS]; 
   char name[MAX_ELEMENTS]; 
   char chemical[MAX_ELEMENTS]; 
   char class[MAX_ELEMENTS];
   double atomicWeight[MAX_ELEMENTS]; 
   int numElec[MAX_ELEMENTS];
};

struct list{//This structure contains an instance of the above structure.
   struct element_t *elements[MAX_ELEMENTS];
};

int main(int agrc, char *argv[]){//This is the main function.
   struct element_t element;
   int i;
   if(argv[2] != NULL || argv[1] == NULL){//If there are more than one, or no command line arguments, exit the program.
      printf("Error: You must provide exactly one argument to this program.\n");
      return 0;
   }
   int N = (int) strtol(argv[1], NULL, 10);
   if(N <= 0 || N > MAX_ELEMENTS){//If if the user enters a negative number, or a number outside of the range, exit the program.
      printf("Error: You must provide an integer greater than 0 and less than or equal to 20. \n");
      return 0;
   }
   for(i = 0; i < N; i++){//scan N number of elements as indicated by user input.
      scan_element(element);
   }
   print_element(element, N);
return 0;
}

void scan_element(struct element_t element){//This method scans in data from the user.
   int iter = 0;
   scanf("%d %s %s %s %lf", element.atomicNum, element.name, element.chemical, element.class, element.atomicWeight);
   scanf("%d", &element.numElec[iter]);
   iter++;
}

void print_element(struct element_t element, int N){//This method prints out the data in a specialized format.
   for(int i = 0; i < N; i++){//This loops N times to print out each node of data.
      printf("---------------\n");
      printf("| %d  %.4f \n", element.atomicNum[i], element.atomicWeight[i]);
      printf("| %s %s \n", element.chemical, element.name);
      if(element.numElec[i] > 0){//If the number of electrons is greater than 0, print the extra line containing the information. 
         printf("| ");
         printf("%d \n", element.numElec[i]);
      }
      printf("---------------\n");
   }
}
