// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 2
// Exercise 4a
// Submission code: 131313 (provided by your TA-s)





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkValue(char val, char start, char end) {
  

  if (!(val >= start && val <= end)) { // chck if the value is not  in the range 
    printf("you entered invalid value, range: <0..1> <0..4> <0..2> <0..1> <0..1>\n");
    exit(0);
  }

  //   return status;
}

typedef struct { // struct to  pack the variables
  unsigned char engine_on : 1;
  unsigned char gear_pos : 3;
  unsigned char key_pos : 2;
  unsigned char brake_F : 1;
  unsigned char brake_B : 1;
} car;

int main(int argc, char *argv[]) {

    
       
    // int checkStat = 0;
        
      if(argc != 6){  // check the number of arguments
     printf("Usage: %s <engine_on> <gear_pos> <key_pos> <brake1> <brake2>\n", argv[0]);
     return 1;
    }else{
         car c ; // a struct of car type
     unsigned char res = 0; // char to store the values of bits
     int cnt = 1; // to count the the arguments 
     char range[6][2] = {{'0', '0'}, {'0', '1'}, {'0', '4'},
                         {'0', '2'}, {'0', '1'}, {'0', '1'}}; // defining the range for each argument respectfly in order
     while (cnt < 6) {
       if (strlen(argv[cnt]) == 1) { // count from one to 5
         checkValue(argv[cnt][0], range[cnt][0], range[cnt][1]); // call the method to check
       } else {
         printf("you entered more than 1 digit in a single arument<>\n");
         exit(0);
       }
       cnt++; // incerment
     }

     c.engine_on = atoi(argv[1]);  //convering the input to digits 
     c.gear_pos = atoi(argv[2]);
     c.key_pos = atoi(argv[3]);
     c.brake_F = atoi(argv[4]);
     c.brake_B = atoi(argv[5]);

    printf("size of c:%d", sizeof(c));
   
     printf("\n%-15s%-10s\n", "Name", "Value");
    printf("-----------------------\n");
    printf("%-15s%d\n", "size c.engine_on:", c.engine_on);
    printf("%-15s%d\n", "size c.gear_pos :", c.gear_pos);
    printf("%-15s%d\n", "size c.key_pos  :", c.key_pos);
    printf("%-15s%d\n", "size c.brake_F  :", c.brake_F);
    printf("%-15s%d\n\n", "size c.brake_B  :", c.brake_B);

     res |= (c.engine_on & 0b00000001) << 7; // packing by chefting to left by 7 and using & 
      //  printf("res:%x\n", res);
    res |= (c.gear_pos & 0b00000111) << 4; // packing by chefting to left by 4 and using & 
    //   printf("res:%x\n", res);
     res |= (c.key_pos & 0b00000011) << 2; // packing by chefting to left by 2 and using & 
     //   printf("res:%x\n", res);
     res |= (c.brake_F & 0b00000001) << 1; // packing by chefting to left by 1 and using & 
     //   printf("res:%x\n", res);
     res |= (c.brake_B & 0b00000001);
     printf("result:%x\n", res);

     printf("size of c:%x\n", c);
    
    
    
    }
    
    
    
    
    
    
    
    return 0;}
  