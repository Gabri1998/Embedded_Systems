// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

// Include section for the header file
#include <stdio.h>
#include <string.h>

// Main function in the program, no program arguments supported
int main(int argc, char *argv[])
{
    // Variable declaration
    int option; // Store the option selected by the user

    // This function will continues to ask the user for an input until the condition is not met and exit
    do
    {
        // Print a message to the user to type a number
        printf("\nEnter a number between 1 to 5: ");
        // Save the input of the user in the validator variable
        int validator = scanf("%d", &option); // Scan the input

        // Check if the user provide a number or a string
        if (validator == 0)
        {
            printf("Wrong input! Type a digit between 1 and 5!\n");
            // Continue running the program
            continue;
        }
        // If the user gives correct input
        else
        {

            // If and else-if statements, after the input is scanned, it prints one the bellow options
            // If the user input is 1
            if (option == 1)
            {
                printf("\nMessage %d: Hope you are having a nice day :)\n", option);
            }
            // If the user input is 2
            else if (option == 2)
            {
                printf("\nMessage %d: Don't forget to smile today!\n", option);
            }
            // If the user input is 3
            else if (option == 3)
            {
                printf("\nMessage %d: Quick reminder: your hard work is making a difference!\n", option);
            }
            // If the user input is 4
            else if (option == 4)
            {
                printf("\nMessage %d: Wishing you success and happiness in everything you do!\n", option);
            }
            // If the user input is 5
            else if (option == 5)
            {
                printf("\nMessage %d: Just a friendly hello to brighten your day. Hello!\n", option);
            }
            // If an incorrect number is provided
            else
            {
                printf("\nUncorrect number, please provide a number between 1 to 5:\n ");
                // Return 0 to exit the program successfully
                return 0;
            }
        }

    } while ((option <= 5) && (option >= 1)); // A while loop to keep the program running while the option is between 1 to 5

    // Return 0 to exit the program successfully
    return 0;
}