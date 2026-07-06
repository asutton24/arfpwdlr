#include <stdlib.h>
#include <time.h>
#include "video.h"
#include "gameloop.h"

int main(int argc, char** argv){
	srand(time(NULL));
	start_video();
	start_game();
	end_video();
	return 0;
}
