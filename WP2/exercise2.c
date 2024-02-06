// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 2
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #### Constants #####
#define MAX 5

// ##### typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);


// ###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *act_post, *head = NULL;
    srand(time(0)); // Random seed
    head = random_list();
    act_post = head;

    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    // Print new list
    int newNode = 40;
    head = add_first(head, newNode); // call the function to add a new record at the beginning

    nr = 0; // reset the post number
    act_post = head;
    while (act_post!= NULL) // while the head is not null, it will print post number and its data
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next; // move to the next node in the list
        
    }

    // --- Free the allocated memory ---
    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }
    
    return 0;

}
// ==== End of main ======================================

REGTYPE *random_list(void)
{
    int nr, i = 0;
    REGTYPE *top = NULL, *old = NULL, *item;

    for (i = 0; i < MAX; i++)
    {
        item = (REGTYPE*)malloc(sizeof(REGTYPE)); // allocate memory for a new node
        if (item == NULL) // Check memmory allocation and prints error message
        {
            printf("Failed memory allocation.\n");
            exit(EXIT_FAILURE);
        }

        item -> number = rand()%101; // generates a random number between 0 and 100
        item -> next = NULL; // initialize the next pointer to null

        if (old != NULL) // if old is not null it set to the next item
        {
            old -> next = item; // set next of the previous node to the current one
            item -> prev = old; // set prev of the current node to the previous one
        }
        else
        {
            top = item; // if is the first node, set top to the current
            item -> prev = NULL; // set prev to null for the first node
        }
        
        old = item; // move the older pointer to the current node
        
    }
    

    return top; //return pointer to the head of the list
}
//==========================================================

REGTYPE *add_first(REGTYPE *temp, int data)
{
    REGTYPE *newItem = (REGTYPE*)malloc(sizeof(REGTYPE)); // allocate memory for a new node

    if (newItem == NULL) // checks if memory allocation and prints error message
    {
       printf("Memory allocation failed.\n");
       exit(EXIT_FAILURE);
    }

    newItem -> number = data; // set number field of the newItem to data
    newItem -> next = temp; // set next field of the newItem to point to the current head of the list
    newItem -> prev = NULL; // set prev field of the newItem to null

    if (temp != NULL)
    {
        temp -> prev = newItem; // update prev field of the current head if exists
    }
    
    return newItem; // return the pointer to the new head of the list
    
}