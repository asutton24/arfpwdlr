#include <ncurses.h>
#include "terminal.h"

int terminal_init(void){
	initscr();
	raw();
	scrollok(stdscr, FALSE);
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
}

int terminal_draw(char* screen){
	clear();
	int row, col, bx, by;
	getmaxyx(stdscr, row, col);
	if (row < 30 || col < 80){
		move(0, 0);
		printw("Terminal must be 80 by 30!");
		refresh();
		return 1;
	}
	by = row / 2 - 16;
	bx = col / 2 - 41;
	if (bx == -1 || by == -1) goto SKIP_BORDER;
	attron(A_REVERSE);
	move(by, bx);
	for (int i = 0; i < 82; i++){
		printw(" ");
	}
	for (int i = 1; i < 31; i++){
		move(by + i, bx);
		printw(" ");
		move(by + i, bx + 81);
		printw(" ");
	}
	move(by + 31, bx);
	for (int i = 0; i < 82; i++){
		printw(" ");
	}
	attroff(A_REVERSE);
SKIP_BORDER:
	bx++;
	by++;
	for (int y = 0; y < 30; y++){
		move(by + y, bx);
		for (int x = 0; x < 80; x++){
			if (screen[80 * y + x]) printw("%c", screen[80 * y + x]);
		}
	}
	return 0;
}

int terminal_update(char* screen){
	int status = terminal_draw(screen);
	while (status == 1){
		getch();
		status = terminal_draw(screen);
	}
	return getch();
}

int terminal_end(void){
	endwin();
}

