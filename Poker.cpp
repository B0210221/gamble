#include "Poker.h"
using namespace std;

Poker::Poker() {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 4; j++) {
			pCard[i+j*13] = i+1;
		}
	}
}
void Poker::shuffle() {
	//srand(time(0)); in main
	random_shuffle(pCard,pCard+52);
}
int Poker::getCard(int idx) {
	return pCard[idx];
}
void Poker::print() {
	for (int i = 0; i < 52; i++) {
		cout << pCard[i] << " ";
	}
	cout << endl;
}
