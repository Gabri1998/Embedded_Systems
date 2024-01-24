// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <string.h>


// Main function in the program, no program arguments supported
int main (int argc, char *argv[]){
    // Variable declaration
    int option;
    
    //This function will continues to ask the user for an input until the condition is not met and exit
    do
    {
        // Print a message to the user to type a number
        printf("\nEnter a number between 1 to 5: ");
       int validator= scanf("%d", &option); // Scan the input
       //Check if the user provide a number or a string 
      if (validator == 0)
        {
            printf("Wrong input! Type a digit between 1 and 5!\n");
            
            continue;
        }else{
       
        // If and else-if statements, after the input is scanned, it prints one the bellow options
        if (option == 1){ 
            printf("\nMessage %d: Hope you are having a nice day :)\n", option);
        }
        else if (option == 2){
            printf("\nMessage %d: Don't forget to smile today!\n", option);
        }
        else if (option == 3)
        {
            printf("\nMessage %d: Quick reminder: your hard work is making a difference!\n", option);
        }
        else if (option == 4)
        {
            printf("\nMessage %d: Wishing you success and happiness in everything you do!\n", option);
        }
        else if (option == 5)
        {
            printf("\nMessage %d: Just a friendly hello to brighten your day. Hello!\n", option);
        }
        else // Exit the program
        {
           printf("\nUncorrect number, please provide a number between 1 to 5:\n ");
         return 0;
        }
        }
        
        
    } while ((option <= 5) && (option >= 1));
    
    return 0;
}