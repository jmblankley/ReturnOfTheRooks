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
// PARAMETERS - instream, number of rows and cols to iterate through.
// return void
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
// PARAMETERS - number of rows and cols in the text file
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

// looks for any 'R' in the 2d array and replaces it back with a '.' so we essentially get an empty board.
void clearBoard()
{
    for (int rowClear = 0; rowClear < row; rowClear++)
    {
        for (int colClear = 0; colClear < col; colClear++)
        {
            if (rooks[rowClear][colClear] == 'R')
            {
                rooks[rowClear][colClear] = '.';
            }
        }
    }
}

// starting with trying at [0,0] check behind in the row and behind in the col
// if there are no 'R' in the row or col return true
// PARAMETERS - the row and col we are starting on
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
        // look behind the current location in column
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
        // look behind the current location in the row
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
// PARAMETERS - number of rooks we are trying to place, the starting row and starting column
bool solveBoard(int numRooks, int rowCur, int colCur)
{
    // WE NEED A BASE CASE!
    // looks at parameteres-done yet?
    if (numRooks == 0)
    {
        return true;
    }
    // LOOP OVER ALL POSSIBLE NEXT MOVES!!!
    // look in every row in every column starting with current location
    for (int rowCheck = rowCur; rowCheck < row; rowCheck++)
    {
        for (int colCheck = colCur; colCheck < col; colCheck++)
        {
            if (canPlace(rowCheck, colCheck))
            {
                rooks[rowCheck][colCheck] = 'R';
                if (solveBoard(numRooks - 1, rowCheck, colCheck + 1))
                {
                    return true;
                }
                else
                {
                    // puts back an empty space when it tries to put a rook and does not work out
                    rooks[rowCheck][colCheck] = '.';
                }
            }
        }
        colCur = 0;
    }

    return false;
}

int main(int argc, char *argv[])
{

    // takes user input to open file
    string fname;
    cout << "Please enter the name of an input file: " << fname;
    cin >> fname;
    ifstream reader(fname);

    // kicks out an error if you enter the name in worng, or if the file is empty
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

    // takes our user input file and store the first two integers in the row and col variables
    reader >> row >> col;

    readFile(reader, row, col);

    // ask the user how many rooks they want to try and place
    cout << "How many rooks would you like to place? ";
    cin >> nRooks;

    // see if you can solve the board with that many rooks
    if (solveBoard(nRooks, 0, 0))
    {
        cout << "Yes, could place " << nRooks << " rooks." << endl;
        printGrid(row, col);
        nRooks = 0;
    }
    clearBoard();
    if (!solveBoard(nRooks, 0, 0) && nRooks != -1)
    {
        cout << "No, could not place " << nRooks << " rooks." << endl;
        nRooks = 0;
    }

    // after asking the user the first time, give them the option to enter in -1 and stop the program
    // keep asking the user for a number of rooks until they enter -1 to stop the program
    while (nRooks != -1)
    {
        cout << "How many rooks would you like to place (-1 to stop)? ";
        cin >> nRooks;

        if (solveBoard(nRooks, 0, 0))
        {
            cout << "Yes, could place " << nRooks << " rooks." << endl;
            printGrid(row, col);
            nRooks = 0;
        }
        clearBoard();
        if (!solveBoard(nRooks, 0, 0) && nRooks != -1)
        {
            cout << "No, could not place " << nRooks << " rooks." << endl;
            nRooks = 0;
        }
    }

    // if the user enters the stopping number then stop the program and print out
    if (nRooks == -1)
    {
        cout << "Thank you for using RookPlacer - hope to see you again soon!" << endl;
    }

    return 0;
}
