// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 5
// Submission code: XXXXXX (provided by your TA-s)


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100 // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers

void create_random(int *tab ){
    for ( int i = 0; i < MAX;i++)
{    
    
    
    tab[i]= rand() % MAXNUMBER + 0; // generate the numbers and put them in the array
    
}


}
// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers


void count_frequency(int *tab, int *freq ){

  for (int i = 0; i < MAX;i++)  // loop and count the frequancy then incerment it
  {
    int number= tab[i]; //storing the number in that index to a var
    
   
    freq[number]= freq[number]+1; // icermenting that number's frequancy
    
  }
  


};
// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq ){

 // loops through the frequancy and print the i and how much that specific i has frequnted
    for (int i = 0; i < MAXNUMBER; i++) {
        int frequency = freq[i];
        if (frequency > 0) { // check if the frequancy is not 0 otherwise it well skip
            printf("%d ", i);
            int j = 1;
            while (j <= frequency) { // loop until the last frequncy is printed
                printf("%c", 'X');
                j++;
            }
            printf("\n");
        }
    }
}





void main (void){
int table[MAX]={0};
int frequency[MAXNUMBER]={0};
 // random number between 1 and 100
srand((unsigned int)time(NULL)); // timer to change the numbers
int *tab= table; // pointer to the table
int *freq=frequency; // pointer to the frequency
create_random(tab); // calling the creat random method
count_frequency(tab,freq ); // calling the frequancy count method
draw_histogram(freq ); // calling the dawing method



}