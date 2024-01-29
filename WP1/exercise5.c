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
    
    
    tab[i]= rand() % MAXNUMBER + 0;
    
}

}
// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers


void count_frequency(int *tab, int *freq ){

  for (int i = 0; i < MAX;i++)
  {
    int number= tab[i];
    
   //printf("tab numbers: %d \n",frequancy);
    freq[number]= freq[number]+1;
   // printf("freq numbers: %d \n",freq[frequancy]);
  }
  


};
// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq ){

    
    for (int i = 0; i < MAXNUMBER; i++) {
        int frequency = freq[i];
        if (frequency > 0) {
            printf("%d ", i);
            int j = 1;
            while (j <= frequency) {
                printf("%c", 'X');
                j++;
            }
            printf("\n");
        }
    }
}




// ------ Function definitions ----------
// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
void main (void){
int table[MAX];
int frequency[MAXNUMBER];
 // random number between 1 and 100
srand((unsigned int)time(NULL));
int *tab= table;
int *freq=frequency;
create_random(tab);
count_frequency(tab,freq );
draw_histogram(freq );



}