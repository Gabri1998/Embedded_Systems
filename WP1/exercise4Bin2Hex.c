

// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 4b
// Submission code: 941551 (provided by your TA-s)

// Include section for the header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define section for the constant variables
#define INDEX 32
// set the bits
int SetBit(int OldValue, int BitNum)
{
  int newValue = (OldValue | (1 << BitNum)); // compare the value with the shifted bit to the  left using |
  // Return the value
  return newValue;
}

// reset the bits
int ResetBit(int OldValue, int BitNum)
{
  int newValue = (OldValue & (~(1 << BitNum))); // compare the value with the shifted bit to the  left  using &/~
  // Return the value
  return newValue;
}

// A function to change the String Binary to Hexadecimal
void StrBinToHex(char *str, char *value)
{
  // Declare the variables
  short FourBit = 0;  // number var to store 4 bit to Set and Reset
  long maxBit=0;
  int size= strlen(str) - 1;
  int FourBitCnt = 0; // indicator for 4 bit
  int ArrIdx = 0;     // array index

  // loop form right to left , detect NULL value and stop to zero index
  for (int idxSZ = size; (idxSZ >= 0) && (str[idxSZ] != '\0');
       idxSZ--) {

    // Set and Reset every 4 Bits & collect 4 Bits
    if (str[idxSZ] == '0')
    {
      // Reset bit number in var FourBit
      FourBit = ResetBit(FourBit, FourBitCnt);
      maxBit = ResetBit(maxBit, size-idxSZ);
    } else if (str[idxSZ] == '1') {
      // Set bit number in var FourBit
      FourBit = SetBit(FourBit, FourBitCnt);
      maxBit = SetBit(maxBit, size-idxSZ);
    } else {
      break;
    }

    // increment var
    FourBitCnt++;

    // if caught 4 bits, handle them as hex value
    if (FourBitCnt == 4)
    {
      // Case where the fourbit is between 0 and 9
      if (FourBit >= 0 && FourBit <= 9)
      {                                  // check if the 4bits between 0 and 9
        value[ArrIdx++] = FourBit + '0'; // storing the bits to the array then incerment
      }
      // Case where fourbut is larger than 10
      else if (FourBit >= 10)
      {                                       // check if the 4bits is between the 10 and 15
        value[ArrIdx++] = FourBit - 10 + 'A'; // storing the bits to the array then incerment
      }
      // Change the fourbit to 0
      FourBit = 0;
      // Change the fourbitcnt to 0
      FourBitCnt = 0;
    }
  }

  // If there are remaining bits, handle them
  if (FourBitCnt > 0)
  {
    // Case where fourbit is between 0 and 9
    if (FourBit >= 0 && FourBit <= 9)
    {                                  // check if the 4bits between 0 and 9
      value[ArrIdx++] = FourBit + '0'; // storing the bits to the array then incerment
    }
    // Case where fourbit is larger than 10
    else if (FourBit >= 10)
    {                                       // check if the 4bits is between the 10 and 15
      value[ArrIdx++] = FourBit - 10 + 'A'; // storing the bits to the array then incerment
    }
  }
  // Reverse the hex string in-place
  for (int start = 0, end = ArrIdx - 1; start < end; start++, end--)
  {
    char temp = value[start];  // set the temporary char and store the start value
    value[start] = value[end]; // the swaping happens here
    value[end] = temp;         // set the temp value to the value[end]
  }
  printf("Maxbit:%lx\n",maxBit);
  // Add null terminator at the end of the hex string
  value[ArrIdx] = '\0';
  
}




int main(int argc, char *argv[])
{
    long binary;
    int remainder;
    int dec = 0;
    char *eptr;
    char output[INDEX];
    char input[INDEX];

    // Check if binary provided via arguement parameter or as input parameter.
    // If binary is provided but not a number ask for a number via input until received one.


    if(argc < 1 && strcmp(argv[1], "-h") == 0) {
        printf("This program is used to convert a binary number to a hexdecimal number.\nRun this program with a binary number as arguement or enter one when asked.\nIt is possible to run this program with dec2bin outut using dec2bin number | bin2hex.");
    } else if (argc <2 ) {
        
            
            scanf("%s", input);
        
    } else if (argc==2) {
       

        sscanf(argv[1],"%s", input);
       
    }

  
    StrBinToHex(input,output);  

    // Print as hexadecimal
    printf("%s\n", output);
    //printf("%d", dec);
    return 0;
}