
// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INDEX 16
int SetBit(int OldValue, int BitNum) {
  int newValue = (OldValue | (1 << BitNum));
  return newValue;
}


int ResetBit(int OldValue, int BitNum) {
  int newValue = (OldValue & (~(1 << BitNum)));
  return newValue;
}




void StrDecToDec(char *str, unsigned int *value) {
  // 12345 str = >> int 12345 - atoi
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
  *value = num;
}






void StrBinToDec(char *str, unsigned int *value) {
  // 00110111 str = >> 55 dec
  // strlen(str),
  char *strCpy = str;
  unsigned int num = 0;
  int idx = strlen(str) - 1;
  //   printf("idx:%d\n", idx);
  while (strCpy[idx] != '\0') {
    // printf("str[%d]:%c , num:%d\n", idx, strCpy[idx], num);
    if (strCpy[idx] == '0') {
      num = ResetBit(num, 7 - idx);
    } else if (strCpy[idx] == '1') {
      num = SetBit(num, 7 - idx);
    } else {
      break;
    }
    idx--;
    if (idx == -1)
      break;
  }
  *value = num;
  
}







void DecToBin(unsigned int var, char *value) {
 
  int ArrIdx = 0;
  int sizeValue = 31;
  int  bb = 0;
  if (var <= 255)
    sizeValue = 7;
  else if (var <= 65535)
    sizeValue = 15;
  printf("Bin:");
  for (char i = sizeValue; i >= 0; i--) {
    bb = var >> i;
    if ((bb & 1) == 1) {
      printf("1");
      
      value[ArrIdx]='1';
      ArrIdx++;
    } else {
        printf("0");
     value[ArrIdx]='0';
     ArrIdx++;
      
    }
  }
  printf("\n");
  value[ArrIdx] = '\0';
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
      if (FourBit >= 0 && FourBit <= 9) {
        value[ArrIdx++] = FourBit + '0';
      } else if (FourBit >= 10) {
        value[ArrIdx++] = FourBit - 10 + 'A';
      }

      FourBit = 0;
      FourBitCnt = 0;
    }
  }

  // If there are remaining bits, handle them
  if (FourBitCnt > 0) {
    if (FourBit >= 0 && FourBit <= 9) {
      value[ArrIdx++] = FourBit + '0';
    } else if (FourBit >= 10) {
      value[ArrIdx++] = FourBit - 10 + 'A';
    }
  }
// Reverse the hex string in-place before adding the null terminator
  for (int start = 0, end = ArrIdx - 1; start < end; start++, end--) {
    char temp = value[start];
    value[start] = value[end];
    value[end] = temp;
  }
  // Add null terminator at the end of the hex string
  value[ArrIdx] = '\0';
  
}



int main (int argc,char *argv[]){
unsigned int x;
  char val[INDEX] = {0};
  char output[INDEX] = {0};
 if (argc != 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }
    // check if the user wants to see the help message
    if(strcmp(argv[1], "-h") == 0){
        printf("Usage: %s <number>\n", argv[0]);
        return 0;
    }

   StrDecToDec(argv[1], &x);
   DecToBin(x,val);
  
  StrBinToHex(val, output);
  printf("hex:%s\n", output);
  
  
   
  
  
  
   
   
   
   
    
    
}