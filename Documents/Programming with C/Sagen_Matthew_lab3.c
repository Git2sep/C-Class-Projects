#include <stdio.h>
#include <math.h>
#include <float.h>

double get_n(void);
double get_input(void);
double current = 0;
int main(void){
	double n = get_n();//sets the n to a number given by user.
	double min = DBL_MAX, max = -DBL_MAX;//sets min as the highest possible number, and max as the lowest possible number.
	double sum_squares = 0;
	double sum = 0;
	double average = 0;
	double std_dev = 0;
	int count = 0;
	double range = 0;
	for(count = 0; count < n; count++){//loop that sets min, max, sum, and sum_squares to their new values.
		current = get_input();
		if(current < min){
			min = current;//sets min to the current value
		}
		if(current > max){
			max = current;//sets max to the current value
		}
		sum = sum + current;//sets sum equal to the previous sum + the current value
		sum_squares = sum_squares + (current*current);//sets sum_squares equal to the previous sum_squares + the current value squares
	
	}
	if(n == 0){
		average = 0, std_dev = 0, range = 0, max = 0, min = 0;//sets the average and std_dev equal to 0 if the user enters 0 for n
	}
	else{
		range = max - min;
		average = (sum/n);//sets the average value to be the sum divided by the number of numbers
		std_dev = sqrt((sum_squares/n)-(average*average));//calculates the standard deviation of the values
	}
	printf("The highest is: %.3f \n", max);//prints the results
        printf("The lowest is: %.3f \n", min);
        printf("The average is: %.3f \n", average);
	printf("The range is: %.3f \n", range);
	printf("The Standard Deviation is: %.3f \n", std_dev);
        return (0);
}

double get_n(void){
	int n;
	do{
		printf("Enter a value for N that is >= 0: ");//prompts user for input
		scanf("%d", &n);//determines size of a collection of numbers
		if(n < 0){
			printf("Invalid value for N \n");
		}
		else{
			break;//ends loop since valid value for N was obtained
		}
	}while(n < 0);
	return n;
	
}

double get_input(void){
	printf("Enter a number: ");
	scanf("%lf", &current);
	return current;   
}

