#include<stdio.h>
#include<math.h>
#define PI 3.14159
#define LOOP_LIMIT 90
/*
 *Author: Matthew Sagen
 *2/20/2017
*/
enum MENU{Sine, Cosine, Tangent, QUIT};//menu enum that is used for user input.
typedef enum MENU menu_t;

menu_t get_input(void);
int is_valid(int check);
void sin_Op(void);
void cosOp(void);
void tanOp(void);

int main(void){//main function that controls main loop.
   menu_t choice;
   while(choice != QUIT){//loops until the user selects QUIT.
     choice = get_input();
  }

  return 0;
}

menu_t get_input(void){//this function prompts the user for input.
   menu_t option;
   do{//this loops so long as the user does not select QUIT. 
      printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT \n");
      printf("Enter your choice > ");
      scanf("%u", &option);
      if(is_valid(option) == 0){//checks to see if the user input is valid.
         switch(option){//calls the function as indecated by the user.
            case 0: 
		sin_Op();
		break;
            case 1: 
		cosOp(); 
		break;
            case 2: 
		tanOp(); 
		break;
            case 3: 
		option = QUIT; 
		break;
         }
      }
      if(option == QUIT){//Lets the user know that the program is terminated.
         printf("You chose QUIT. Thank you, come again! \n");
      }	
   }while(option != QUIT);
return option;//returns the users selection if it is valid, to the main loop.
}

int is_valid(int check){//This function checks to see if the user's input is valid
   if(check < 0 || check > 3){//we know it is invalid input if the number is less than 0 or greater than three.
      printf("%d is an invalid option. Please try again. \n", check);
      return -1;//returns -1 so that the get_input function does not go into its first if statement.
   }
   else{//returns 0 if the input is valid.
      return 0;
   }
}

void sin_Op(void){//this function calculates sin values.
   int a;
   double x;
   double value;
   for(a = 0; a <= LOOP_LIMIT; a += 15){//this loops from zero to LOOP_LIMIT with a step value of 15 degrees, and calculates the sin of each c+15 degrees.
        value = PI / 180;
	x = sin(a*value);
	printf("\t sin(%d) = %.4lf \n", a, x);
   }
}
void cosOp(void){//this function calculates cos values.
   int b;
   double x;
   double value;
   for(b = 0; b <= LOOP_LIMIT; b += 15){//this loops from zero to LOOP_LIMIT with a step value of 15 degrees, and calculates the cos of each c+15 degrees.
        value = PI / 180;
        x = cos(b*value);
        printf("\t cos(%d) = %.4lf \n", b, x);
   }
}
void tanOp(void){//this function calculates tan values.
   int c;
   double x;
   double value;
   for(c = 0; c <= LOOP_LIMIT; c += 15){//this loops from zero to LOOP_LIMIT with a step value of 15 degrees, and calculates the tan of each c+15 degrees.
        if(c == LOOP_LIMIT){//if c == LOOP_LIMIT, which is 90, it returns that the value is UNDEFINED at that degree.
            printf("\t tan(%d) is UNDEFINED \n", c);
        }
	else{//otherwise it calculates the tan of each degree.
	value = PI / 180;
        x = tan(c*value);
        printf("\t tan(%d) = %.4lf \n", c, x);
        }
    }
}
