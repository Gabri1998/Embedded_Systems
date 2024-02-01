// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 2
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

// -----typedefs -------
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;
// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.

// Creates a file and writes the first record
void write_new_file(PERSON *inrecord)
{

    FILE *fileptr;
    PERSON *records = malloc(MAX * sizeof(PERSON));

    memcpy(records, inrecord, sizeof(PERSON));

    if ((fileptr = fopen("David.bin", "wb")) == NULL)
    {
        printf("\n Cannot create the file");
        exit(1);
    }

    fwrite(records, sizeof(PERSON), 1, fileptr);
    fclose(fileptr);
    free(records);
};

void printfile(void)
{
    FILE *fileptr;
    PERSON *records = malloc(MAX * sizeof(PERSON));

    if ((fileptr = fopen("David.bin", "r")) == NULL)
    {
        printf("\n Cannot open the file");
        exit(1);
    }

    fread(records, sizeof(PERSON), MAX, fileptr);

    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(records[i].firstname, "") > 0)
        {
            printf("\nFirst Name: %s\n", records[i].firstname);
            printf("Family Name: %s\n", records[i].famname);
            printf("Personal Number: %s \n", records[i].pers_number);
        }
    }
    fclose(fileptr);
    free(records);

}; // Prints out all persons in the file

// Prints out the person if in list
void search_by_firstname(char *name)
{
    FILE *fileptr;
    PERSON *records = malloc(MAX * sizeof(PERSON));
    char option;

    if ((fileptr = fopen("David.bin", "r")) == NULL)
    {
        printf("\n Cannot open the file");
        exit(1);
    }

    while (option != 'F' || option != 'N')
    {
        printf("Choose the search method for the search. Type F for family name and N for firstname: ");
        scanf(" %c", &option);

        if (option == 'F' || option == 'N')
        {
            break;
        }
    }

    fread(records, sizeof(PERSON), MAX, fileptr);

    for (int i = 0; i < MAX; i++)
    {
        switch (option)
        {
        case ('F'):
            if (strcmp(records[i].famname, name) == 0)
            {
                printf("First Name: %s\n", records[i].firstname);
                printf("Family Name: %s\n", records[i].famname);
                printf("Personal Number: %s\n", records[i].pers_number);
                printf("\n");
            };
        case ('N'):
            if (strcmp(records[i].firstname, name) == 0)
            {
                printf("\nFirst Name: %s\n", records[i].firstname);
                printf("Family Name: %s\n", records[i].famname);
                printf("Personal Number: %s\n", records[i].pers_number);
                printf("\n");
            }
        }
    }
    fclose(fileptr);
    free(records);
};
// appends a new person to the file
void append_file(PERSON *inrecord)
{
    char *binaryFileName = "David.bin";
    FILE *pBinaryFile = fopen(binaryFileName, "ab");

    if (pBinaryFile != NULL)
    {
        fseek(pBinaryFile, 0, SEEK_END);

        printf("Type in the first name of the user: ");
        scanf(" %19s", inrecord->firstname);
        printf("Type in the family name of the user: ");
        scanf(" %19s", inrecord->famname);
        printf("Type in the personal number of the user: ");
        scanf(" %12s", inrecord->pers_number);

        fwrite(inrecord, sizeof(PERSON), 1, pBinaryFile);
        fclose(pBinaryFile);
    }
};
int main(void)
{
    PERSON ppost;
    char name[10];
    int userOption;

    strcpy(ppost.firstname, "David");
    strcpy(ppost.famname, "Hong");
    strcpy(ppost.pers_number, "030521");
    do
    {
        printf("1. Create a new and delete the old file.\n");
        printf("2. Add a new person to the file.\n");
        printf("3. Search for a person in the file.\n");
        printf("4. Print out all in the file.\n");
        printf("5. Exit the program.\n");
        printf("Choose your option: ");
        scanf(" %d", &userOption);

        if (userOption < 1 || userOption > 5)
        {
            printf("Please input a valid number!!\n");
        }

        switch (userOption)
        {
        case (1):
            write_new_file(&ppost);
            break;
        case (2):
            append_file(&ppost);
            break;
        case (3):
            printf("Type in the name that you want to search: ");
            scanf(" %s", name);
            search_by_firstname(name);
            break;
        case (4):
            printfile();
            break;
        };

    } while (userOption != 5);

    return (0);
}