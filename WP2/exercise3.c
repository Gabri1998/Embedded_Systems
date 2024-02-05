// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 2
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s)

// Include section for the header files
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define section for the constant variables
#define MAX 100

// -----typedefs -------

// Define the structure of a PERSON
typedef struct
{
    char firstname[20];   // First name of the person
    char famname[20];     // Family name of the person
    char pers_number[13]; // Personal Number of the person
} PERSON;                 // Name of the structure

// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.

// Creates a file and writes the first record
void write_new_file(PERSON *inrecord)
{
    // Variable declarations
    FILE *fileptr;                                  // Pointer to the file
    PERSON *records = malloc(MAX * sizeof(PERSON)); // Allocate memory to the records of the person(s)

    memcpy(records, inrecord, sizeof(PERSON)); // Copy the records into the inrecord that has the size of the PERSON

    // If the file cannot be created, exit with code 1
    if ((fileptr = fopen("David.bin", "wb")) == NULL)
    {
        printf("\n Cannot create the file");
        // Exit with code 1 to show failure
        exit(1);
    }

    // Write the records to the file
    fwrite(records, sizeof(PERSON), 1, fileptr);
    // Close the file
    fclose(fileptr);
    // Free the allocated memory
    free(records);
};

// Print the content(s) written in the file
void printfile(void)
{
    // Varaible declarations
    FILE *fileptr;                                  // Pointer to the file
    PERSON *records = malloc(MAX * sizeof(PERSON)); // Allocate memory to the records of the person(s)

    // If the file does not exist, exit with code 1 to indicate error
    if ((fileptr = fopen("David.bin", "r")) == NULL)
    {
        printf("\n Cannot open the file");
        // Exit with 1 to show error
        exit(1);
    }

    // If the file can be opened, read the records
    fread(records, sizeof(PERSON), MAX, fileptr);

    // Iterate through the file and print the records
    for (int i = 0; i < MAX; i++)
    {
        // To only open the records that exist, compare the firstname and a blank space to see if the firstname exists
        if (strcmp(records[i].firstname, "") > 0)
        {
            printf("\nFirst Name: %s\n", records[i].firstname);
            printf("Family Name: %s\n", records[i].famname);
            printf("Personal Number: %s \n", records[i].pers_number);
        }
    }
    // Close the file
    fclose(fileptr);
    // Free the allocated memory
    free(records);
};

// Prints out the person if in list
void search_by_firstname(char *name)
{
    // Variable declarations
    FILE *fileptr;                                  // Pointer to the file
    PERSON *records = malloc(MAX * sizeof(PERSON)); // Allocate memory to the records of the person(s)
    char option;                                    // Option chosen by the user

    // If the file does not exist, exit with code 1
    if ((fileptr = fopen("David.bin", "r")) == NULL)
    {
        printf("\n Cannot open the file");
        // Exit with 1 to show failure
        exit(1);
    }

    // Keep asking until the user answers the option as either a 'F' or a 'N'
    while (option != 'F' || option != 'N')
    {
        printf("Choose the search method for the search. Type F for family name and N for firstname: ");
        // Save the input of the user at the option variable
        scanf(" %c", &option);

        // If the user answers the option either as a 'F' or a 'N', exit the loop
        if (option == 'F' || option == 'N')
        {
            // Exit the loop
            break;
        }
    }

    // Read the records
    fread(records, sizeof(PERSON), MAX, fileptr);

    // Itterate through all of the records
    for (int i = 0; i < MAX; i++)
    {
        // Based on the option
        switch (option)
        {
        // If the user searches by family name
        case ('F'):
            // Compare the string to see if the family name matches the desired name
            if (strcmp(records[i].famname, name) == 0)
            {
                printf("First Name: %s\n", records[i].firstname);
                printf("Family Name: %s\n", records[i].famname);
                printf("Personal Number: %s\n", records[i].pers_number);
                printf("\n");
            };
        // If the user searches by first name
        case ('N'):
            // Compare the string to see if the first name matches the desired name
            if (strcmp(records[i].firstname, name) == 0)
            {
                printf("\nFirst Name: %s\n", records[i].firstname);
                printf("Family Name: %s\n", records[i].famname);
                printf("Personal Number: %s\n", records[i].pers_number);
                printf("\n");
            }
        }
    }
    // Close the file
    fclose(fileptr);
    // Free the allocated memory
    free(records);
};
// appends a new person to the file
void append_file(PERSON *inrecord)
{
    // Variable declarations
    char *binaryFileName = "David.bin";              // The name of the binary file to be edited
    FILE *pBinaryFile = fopen(binaryFileName, "ab"); // File opener

    if (pBinaryFile != NULL)
    {
        // Find the end of the binary file
        fseek(pBinaryFile, 0, SEEK_END);

        printf("Type in the first name of the user: ");
        // Scan the user input and save it at the firstname of the record
        scanf(" %19s", inrecord->firstname);
        printf("Type in the family name of the user: ");
        // Scan the user input and save it at the famname of the record
        scanf(" %19s", inrecord->famname);
        printf("Type in the personal number of the user: ");
        // Scan the user input and save it at the pers_number of the record
        scanf(" %12s", inrecord->pers_number);

        // Write the records to the file
        fwrite(inrecord, sizeof(PERSON), 1, pBinaryFile);
        // Close the file
        fclose(pBinaryFile);
    }
};
int main(void)
{
    // Variable declaration
    PERSON ppost;   // Variable of a person
    char name[10];  // Name to be searched by the user
    int userOption; // Option selected by the user

    // Initial insert data
    strcpy(ppost.firstname, "David");
    // Initial insert data
    strcpy(ppost.famname, "Hong");
    // Initial insert data
    strcpy(ppost.pers_number, "030521");
    do
    {
        printf("1. Create a new and delete the old file.\n");
        printf("2. Add a new person to the file.\n");
        printf("3. Search for a person in the file.\n");
        printf("4. Print out all in the file.\n");
        printf("5. Exit the program.\n");
        printf("Choose your option: ");
        // Scan the input of the user
        scanf(" %d", &userOption);

        // Check if the user is giving a valid input
        if (userOption < 1 || userOption > 5)
        {
            printf("Please input a valid number!!\n");
        }

        // A switch loop that takes in userOption as the argument
        switch (userOption)
        {
        // User input 1
        case (1):
            // Write new file
            write_new_file(&ppost);
            // Break out of the switch loop
            break;
        // User input 2
        case (2):
            // Add new record to the file
            append_file(&ppost);
            // Break out of the switch loop
            break;
        // User input 3
        case (3):
            printf("Type in the name that you want to search: ");
            // Scan the desired name to be searched
            scanf(" %s", name);
            // Run the search function
            search_by_firstname(name);
            // Break out of the switch loop
            break;
        // User input 4
        case (4):
            // Print all records
            printfile();
            // break out of teh switch loop
            break;
        };

    } while (userOption != 5); // Exit when the user presses 5

    // Return with 0 to exit successfully
    return (0);
}