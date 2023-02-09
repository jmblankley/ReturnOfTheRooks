#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 100
#define EMPTY '.'

char input;
char rooks[SIZE][SIZE];
int row, col;
int nRooks;

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

// starting with trying at [0,0] check behind in the row and behind in the col
// if there are no 'R' in the row or col return true
bool canPlace(int currentRow, int currentCol)
{
    // check if the spot you are looking is empty
    // if it isnt
    if (rooks[currentRow][currentCol] == 'R' || rooks[currentRow][currentCol] == '#')
    {
        return false;
    }

    // if it is
    if (rooks[currentRow][currentCol] == EMPTY)
    {
    }

    return true;
}

// if you can place a 'R' place it
// move on to the next element and check if you can place another 'R'

// THINK VERY VERY VERY HARD ABOUT WHAT PARAMETERS!!!!!!!!!!!!!
bool solveBoard(int numRooks, int currentRow, int currentCol)
{
    // WE NEED A BASE CASE!
    // looks at parameteres-done yet?
    if (numRooks <= 0)
    {
        return true;
    }
    // LOOP OVER ALL POSSIBLE NEXT MOVES!!!
    for (int rowCheck = currentRow; rowCheck <= row; row++)
    {
        for (int colCheck = currentCol; colCheck <= col; col++)
        {
            if (canPlace(rowCheck, colCheck))
            {
                rooks[rowCheck][colCheck] = 'R';
                if (solveBoard(numRooks - 1, rowCheck + 1, colCheck + 1))
                {
                    return true;
                }
                rooks[rowCheck][colCheck] = rooks[rowCheck][colCheck];
            }
        }
    }
    // might be a combination of loops to go over EVERY POSSIBLE NEXT MOVE!!

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

    cout << "Please enter the number of rooks you would like to place: ";
    cin >> nRooks;

    if (solveBoard(nRooks, 0, 0))
    {
        printGrid(row, col);
    }

    return 0;
}
