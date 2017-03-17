class Card
{
private:
	int suite;
	int number;
public:
	Card(int n=0, int s=0);
	void setCard(int s, int n);
	void show();
	// true if this card >= c
	bool greaterThan(Card &c);
};

class Deck
{
private:
	Card * m_deck;
	int max_cards;
	int curr_card;
public:
	Deck(int num=52);
	~Deck();
	void shuffle();
	Card nextCard();
};
class Hand
{
private:
	Card * m_hand;
	int max_cards;
public:
	Hand(int num);
	~Hand();
	void Deal(Deck & d);
	void sort();
	void show();
};