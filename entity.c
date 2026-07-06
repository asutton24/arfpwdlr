#include "entity.h"
#include "player.h"
#include "map.h"

int init_entity(entity_t* e, int x, int y, e_type t, int hp, int atk, int def, int r, int l){
	e->x_pos = x;
	e->y_pos = y;
	e->type = t;
	e->hp = hp;
	e->atk = atk;
	e->def = def;
	e->room = r;
	e->level = l;
	return 0;
}

int destroy_entity(entity_t* e){
	e->hp = -1;
	return 0;
}

int is_alive(entity_t e){
	return e.hp > 0;
}

int draw_entity(entity_t e, map_t m, char* screen){
	if (!is_alive(e)) return 0;
	if (e.room != -1 && m[e.room].active == 0) return 0;
	char to_draw;
	switch (e.type){
		case PLAYER:
			to_draw = '@';
			break;
		default:
			to_draw = '?';
	}
	screen[80 * e.y_pos + e.x_pos] = to_draw;
	return 0;
}

int update_entities(player_t* p, entity_t* e, int e_size, map_t m, int m_size, char* screen_map, int input){
	int status;
	for (int i = 0; i < e_size; i++){
		if (!is_alive(e[i])) continue;
		switch (e[i].type){
			case PLAYER:
				status = player_update(p, e, e_size, m, m_size, screen_map, input);
				if (status == 1) return 0;
				if (status == -1) return -1;
				break;
			case GENERIC:
				break;
		}
	}
}
