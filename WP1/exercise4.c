
// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 1
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


void StrBinToBin(char *str, unsigned int *value) {
    // Initialize num to 0
    int num = 0;
    char *strCpy = str;
    
    while (*strCpy != '\0') {
       
        if (*strCpy == '0' || *strCpy == '1') {
            
            num = (num << 1) | (*strCpy - '0');
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
  //   printf("Num:%d\n", num);
}




int SetBit(int OldValue, int BitNum) {
  int newValue = (OldValue | (1 << BitNum));
  return newValue;
}


int ResetBit(int OldValue, int BitNum) {
  int newValue = (OldValue & (~(1 << BitNum)));
  return newValue;
}


void DecToBin(unsigned int var) {
  
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
      
      
    } else {
     
      printf("0");
    }
  }
  printf("\n");
  }

void BinToHex(unsigned long long var) {

    char hexNumber[17];  
    int sizeValue = 15;
    printf("Hex: 0x");
    for (int i = sizeValue; i >= 0; i--) {
        int hexDigit = (var >> (4 * i)) & 0xF;
        char hexChar;
        if (hexDigit < 10) {
            hexChar = hexDigit + '0';
        } else {
            hexChar = hexDigit - 10 + 'A';
        }

        hexNumber[sizeValue - i] = hexChar;
    }

    // Null-terminate the hex string
    hexNumber[sizeValue + 1] = '\0';

    printf("%s\n", hexNumber);
}

int main (int argc,char *argv[]){
unsigned int x;
   // StrDecToDec(argv[1], &x);
    StrBinToBin(argv[1], &x);
    printf("x value:%d\n\n", x);
    //DecToBin(x);
    BinToHex(x);
}