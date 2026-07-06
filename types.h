#ifndef TYPES_H
#define TYPES_H

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

typedef struct {
	entity_t* entity;
	int mana;
	int score;
	int max_hp;
	int max_mana;
} player_t;

typedef struct {
	int start_x;
	int start_y;
	int len_x;
	int len_y;
	int active;
} room_t;

typedef room_t* map_t;

#endif
