// Include section to add the header files
#include <stdio.h>

// Initialize the function
int main()
{
    // Variable declarations
    int num; // A variable to store the input of the user

    // While true loop to keep the code running
    while (1)
    {
        printf("Enter a number between 1 and 5: ");
        // Take an integer and assign it to the variable num.
        scanf("%d", &num);
        // Only run the code when the number is between 1 to 5.
        if (num > 0 && num < 6)
        {
            // Switch the results based on the numbers.
            switch (num)
            {
            // Case for input of number 1
            case 1:
                printf("Your favorite language is C. \n");
                // Break out of the loop
                break;
            // Case for input number 2
            case 2:
                printf("Your favourite language is C++. \n");
                // Break out of the loop
                break;
            // Case for input number 3
            case 3:
                printf("Your favorite language is JavaScript. \n");
                // Break out of the loop
                break;
            // Case for input number 4
            case 4:
                printf("Your favorite langauge is Java. \n");
                // Break out of the loop
                break;
            // Case for input number 5
            case 5:
                printf("Your favorite language is Python. \n");
                // Break out of the loop
                break;
            }
        }
        // Case where input number is not between 1 to 5
        else
        {
            printf("Invalid input. Number must be between 1 and 5.\n");
            // Break out of the loop
            break;
        }
    }

    // Return 0 to exit the program
    return 0;
}
