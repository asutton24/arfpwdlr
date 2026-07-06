#include "player.h"
#include "entity.h"
#include "map.h"

int player_update(player_t* p, entity_t* e, int e_size, map_t m, int m_size, char* screen_map, int input){
	int oldx = p->entity->x_pos;
	int oldy = p->entity->y_pos;
	int moved = 0;
	switch (input){
		case 'w':
			moved = 1;
			p->entity->y_pos--;
			break;
		case 'a':
			moved = 1;
			p->entity->x_pos--;
			break;
		case 's':
			moved = 1;
			p->entity->y_pos++;
			break;
		case 'd':
			moved = 1;
			p->entity->x_pos++;
			break;
		default:
			break;
	}
	if (moved){
		if (screen_map[80 * p->entity->y_pos + p->entity->x_pos] == '#' || p->entity->x_pos < 0 || p->entity->x_pos > 79 || p->entity->y_pos < 0 || p->entity->y_pos > 28){
			p->entity->x_pos = oldx;
			p->entity->y_pos = oldy;
			return 1;
		}		
		if (screen_map[80 * p->entity->y_pos + p->entity->x_pos] == '*'){
			int room = what_room_am_i_in(m, m_size, p->entity->x_pos, p->entity->y_pos);
			if (room == -1) return -1;
			m[room].active = !m[room].active;
		}	
		//if (screen_map[80 * p->entity->y_pos + p->entity->x_pos] == ' '){
		//	screen_map[80 * p->entity->y_pos + p->entity->x_pos] = 'x';
		//}
		if (screen_map[80 * oldy + oldx] == ' '){
			screen_map[80 * oldy + oldx] = 'x';
		}
	}
	for (int i = 0; i < e_size; i++){
		continue;
	}
	return 0;
}

int player_init(player_t* p){
	p->entity->hp = 1;
	p->entity->y_pos = 0;
	p->entity->x_pos = 0;
	p->entity->room = -1;
	return 0;
}
