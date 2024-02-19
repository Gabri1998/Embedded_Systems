// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 3
// Exercise 5
// Submission code: 021513 (provided by your TA-s)

/*
The program shall then, by use of a pointer, print out each integer value and then print the value multiplied by
two.
*/

// Include section for the header files
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100 // set max to 100
// method to create random nimbers
void create_random(int *array)
{
  // Create MAX amount of random integers
  for (int i = 0; i < MAX; i++)
  {
    // Store the random integer in the array
    array[i] = rand() % MAX + 0;
  }
}

//print the results for the exercise

void print_result(int *array){

  // print the address of the array
     printf("The value of the address of the array (pointer) is:%p\n",array);
// print the first elemnt in the array
    printf("First integer in the array is[arra[%d]] is :%d \n", 0, *(array + 0));
    //print the last elemnt in the array
    printf("Last integer in the array is[arra[%d]] is :%d \n", MAX, *(array + (MAX-1)));
    // print the size of an integer in the array
    printf("The size of an integer (number of bytes) is:%ld\n",sizeof (*(array + 0)));
    // print the size of the array
    printf("The size of the whole array in bytes is:%ld\n\n",sizeof (*(array + 0))*MAX);
    
   
 
}

// print the array
void print_array(int *array){

for (int i = 0; i < MAX; i++)
  {  // formatting the values then show the value multiblied with two
    printf("the value of index[%d]: %d - the value multiplied by two: %d \n",i,*(array + i), (*(array + i)*2));
     
  }

}


 int main(){

unsigned int array[100];  // set an array of integers with size max

srand((unsigned int)time(NULL)); // enable the random to generate diffrenet numbers each run



 create_random( array); // calling the method

print_result(array); // calling the method
  // another way to print the size of the array
  // in case you do not agree with the first one above
 //printf("The size of the whole array in bytes is: %ld\n\n", sizeof(array));

 print_array(array);// calling the method


    return 0;
    }