// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 2
// Exercise 4b
// Submission code: 131313 (provided by your TA-s)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Check the value in hex using Ascii table
void checkDecode(char *value) {
 if (value[0] >= 'A' && value[0] <= 'Z'){ // Check the first digit og the input
value[0]+=32;  // change it to  small 
 }
 if (value[1] >= 'A' && value[1] <= 'Z'){//Check the seconed digit of the input
value[1]+=32;   // change it to  small
 }
  if (value[0] > 'c' || value[1] > 'b')  { //check if the value is between C and B in hexa
    printf("you entered invalid value max cb\n");
    exit(0); // exit with code 0
  }

  //   return status;
}

typedef struct {  // a struct to store the and pack the variables
  unsigned char engine_on : 1;
  unsigned char gear_pos : 3;
  unsigned char key_pos : 2;
  unsigned char brake_F : 1;
  unsigned char brake_B : 1;
} car;

int main(int argc, char *argv[]) {
    


    if(argc == 2){ // check the number of arguments

      if (strlen(argv[1]) != 2) { // check the number of digit provided in the argument
   
   printf("Invalid input, max 2 digit allowed in hexa\n");
   
      } else {  // calling the method to check the input
        checkDecode(argv[1]);

        unsigned char tmp = 0; // char to store the values of bits
      car c ; // a struct of car type
      if (argv[1][0] >= '0' && argv[1][0] <= '9') { //check if the first digit of value between 0 and 9
       tmp = argv[1][0] - '0';
      } else if (argv[1][0] >= 'a' && argv[1][0] <= 'f') { //check if the first digit of value between a and f
       tmp = (argv[1][0] - 'a') + 10;
      } else if (argv[1][0] >= 'A' && argv[1][0] <= 'F') { //check if the first digit of value between A and F
      tmp = (argv[1][0] - 'A') + 10;
       }
       //  tmp =>  0b0000 1111
       tmp <<= 4; // shift to the left 
      //  tmp =>  0b1111 0000
      if (argv[1][1] >= '0' && argv[1][1] <= '9') { //check if the seconed digit of value between 0 and 9
       tmp |= argv[1][1] - '0';
       } else if (argv[1][1] >= 'a' && argv[1][1] <= 'f') { //check if the seconed digit of value between a and f
      tmp |= (argv[1][1] - 'a') + 10;
      } else if (argv[1][1] >= 'A' && argv[1][1] <= 'F') { //check if the seconed digit of value between A and F
      tmp |= (argv[1][1] - 'A') + 10;
       }

     c.engine_on = tmp >> 7; // unpacking by chefting to right by 7
     c.gear_pos = tmp >> 4; // unpacking by chefting to right by 4
     c.key_pos = tmp >> 2;  // unpacking by chefting to right by 2
     c.brake_F = tmp >> 1;  // unpacking by chefting to right by 1
     c.brake_B = tmp; // last bit
     printf("\n%-15s%-10s\n", "Name", "Value");
    printf("-----------------------\n");
    printf("%-15s%d\n", "engine_on", c.engine_on);
    printf("%-15s%d\n", "gear_pos", c.gear_pos);
    printf("%-15s%d\n", "key_pos", c.key_pos);
    printf("%-15s%d\n", "brake_F", c.brake_F);
    printf("%-15s%d\n\n", "brake_B", c.brake_B);

     }
     
      
    }else{
     printf("Only one argument expected  code.exe <hexa>\n");
      exit(1);
 
    }
    
    
    
    return 0;}