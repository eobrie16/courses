enum CELL_TYPE { Boundary, Ant, Empty, APredator, PPredator};


class Organism
{
private:
	CELL_TYPE ctype;
	int isolation_count;
	int crowding_count;
	int birth_count;

public:
	Organism();
	virtual CELL_TYPE getType()=0;
	// An Ant who has no neighbors for the following number of iterations, will die
	virtual int getISOLATION_COUNT()=0;
	// An Ant who has TOO_MANY_NEIGHBORS for CROWDING_COUNT iterations, will die
	virtual int getTOO_MANY_NEIGHBORS()=0;
	virtual int getCROWDING_COUNT()=0;
	virtual Organism * getBaby()=0;

	// After BIRTH_COUNT iterations, a birth will be attempted if there is a 
// neighboring Ant and there is an adjacent Empty cell
	virtual int getBIRTH_COUNT()=0;

	void makeBaby(int row, int col);
	virtual void processCell(int row, int col);

};


class AntBug : public Organism
{
public:
	CELL_TYPE getType()
	{
		return Ant;
	}
	// An Ant who has no neighbors for the following number of iterations, will die
	int getISOLATION_COUNT()
	{
		return 10;
	}
	// An Ant who has TOO_MANY_NEIGHBORS for CROWDING_COUNT iterations, will die
	int getTOO_MANY_NEIGHBORS()
	{
		return 4;
	}
	int getCROWDING_COUNT()
	{
		return 2;
	}
	int getBIRTH_COUNT()
	{
		return 15;
	}
	Organism * getBaby()
	{
		cout <<"Ant born: ";
		return new AntBug();
	}
};

class APredatorOrg : public Organism
{
	int eatCount;

public:
	APredatorOrg()
	{
		eatCount=rand()%9;
	}
	void processCell(int row, int col);

	CELL_TYPE getType()
	{
		return APredator;
	}
	// An Ant who has no neighbors for the following number of iterations, will die
	int getISOLATION_COUNT()
	{
		return 20;
	}
	// An Ant who has TOO_MANY_NEIGHBORS for CROWDING_COUNT iterations, will die
	int getTOO_MANY_NEIGHBORS()
	{
		return 4;
	}
	int getCROWDING_COUNT()
	{
		return 2;
	}
	int getBIRTH_COUNT()
	{
		return 15;
	}
	Organism * getBaby()
	{
		cout <<"APredator born: ";
		return new APredatorOrg();
	}
};
class BoundaryOrg : public Organism
{
public:
	CELL_TYPE getType()
	{
		return Boundary;
	}
	// An Ant who has no neighbors for the following number of iterations, will die
	int getISOLATION_COUNT()
	{
		return 10;
	}
	// An Ant who has TOO_MANY_NEIGHBORS for CROWDING_COUNT iterations, will die
	int getTOO_MANY_NEIGHBORS()
	{
		return 4;
	}
	int getCROWDING_COUNT()
	{
		return 2;
	}
	int getBIRTH_COUNT()
	{
		return 15;
	}
	Organism * getBaby()
	{
		return new BoundaryOrg();
	}
};


const int NSIZE = 10;

class World
{
private:	
	Organism * life[NSIZE+2][NSIZE+2];

public:
	World();
	void displayLife();
	void init(int density, double APredatorFraction);
	int countNeighbors(int row, int col, CELL_TYPE ct);
	bool getNeighbor(int row, int col,  CELL_TYPE ct, int & retRow, int & retCol);
	void nextIteration();
	void lifeGame(int density);
	void addOrganism(Organism * org, int row, int col);

};
