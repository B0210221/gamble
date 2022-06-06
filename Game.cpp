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
	cout << "���״��ɡI(���\�����y��֡A���Ѫ��g�@�W�[)" << endl;
}
void Game::printDoor() const {
	cout << "�e��i�P���O�O�G " << door[0] << " , " << door[1] << endl;
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
	cout << "�o���C���O�g�s���A�п�J�U�`�I��" << endl;
	cout << "(��e�I�ơG"<< getPoint() <<"�A���\ + " << plusRate << "�� / ���� - "<<decRate<<"��)�G";
	inputBet();
	cout << "----------" << endl;
	cout << "�U�@�i�P�O�G" << ball << endl;
	if ((ball == door[0]) || (ball == door[1])) {
		cout << "�A���W�F�I�ߤF" << decRate << "*2���U�`���I��" << endl;
		dec();
		dec();
	}
	else if ((ball > door[0]) && (ball < door[1])) {
		cout << "�A���\�F�A��o" << plusRate << "���U�`���I��" << endl;
		plus();
	}
	else {
		cout << "�A���ѤF�A�ߤF" << decRate << "���U�`���I��" << endl;
		dec();
	}
	cout << "�A�{�b�����ƬO�G" << getPoint() << endl;
}
void Game::gamePhase2() {
	int b;
	int choice;
	cout << "�o���C���O��j�p�A�п�J�U�`�I��" << endl;
	cout << "(��e�I�ơG" << getPoint() << "�A���\ + " << plusRate << "�� / ���� - " << decRate << "��)�G";
	inputBet();
	cout << "�A����q�U�@�i�P�O�j�٬O�p�O�H(�п�J�p:0 / �j:1)�G";
	cin >> choice;
	while (choice > 1) { //for error
		cout << "(�п�J�p:0 / �j:1)�G";
		cin >> choice;
	}
	cout << "----------" << endl;
	cout << "�U�@�i�P�O�G" << ball << endl;
	if ((ball == door[0])) {
		cout << "�A���W�F�I�ߤF" << decRate << "*3���U�`���I��" << endl;
		dec();
		dec();
		dec();
	}
	else {
		if ((ball < door[0]) && (choice == false)) {
			cout << "�A���\�F�A��o" << plusRate << "���U�`���I��" << endl;
			plus();
		}
		else if ((ball > door[0]) && (choice == true)) {
			cout << "�A���\�F�A��o" << plusRate << "���U�`���I��" << endl;
			plus();
		}
		else {
			cout << "�A���ѤF�A�ߤF" << decRate << "���U�`���I��" << endl;
			dec();
		}
	}
	cout << "�A�{�b�����ƬO�G" << getPoint() << endl;
}