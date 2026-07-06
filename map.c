#include "map.h"
#include <stdlib.h>

static int rectangle_collide(int r1x, int r1y, int r1w, int r1h, int r2x, int r2y, int r2w, int r2h){
	return r1x + r1w >= r2x &&
		   r1x <= r2x + r2w &&
		   r1y + r1h >= r2y &&
		   r1y <= r2y + r2h;
}

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

int what_room_am_i_in(map_t m, int count, int x, int y ){
	for (int i = 0; i < count; i++){
		if (am_i_in_room(m[i], x, y)) return i;
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
			screen[80 * i + r.start_x] = '*';
			screen[80 * i + r.start_x + r.len_x - 1] = '*';
		} else {
			screen[80 * i + r.start_x] = '#';
			screen[80 * i + r.start_x + r.len_x - 1] = '#';
		}
		for (int j = r.start_x + 1; j < r.start_x + r.len_x - 1; j++){
			if (r.active) screen[80 * i + j] = '.';
			else screen[80 * i + j] = ' ';
		}
	}
	for (int i = r.start_x; i < r.start_x + r.len_x; i++){
		if (i == r.start_x + r.len_x / 2) screen[80 * (r.start_y + r.len_y - 1) + i] = '*'; 
		else screen[80 * (r.start_y + r.len_y - 1) + i] = '#'; 
	}
	return 0;
}

int are_rooms_colliding(room_t a, room_t b){
	return rectangle_collide(a.start_x, a.start_y, a.len_x, a.len_y, b.start_x, b.start_y, b.len_x, b.len_y);	
}

int generate_random_rooms(map_t m, int amount, int min_x, int min_y, int vx, int vy){
	for (int i = 0; i < amount; i++){
		int invalid = 1;
		while (invalid){
			invalid = 0;
			init_room(&m[i], rand() % 78 + 1, rand() % 27 + 1, min_x + (rand() % vx), min_y + (rand() % vy));
			for (int j = 0; j < i; j++){
				invalid += are_rooms_colliding(m[i], m[j]);
			}
			invalid += (m[i].start_x + m[i].len_x > 80) || (m[i].start_y + m[i].len_y > 28);
		}
	}
	return 0;
}

