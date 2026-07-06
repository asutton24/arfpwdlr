#ifndef ENTITY_H
#define ENTITY_H

#include "types.h"

int init_entity(entity_t* e, int x, int y, e_type t, int hp, int atk, int def, int r, int l);
int destroy_entity(entity_t* e);
int draw_entity(entity_t e, map_t m, char* screen);
int update_entities(player_t* p, entity_t* e, int e_size, map_t m, int m_size, char* screen_map, int input);
#endif
