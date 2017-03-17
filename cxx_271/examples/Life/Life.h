enum CELL_TYPE { Boundary, Ant, Empty};


class Organism
{
private:
	CELL_TYPE ctype;
	int isolation_count;
	int crowding_count;
	int birth_count;

	// An Ant who has no neighbors for the following number of iterations, will die
	static int ISOLATION_COUNT;
// An Ant who has TOO_MANY_NEIGHBORS for CROWDING_COUNT iterations, will die 
	static int TOO_MANY_NEIGHBORS ;
	static int CROWDING_COUNT ;

// After BIRTH_COUNT iterations, a birth will be attempted if there is a 
// neighboring Ant and there is an adjacent Empty cell
	static int BIRTH_COUNT;

public:
	CELL_TYPE getType();
	Organism(CELL_TYPE c);
	void makeBaby(int row, int col);
	void processCell(int row, int col);

};

const int NSIZE = 10;

class World
{
private:	
	Organism * life[NSIZE+2][NSIZE+2];

public:
	World();
	void displayLife();
	void init(int density);
	int countNeighbors(int row, int col, CELL_TYPE ct);
	bool getNeighbor(int row, int col,  CELL_TYPE ct, int & retRow, int & retCol);
	void nextIteration();
	void lifeGame(int density);
	void addOrganism(Organism * org, int row, int col);

};
