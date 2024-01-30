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

    int number, guess, tries = 0; //variable declaration and set them to zero
    srand(time(0)); // See the random number generator
    number = rand() % 100 + 1; // random number between 1 and 100
    int option; // variable declaration

    printf("\nWelcome to:\nGuess the Number!!\n\n");

    // The program will run until the user can guess the correct number or runs out of chances
    do {
        printf("Enter a guess between 1 and 100: ");
        //Assign the input value to the variable guess
        int validator = scanf("%d", &guess);

        if (validator == 0) // if the user input an invalid value
        {
            printf("Wrong input! Type a digit between 1 and 100!\n");
            tries = 0; // tries are set zero
            break; // game ends
        }
            
        // If the user cannot guess the correct in 10 tries, prints a message and the correct number
        if (tries == MAX){
            printf("\nYou reached the maximum guesses and the correct number was %d\n", number);

            printf("\nThe game has ended. For another round, press 1 or to exit the game, press 0!\n");
            
            scanf("%d", &option); //scan the input value when the user wants to exit or continue the game
            if (option == 0) // if option is zero, it ends the game
            {
                tries = MAX; // tries has reached the maximum number
                break; // it breaks this block
        
            }
            else if(option == 1) // if option is number one, resets the tries to zero and restart the game
            {
                tries = 0; // tries is reset to zero
                srand(time(0)); // See the random number generator
                number = rand() % 100 + 1; // random number between 1 and 100
                continue; // re-start the game 
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

        else if (guess == number) // the guessed number is equal to random number
        {
            printf("\nCorrect! You got it in %d guesses!\n", tries);

            printf("\nThe game has ended. For another round, press 1 or to exit the game, press 0!\n");
            
            scanf("%d", &option);

            //set of options if user wants to end the game or restart when they exceed the max number of tries
            if (option == 0)
            {
                tries = MAX; // tries is equal to maximum of 10
                break; // it breaks this block
        
            }
            else if(option == 1) // if the user wants to continue the game
            {
                tries = 0; // tries is reset to zero
                srand(time(0)); // See the random number generator
                number = rand() % 100 + 1; // random number between 1 and 100
                continue; // re-start the game again
            }
            
        }
        
    }
    while (tries <= MAX); // It will run while the input value is not equal to the correct number

    return 0;
}