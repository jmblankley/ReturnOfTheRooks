#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 100


char input;
char rooks[SIZE][SIZE];
int row, col;
int nRooks;



//iterate through the grid in the file
//print out each element
void readFile(ifstream &input, int rowCount, int colCount)
{   
    for(int row = 0; row < rowCount; row++)
    {
        for(int col = 0; col < colCount; col++)
        {
            char var;
            input >> var;
            rooks[row][col] = var;
        }
    }
}

//take in an input file from user
//store the first two ints in vars row and col
//iterate through the grid in the file
void printGrid(int rowCount, int colCount)
{
    for(int row = 0; row < rowCount; row++)
    {
        for(int col = 0; col < colCount; col++)
        {
            cout << rooks[row][col];
        }
        cout << endl;
    }
}


//starting with trying at [0,0] check behind in the row and behind in the col
//if there are no 'R' in the row or col return true
bool canPlace(int currentRow, int currentCol)
{
    if(rooks[currentRow][currentCol] == 'R' || rooks[currentRow][currentCol] == '#')
    {
        return false;
    }

    if(rooks[currentRow][currentCol] == '.')
    {
        for(int colCheck = currentCol; colCheck > 0; colCheck--)
        {
            if(rooks[currentRow][colCheck] == '#')
            {
                return true;
            }
            if(rooks[currentRow][colCheck] == 'R')
            {
                return false;
            }
        }
        
        for(int rowCheck = currentRow; rowCheck > 0; rowCheck--)
        {
            if(rooks[rowCheck][currentCol] == '#')
            {
                return true;
            }
            if(rooks[rowCheck][currentCol] == 'R')
            {
                return false;
            }
        }

        
    }

    return true;
}

//if you can place a 'R' place it
//move on to the next element and check if you can place another 'R'
bool solveBoard(int colForNextRook, int numRooks)
{
    int maxRows = row;

    if (numRooks <= 0)
    {
        return true;
    }

    for(int inRow = 0; inRow < maxRows; inRow++)
    {
        if(canPlace(inRow, colForNextRook))
        {
            rooks[inRow][colForNextRook] = 'R';
            numRooks--;
            inRow++;
            return true;
            //need to have some sort of way to break out and tell main that
            //solve board is true so it will print out the board

        }
        //if you can't place anything put back what was there before
        rooks[inRow][colForNextRook] = rooks[inRow][colForNextRook];
    }
    return false;
}


int main(int argc, char* argv[])
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


    if(solveBoard(0, nRooks))
    {
        printGrid(row, col);
    }



    return 0;
}
