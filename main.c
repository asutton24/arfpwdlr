#include <stdlib.h>
#include <time.h>
#include "video.h"
#include "map.h"

int main(int argc, char** argv){
	srand(time(NULL));
	char screen[2400];
	room_t map[5];
	generate_random_rooms(map, 5, 7, 5, 4, 4);	
	for (int i = 0; i < 2400; i++) screen[i] = ' ';
	for (int i = 0; i < 5; i++) draw_room(screen, map[i]);
	start_video();
	while (update_screen(screen) != 'q');
	end_video();
	return 0;
}
