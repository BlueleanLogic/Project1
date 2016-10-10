#include "Sound.h"

//http://www.lazyfoo.net/SDL_tutorials/lesson11/index.php		for reference

//---------------------------------------------------------------------------
Mix_Music *music = NULL;

Sound::Sound(void)
{
	// start SDL with audio support
	if(SDL_Init(SDL_INIT_EVERYTHING)==-1) {
	    printf("SDL_Init: %s\n", SDL_GetError());
	    exit(1);
	}
	Mix_Init(0);
	// open 44.1KHz, signed 16bit, system byte order,
	//      stereo audio, using 1024 byte chunks
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096)==-1) {
	    printf("Mix_OpenAudio: %s\n", Mix_GetError());
	    exit(3);
	}
	printf("1=====================================================================\n");
	music = Mix_LoadMUS("Sounds/music.wav");
	printf("2=====================================================================\n");
	Mix_PlayMusic(music,-1);
	printf("3=====================================================================\n");

}
//---------------------------------------------------------------------------
Sound::~Sound(void)
{
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	Mix_Quit();
	SDL_Quit();
}

