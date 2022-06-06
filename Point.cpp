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
		cout << "�U�`�I�Ƥ���p��10�I�@�I�Э��s��J:";
		inputBet();
	}
	else if (b > ownPoint) {
		cout << "�A�u�� " << ownPoint<< " �I�@�I�Э��s��J:";
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
