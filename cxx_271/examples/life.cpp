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
int ISOLATION_COUNT = 5;
int CROWDING_COUNT = 4;
int BIRTH_COUNT=3;

Cell life[NSIZE+2][NSIZE+2];

void initCell(Cell & c, CELL_TYPE ctype, int icount, int ccount, int bcount)
{
	c.ctype = ctype;
	c.isolation_count = icount;
	c.crowding_count = ccount;
	c.birth_count = bcount;
}


void init(int density)
{
	for (int i =0; i < NSIZE+2; i++)
	{
		initCell(life[0][i], Boundary, 0, 0, 0);
		initCell(life[NSIZE+1][i], Boundary, 0, 0, 0);
		initCell(life[i][0], Boundary, 0, 0, 0);
		initCell(life[i][NSIZE+1], Boundary, 0, 0, 0);
	}

	for (int i=1; i <= NSIZE ; i++)
		for (int k= 1; k <= NSIZE; k++)
		{
			int r = rand();
			r = r % 100;
			if (r < density)
			{
				// Ant
				initCell(life[i][k], Ant, 0, 0, 0);
			}
			else
			{
				initCell(life[i][k], Empty, 0, 0, 0);
			}
		}
	

}

int main()
{
	init(50);

	return 0;
}