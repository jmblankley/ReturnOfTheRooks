#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 100
#define EMPTY '.'

char input;
char rooks[SIZE][SIZE];
int row, col;
int nRooks;
int newRooks;

// iterate through the grid in the file
// print out each element
void readFile(ifstream &input, int rowCount, int colCount)
{
    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < colCount; col++)
        {
            char var;
            input >> var;
            rooks[row][col] = var;
        }
    }
}

// take in an input file from user
// store the first two ints in vars row and col
// iterate through the grid in the file
void printGrid(int rowCount, int colCount)
{
    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < colCount; col++)
        {
            cout << rooks[row][col];
        }
        cout << endl;
    }
}

void clearBoard(int rowCount, int colCount)
{
    for(int rowClear = 0; rowClear < rowCount; rowClear++)
    {
        for(int colClear = 0; colClear < colCount; colClear++)
        {   
            rooks[rowClear][colClear] = var;
        }
    }
}

// starting with trying at [0,0] check behind in the row and behind in the col
// if there are no 'R' in the row or col return true
bool canPlace(int currentRow, int currentCol)
{
    // check if the spot you are looking is empty
    // if it isnt
    if (rooks[currentRow][currentCol] == 'R')
    {
        return false;
    }
    if (rooks[currentRow][currentCol] == '#')
    {
        return false;
    }
    if (rooks[currentRow][currentCol] == EMPTY)
    {
        for (int rowCheck = currentRow - 1; rowCheck >= 0; rowCheck--)
        {
            if (rooks[rowCheck][currentCol] == '#')
            {
                break;
            }
            if (rooks[rowCheck][currentCol] == 'R')
            {
                return false;
            }
        }
        for (int colCheck = currentCol - 1; colCheck >= 0; colCheck--)
        {
            if (rooks[currentRow][colCheck] == '#')
            {
                return true;
            }
            if (rooks[currentRow][colCheck] == 'R')
            {
                return false;
            }
        }
    }

    // if there are no other rooks
    return true;
}

// THINK VERY VERY VERY HARD ABOUT WHAT PARAMETERS!!!!!!!!!!!!!
bool solveBoard(int numRooks, int rowCur, int colCur)
{
    // WE NEED A BASE CASE!
    // looks at parameteres-done yet?
    if (numRooks == 0)
    {
        return true;
    }
    // LOOP OVER ALL POSSIBLE NEXT MOVES!!!
    for (int rowCheck = rowCur; rowCheck < row; rowCheck++)
    {
        for (int colCheck = 0; colCheck < col; colCheck++)
        {
            if (canPlace(rowCheck, colCheck))
            {
                rooks[rowCheck][colCheck] = 'R';
                while (colCheck <= col)
                {
                    if (solveBoard(numRooks - 1, rowCheck, colCheck + 1))
                    {
                        return true;
                    }
                    else
                    {
                        rooks[rowCheck][colCheck] = rooks[rowCheck][colCheck];
                    }
                }                    
            }

        }
        
    }

    return false;
}

int main(int argc, char *argv[])
{

    string fname;
    cout << "Please enter the name of an input file: " << fname;
    cin >> fname;

    ifstream reader(fname);

    if (!reader)
    {

        cerr << "Could not open \"" << fname << '"' << endl;
        return 1;
    }
    // returns error if nothing is in the file
    if (!reader)
    {
        cerr << "File had no data in it!!!" << endl;
        return 2;
    }

    reader >> row >> col;

    
    readFile(reader, row, col);
    printGrid(row, col);


    cout << "How many rooks would you like to place? ";
    cin >> nRooks;

    if (solveBoard(nRooks, 0, 0))
    {
        printGrid(row, col);
    }
    clearBoard(row, col);
    while (nRooks != -1)
    {
        cout << "How many rooks would you like to place (-1 to stop)?";
        cin >> nRooks;

        if (solveBoard(nRooks, 0, 0))
        {
            printGrid(row, col); 
        }

        clearBoard(row, col);
    }
    if (nRooks == -1)
    {
        cout << "Thank you for using RookPlacer - hope to see you again soon!" << endl;
        return 0;
    }


    return 0;
}
