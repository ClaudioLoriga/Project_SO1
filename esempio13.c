#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

char sprite1[5]={"[-|-]"};
int main() {
	int maxy = 0, maxx = 0, newx = 0, direzionex = 1, direzioney = 1;
	initscr();
	noecho();
	curs_set(false);
	
	getmaxyx(stdscr, maxy, maxx); 
	int dimsprite = sizeof(sprite1);
	int x = (maxx/2)-(dimsprite/2), y = (maxy/2); 
	
	while(true) {
		clear();
		
		x += (1 * direzionex);
		y += (1 * direzioney);
		
		mvprintw(y, x, sprite1);
		if(x >= (maxx-dimsprite) || x <= 0) direzionex *=-1;
		if(y >= maxy || y <= 0) direzioney *=-1;
		refresh();
		usleep(50000);
		timeout(1);
		if(getch() == 113) break;
		endwin();
		}
	}
