#ifndef VIDEO_H
#define VIDEO_H

char get_video_mode(void);
int set_video_mode(char mode);
int start_video(void);
int end_video(void);
int update_screen(char* screen);

#endif
