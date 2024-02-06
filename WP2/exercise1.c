// Include section for the header files
#include <stdio.h>
#include <stdlib.h>

// Define the constant values
#define MAX 99

// Enum for the directions (N, E, S, W)
enum DIRECTION
{
    N, // = 0
    E, // = 1
    S, // = 2
    W  // = 3
};

// Define the structure for the robot
typedef struct
{
    int xpos;           // xPosition for the robot
    int ypos;           // yPosition for the robto
    enum DIRECTION dir; // Direction of the robot
} ROBOT;

// Function to move the robot
void move(ROBOT *robot)
{
    // Switch case based on the robot's direction
    switch (robot->dir)
    {
    // Heading North
    case 0:
        // Increase the y position of the robot
        robot->ypos++;
        // Break out of the loop
        break;
    // Heading East
    case 1:
        // Increase the x position of the robot
        robot->xpos++;
        // Break out of the loop
        break;
    // Heading South
    case 2:
        // Decrease the y position of the robot
        robot->ypos--;
        // Break out of the loop
        break;
    // Heading West
    case 3:
        // Decrease the x position of the robot
        robot->xpos--;
        // Break out of the loop
        break;
    }

    printf("X Position: %d \n", robot->xpos);
    printf("Y Position: %d \n", robot->ypos);
    printf("Direction: %d \n", robot->dir);
}

// Function to turn the obot
void turn(ROBOT *robot)
{
    // Switch loop based on the direction of the robot
    switch (robot->dir)
    {
    // Robot facing North
    case 0:
        // Set the robot's direction as East
        robot->dir = 1;
        // Break out of the loop
        break;
    // Robot facing East
    case 1:
        // Set the robot's direction as South
        robot->dir = 2;
        // Break out of the loop
        break;
    // Robot facing South
    case 2:
        // Set the robot's direction as West
        robot->dir = 3;
        // Break out of the loop
        break;
    // Robot facing West
    case 4:
        // Set the robot's direction as North
        robot->dir = 0;
        // Break out of the loop
        break;
    }
    printf("X Position: %d \n", robot->xpos);
    printf("Y Position: %d \n", robot->ypos);
    printf("Direction: %d \n", robot->dir);
}

// Start of the main function
int main()
{
    // Variable declarations
    ROBOT robots[1];  // Declare the robot
    int startPosX;    // Starting x position of the robot
    int startPosY;    // Starting y position of the robot
    char userRequest; // Selected option of the user

    // While loop that runs until the user exits
    do
    {
        printf("Define the x coordinate of the starting position: ");
        // Scan for the starting X position of the robot
        scanf("%d", &startPosX);
        printf("Define the y coordinate of the starting position: ");
        // Scan for the starting Y position of the robot
        scanf("%d", &startPosY);

        // While loop that runs when the starting position is not right
        while (startPosX < 0 || startPosX > MAX || startPosY < 0 || startPosY > MAX)
        {
            // Case where the starting position X is bad
            if (startPosX > MAX || startPosX < 0)
            {
                printf("Error: Starting position should be between 0 and 99 \n");

                printf("Define the x coordinate of the starting position: ");
                // Scan for the new user input of starting position X
                scanf("%d", &startPosX);
            }

            // Case where the starting position Y is bad
            if (startPosY > MAX || startPosY < 0)
            {
                printf("Error: Starting position should be between 0 and 99 \n");

                printf("Define the y coordinate of the starting position: ");
                // Scan for the new user input of starting position y
                scanf("%d", &startPosY);
            }
        }

        // Set the xposition of the robot as the user input
        robots[0].xpos = startPosX;
        // Set the yposition of the robot as the user input
        robots[0].ypos = startPosY;
        // Set the direction of the robot as the user input
        robots[0].dir = 0;

        printf("Your robot's settings have been defined as the following. xPos: %d yPos: %d dir: %d \n", robots[0].xpos, startPosY, robots[0].dir);

        // Run the program unless the user enters x or the robot is out of grid
        do
        {
            printf("Enter your command: ");
            // Scan for the user's request
            scanf(" %c", &userRequest);

            // Case where the user moves the robot
            if (userRequest == 'm')
            {
                // Use the move function to move the robot's position
                move(&robots[0]);
            }
            // Case where the user turns the robot
            if (userRequest == 't')
            {
                // Use the turn function to turn the robot's direction
                turn(&robots[0]);
            }
            // Case where the user inputs x
            if (userRequest == 'x')
            {
                // Break out of the loop
                break;
            }
        } while (robots[0].xpos > 0 && robots[0].xpos < 99 && robots[0].ypos > 0 && robots[0].ypos < 99);
    } while (getchar() != EOF); // Exit if end of file is pressed

    // Return 0 to exit the program successfully
    return 0;
}