#include <iostream>
#include <windows.h>
#include "Snake.h"
#include "Board.h"
using namespace std;

int main() {
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	// TODO: Write the code to declare an instance of the Board class

Board b1;

	// TODO: Write the code to declare an instance of the Snake class

Snake s1(b1);

	int time = 0;
	while (!s1.crashed()) {
		if (GetAsyncKeyState(VK_UP) & 0x7FFF) {
			// TODO: Set the direction of your snake to UP.
s1.setDirection(UP);

		}		
		else if (GetAsyncKeyState(VK_DOWN) & 0x7FFF) {
			// TODO: Set the direction of your snake to DOWN.
s1.setDirection(DOWN);
		}

		else if (GetAsyncKeyState(VK_LEFT) & 0x7FFF) {
			// TODO: Set the direction of your snake to LEFT.
s1.setDirection(LEFT);
		}

		else if (GetAsyncKeyState(VK_RIGHT) & 0x7FFF) {
			// TODO: Set the direction of your snake to RIGHT.
s1.setDirection(RIGHT);

	    }
		else if (GetAsyncKeyState(0x51) & 0x7FFF) { 
			break;
		}

		time++;
		if (time%10 == 0) {
		// TODO: Make your snake grow.
		s1.grow();
		}
		// TODO: Make your snake move forward.
		s1.moveForward();

		// TODO: Draw your snake to the screen.
		s1.draw(screen);
		// TODO: Draw the board to the screen.
		b1.draw(screen);


		Sleep(120);
  }
	return 0;
}