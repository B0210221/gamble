#ifndef gF
#define gF
#include "Point.h"
#include "Poker.h"

class Game : public Point{
private:
	int door[2];
	int ball;
	Poker card;
public:
	Game();
	void setCard(Poker);
	int getDoor(int) const;
	void diffChange();
	void printDoor() const;
	void gameBegin();
	void gamePhase1();
	void gamePhase2();
};

#endif