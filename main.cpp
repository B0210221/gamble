//#include "Poker.h"
#include "Game.h"
using namespace std;

int main() {
	Poker p;
	Game game;
	int i;
	srand(time(0));
	for (i = 0; i < 10; i++) {
		cout << "====第 " << i+1 << " 回合====" << endl;
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
	cout << "====遊戲結束====" << endl;
	cout << "你玩了" << i << "回合，最終擁有 " << game.getPoint() << " 點" << endl;
}