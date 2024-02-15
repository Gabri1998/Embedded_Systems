// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 3
// Exercise 5
// Submission code: XXXXXX (provided by your TA-s)

/*
The program shall then, by use of a pointer, print out each integer value and then print the value multiplied by
two.
*/

// Include section for the header files
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100

void create_random(int *array)
{
  // Create MAX amount of random integers
  for (int i = 0; i < MAX; i++)
  {
    // Store the random integer in the array
    array[i] = rand() % MAX + 0;
  }
}

void print_result(int *array){


     printf("The value of the address of the array (pointer) is:%p\n",array);

    printf("First integer in the array is[arra[%d]] is :%d \n", 0, *(array + 0));
    printf("Last integer in the array is[arra[%d]] is :%d \n", MAX, *(array + (MAX-1)));
    printf("The size of an integer (number of bytes) is:%ld\n",sizeof (*(array + 0)));
    printf("The size of the whole array in bytes is:%ld\n\n",sizeof (*(array + 0))*MAX);
    
   
 
}


void print_array(int *array){

for (int i = 0; i < MAX; i++)
  {
    printf("the value of index[%d]: %d - the value multiplied by two: %d \n",i,*(array + i), (*(array + i)*2));
     
  }

}


 int main(){

unsigned int array[100];

srand((unsigned int)time(NULL));



 create_random( array);

print_result(array);
 
 //printf("The size of the whole array in bytes is: %ld\n\n", sizeof(array));

 print_array(array);


    return 0;
    }