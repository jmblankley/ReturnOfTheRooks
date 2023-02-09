#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 100
#define EMPTY '.'


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

    if(rooks[currentRow][currentCol] == EMPTY)
    {
        //look through every col in the row behind your current location
        for(int colCheck = currentCol; colCheck >= 0; colCheck--)
        {
            //if you run into another rook stop looking here because you cant place it
            if(rooks[currentRow][colCheck] == 'R')
            {
                return false;
            }
            //if you run into a block, then you are good to place in the horizontal (or if you run of the array and dont run into anyting)
            if(rooks[currentRow][colCheck] == '#')
            {
                return true;
            }
        }
        for(int rowCheck = currentRow - 1; rowCheck > 0; rowCheck--)
        {
            //if you run into a rook here stop looking
            if(rooks[rowCheck][currentCol] == 'R')
            {
                return false;
            }
            //if you run into a block (or off the page without hitting a rook) then you can place a rook!!!
            if(rooks[rowCheck][currentCol] == '#')
            {
                return true;
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

    if (numRooks == 0)
    {
        return true;
    }

    for(int inRow = 0; inRow < maxRows; inRow++)
    {
        if(canPlace(inRow, colForNextRook))
        {
            rooks[inRow][colForNextRook] = 'R';
            numRooks--;
            //need to have some sort of way to return to main and tell main that
            //solve board is true so it will print out the board]

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
