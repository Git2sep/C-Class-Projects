#include<stdio.h>
/**
 * Author: Matthew Sagen
 * 2/19/2017
 * */
int get_input(void);
int is_valid(int);
void print_pattern(int);

int main(void){//This is the main function, it calls get_input and print_pattern.
	int x = get_input();//sets x equal to a number obtained from the user.
	printf("\n");
	print_pattern(x);//prints the diamond created from x.
	printf("\n");
return 0;

}

int get_input(void){//This function retrieves an odd number from the user.
	int num;
	do{//this loop prompts the user for input, and scans the number into a variable "num".
	   printf("Enter an odd number less than or equal to 9 and greater than 0 > ");
           scanf("%d", &num);
	}
	while(is_valid(num)== -1);//this checks to see if the number is valid, if not it runs the do loop again.
	return num;//if the number is valid, it is then returned to the main function.
}
int is_valid(int check){//This function checks to see if the users number is valid.
	if(check < 1){//If the number is less than one, it prompts the user to try again.
	   printf("You have entered a number less than 1. Please try again. \n");
	   printf("\n");
	   return -1;
	} 
	if(check > 9){//If the number is greater than nine, it prompts the user to try again.
	   printf("You have entered a number greater than 9. Please try again. \n");
	   printf("\n");
	   return -1;
	}
	if(check % 2 == 0){//If the number is not even, it prompts the user to try again.
	   printf("You have entered an even number. Please try again. \n");
	   printf("\n");
	   return -1;
	}
	else{
	   return check;//If the number is not true for any of the above, it is valid, and returned to the get_input function.
	}
}
void print_pattern(int x){//This function prints out a diamond using the number entered by the user.
	int i;
	int j;
	int h;
	int count = 1;
	int spaces;	
	for(i = 1; i <= 1+(x/2); i++){//The outter loop controls which line is being printed on, and prints the top half of the diamond.
	   j = 1;
	   spaces = (x+5) - count;//creates a small buffer, which shifts the figure slightly to the right.
	   printf("%*s",spaces,"");
	   while(j <= count && count <= x){//The inner loop prints the constituent numbers of the number entered by the user.
	      printf("%d ", j);
	      j++;
	   }
	   count += 2;//count is incrimented by 2.
	   printf("\n");
	  }  
	count -=2;//count is decremented by 2.
	for(h = 1; h <= 1+(x/2); h++){//This outter loop prints the bottom half of the diamond.
           spaces = (x+7) - count;//creates the same buffer as before. But increasing spacing instead of decreasing.
	   j = 1;
	   count -= 2;
	   printf("%*s",spaces,"");
	   while(j <= count && count > 0 ){//This inner loop prints the constituent numbers as it did above.
	      printf("%d ", j);
	      j++;
	   }
	   printf("\n");
	}
}
