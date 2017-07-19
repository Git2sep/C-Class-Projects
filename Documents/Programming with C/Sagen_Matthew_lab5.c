#include<stdio.h>
void get_input(void);
int oddSum(void);
int evenSum(void);
int check_last_digit(int);
void is_valid(int);

int barCode[12];

int main(void){//This is the main function.
   int sum1,sum2,totalSum,check;
   get_input();//retrieves input from user.
   sum1 = oddSum();//sets sum of odd indices to sum1.
   printf("STEP 1: Sum of odds times 3 is %d \n", sum1);
   sum2 = evenSum();//sets sum of even indices to sum2.
   printf("STEP 2: Sum of the even digits is %d \n", sum2);
   totalSum = sum1 + sum2;
   printf("STEP 3: Total sum is %d \n", totalSum);
   check = check_last_digit(totalSum);//determines check value   
   printf("STEP 4: Calculated check digit is %d \n", check);
   is_valid(check);//checks to see if check value and last valud of array are equal.
return 0;
}


void get_input(void){//This method gets the barCode from the user.
   int in;
   int i = 0;
   printf("Enter a bar code to check. Separate digits with a space > \n");
   while(i < 12){//This loop allows the user to enter a 12 digit barcode, and scans it into the barCode array.
      scanf("%d", &in);
      barCode[i] = in;
      i++;
   }
   printf("\n");
   printf("You have entered the code: ");
   for(i = 0; i < 12; i++){//This reaffirms to the user the barcode that they entered.
      printf("%d ", barCode[i]);
   }
   printf("\n");
}


int oddSum(void){//This method sums the number at each odd position of the barcode.
   int a;
   int sum = 0;
   for(a = 0; a < 12; a += 2){//this loops through the odd numbers in the barCode that the user entered and sums each of them. 
      sum = sum + barCode[a];
   }
   sum = sum * 3;
   return sum;
}


int evenSum(void){//This method sums the number at each even position of the barcode.
   int e;
   int evens = 0;
   for(e = 1; e < 11; e += 2){//This loops through the even numbers in the barCode execpt for the final number, and sums them.
      evens = evens + barCode[e];
   }
   return evens;
}

int check_last_digit(int total){//This method determines the check value.
   int last;
   last = total % 10;
   if(last == 0){//If the modulus of the last number the user entered and 10 is equal to 0, then we simply return 0;
      return last;
   }
   else{//Otherwise we subtract the last number the user entered from 10, and return that value.
      last = 10 - last;
      return last;
   }
}

void is_valid(int a){//This method checks the validity of the barcode.
  
   if(a == barCode[11]){//If the check valud matches the last digit of the barcode that the user entered. The barcode is valid.
     printf("STEP 5: Check digit and last digit match \n");
     printf("Barcode is VALID. \n");
   }
   else{//Otherwise we deem the barcode to be invalid.
     printf("STEP 5: Check digit and last digit do not match \n");
     printf("Barcode is INVALID. \n");
   }
}
