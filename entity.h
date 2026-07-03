#ifndef ENTITY_H
#define ENTITY_H

typedef enum e_type = {PLAYER, GENERIC};
typedef struct {
	int x_pos;
	int y_pos;
	e_type type;
	int hp;
	int atk;
	int def;
	int room;
	int mana;
} entity_t;

#endif
