#include "video.h"

int main(int argc, char** argv){
	char screen[4800];
	start_video();
	for (int i = 0; i < 4800; i++) screen[i] = ' ';
	while (update_screen(screen) != 'q');
	end_video();
	return 0;
}
