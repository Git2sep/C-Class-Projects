#include<stdio.h>
#include<stdlib.h>
#define NAME_SIZE 25
/*
 *Author@ Matthew Sagen
 *4/19/2017
*/
typedef struct{//This creates my student structure to store data.
   int sid;
   char lastName[NAME_SIZE];
   char firstName[NAME_SIZE];
   float *grades;
   float gpa;
}student;

student get_input(int G);
void print_students(student students, int N, int G);
void memRel(student students, int N);
float gpaCalc(student newStudent, int G);

int main(void){//this is the main function
   
   int N,G;  
   student *students;
   scanf("%d",&N);//Total number of students
   scanf("%d",&G);//Number of grades (each)
   printf("Number of students: %d\n", N);
   printf("Number of grades (each): %d\n", G);
   students =(student*)calloc(N, sizeof(student));//allocates memory for an array of students
   for(int i = 0; i < N; i++){//loops for each student, and gets data for each student
     student newStudent = get_input(G);
     students[i] = newStudent; 
   }
   for(int i = 0; i < N; i++){//loops for each student, and prints out their student record 
      print_students(students[i], N, G);
      memRel(students[i], N);
   }
return 0;
}

student get_input(int G){//function to input student information
   student newStudent;
   scanf("%d", &newStudent.sid);//sid
   scanf("%s", newStudent.lastName);//last name
   scanf("%s", newStudent.firstName);//first name            
   newStudent.grades = (float*)calloc(G, sizeof(student));//allocates memory for the array of grades 
   for(int i = 0; i < G; i++){//scans each grade
      scanf("%f", &newStudent.grades[i]);
   }
   newStudent.gpa = gpaCalc(newStudent, G);
   return newStudent;
}

void print_students(student students, int N, int G){//this function prints the data of a student
      printf("ID: %d, Name: %s %s, GPA: %.2f\n",students.sid, students.firstName, students.lastName, students.gpa);
      printf("Grades: ");
      for(int j = 0; j < G; j++){//loops through each grade to print the data
         printf("%.1f ", students.grades[j]);
      }
      printf("\n");
}

float gpaCalc(student newStudent, int G){//this function calculates the grade point average of all grades
   float total = 0;
   for(int i = 0; i < G; i++){//loops for each grade and adds it to the total
      total += newStudent.grades[i];
   }
   total = total/G;//get the average by deviding total by number of grades
   return total;
}

void memRel(student students, int N){//this function releases memory assoicated with the student structures grades.
   for(int i = 0; i < N; i++){
     free(students.grades);
     students.grades = NULL;
   }
}
