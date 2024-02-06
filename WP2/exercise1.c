// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 2
// Exercise 1
// Submission code: 131313 (provided by your TA-s)

// Include section for the header files
#include <stdio.h>
#include <string.h>

// Enum for directions of robot
enum DIRECTION
{
    N, // North
    O, // East
    S, // South
    W  // West
};

// Struct for robot with x and y position, and direction
typedef struct
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

/*----FUNCTION DECLARATIONS----*/

// Move the robot one step in its current direction
void move(ROBOT *robot);
// Turn the robot 90 degrees clockwise
void turn(ROBOT *robot);

int main()
{
    // Define the variables
    ROBOT robot;     // Declare the robot
    char buffer[32]; // User input buffer
    do
    {
        // Set robot to default direction
        robot.dir = N;
        // Get starting coordinates
        printf("Enter starting coordinates in the format x,y (q to exit): ");
        // Scan for the user input
        scanf("%5s", &buffer);
        // Quit if user enters q
        if (strcmp(buffer, "q") == 0)
            // Break out of the loop
            break;
        // Check if input is in the format x,y
        int formatCheck = sscanf(buffer, "%d,%d", &robot.xpos, &robot.ypos);
        // If the format is wrong
        if (formatCheck != 2)
        {
            printf("Invalid format. Try again.\n");
            // Continue the loop
            continue;
        }

        // Check if coordinates are valid
        if (robot.xpos < 0 || robot.xpos > 100 || robot.ypos < 0 || robot.ypos > 100)
        {
            printf("Invalid coordinates. Try again.\n");
            // Continue the loop
            continue;
        }

        // Get commands from user
        printf("Enter commands (m for move, t for turn): ");
        // Scan for the user input
        scanf("%31s", &buffer);
        // Execute commands
        for (int i = 0; i < strlen(buffer); i++)
        {
            // If the input is m
            if (buffer[i] == 'm')
            {
                // Move the robot
                move(&robot);
            }
            // If the input is t
            else if (buffer[i] == 't')
            {
                // Turn the robot
                turn(&robot);
            }
        }
        printf("\n------------------------------\n");
        // Print robot position
        printf("The robot is now at %d,%d\n\n", robot.xpos, robot.ypos);

    } while (strcmp(buffer, "q") != 0); // While q is not found here
    printf("Goodbye!\n");
    // Return 0 to exit the program successfully
    return 0;
}

// Move the robot one step in its current direction
void move(ROBOT *robot)
{
    // If the direction is North
    if (robot->dir == N)
    {
        // Increase Y position
        robot->ypos++;
    }
    // If the direction is East
    else if (robot->dir == O)
    {
        // Increase X position
        robot->xpos++;
    }
    // If the direction is South
    else if (robot->dir == S)
    {
        // Decrease Y position
        robot->ypos--;
    }
    // If the direction is West
    else if (robot->dir == W)
    {
        // Decrease the X position
        robot->xpos--;
    }
}

// Turn the robot 90 degrees clockwise
void turn(ROBOT *robot)
{
    // If the Robot's direction is North
    if (robot->dir == N)
    {
        // Change it to East
        robot->dir = O;
    }
    // If the Robot's direction is East
    else if (robot->dir == O)
    {
        // Change it to South
        robot->dir = S;
    }
    // If the Robot's direction is South
    else if (robot->dir == S)
    {
        // Change it to Weest
        robot->dir = W;
    }
    // If the Robot's direction is West
    else if (robot->dir == W)
    {
        // Change it to North
        robot->dir = N;
    }
}