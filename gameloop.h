#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "types.h"

int init_level(map_t m, int* m_size, entity_t* e, int e_size, int level_num);
int level_loop(map_t m, int m_size, entity_t* e, int e_size, player_t* p, char* screen, char* map);
int start_game(void);

#endif
