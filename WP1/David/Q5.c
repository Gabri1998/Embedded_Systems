// Include section to include the header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The define section for the variables
#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers
// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab)
{
    // Make time random to generate random numbers
    srand(time(NULL));
    // Create MAX number of random integers
    for (int i = 0; i < MAX; i++)
    {
        // Insert random numbers to the tab array
        tab[i] = rand() % MAXNUMBER;
    }
};
// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq)
{
    // Read every numbers generated
    for (int i = 0; i < MAX; i++)
    {
        // Store the number in the num variable
        int num = tab[i];

        // Increase the frequency value of the number
        freq[num]++;
    }
};
// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq)
{
    // Itterate through the array of frequencies
    for (int i = 0; i <= MAXNUMBER; i++)
    {
        // Exclude the numbers that have the frequency of 0
        if (freq[i] != 0)
        {
            printf("%3d ", i);
            // Print X(s) based on the frequency of the number
            for (int j = 0; j < freq[i]; j++)
            {
                printf("X");
            }
            printf("\n");
        }
    }
};
// ------ Function definitions ----------
// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
void main(void)
{
    // Declare the variables
    int table[MAX], n;        // Table with a size of MAX
    int frequency[MAXNUMBER]; // Table with a size of MAXNUMBER

    int *tab = table;      // Assign the pointer tab to the table
    int *freq = frequency; // Assign the pointer freq to the frequency

    // Run the create_random function with the table
    create_random(table);
    // Run the count_frequency function with the table and the frequency
    count_frequency(table, frequency);
    // Run the draw_histogram function with the frequency
    draw_histogram(frequency);
}