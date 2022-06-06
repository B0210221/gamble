#include "Game.h"
using namespace std;

Game::Game() : Point(){
	door[0] = 0;
	door[1] = 0;
	ball = 0;
}
void Game::setCard(Poker c) {
	card = c;
}
int Game::getDoor(int idx) const {
	return door[idx];
}
void Game::diffChange() {
	plusRate = plusRate - 0.3;
	decRate = decRate + 0.3;
	cout << "難度提升！(成功的獎勵減少，失敗的懲罰增加)" << endl;
}
void Game::printDoor() const {
	cout << "前兩張牌分別是： " << door[0] << " , " << door[1] << endl;
}
void Game::gameBegin() {
	do {
		card.shuffle();
		door[0] = card.getCard(0);
		door[1] = card.getCard(1);
		ball = card.getCard(2);
		if (door[1] < door[0]) {
		int buf = door[1];
		door[1] = door[0];
		door[0] = buf;
		}
	} while (door[0]+1 == door[1]); //debug
	printDoor();
}
void Game::gamePhase1() {
	int b;
	cout << "這局遊戲是射龍門，請輸入下注點數" << endl;
	cout << "(當前點數："<< getPoint() <<"，成功 + " << plusRate << "倍 / 失敗 - "<<decRate<<"倍)：";
	inputBet();
	cout << "----------" << endl;
	cout << "下一張牌是：" << ball << endl;
	if ((ball == door[0]) || (ball == door[1])) {
		cout << "你撞柱了！賠了" << decRate << "*2倍下注的點數" << endl;
		dec();
		dec();
	}
	else if ((ball > door[0]) && (ball < door[1])) {
		cout << "你成功了，獲得" << plusRate << "倍下注的點數" << endl;
		plus();
	}
	else {
		cout << "你失敗了，賠了" << decRate << "倍下注的點數" << endl;
		dec();
	}
	cout << "你現在的分數是：" << getPoint() << endl;
}
void Game::gamePhase2() {
	int b;
	int choice;
	cout << "這局遊戲是比大小，請輸入下注點數" << endl;
	cout << "(當前點數：" << getPoint() << "，成功 + " << plusRate << "倍 / 失敗 - " << decRate << "倍)：";
	inputBet();
	cout << "你打算猜下一張牌是大還是小呢？(請輸入小:0 / 大:1)：";
	cin >> choice;
	while (choice > 1) { //for error
		cout << "(請輸入小:0 / 大:1)：";
		cin >> choice;
	}
	cout << "----------" << endl;
	cout << "下一張牌是：" << ball << endl;
	if ((ball == door[0])) {
		cout << "你撞柱了！賠了" << decRate << "*3倍下注的點數" << endl;
		dec();
		dec();
		dec();
	}
	else {
		if ((ball < door[0]) && (choice == false)) {
			cout << "你成功了，獲得" << plusRate << "倍下注的點數" << endl;
			plus();
		}
		else if ((ball > door[0]) && (choice == true)) {
			cout << "你成功了，獲得" << plusRate << "倍下注的點數" << endl;
			plus();
		}
		else {
			cout << "你失敗了，賠了" << decRate << "倍下注的點數" << endl;
			dec();
		}
	}
	cout << "你現在的分數是：" << getPoint() << endl;
}