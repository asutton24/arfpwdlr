#ifndef LEVEL_H
#define LEVEL_H

typedef struct {
	int start_x;
	int start_y;
	int len_x;
	int len_y;
	int active;
} room_t;

typedef room_t* level_t;

int init_room(room_t* r, int sx, int sy, int lx, int ly);
int am_i_in_room(room_t r, int x, int y);
int what_room_am_i_in(level_t l, int count, int x, int y );
int draw_room(char* screen, room_t r);
#endif
