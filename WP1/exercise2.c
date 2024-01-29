// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


 void StrDecToDec(char *str, void *value) {
  // 12345 str = >> 123 - atoi
  // strlen(str),
  char *strCpy = str;
  int num = 0;
  while (strCpy != NULL) {
    if (*strCpy >= '0' && *strCpy <= '9') {
      num = ((num * 10) + (*strCpy - '0')); // 123
    } else {
      break;
    }
    strCpy++;
  }
  *value = (unsigned int)num;
}


// Main function in the program
int main (int argc, char *argv[]) {

   int key = atoi(argv[1]); //Converts the input from string to integer
  
  /*unsigned int num;
   int *value;
StrDecToDec(argv[1],value);*/ 
   
    char message[100]; 
    char encriptedMessage[strlen(message) + 1];
    int i;

    do{
        // Prompt the user to type a message
        printf("\nEnter a message:\n");
        scanf("%s", message); // Read the given input

        // Loop through each character
        for (i = 0; message[i] != '\0'; ++i){

            char givenMessage = message[i];

            // If the input is lower case char
            if (givenMessage >= 'a' && givenMessage <= 'z'){
                encriptedMessage[i] = (givenMessage + key - 'a') % 26 + 'a';
            }

            // If the input is upper case char
            else if (givenMessage >= 'A' && givenMessage <= 'Z'){
                encriptedMessage[i] = (givenMessage + key - 'A') % 26 + 'A';
            }
            else
            {
                encriptedMessage[i] = givenMessage;
            }
            
        }

        encriptedMessage[i] = '\0';

        // Print the encripted message
        printf("\nEncrypted message is: %s\n", encriptedMessage);

    } while (1); // End the program
    
    return 0;
}