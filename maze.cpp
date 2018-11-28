#include "maze.h"

using std::cout;
using std::endl;

maze::maze(int r, int c)
{
    row = r;
    col = c;
    int numberOfCells = r * c;
    // Add the first cell
    theMaze.push_back(mazeCell(false, true, false, true));
    for(int i = 1; i < numberOfCells - 1; ++i)
    {
        theMaze.push_back(mazeCell());
    }
    theMaze.push_back(mazeCell(true, false, true, false));
}
bool maze::neighbors(int cell, int neigh) const
{
    // Adjacent neighbors
    if(cell == neigh + 1 && cell % col != 0)
        return true;
    else if(cell == neigh - 1 && cell % col != (col - 1))
        return true;
    else if(col == cell - neigh || col == neigh - cell)
        return true;
    else
        return false;
}
void maze::smashWall(int cell, int neigh)
{

    if(cell == neigh - 1 && (col - 1) != cell % col)
    {
        // This case, neigh is right of cell
        theMaze.at(cell).setRight(false);
        theMaze.at(neigh).setLeft(false);
    }
    else if(cell == neigh + 1 && 0 != cell % col)
    {
        // This case, neigh is left of cell
        theMaze.at(cell).setLeft(false);
        theMaze.at(neigh).setRight(false);
    }
    else if(col == cell - neigh)
    {
        // This case, neigh is above cell
        theMaze[cell].setTop(false);
        theMaze[neigh].setBot(false);
    }
    else if(col == neigh - cell)
    {
        // This case, neigh is below cell
        theMaze[cell].setBot(false);
        theMaze[neigh].setTop(false);
    }
}
void maze::printMaze()
{
    // Print Upper Edges
    cout << " " << " " << " ";
    for(int i = 1; i < col; ++i)
    {
        cout << "_ ";
    }
    cout << endl;
    // Print first cell
    if(theMaze.at(0).getBot())
    {
        cout << " _";
    }
    else
    {
        cout << "  ";
    }
    // Print Middle Cells
    for(int i = 1; i < theMaze.size() - 1; ++i)
    {
        // Close off right edge
        if(i % col == 0)
        {
            cout << "|" << endl;
        }
        // Check for Left Edge
        if(theMaze.at(i).getLeft())
        {
            cout << "|";
        }
        else
        {
            cout << " ";
        }
        // Check For Bottom Edge
        if(theMaze.at(i).getBot())
        {
            cout << "_";
        }
        else
        {
            cout << " ";
        }
    }
    cout << endl; // Final new line
}
