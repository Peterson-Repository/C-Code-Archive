#include <iostream>
#include "Snake.h"
#include "Board.h"
using namespace std;

Snake::Snake(Board& b) {
	myBoard = b;
	length = 5;
	current_direction = LEFT;
	for (int i = 0; i < length; i++) {
		x_coords[i] = myBoard.getWidth()/2+i;
		y_coords[i] = myBoard.getHeight()/2;
	}
}

void Snake::moveForward() {
  for (int s = length-1; s > 0; s--) {
    x_coords[s] = x_coords[s-1];
    y_coords[s] = y_coords[s-1];
  }
  if (current_direction == LEFT) {
    x_coords[0] = x_coords[0]-1;
    y_coords[0] = y_coords[0];
  }
  else if (current_direction == RIGHT) {
    x_coords[0] = x_coords[0]+1;
    y_coords[0] = y_coords[0];
  }
  else if (current_direction == UP) {
    x_coords[0] = x_coords[0];
    y_coords[0] = y_coords[0]-1;
  }
  else {
    x_coords[0] = x_coords[0];
    y_coords[0] = y_coords[0]+1;
  }
}

void Snake::grow() {
	if (length < MAX_LENGTH) {
		length++;
	}
}

bool Snake::crashed() {
	// Test if the snake has run into itself.
	for (int s = 1; s < length; s++) {
		if (x_coords[0] == x_coords[s] && 
			y_coords[0] == y_coords[s])
		return true;
	}
	// Test if the snake runs into the border
	if (x_coords[0] == 0 || x_coords[0] == myBoard.getWidth() ||
		y_coords[0] == 0 || y_coords[0] == myBoard.getHeight()) {
		return true;
	}
	return false;
}

void Snake::setDirection(direction d) {
	if (d == UP && current_direction != DOWN) {
		current_direction = d;
	}
	else if (d == DOWN && current_direction != UP) {
		current_direction = d;
	}
	else if (d == LEFT && current_direction != RIGHT) {
		current_direction = d;
	}
	else if (d == RIGHT && current_direction != LEFT) {
		current_direction = d;
	}
}

void Snake::draw(HANDLE screen) {
	COORD pos;
	for (int s = length-1; s > 0; s--) {
		pos.X = x_coords[s];
		pos.Y = y_coords[s];
		SetConsoleCursorPosition(screen, pos);
		cout << SNAKE_SEGMENT;
	}
	pos.X = x_coords[0];
	pos.Y = y_coords[0];
	SetConsoleCursorPosition(screen, pos);
	cout << SNAKE_HEAD;
	pos.X = x_coords[length-1];
	pos.Y = y_coords[length-1];
	SetConsoleCursorPosition(screen, pos);
	cout << ' ';
}

