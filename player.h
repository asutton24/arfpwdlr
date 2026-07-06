#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"


int player_update(player_t* p, entity_t* e, int e_size, map_t m, int m_size, char* screen_map, int input);
int player_init(player_t* p);

#endif
