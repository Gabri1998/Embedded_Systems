// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 3
// Exercise 6
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define MAXSTRLEN 20

// standard strcpy built in function
void stdStrCpy(char *src, char *dst) { strcpy(dst, src); }

// custome strcpy
void myStrCpy(char *src, char *dst) {
  int idx = 0;
  while (src[idx] != '\0') {
    dst[idx] = src[idx];
    idx++;
  }
}

int main(int argc, char *argv[]) {
  char inStr[MAXSTRLEN] = {0};  // to store the input value
  char outStdStr[MAXSTRLEN] = {0}; // to store the standard copy
  char outMyStr[MAXSTRLEN] = {0}; // to store the custom copy

// prompt the user to enter a string if the input is a terminal, i.e not redirected
if (isatty(STDIN_FILENO))
{
    printf("Enter a string: ");
}

// read 20 characters from the user to store it in inStr
  fgets(inStr, MAXSTRLEN, stdin);
  printf("inStr:%s", inStr); 
  // if the user input does not end with a new line character, print a new line formatting purposes
  if (inStr[strlen(inStr) - 1] != '\n')
    printf("\n");
  // calling the standerd method
  stdStrCpy(inStr, outStdStr);
  printf("outStdStr:%s", outStdStr);

    // if the user input does not end with a new line character, print a new line formatting purposes
  if (outStdStr[strlen(outStdStr) - 1] != '\n')
    printf("\n");
  // calling the custom method
  myStrCpy(inStr, outMyStr);
  printf("outMyStr:%s", outMyStr);
  
    // if the user input does not end with a new line character, print a new line formatting purposes
  if (outStdStr[strlen(outStdStr) - 1] != '\n')
    printf("\n");

  return 0;
}
