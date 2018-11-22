#include <iostream>
#include <limits>
#include <string>
#include <ctime>
#include "maze.h"
#include "DisjSets.h"

int getInt(int);
// Precondition: given lower bound
// Postcondition: return valid integer input from the user
bool getDecision();
// Precondition: None
// Postcondition: returns true if user decides yes.
void twoRandom(int &, int &, int);
// Precondition: Must be given two integers by reference and a final int for range
// Postcondition: makes both passed-by-reference integers random but not equal.
bool isConnected(int n1, int n2);
// Precondition: Passed two numbers (representing cells)
// Postcondition: Returns true if these two cells are connected

int main()
{
    // Get Row and column Input
    std::cout << "Please enter the number of rows greater than 1: ";
    int row = getInt(1);
    std::cout << "Please enter the number of columns greater than 1: ";
    int col = getInt(1);
    // Get decision to repeat or not
    std::cout << "Would you like to see each iteration of the maze: ";
    bool seeIterations = getDecision();
    // Create the maze object
    maze maze(row, col);
    int mazeSize = maze.getRow() * maze.getCol();
    // Print the Before
    maze.printMaze();
    // Create the corresponding disjoint set
    DisjSets set(mazeSize);
    srand(time(0));
    // Set up the first two randomly chosen Cells
    int cellOne, cellTwo;
    twoRandom(cellOne, cellTwo, mazeSize);
    // Start path-finding
    while(!isConnected(set.find(0), set.find(mazeSize - 1))) // While Start !connected End
    {
        // If neighbors and arent already connected
        if(maze.neighbors(cellOne, cellTwo) && !isConnected(set.find(cellOne), set.find(cellTwo)))
        {
            // Union them
            set.unionSets(set.find(cellOne), set.find(cellTwo));
            // Smash The Walls
            maze.smashWall(cellOne, cellTwo);
            // Display Update if
            if(seeIterations)
            {
                std::cout << "Neighbors " << cellOne << ", " << cellTwo
                          << " wall smashed below" << endl << endl;
                maze.printMaze();
                cout << endl;
            }
        }
        // Get Two new random numbers
        twoRandom(cellOne, cellTwo, mazeSize);
    }
    // Print out the final Maze
    cout << endl;
    maze.printMaze();


    return 0;
}

int getInt(int lower)
{
    int input;
    while(true)
    {
        std::cin >> input;
        if(std::cin.fail())
        {
            std::cout << "Invalid input, please try again: ";
        }
        else if(input < lower)
        {
            std::cout << "Input can not be less than 1, try again: ";
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return input;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
bool getDecision()
{
    std::string input;
    while(true)
    {
        getline(std::cin, input);
        if(input.at(0) == 'y' || input.at(0) == 'Y')
        {
            return true;
        }
        else if(input.at(0) == 'n' || input.at(0) == 'N')
        {
            return false;
        }
        std::cout << "Invalid input, please enter y or n: ";
    }
}
void twoRandom(int & n1, int & n2, int maxN)
{
    n1 = rand() % maxN;
    do
    {
        n2 = rand() % maxN;
    } while(n1 == n2);
}
bool isConnected(int n1, int n2)
{
    if(n1 == n2)
        return true;
    else
        return false;
}
