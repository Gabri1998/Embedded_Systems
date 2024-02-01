// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 2
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>

#define MAX 99

enum DIRECTION
{
    N,
    E,
    S,
    W
};

typedef struct
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void move(ROBOT *robot)
{
    switch (robot->dir)
    {
    case 0:
        robot->ypos++;
        break;
    case 1:
        robot->xpos++;
        break;
    case 2:
        robot->ypos--;
        break;
    case 3:
        robot->xpos--;
        break;
    }

    printf("X Position: %d \n", robot->xpos);
    printf("Y Position: %d \n", robot->ypos);
    printf("Direction: %d \n", robot->dir);
}

void turn(ROBOT *robot)
{
    switch (robot->dir)
    {
    case 0:
        robot->dir = 1;
        break;
    case 1:
        robot->dir = 2;
        break;
    case 2:
        robot->dir = 3;
        break;
    case 4:
        robot->dir = 0;
        break;
    }
    printf("X Position: %d \n", robot->xpos);
    printf("Y Position: %d \n", robot->ypos);
    printf("Direction: %d \n", robot->dir);
}

int main()
{
    ROBOT robots[1];
    int startPosX;
    int startPosY;
    char userRequest;
    do
    {
        printf("Define the x coordinate of the starting position: ");
        scanf("%d", &startPosX);

        if (startPosX > MAX || startPosX < 0)
        {
            printf("Error: Starting position should be between 0 and 99 \n");
            return 1;
        }

        printf("Define the y coordinate of the starting position: ");
        scanf("%d", &startPosY);

        if (startPosY > MAX || startPosY < 0)
        {
            printf("Error: Starting position should be between 0 and 99 \n");
            return 1;
        }

        robots[0].xpos = startPosX;
        robots[0].ypos = startPosY;
        robots[0].dir = 0;

        printf("Your robot's settings have been defined as the following. xPos: %d yPos: %d dir: %d \n", robots[0].xpos, startPosY, robots[0].dir);

        do
        {
            printf("Enter your command: ");
            scanf(" %c", &userRequest);

            if (userRequest == 'm')
            {
                move(&robots[0]);
            }
            if (userRequest == 't')
            {
                turn(&robots[0]);
            }
        } while (getchar() != 'x' && robots[0].xpos > 0 && robots[0].xpos < 99 && robots[0].ypos > 0 && robots[0].ypos < 99);
    } while (getchar() != EOF);

    return 0;
}