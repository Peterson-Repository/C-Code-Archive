#ifndef BOARD_H
#define BOARD_H

#include <windows.h>

class Board {
private:
	int width;
	int height;
public:
	Board();
	void draw(HANDLE screen);
	int getWidth();
	int getHeight();
};

#endif