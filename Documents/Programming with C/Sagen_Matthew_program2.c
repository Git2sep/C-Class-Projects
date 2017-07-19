#include<stdio.h>
#define MAX_ARRAY_SIZE 50
//Author: Matthew Sagen
//3/13/17

int populate_array(int[]);     //Fill array with values from user.
void print_array(int[], int);  //Print out the array values.
void swap(int[], int, int);    //Swap two array elements.
int partition(int[],int,int);  //Find the partition point(pivot).
void quicksort(int[],int,int); //sorting algorithm

int main(void){//This is the main function that calls functions to manipulate data and print data.
   int n;
   int array[MAX_ARRAY_SIZE];
   n = populate_array(array);
   printf("The initial array contains: \n");
   print_array(array, n);
   quicksort(array, 0, n-1);
   printf("The array is now sorted: \n");
   print_array(array, n);
   return 0;
}

int populate_array(int array[MAX_ARRAY_SIZE]){//This function fills an empty array.
   int n,i,in;
   do{//Prompts user for a value "n" which is the size of the array, as long as the user enters invalid input.
      printf("Enter the value of n > ");
      scanf("%d", &n);
      if(n < 0){//Tells the user that it is invalid input if they enter a negative number.
         printf("%d is less than zero. Please try again. \n", n);
         printf("\n");
      }
      if(n > MAX_ARRAY_SIZE){//If the user enters a number larger than 50, it tells the user that the input is invalid.
         printf("%d exceeds the maximum array size. Please try again. \n", n);
         printf("\n");
      }
   }while(n > MAX_ARRAY_SIZE || n < 0);
   printf("Enter %d integers (positive, negative, or zero) >\n",n);
   for(i = 0; i < n; i++){//This loop allows the user to enter as many inputs as they indicated with the loop above.
      scanf("%d", &in);
      array[i] = in;
   }   
  
   return n;
}

void quicksort(int a[], int low, int high){ //This method sorts the value in the array from smallest to largest.
   int pivot;
   if(low < high){//If low is less than high, then we select a pivot using the partition method, and sort the two halves of the array with quicksort.
      pivot = partition(a,low,high);
      quicksort(a, low ,pivot -1);
      quicksort(a, pivot + 1, high);
   }
}

int partition(int a[], int low, int high){//This method is used to partition the array and returns the pivot point.
   int pivot,i,j;
   pivot = a[high];
   i = low;
   for(j = low; j <= high - 1; j++){//This loops from low to high -1
      if(a[j] <= pivot){//if the number contained at a[j] is <= to the pivot value, then the two values are swapped around.
        swap(a, i, j);
        i += 1;
      }
   }
   swap(a, i, high);
   return i;
}

void swap(int a[], int i, int j){//This is a helper function used to swap values.
   int temp;
   temp = a[i];
   a[i] = a[j];
   a[j] = temp;
}

void print_array(int a[], int n){//This function prints out the contents of the array.
   int i;
   for(i = 0; i < n; i++){//This loops through the array to get the contents at each index.
      printf("%+5d \n", a[i]);
   }
}
