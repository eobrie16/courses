#include <iostream>
using namespace std;
enum CELL_TYPE { Boundary, Ant, Empty};

struct Cell
{
	CELL_TYPE ctype;
	int isolation_count;
	int crowding_count;
	int birth_count;
};

const int NSIZE=10;
Cell life[NSIZE+2][NSIZE+2];

// An Ant who has no neighbors for the following number of iterations, will die
int ISOLATION_COUNT = 10;
// An Ant who has TOO_MANY_NEIGHBORS for CROWDING_COUNT iterations, will die 
int TOO_MANY_NEIGHBORS = 4;
int CROWDING_COUNT = 2;

// After BIRTH_COUNT iterations, a birth will be attempted if there is a 
// neighboring Ant and there is an adjacent Empty cell
int BIRTH_COUNT=15;




// Display current state of Life
void displayLife()
{
    cout << endl << endl << "*******************************" << endl;
    cout << "    ";
    for (int i=1; i <= NSIZE; i++)
        if (i > 9) cout << " " << i/10;
        else cout << "  ";
    cout << endl;
    
    cout << "    ";
    for (int i=1; i <= NSIZE; i++)
        cout << " "<< i%10;
    cout << endl;
    
    for (int i=0; i <= NSIZE+2; i++)
        cout << "++";
    cout << endl;
    for (int i=1; i <= NSIZE; i++)
        for (int j=0; j <= NSIZE+1; j++)
        {
            if (j == 0)
            {
                if (i <= 9)
                    cout <<" " << i <<"++";
                else                    
                    cout << i <<"++";
            }
            else if (j <= NSIZE)
            {
                if (life[i][j].ctype == Ant)
                    cout << " A";
                else
                    cout << "  ";
            }
            else
            {
                cout << "++" << endl;
            }

        }

    for (int i=0; i <= NSIZE+2; i++)
        cout << "++";
    cout << endl;
}

void initCell(Cell & c, CELL_TYPE ctype)
{
	c.ctype = ctype;
	c.isolation_count = 0;
	c.crowding_count = 0;
	c.birth_count = rand() % (BIRTH_COUNT/2);
}


void init(int density)
{
    // Fill in a Boundary cell in the first and last column,
    // and also in the first and last row of the life matrix of Cells
	
    for (int i =0; i < NSIZE+2; i++)
	{
		initCell(life[0][i], Boundary);
		initCell(life[NSIZE+1][i], Boundary);
		initCell(life[i][0], Boundary);
		initCell(life[i][NSIZE+1], Boundary);
	}


    // For all of the interior cells, fill in either an Ant or an Empty cell
    // The probability for an Ant in any given cell should be density/100

    for (int i=1; i <= NSIZE ; i++)
		for (int k= 1; k <= NSIZE; k++)
		{
			int r = rand();
			r = r % 100;
			if (r < density)
			{
				// Ant
				initCell(life[i][k], Ant);
			}
			else
			{
				initCell(life[i][k], Empty);
			}
		}
}

// Return the number of adjacent Ants to the cell defined by col and row
int countNeighbors(int row, int col)
{
    int count=0;

	for (int i=-1; i<2; i++)
		for (int k=-1; k<2; k++)
			if (life[row+i][col+k].ctype == Ant)
				count++;

    //Return count-1 to account for self
	return count-1;
}

// Look for an adjacent Empty cell to create a baby Ant in.
// Also output a print line announcing the baby's birth
void makeBaby(int row, int col)
{
	for (int i=row-1; i<row+2; i++)
		for (int j=col-1; j<col+2; j++)
			if (life[i][j].ctype == Empty)
			{
				initCell(life[i][j], Ant);
				cout << "New ant created!" << endl;
				life[row][col].birth_count = 0;
				return;
			}
}
void processCell(Cell & cell, int row, int col)
{
    if (cell.ctype == Ant)
    {
		int count=0;
		count = countNeighbors(row, col);

		//Crowding code
		if (count >= TOO_MANY_NEIGHBORS)
			cell.crowding_count++;
		else
			cell.crowding_count = 0;

		if (cell.crowding_count == CROWDING_COUNT)
		{
			initCell(cell, Empty);
			cout << "Crowding death!" << endl;
		}

		//Isolation code
		if (count == 0)
			cell.isolation_count++;
		else
			cell.isolation_count = 0;

		if (cell.isolation_count == ISOLATION_COUNT)
		{
			initCell(cell, Empty);
			cout << "Isolation death!" << endl;
		}

		//New ant code
		cell.birth_count++;
		if (cell.birth_count == BIRTH_COUNT)
			if ((count>0) && (count<8))
			{
				makeBaby(row, col);
			}
		
        // For every Ant cell.  An Ant dies if the number of Ant
        // neighbors is >= TOO_MAN_NEIGHBORS for CROWDING_COUNT
        // times in a row.
        // An Ant dies if the number of Ant
        // neighbors is = 0 for ISOLATION_COUNT
        // times in a row.

        // After BIRTH_COUNT iterations, crate a baby Ant
        // if there is at least one adjacent Ant and an
        // Adjacent empty cell. 
    }
}
void nextIteration()
{
    displayLife();

	for (int i=1; i<NSIZE+1; i++)
		for (int j=1; j<NSIZE+1; j++)
			processCell(life[i][j], i, j);
}

void lifeGame(int density)
{
    init(density);
    char responseChar;
    do
    {
        nextIteration();
        cout << "To continue, enter a y: ";
        cin >> responseChar;
    } while (responseChar == 'y');
	
}

int main()
{
    bool continueFlag = true;
	do
    {
        int density;
        cout << "To play the game of life, enter an integer between 1 and 99: ";
        cin >> density;
        if (density > 0 && density <= 99)
            lifeGame(density);
        else
            continueFlag = false;
    } while (continueFlag);        

	return 0;
}
