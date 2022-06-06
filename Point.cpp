#include "Point.h"
using namespace std;

Point::Point() {
	ownPoint = 100;
	plusRate = 1;
	decRate = 1;
}
Point::Point(int op) {
	ownPoint = op;
	plusRate = 1;
	decRate = 1;
}
int Point::getPoint() const {
	return ownPoint;
}
void Point::setPoint(int op) {
	ownPoint = op;
}
void Point::inputBet() {
	int b;
	cin >> b;
	if (b < 10) {
		cout << "下注點數不能小於10點哦！請重新輸入:";
		inputBet();
	}
	else if (b > ownPoint) {
		cout << "你只有 " << ownPoint<< " 點哦！請重新輸入:";
		inputBet();
	}
	else {
		bet = b;
	}
}
void Point::plus() {
	ownPoint = ownPoint + bet * plusRate;
}
void Point::dec() {
	ownPoint = ownPoint - bet * decRate;
}
