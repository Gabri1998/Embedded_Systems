
// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INDEX 16

// set the bits
int SetBit(int OldValue, int BitNum) {
  int newValue = (OldValue | (1 << BitNum)); //compare the value with the shifted bit to the  left using |
  return newValue; 
}

// reset the bits
int ResetBit(int OldValue, int BitNum) {
  int newValue = (OldValue & (~(1 << BitNum))); //compare the value with the shifted bit to the  left  using &/~
  return newValue;
}




void StrDecToDec(char *str, unsigned int *value) {
  // 12345 str = >> int 12345 - atoi
  // strlen(str),
  char *strCpy = str; // copying the arument
  int num = 0; // setting  a variable to store the output
  while (strCpy != NULL) { //loop while the string is not null 
    if (*strCpy >= '0' && *strCpy <= '9') { // check the tstring is a digits between 0 and 9
      num = ((num * 10) + (*strCpy - '0')); // 123 converting to int

      
    } else {
     
      break;
    }
    strCpy++; // incerment the string to the next charecheter
  }
  *value = num; // setting the attribute value to num
}














void DecToBin(unsigned int var, char *value) {
 
  int ArrIdx = 0; // array index
  int sizeValue = 31; // intial size of the bits
  int  bb = 0; // store the var after the shifting
  if (var <= 255) // if the number under the limit of 1 byte
    sizeValue = 7; // set the size of bits to one byte
  else if (var <= 65535) // if the number under the limit of 2 byte
    sizeValue = 15;// set the size of bits to two byte
  printf("Bin:");
  // loop through bits and shift ir i time
  for (char i = sizeValue; i >= 0; i--) {
    bb = var >> i;  //shifting i time
    if ((bb & 1) == 1) { //compare that bit with one then print 1 if correct
      
      printf("1");
      
      value[ArrIdx]='1'; // store the ones in an array
      ArrIdx++; // incerment the indexes
    } else { // print zero's 
        printf("0");
     value[ArrIdx]='0'; // store the zeros in an array
     ArrIdx++; // incerment the indexes
      
    }
  }
  printf("\n");
  value[ArrIdx] = '\0'; // Add null terminator at the end of the hex string
  }




int main (int argc,char *argv[]){
unsigned int x;
   
  char output[INDEX] = {0};
 
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
   // calling the methods
   // change the string to int
   StrDecToDec(argv[1], &x);
   //convert the Decimal to Binary
   DecToBin(x,output);
  
  
  
}
   
}
  
  
   
   
   
   
    
    
}