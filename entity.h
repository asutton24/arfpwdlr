#ifndef ENTITY_H
#define ENTITY_H

#include "map.h"
#include "player.h"

typedef enum {PLAYER, GENERIC} e_type;
typedef struct {
	int x_pos;
	int y_pos;
	e_type type;
	int hp;
	int atk;
	int def;
	int room;
	int level;
} entity_t;

int init_entity(entity_t* e, int x, int y, e_type t, int hp, int atk, int def, int r, int l);
int destroy_entity(entity_t* e);
int draw_entity(entity_t e, map_t m, char* screen);
int update_entities(player_t* p, entity_t* e, int e_size, map_t m, int m_size, char* screen_map, int input);
#endif
