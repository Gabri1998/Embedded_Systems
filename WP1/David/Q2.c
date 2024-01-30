// Include section to include the header files
#include <stdio.h>
#include <string.h>
// Dfine section
#define MAX_LIMIT 1024 // The maximum input value for the string is 1024

// Beginning of the program
int main(int argc, char *argv[])
{
    // Section to declare the variables
    char strInput[MAX_LIMIT];  // The input string is declared
    char strOutput[MAX_LIMIT]; // The output string is declared
    int i;                     // Used for itterating through the input string

    // Copy the second argument into the strInput string to encrypt the message.
    strncpy(strInput, argv[1], MAX_LIMIT - 1);

    // A for-loop to itterate through the string and change the ascii value by 13.
    for (i = 0; i < strlen(strInput); i++)
    {
        // If the letter (both capital and lower) is between a to m, add 13
        if (strInput[i] >= 97 && strInput[i] <= 109 || strInput[i] >= 65 && strInput[i] <= 77)
        {
            // Add 13 and write it to the strOutput string
            strOutput[i] = strInput[i] + 13;
        }
        // If the letter (both capital and lower) is between n to z, subtract 13
        else
        {
            // Subtract 13 and write it to the strOutput string
            strOutput[i] = strInput[i] - 13;
        }
    }
    printf("%s \n", strOutput);

    // Return 0 to exit the program.
    return 0;
}