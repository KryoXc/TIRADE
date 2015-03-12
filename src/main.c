/*
 * game to explore socket level programming
 * Diego Morales 3/12/2015
 *
*/

#include <stdio.h>
#include "map.h"
#include "gui.h"


int main(void) {

	int quit = 0;
	initscr();

	// Initialize the use of the arrow keys in the keypad
	keypad(stdscr, TRUE);
	noecho(); //won't echo key presses on getch() call
	cbreak();
	raw(); // line buffering disabled
	nodelay(stdscr,TRUE);

	printw("Welcome to game.");
	refresh();

	screen_init();

	while(quit == 0) {
		quit = get_input();		
		draw();
		refresh();
	}
	endwin();
	
	return 0;
}
