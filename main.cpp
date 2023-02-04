#include <iostream>
#include <fstream>
#define MAXSIZE 100
using namespace std;

char rooks[MAXSIZE][MAXSIZE]; //initializing a 2d array that will be no larger that 100x100
int row, col;
int numRooks;
int actualSize;

//initialize a board
void initBoard()
{
    for (int rowCount = 0; rowCount < actualSize; rowCount++)
        for (int colCount = 0; colCount < actualSize; colCount++)
            rooks[rowCount][colCount] = ' ';
}

// this function takes in our ifstream and stores it in our 2d array
void readGrid(int rowCount, int colCount, ifstream& input)
{
    for (int r = 0; r < rowCount; r++)
    {
        for (int c = 0; c < colCount; c++)
        {
            char var;
            input >> var;
            rooks[r][c] = var;
        }
    }
}


//this function takes user input for a file name, reads through it and takes the integers in the file storing them in row and col
//to be used in construction of grid
void fileRead()
{
    // ask user for input
    string fname;
    cout << "Please enter the name of an input file: ";
    cin >> fname;

    // uses fstream to read the filename given by the user and store
    ifstream reader(fname);

    // next two if statements handles errors
    // returns error if file is un-openable
    if (!reader)
    {

        cerr << "Could not open \"" << fname << '"' << endl;
        return;
    }
    // returns error if nothing is in the file
    if (!reader)
    {
        cerr << "File had no data in it!!!" << endl;
        return;
    }

    // takes the first two values of our text file and stores them in variables to construct the 2d array
    reader >> row >> col;

    // call this function, pass it our row and col size taken from input file as well as what ifstream we need to read
    readGrid(row, col, reader);
}



// prints out our empty grid
// used to test if our input was getting put into the grid
void printGrid(int rowCount, int colCount)
{
    for (int r = 0; r < rowCount; r++)
    {
        for (int c = 0; c < colCount; c++)
        {
            cout << rooks[r][c];
        }
        cout << endl;
    }
}

bool canPlace(int inRow, int inCol)
{

    //check the row
    for(int colCheck = 0; colCheck < inCol; colCheck++)
    {
        if(rooks[inRow][colCheck] == 'R')
        {
            return false;
        }

    }
    return true;
    
}

bool solveBoard(int colForNewRook)
{
    //this uses the text file to set how many columns we have available
    actualSize = row;

    if (colForNewRook >= actualSize)
    {
        return true;

    }


    for(int rowNum = 0; rowNum < actualSize; rowNum++)
    {
        if(canPlace(rowNum, colForNewRook))
        {
            if(rooks[rowNum][colForNewRook] != '#')
            {
                rooks[rowNum][colForNewRook] = 'R';
            }
            //if there is a next column, continue on.
            if(solveBoard(colForNewRook + 1))
            {
                return true;
            }

            rooks[rowNum][colForNewRook] = rooks[rowNum][colForNewRook];
        }
    }

return false;
}



int main(int argc, char *argv[])
{
    //initialize a board
    initBoard();

    //ask for input filename
    fileRead();

    //print out the board from the file selected
	printGrid(row, col);

        //ask user for the number of rooks they want to place
    cout << "How many rooks would you like to place? ";
    cin >> numRooks;



    //check to see if you can place that many rooks without them attacking eachother
    //solveBoard(0);
    if(solveBoard(0))
    {
        cout << "The solved board is: " << endl;
        printGrid(row,col);
    }
    else
    { 
        cout << "No Solution!!!" << endl;
    }

    
	return 0;
}