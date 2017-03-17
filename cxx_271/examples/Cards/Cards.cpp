#include <iostream>
using namespace std;
#include "Cards.h"
char * suites[] = {"clubs", "diamonds", "hearts", "spades"};
char * numbers[] ={"two", "three", "four", "five", "six", "seven",
"eight", "nine", "ten", "jack", "queen", "king", "ace"};

const int num_suites = 4;
const int num_numbers = 13;

Card::Card(int n, int s): suite(s), number(n)
{
}
void Card::setCard(int s, int n)
{
	suite = s;
	number =n;
}
void Card::show()
{
	cout << numbers[number] << " of " << suites[suite];
}
bool Card::greaterThan(Card &c)
{
	if (suite > c.suite) return true;
	if (suite == c.suite)
		if (number >= c.number)return true;
	return false;
}

Deck::Deck(int num)
{
	max_cards = num;
	curr_card =0;
	m_deck = new Card[num];
	for (int i=0; i < num_suites; i++)
		for (int j=0; j < num_numbers; j++)
			m_deck[j+i*num_numbers].setCard(i,j);

}
Deck::~Deck()
{
	delete [] m_deck;
}

Card Deck::nextCard()
	{
		if (curr_card >= max_cards)
		{
			cout << " Card Deck Exhausted ... aborting" << endl;
			exit(-1);
		}
		Card toReturn = m_deck[curr_card];
		curr_card += 1;
		return toReturn;
	}
void Deck::shuffle()
{

}

Hand::Hand(int num)
{
	max_cards = num;
	m_hand = new Card[num];
}
Hand::~Hand()
{
	delete[] m_hand;
}
void Hand::Deal(Deck & d)
{
	for (int i=0; i < max_cards; i++)
		m_hand[i] = d.nextCard();
}
void Hand::sort()
{

}

void Hand::show()
{
	for (int i=0; i < max_cards; i++)
	{
		m_hand[i].show();
		cout << "  ";
	}
}
