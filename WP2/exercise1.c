// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 2
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

// Include section for the header files
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the field
#define MAX 99

// Declare the enum for the directions
enum DIRECTION
{
    N, // North is set as 0
    E, // East is set as 1
    S, // South is set as 2
    W  // West is set as 3
};

// Define the structure of the robot
typedef struct
{
    int xpos;           // X Position of the robot
    int ypos;           // Y position of the robot
    enum DIRECTION dir; // Direction of the robot
} ROBOT;                // Declare the structure as a ROBOTs

// A function to move the robot (Uses the pointer that addresses the robot in the main function)
void move(ROBOT *robot)
{
    // Switch statement to move the robot based on the direction
    switch (robot->dir)
    {
    // Case when the direction of the Robot is North
    case 0:
        // Increase the Y position of the Robot
        robot->ypos++;
        // Break out of the switch loop
        break;
    // Case when the direction of the Robot is East
    case 1:
        // Increase the X position of the Robot
        robot->xpos++;
        // Break out of the switch loop
        break;
    // Case when the direction of the Robot is South
    case 2:
        // Decrease the Y position of the Robot
        robot->ypos--;
        // Break out of the switch loop
        break;
    // Case when the direction of the Robot is West
    case 3:
        // Decrease the X position of the Robot
        robot->xpos--;
        // Break out of the switch loop
        break;
    }

    printf("X Position: %d \n", robot->xpos);
    printf("Y Position: %d \n", robot->ypos);
    printf("Direction: %d \n", robot->dir);
}

// A function to turn the robot
void turn(ROBOT *robot)
{
    // A switch loop to rotate the robot based on their initial direction
    switch (robot->dir)
    {
    // Case when the direction of the robot is North
    case 0:
        // Change the direction of the robot to East
        robot->dir = 1;
        // Break out of the switch loop
        break;
    // Case when the direction of the robot is East
    case 1:
        // Change the direction of the robot to South
        robot->dir = 2;
        // Break out of the switch loop
        break;
    // Case when the direction of the robot is South
    case 2:
        // Change the direction of the robot to West
        robot->dir = 3;
        // Break out of the switch loop
        break;
    // Case when the direction of the robot is West
    case 4:
        // Change the direction of the robot to North
        robot->dir = 0;
        // Break out of the switch loop
        break;
    }
    printf("X Position: %d \n", robot->xpos);
    printf("Y Position: %d \n", robot->ypos);
    printf("Direction: %d \n", robot->dir);
}

// Initialize the main function
int main()
{
    // Variable declarations
    ROBOT robots[1];  // Declare the array of robots(Only one since we create just a single robot)
    int startPosX;    // The starting x position of the robot
    int startPosY;    // The starting y position of the robot
    char userRequest; // The request of the user (between m and t)

    // A do while loop to run the program until the user presses EOF.
    do
    {
        printf("Define the x coordinate of the starting position: ");
        // Store the starting position X value at startPosX
        scanf("%d", &startPosX);

        // If the starting position value is larger than 99 or smaller than 0, exit the program
        if (startPosX > MAX || startPosX < 0)
        {
            printf("Error: Starting position should be between 0 and 99 \n");
            // Exit the program with code 1
            return 1;
        }

        printf("Define the y coordinate of the starting position: ");
        // Store the starting position Y value at startPosY
        scanf("%d", &startPosY);

        // If the starting position value is larger than 99 or smaller thant 0, exit the program
        if (startPosY > MAX || startPosY < 0)
        {
            printf("Error: Starting position should be between 0 and 99 \n");
            // Exit the program with code 1
            return 1;
        }

        // Set the Robot's x position as the user's input
        robots[0].xpos = startPosX;
        // Set the Robot's y position as the user's input
        robots[0].ypos = startPosY;
        // Always start the Robot's starting direction as North
        robots[0].dir = 0;

        printf("Your robot's settings have been defined as the following. xPos: %d yPos: %d dir: %d \n", robots[0].xpos, startPosY, robots[0].dir);

        // A do-while loop to continue until the user decides not to
        do
        {
            printf("Enter your command: ");
            // Save the user's order in the userRequest variable
            scanf(" %c", &userRequest);

            // Check if the user's request is either m or t
            if (userRequest != 'm' || userRequest != 't')
            {
                printf("Please type in a valid command. Exiting the program... \n");
                // Return with 1 to exit the program as a failure
                return 1;
            }

            // If the user's request is a m, move the robot
            if (userRequest == 'm')
            {
                // Pass the address of the robot[0]
                move(&robots[0]);
            }
            // If the user's request is a t, turn the robot
            if (userRequest == 't')
            {
                // Pass the address of the robot[0]
                turn(&robots[0]);
            }
        } while (getchar() != 'x' && robots[0].xpos > 0 && robots[0].xpos < 99 && robots[0].ypos > 0 && robots[0].ypos < 99); // While the position of the robot is valid
    } while (getchar() != EOF);                                                                                               // While the user does not end the program through EOF key

    // Return 0 to exit the program with a success
    return 0;
}