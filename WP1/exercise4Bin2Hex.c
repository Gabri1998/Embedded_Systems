

// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 4b
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INDEX 32
// set the bits
int SetBit(int OldValue, int BitNum) {
  int newValue = (OldValue | (1 << BitNum));//compare the value with the shifted bit to the  left using |
  return newValue;
}

// reset the bits
int ResetBit(int OldValue, int BitNum) {
  int newValue = (OldValue & (~(1 << BitNum)));//compare the value with the shifted bit to the  left  using &/~
  return newValue;
}


void StrBinToHex(char *str, char *value) {
  short FourBit = 0;  // number var to store 4 bit to Set and Reset
  int FourBitCnt = 0; // indicator for 4 bit
  int ArrIdx = 0;     // array index

  // loop form right to left , detect NULL value and stop to zero index
  for (int idxSZ = strlen(str) - 1; (idxSZ >= 0) && (str[idxSZ] != '\0');
       idxSZ--) {

    // Set and Reset every 4 Bits & collect 4 Bits
    if (str[idxSZ] == '0') {
      // Reset bit number in var FourBit
      FourBit = ResetBit(FourBit, FourBitCnt);
    } else if (str[idxSZ] == '1') {
      // Set bit number in var FourBit
      FourBit = SetBit(FourBit, FourBitCnt);
    } else {
      break;
    }

    // increment var
    FourBitCnt++;

    // if caught 4 bits, handle them as hex value
    if (FourBitCnt == 4) {
      if (FourBit >= 0 && FourBit <= 9) { // check if the 4bits between 0 and 9
        value[ArrIdx++] = FourBit + '0'; // storing the bits to the array then incerment
      } else if (FourBit >= 10) {  // check if the 4bits is between the 10 and 15
        value[ArrIdx++] = FourBit - 10 + 'A';  // storing the bits to the array then incerment
      }

      FourBit = 0;
      FourBitCnt = 0;
    }
  }

  // If there are remaining bits, handle them
  if (FourBitCnt > 0) {
    if (FourBit >= 0 && FourBit <= 9) { // check if the 4bits between 0 and 9
      value[ArrIdx++] = FourBit + '0';  // storing the bits to the array then incerment
    } else if (FourBit >= 10) {  // check if the 4bits is between the 10 and 15
      value[ArrIdx++] = FourBit - 10 + 'A';  // storing the bits to the array then incerment
    }
  }
// Reverse the hex string in-place 
  for (int start = 0, end = ArrIdx - 1; start < end; start++, end--) {
    char temp = value[start]; 
    value[start] = value[end];  // the swaping happens here
    value[end] = temp;
  }
  // Add null terminator at the end of the hex string
  value[ArrIdx] = '\0';
  
}


int main (int argc,char *argv[]){
unsigned int x;
  
  char output[INDEX] = {0}; // store the output


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

// calling the method that convert to hexa
  StrBinToHex(argv[1], output);
  printf("hex:%s\n", output);
}

}

}