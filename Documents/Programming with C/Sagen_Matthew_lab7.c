#include<stdio.h>
#include<string.h>
//Matthew Sagen
//3/28/2017

char *my_strncpy(char *dest, char *source, int in);
char *my_strncat(char *dest, char *source, int n);

int main(void){//Main function, prints out end results of data manipulation.

   char testSrc[] = "worldhello";
   char testDest[40] = "helloworld";
   int n = 15;
   
   my_strncat(testDest, testSrc, n);
   printf("CAT: %s \n", testDest);
   
   my_strncpy(testDest, testSrc, n);
   printf("CPY: %s \n", testDest);

   printf("%s \n", testDest);
   return 0;
}

char *my_strncat(char *dest, char *source, int n){//Concatenates two character arrays together. "appends n char's of source to the end of dest"
   int i;
 
   for(i = 0; i < n; i++){//adds n char's from source to the end of dest by looping n times.
      dest[strlen(dest)] = source[i];
   }
   dest[strlen(dest)+ n] = '\0';//assigns the exit operator to the end of the altered array.
   return dest;
}

char *my_strncpy(char *dest, char *source, int n){//Copies a given number of character elements from a soure char[], into a destination char[]
   int i;
   for(i = 0; i < n; i++){//loop to assign first n elements of dest to the first elements of source.
      dest[i] = source[i];
   }
   dest[n] = '\0';//assings the exit operator to the end of the altered array.

   return dest;
}
