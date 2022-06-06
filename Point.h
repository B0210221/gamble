#ifndef poF
#define poF

#include <iostream>

class Point{
private:
	int ownPoint;
protected:
	int bet;
	double plusRate;
	double decRate;
public:
	Point();
	Point(int);
	int getPoint() const;
	void setPoint(int);
	void inputBet(); //new
	void plus();
	void dec();
};

#endif