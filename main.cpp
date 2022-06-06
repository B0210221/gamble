//#include "Poker.h"
#include "Game.h"
using namespace std;

int main() {
	Poker p;
	Game game;
	int i;
	srand(time(0));
	for (i = 0; i < 10; i++) {
		cout << "====�� " << i+1 << " �^�X====" << endl;
		switch (i){
		case 3:
		case 6:
		case 9:
			game.diffChange();
		}
		game.gameBegin();
		if (game.getDoor(0) != game.getDoor(1)) game.gamePhase1();
		else game.gamePhase2();
		
		if (game.getPoint() < 10) { 
			i++;
			break; 
		}
	}
	cout << "====�C������====" << endl;
	cout << "�A���F" << i << "�^�X�A�̲׾֦� " << game.getPoint() << " �I" << endl;
}