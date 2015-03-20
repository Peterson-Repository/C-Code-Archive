#ifndef SNAKE_H
#define SNAKE_H

#include "Board.h"

const char SNAKE_HEAD    = '*' ;
const char SNAKE_SEGMENT = '+' ;
const int START_LENGTH   = 5;
const int MAX_LENGTH     = 150;
enum direction {UP, DOWN, LEFT, RIGHT};

class Snake {
private:
	int length;
	int x_coords[MAX_LENGTH];
	int y_coords[MAX_LENGTH];
	direction current_direction;
	Board myBoard;

public:
	Snake(Board& b);
	void moveForward();
	void grow();
	bool crashed();
	void setDirection(direction d);
	void draw(HANDLE screen);
};

#endif