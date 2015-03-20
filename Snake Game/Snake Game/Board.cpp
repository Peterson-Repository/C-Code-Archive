#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
	width = 80;
	height = 24;
}

void Board::draw(HANDLE screen) {
	COORD pos = {40,3};
	for (int x = 0; x < width; x++) {
		pos.X = x;
		pos.Y = 0;
		SetConsoleCursorPosition(screen, pos);
		cout << 'X';
		pos.Y = height-1;
		SetConsoleCursorPosition(screen, pos);
		cout << 'X';
	}
	for (int y = 0; y < height; y++) {
		pos.X = 0;
		pos.Y = y;
		SetConsoleCursorPosition(screen, pos);
		cout << 'X';
		pos.X = width-1;
		SetConsoleCursorPosition(screen, pos);
		cout << 'X';
	}
}

int Board::getWidth() {
	return width;
}

int Board::getHeight() {
	return height;
}