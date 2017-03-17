#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

const int NUM_WEEKS=17;

struct Player
{
	string name;
	string team;
	float  avg;
	float weekly[NUM_WEEKS];
};

Player players[100];
int num_players = 0;

void publish()
{
	for (int i=0; i < num_players; i++)
	{
		cout << players[i].name << " " << players[i].team << " " << players[i].avg ;
		for (int k=0; k <NUM_WEEKS ; k++)
			cout << " " << players[i].weekly[k];
		cout << endl;
	}
}

void getName(char buff[], int & index, string & name)
{
	int count =0;
	int len = strlen(buff);
	while(index < len)
	{
		if (buff[index] == '"')
		{
			count += 1;
			if (count == 3)
			{
				index += 1;
				while (buff[index] != '(')
				{
					name += buff[index];
					index +=1;
				}
				return;

			}
		}
		index += 1;
	}
}
void getTeam(char buff[], int & index, string & team)
{
  // Assume index is point to '('
	index +=1;
	while (buff[index] != ')')
	{
		team += buff[index];
		index +=1;
	}
	index += 1; // index should be looking at a comma
}
void getNum(char buff[], int & index, float & num)
{
	char numBuff[100];
	int count=0;
	index += 1;
	while(buff[index] != ',' && buff[index] != '"')
	{
		numBuff[count] = buff[index];
		count += 1;
		index += 1;
	}
	numBuff[count]=0;
	num = (float)atof(numBuff);
}

void parse(char buff[])
{
	int index= 0;

	getName(buff, index, players[num_players].name);
	getTeam(buff, index, players[num_players].team);
	getNum(buff, index, players[num_players].avg);
	for (int i=0; i < NUM_WEEKS; i++)
		getNum(buff, index, players[num_players].weekly[i]);

	num_players += 1;

}


void process_file(char file_name[])
{
	ifstream file(file_name);
	char buffer[1000];
	
	while(file)
	{
		file.getline(buffer, sizeof(buffer));
		if (file)
		{
			// Successful Read
			parse(buffer);
		}
	}
}

int main()
{
	process_file("football.txt");
	publish();
}
