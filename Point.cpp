#include "Point.h"
Point::Point() {
	ownPoint = 100;
	plusRate = 1;
	decRate = 1;
}
Point::Point(int op) {
	ownPoint = op;
}
int Point::getPoint() const {
	return ownPoint;
}
void Point::setPoint(int op) {
	ownPoint = op;
}
void Point::plus() {
	ownPoint = ownPoint + bet*plusRate;
}
void Point::dec() {
	ownPoint = ownPoint - bet*decRate;
}