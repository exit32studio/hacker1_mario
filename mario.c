#include <cs50.h>
#include <stdio.h>

int getNumberOfBricks (void);
void layoutBricks (int heightOfPyramid);
void printBricks (int numberOfBricks);
void printSpaces (int numberOfSpaces);

int main (void)
{
    //Make a place holder for the number of bricks
    int numberOfBricks = 0;
    
    //Ask the helper routine to get the number of bricks from the user
    numberOfBricks = getNumberOfBricks();
    
    //Let the user know the height of the pyramid
    printf("Height: %i\n", numberOfBricks);
    
    //Pass the number of bricks over to the layout helper
    layoutBricks(numberOfBricks);
    
    //return 0 at the end of the program
    return 0;
}

int getNumberOfBricks (void)
{
    //Make an int to hold the number of bricks
    int userEntry = 0;
    
    /*
    Enter into a loop that will only return a number between 1 and 23. Use a do->while loop to make sure
    the program runs through the loop at least once
    */
    do 
    {
        printf ("Please enter a number between 1 and 23: ");
        userEntry = GetInt();
        
    } 
    while (userEntry <= 0 || userEntry >23);
    
    //Return the number of bricks the user entered
    return userEntry;
}


void layoutBricks (int heightOfPyramid)
{   
    //Make place holders for the number of bricks and the number of gaps
    int numberOfBricks = 1;
    int numberOfSpaces = 0;
    do 
    {
        numberOfSpaces = heightOfPyramid - numberOfBricks;
        //Print the spaces and the bricks
        printSpaces(numberOfSpaces);
        printBricks(numberOfBricks);
        printf("  ");
        printBricks(numberOfBricks);
        printSpaces(numberOfSpaces);
        printf("\n");
        numberOfBricks++;
    }
    while (numberOfBricks <= heightOfPyramid);
} 

void printBricks(int numberOfBricks)
{
    for (int i = 0; i < numberOfBricks; i++)
    {
        printf("#");
    }
}

void printSpaces (int numberOfSpaces)
{
    for (int i = 0; i < numberOfSpaces; i++)
    {
        printf(" ");
    }
}
