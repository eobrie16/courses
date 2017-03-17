#include <iostream>
using namespace std;

enum SUIT {clubs, diamonds, hearts, spades};
enum CARD_NUM {two=2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

struct CARD 
{
	SUIT suit;
	CARD_NUM card_num;
};

CARD deck[52];

int main()
{
	for (int i= 0; i < 4; i++)
	{
		SUIT s;
		switch (i)
		{
		case 0:
			s = clubs;
			break;
		case 1:
			s = diamonds;
			break;
		case 2:
			s = hearts;
			break;
		case 3:
			s = spades;
			break;
		}
		for (int k=0; k < 13; k++)
		{
			CARD_NUM c ;
			switch (k)
			{
			case 0:
				c = two;
				break;
			case 1:
				c=three;
				break;
			case 2:
				c=four;
				break;
			case 3:
				c = five;
				break;
			case 4:
				c = six;
				break;
			case 5:
				c = seven;
				break;
			case 6:
				c = eight;
				break;
			case 7:
				c = nine;
				break;
			case 8:
				c = ten;
				break;
			case 9:
				c = jack;
				break;
			case 10:
				c = queen;
				break;
			case 11:
				c = king;
				break;
			case 12:
				c = ace;
				break;
			}
			deck[13*i + k].suit =s;
			deck[13*i + k].card_num =c;
		}
	}


	return 0;
}