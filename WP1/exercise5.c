// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 5
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers

// A function to create random integers
void create_random(int *tab)
{
  // Create MAX amount of random integers
  for (int i = 0; i < MAX; i++)
  {
    // Store the random integer in the tab
    tab[i] = rand() % MAXNUMBER + 0;
  }
}
// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers

// Count the number of each numbers
void count_frequency(int *tab, int *freq)
{

  // Itterate through the whole array
  for (int i = 0; i < MAX; i++)
  {
    // Save each random number in teh number variable
    int number = tab[i];

    // Increase the frequency value
    freq[number] = freq[number] + 1;
  }
};
// This function takes the frequency count table
// and draws a histogram of the values in that frequency table

// A function to draw the histogram
void draw_histogram(int *freq)
{
  // Itterate through teh frequency array
  for (int i = 0; i < MAXNUMBER; i++)
  {
    // Store the frequency of a specific number in the variable frequency
    int frequency = freq[i];
    // Check if the frequency is bigger than 0
    if (frequency > 0)
    {
      printf("%d ", i);
      // Declare a vailable j to count the number of X(s) to be drawn
      int j = 1;
      // Draw X(s) based on the number of frequencies
      while (j <= frequency)
      {
        printf("%c", 'X');
        // Increase j value to limit the number of X(s) printed
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

// The main function
void main(void)
{
  // Declare the tables
  int table[MAX] = {0};           // Create an array with the length of MAX
  int frequency[MAXNUMBER] = {0}; // Create an array with the length of MAXNUMBER
  // random number between 1 and 100

  // Set the time to random so that we get different results every time
  srand((unsigned int)time(NULL));
  // Assign the tab pointer to the table
  int *tab = table;
  // Assign the freq pointer to the frequency
  int *freq = frequency;
  // Initiate the create_random function with the tab as an input
  create_random(tab);
  // Initiate the count_frequency function with the tab and freq as an input
  count_frequency(tab, freq);
  // Initiate the draw_histogram function with the freq as an input
  draw_histogram(freq);
}