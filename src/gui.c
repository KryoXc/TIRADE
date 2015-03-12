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
} ACTOR;

typedef struct {
	char *name;
	int x;
	int y;	
} ITEM;
//initialize player data ------------------------------------------------------
ACTOR player = {2,2,10};

ITEM key={"KEY",15, 10};
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
			if(player.x > 1) {
				--player.x;
			}	
			break;

		case KEY_RIGHT:
			if(player.x < 58) {
				++player.x;
			}	
			break;

		case KEY_UP:
			if(player.y > 1) {
				--player.y;
			}	
			break;

		case KEY_DOWN:
			if(player.y < 16) {
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
	// 

	// viewport draw
	werase(view);
	box(view,0,0);
	mvwprintw(view, key.y, key.x, "q");
	mvwprintw(view, player.y, player.x,"i");
	wrefresh(view);

	// console draw
	if(player.x == 15 && player.y == 10) {
		mvwprintw(console, 1, 2, "you found a %s.\n", key.name);
		werase(view);	
		box(console, 0, 0);
		wrefresh(console);			
	}
	// inventory draw

}
