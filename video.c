#include "terminal.h"

char video_mode = 't';

char get_video_mode(void){
	return video_mode;
}

int set_video_mode(char mode){
	if (mode != 't' && mode != 'g') return 1;
	video_mode = mode;
	return 0;
}

int start_video(void){
	switch (video_mode){
		case 't':
			return terminal_init();
		case 'g':
			return 0;		
	}
}

int end_video(void){
	switch (video_mode){
		case 't':
			return terminal_end();
		case 'g':
			return 0;		
	}
}

int update_screen(char* screen){
	switch (video_mode){
		case 't':
			return terminal_update(screen);
		case 'g':
			return 0;		
	}
}
