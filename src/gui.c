/* 
	Define gui functions

*/

#include "gui.h"

WINDOW *view;
WINDOW *console;
WINDOW *inventory;

//TODO: add in mouseover console info? 

//Initialize all windows in their proper spots

WINDOW *create_newwin(int height, int width, int starty, int startx) {
	WINDOW *local_win;
	
	local_win = newwin(height,width, starty, startx);
	box(local_win,0,0);
	//wborder(local_win,'|','|','-','-','+','+','+','+');
	wrefresh(local_win);
	
	return local_win;
}

void screen_init() {
	view = create_newwin(18,60,4,0);
	console =  create_newwin(8,60,22,0);
	inventory = create_newwin(26,20,4,60);
}


//TODO: add vim like commands for scrolling through the console and the invent.
int get_input() {

	int quit = 0;	
	int ch = getch();
	switch(ch) {
		case KEY_LEFT:
			
			break;
		case KEY_RIGHT:

			break;
		case KEY_UP:

			break;
		case KEY_DOWN:

			break;
		case 'q':
			quit = 1;
			break;
	}
	
	return quit;
}
 
void draw() {

}
