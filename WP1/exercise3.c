// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum of tries
#define MAX 10

// Main function in the program
int main (){

    int number, guess, tries = 0;
    srand(time(0)); // See the random number generator
    number = rand() % 100 + 1; // random number between 1 and 100
    int option;

    printf("\nWelcome to:\nGuess the Number!!\n\n");

    // The program will run until the user can guess the correct number or runs out of chances
    do {
        printf("Enter a guess between 1 and 100: ");
        //Assign the input value to the variable guess
        int validator = scanf("%d", &guess);

        if (validator == 0)
        {
            printf("Wrong input! Type a digit between 1 and 100!\n");
            tries = 0;
            break;
        }
            
        // If the user cannot guess the correct in 10 tries, prints a message and the correct number
        if (tries == MAX){
            printf("\nYou reached the maximum guesses and the correct number was %d\n", number);

            printf("\nThe game has ended. For another round, press 1 or to exit the game, press 0!\n");
            
            scanf("%d", &option);
            if (option == 0)
            {
                tries = MAX;
                break; // it breaks this block
        
            }
            else if(option == 1)
            {
                tries = 0;
                srand(time(0)); // See the random number generator
                number = rand() % 100 + 1; // random number between 1 and 100
                continue;
            }
        }
        
        //It counts and adds +1 try, through each iteration of the game
        tries++;

        // If the input value is bigger than 100
        if (guess > 100 || guess < 1){
            printf("\nEnter a guess between 1 and 100!\n\n");
        }

        // If the guess is higher than the correct number, the program will print a message
        else if (guess > number){
            printf("Too high!\n\n");
        }

        // If the guess is smaller than the correct number, the program will print a message
        else if (guess < number){
            printf("Too low!\n\n");
        }

        else if (guess == number)
        {
            printf("\nCorrect! You got it in %d guesses!\n", tries);

            printf("\nThe game has ended. For another round, press 1 or to exit the game, press 0!\n");
            
            scanf("%d", &option);
            if (option == 0)
            {
                tries = MAX;
                break; // it breaks this block
        
            }
            else if(option == 1)
            {
                tries = 0;
                srand(time(0)); // See the random number generator
                number = rand() % 100 + 1; // random number between 1 and 100
                continue;
            }
            
        }
        
    }
    while (tries <= MAX); // It will run while the input value is not equal to the correct number

    return 0;
}