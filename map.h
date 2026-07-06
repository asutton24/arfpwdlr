#ifndef MAP_H
#define MAP_H

#include "types.h"

int init_room(room_t* r, int sx, int sy, int lx, int ly);
int am_i_in_room(room_t r, int x, int y);
int what_room_am_i_in(map_t m, int count, int x, int y );
int draw_room(char* screen, room_t r);
int generate_random_rooms(map_t m, int amount, int min_x, int min_y, int vx, int vy);
#endif
