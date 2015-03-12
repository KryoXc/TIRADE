/* 
	Define gui functions

*/

#include "gui.h"

WINDOW *view;
WINDOW *console;
WINDOW *inventory;

//player struct info does not belong here
typedef struct {
	int x;
	int y;
	int hp;
} PLAYER;

//initialize player data ------------------------------------------------------
PLAYER player = {2,2,10};

/*
player.x = 2;
player.y = 2;
player.hp = 10;
*/

//-----------------------------------------------------------------------------

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
			if(player.x > 0) {
				--player.x ;
			}	
			break;

		case KEY_RIGHT:
			if(player.x < 60) {
				++player.x;
			}	
			break;

		case KEY_UP:
			if(player.y > 0) {
				--player.y;
			}	
			break;

		case KEY_DOWN:
			if(player.x < 18) {
				++player.y;
			}	
			break;

		case 'q':
			quit = 1;
			break;
	}
	
	return quit;
}
void draw() {
	mvwprintw(view, player.y, player.x,"i");
	wrefresh(view);
}
