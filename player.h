#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

typedef struct entity_t entity_t;
typedef struct {
	entity_t* entity;
	int mana;
	int score;
	int max_hp;
	int max_mana;
} player_t;

int player_update(player_t* p, entity_t* e, int e_size, map_t m, int m_size, char* screen_map, int input);
int player_init(player_t* p);

#endif
