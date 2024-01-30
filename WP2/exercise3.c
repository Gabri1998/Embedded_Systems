// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 2
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s)

#include <stdlib.h>
#include <stdio.h>
// -----typedefs -------
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;
// Function declaration (to be extend)
PERSON input_record(void);             // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and
// writes the first record
void printfile(void);                 // Prints out all persons in the file
void search_by_firstname(char *name); // Prints out the person if
// in list
void append_file(PERSON *inrecord); // appends a new person to the file
int main(void)
{
    PERSON ppost;
    return (0);
}