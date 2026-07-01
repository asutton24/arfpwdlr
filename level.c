#include "level.h"
#include <stdlib.h>

int init_room(room_t* r, int sx, int sy, int lx, int ly){
	r->start_x = sx;
	r->start_y = sy;
	r->len_x = lx;
	r->len_y = ly;
	r->active = 0;
	return 0;
}

int am_i_in_room(room_t r, int x, int y){
	return x >= r.start_x && x < r.start_x + r.len_x && y >= r.start_y && y < r.start_y + r.len_y;
}

int what_room_am_i_in(level_t l, int count, int x, int y ){
	for (int i = 0; i < count; i++){
		if (am_i_in_room(l[i], x, y)) return i;
	}
	return -1;
}

int draw_room(char* screen, room_t r){
	for (int i = r.start_x; i < r.start_x + r.len_x; i++){
		if (i == r.start_x + r.len_x / 2) screen[80 * r.start_y + i] = '*'; 
		else screen[80 * r.start_y + i] = '#'; 
	}
	for (int i = r.start_y + 1; i < r.start_y + r.len_y - 1; i++){
		if (i == r.start_y + r.len_y / 2){
			screen[80 * i] = '*';
			screen[80 * i + r.len_x - 1] = '*';
		} else {
			screen[80 * i] = '#';
			screen[80 * i + r.len_x - 1] = '#';
		}
		for (int j = r.start_x + 1; j < r.start_x + r.len_x - 1 && r.active; j++){
			screen[80 * i + j] = '.';
		}
	}
	for (int i = r.start_x; i < r.start_x + r.len_x; i++){
		if (i == r.start_x + r.len_x / 2) screen[80 * (r.start_y + r.len_y - 1) + i] = '*'; 
		else screen[80 * (r.start_y + r.len_y - 1) + i] = '#'; 
	}
	return 0;
}
