#include "entity.h"
#include "map.h"
#include "player.h"
#include "video.h"

int init_level(map_t m, int* m_size, entity_t* e, int e_size, int level_num){
	generate_random_rooms(m, 5, 7, 5, 4, 4);
	*m_size = 5;
	for (int i = 1; i < e_size; i++){
		e[i].hp = -1;
	}
	return 0;		
}

int level_loop(map_t m, int m_size, entity_t* e, int e_size, player_t* p, char* screen, char* map){
	int input = 'x';
	int status;
	for (int i = 0; i < 2400; i++) screen[i] = ' ';
	for (int i = 0; i < 2400; i++) map[i] = ' ';
	for (int i = 0; i < m_size; i++){
		draw_room(map, m[i]);	
	}
	do {	
		for (int i = 0; i < m_size; i++){
			draw_room(map, m[i]);	
		}
		for (int i = 0; i < 2400; i++) screen[i] = map[i];
		for (int i = 0; i < e_size; i++) draw_entity(e[i], m, screen);
		input = update_screen(screen);
		status = update_entities(p, e, e_size, m, m_size, map, input);	
		if (status == -1) return 0;
	} while (input != 'q');
}

int start_game(void){
	player_t p;
	entity_t entities[64];
	p.entity = &entities[0];
	room_t rooms[16];
	char screen[2400];
	char map[2400];
	int r_size;
	int e_size = 64;
	init_level(rooms, &r_size, entities, e_size, 1);
	player_init(&p);
	return level_loop(rooms, r_size, entities, e_size, &p, screen, map);
}
