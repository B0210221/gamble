#ifndef pF
#define pF

#include <iostream>
#include <ctime>
#include <algorithm>

class Poker{
private:
	int pCard[52];
public:
	Poker();
	void shuffle();
	int getCard(int);
	void print();
};
#endif

