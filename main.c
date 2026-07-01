#include "video.h"
#include "level.h"

int main(int argc, char** argv){
	char screen[4800];
	room_t r;
	init_room(&r, 0, 0, 7, 7);
	for (int i = 0; i < 4800; i++) screen[i] = ' ';
	draw_room(screen, r);
	start_video();
	while (update_screen(screen) != 'q');
	end_video();
	return 0;
}
