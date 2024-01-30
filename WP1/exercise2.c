<<<<<<< HEAD
// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

// Include section for the header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to change the decimal in string format to a decimal format
void StrDecToDec(char *str, unsigned int *value)
{
  // Variable declaration section
  char *strCpy = str; // Create a pointer to the str string
  int num = 0;        // Create a variable that accepts the user input to encrypt the string

  // A while loop that runs until the strCpy is a null
  while (strCpy != NULL)
  {
    // An if statement to see if the pointer to the str is between 0 and 9
    if (*strCpy >= '0' && *strCpy <= '9')
    {
      // If true, change the string version of decimal into a string
      num = ((num * 10) + (*strCpy - '0')); // 123
    }
    // Case when this is not true
    else
    {
      // Break out of the loop
      break;
    }
    // Increase by one
    strCpy++;
  }
  // Set a pointer value to the num variable
  *value = num;
}

// Main function in the program
int main(int argc, char *argv[])
{
  // Converts the input from string to integer
  int key = atoi(argv[1]);

  // Section to define the variables
  char message[100];          // Set a string that can accept 100 characters
  char encriptedMessage[101]; // Set a string for the encrypted message (1 character longer than the input string)
  int i;                      // Declare a variable i to itterate through the input message string

  // A loop to keep running the program
  do
  {
    // Prompt the user to type a message
    printf("\nEnter a message:\n");
    // Read the given input
    scanf("%s", message);

    // Loop through each character
    for (i = 0; message[i] != '\0'; ++i)
    {
      // Save each letters of the message in the givenMessage char
      char givenMessage = message[i];

      // If the input is lower case char
      if (givenMessage >= 'a' && givenMessage <= 'z')
      {
        // Encrypt the char and add to the encryptedMessage string
        encriptedMessage[i] = (givenMessage + key - 'a') % 26 + 'a';
      }

      // If the input is upper case char
      else if (givenMessage >= 'A' && givenMessage <= 'Z')
      {
        // Encrypt the char and add to the encryptedMessage string
        encriptedMessage[i] = (givenMessage + key - 'A') % 26 + 'A';
      }
      // Case for chars that are not alphabets
      else
      {
        // Just save the givenMessage in the encryptedMessage string
        encriptedMessage[i] = givenMessage;
      }
    }

    // Lastly add the \0 at the end of the string to indicate the finish of the program
    encriptedMessage[i] = '\0';

    // Print the encripted message
    printf("\nEncrypted message is: %s\n", encriptedMessage);

  } while (getchar() != EOF); // End the program

  // Return 0 to end the program successfully
  return 0;
=======
// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

// Include section for the header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to change the decimal in string format to a decimal format
void StrDecToDec(char *str, unsigned int *value)
{
  // Variable declaration section
  char *strCpy = str; // Create a pointer to the str string
  int num = 0;        // Create a variable that accepts the user input to encrypt the string

  // A while loop that runs until the strCpy is a null
  while (strCpy != NULL)
  {
    // An if statement to see if the pointer to the str is between 0 and 9
    if (*strCpy >= '0' && *strCpy <= '9')
    {
      // If true, change the string version of decimal into a string
      num = ((num * 10) + (*strCpy - '0')); // 123
    }
    // Case when this is not true
    else
    {
      // Break out of the loop
      break;
    }
    // Increase by one
    strCpy++;
  }
  // Set a pointer value to the num variable
  *value = num;
}

// Main function in the program
int main(int argc, char *argv[])
{

     if (argc<=1){
printf("No argument provided for more information use \'-h\'\n");
return 2;
//check if the user pass more than one argument
}else if(argc!=2){
printf("Only one Argument expected for more information use \'-h\' \n");

return 2;
}else{
// Using external library to check if the user pass -h for help

if(strcmp(argv[1],"-h")==0){
printf("you should pass the name of the file then the first argment should be a digit\n");

}
else{
  // Converts the input from string to integer
  int key = atoi(argv[1]);

  // Section to define the variables
  char message[100];                          // Set a string that can accept 100 characters
  char encriptedMessage[strlen(message) + 1]; // Set a string for the encrypted message (1 character longer than the input string)
  int i;                                      // Declare a variable i to itterate through the input message string

  // A loop to keep running the program
  do
  {
    // Prompt the user to type a message
    printf("\nEnter a message:\n");
    // Read the given input
    scanf("%s", message);

    // Loop through each character
    for (i = 0; message[i] != '\0'; ++i)
    {
      // Save each letters of the message in the givenMessage char
      char givenMessage = message[i];

      // If the input is lower case char
      if (givenMessage >= 'a' && givenMessage <= 'z')
      {
        // Encrypt the char and add to the encryptedMessage string
        encriptedMessage[i] = (givenMessage + key - 'a') % 26 + 'a';
      }

      // If the input is upper case char
      else if (givenMessage >= 'A' && givenMessage <= 'Z')
      {
        // Encrypt the char and add to the encryptedMessage string
        encriptedMessage[i] = (givenMessage + key - 'A') % 26 + 'A';
      }
      // Case for chars that are not alphabets
      else
      {
        // Just save the givenMessage in the encryptedMessage string
        encriptedMessage[i] = givenMessage;
      }
    }

    // Lastly add the \0 at the end of the string to indicate the finish of the program
    encriptedMessage[i] = '\0';

    // Print the encripted message
    printf("\nEncrypted message is: %s\n", encriptedMessage);

  } while (getchar() != EOF); // End the program
}
  // Return 0 to end the program successfully
  return 0;}
>>>>>>> b36f2c838f06ee7dd08ffd9dc5f28f7324772dcf
}