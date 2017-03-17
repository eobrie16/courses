#include <iostream>
using namespace std;
#include "Life.h"

World theWorld;

Organism::Organism()
{
	isolation_count = 0;
	crowding_count = 0;
	birth_count = rand() % 8;
}



void Organism::makeBaby(int row, int col)
{
	int numEmpty = theWorld.countNeighbors(row, col, Empty);
    if (numEmpty > 0)
	{
		int retRow, retCol;
		if (theWorld.getNeighbor(row, col,  Empty, retRow, retCol))
		{
			Organism * org = getBaby();		
            cout << " Birth - row:" << retRow << " col:" << retCol << endl;
			theWorld.addOrganism(org, retRow, retCol);
		}
	}
                    
}

void Organism::processCell(int row, int col)
{
        // For every Ant cell.  An Ant dies if the number of Ant
        // neighbors is >= TOO_MAN_NEIGHBORS for CROWDING_COUNT
        // times in a row.
        // An Ant dies if the number of Ant
        // neighbors is = 0 for ISOLATION_COUNT
        // times in a row.

        // After BIRTH_COUNT iterations, crate a baby Ant
        // if there is at least one adjacent Ant and an
        // Adjacent empty cell. 


        int numNeighbors = theWorld.countNeighbors(row,col,getType());
        if (numNeighbors == 0)
            isolation_count += 1;
        else
            isolation_count = 0;

        if (numNeighbors >= getTOO_MANY_NEIGHBORS())
            crowding_count += 1;
        else
            crowding_count = 0;

        if (isolation_count >= getISOLATION_COUNT() ||
            crowding_count >= getCROWDING_COUNT())
        {
			theWorld.addOrganism(NULL, row, col);
            
            cout << "Death - row:"<< row << " col:"<< col << endl;
        }
        else
        {
            if (birth_count++ >=  getBIRTH_COUNT())
            {
                birth_count = 0;
                if (numNeighbors > 0)
                    makeBaby(row, col);
            }
        }
    
}


World::World()
{
}

void World::init(int density, double APredatorFraction)
{
	  // Fill in a Boundary cell in the first and last column,
    // and also in the first and last row of the life matrix of Cells
	for (int i =0; i < NSIZE+2; i++)
	{
		life[0][i] = new BoundaryOrg();//top row
		 
		life[NSIZE+1][i]= new BoundaryOrg(); // bottom row
		life[i][0] = new BoundaryOrg();       // left side
		life[i][NSIZE+1] = new BoundaryOrg(); // right side
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
				double r2 = rand() % 100;
				if (r2 < 100*APredatorFraction)
				{
					life[i][k] = new APredatorOrg();
				}
				else
					// Ant
					life[i][k] = new AntBug();
			}
			else
			{
				life[i][k] = NULL;
			}
		}
}



// Display current state of Life
void World::displayLife()
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
				Organism * org = life[i][j];
				if (org == NULL)
					cout << "  ";
                else if (org->getType() == Ant)
                    cout << " A";    
                else if (org->getType() == APredator)
                    cout << " p";                   
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

int World::countNeighbors(int row, int col,  CELL_TYPE ct)
{
    int count = 0;
    for (int i=row-1; i <= row+1; i++)
        for (int j=col-1; j <= col+1; j++)
        {
            if (i != row || j != col)
			{
				Organism * org = life[i][j];
				if (ct == Empty )
				{
					if (org == NULL) count += 1;
				}
				else
				{
					if (org != NULL)
						if (org->getType() == ct)
							count += 1;
				}
			}
        }
    return count;
}
bool World::getNeighbor(int row, int col,  CELL_TYPE ct, int & retRow, int & retCol)
{
    for (int i=row-1; i <= row+1; i++)
        for (int j=col-1; j <= col+1; j++)
        {
            if (i != row || j != col)
			{
				Organism * org = life[i][j];
				if (ct == Empty )
				{
					if (org == NULL)
					{
						retRow = i;
						retCol =j;
						return true;
					}
				}
				else
				{
					if (org != NULL)
						if (org->getType() == ct)
						{							
							retRow = i;
							retCol =j;
							return true;
						}				
				}
			}
        }
    return false;
}

void World::addOrganism(Organism * org, int row, int col)
{
	if (life[row][col] != NULL)
		delete life[row][col];
	life[row][col] = org;
}

void World::nextIteration()
{
    displayLife();

    // For every Ant, call processCell.
    for (int i=1; i < NSIZE+1; i++)
        for (int j=1; j < NSIZE+1; j++)
        {
			Organism * org = life[i][j];
			if (org != NULL)
				org->processCell(i,j);
        }
}

void World::lifeGame(int density)
{
    init(density, 0.25);
    char responseChar;
    do
    {
        nextIteration();
        cout << "To continue, enter a y: ";
        cin >> responseChar;
    } while (responseChar == 'y');
}

void APredatorOrg::processCell(int row, int col)
	{
		if (eatCount % 3 == 0)
		{
			// Look  for Ant and Eat
			int numAnts = theWorld.countNeighbors(row, col, Ant);
			if (numAnts > 0)
			{
				int retRow, retCol;
				if (theWorld.getNeighbor(row, col,  Ant, retRow, retCol))
				{		
					cout << "Eating Ant - row:" << retRow << " col:" << retCol << endl;
					theWorld.addOrganism(NULL, retRow, retCol);
					eatCount =1;
				}
			}


			if (eatCount >= 16)
			{
				// Starve
				theWorld.addOrganism(NULL, row, col);            
				cout << "Starving Death - row:"<< row << " col:"<< col << endl;
				return;
			}
		}
		eatCount += 1;
		Organism::processCell(row, col);
	}