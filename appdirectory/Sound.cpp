#include "Sound.h"

//http://www.lazyfoo.net/SDL_tutorials/lesson11/index.php		for reference

//---------------------------------------------------------------------------
Mix_Music *music = NULL;
Mix_Chunk *bounce = NULL;
Mix_Chunk *hit = NULL;

Sound::Sound(void)
{
	// open 44.1KHz, signed 16bit, system byte order,
	//      stereo audio, using 1024 byte chunks
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096)==-1) {
	    printf("Mix_OpenAudio: %s\n", Mix_GetError());
	    exit(3);
	}
	// start SDL with audio support
	if(SDL_Init(SDL_INIT_EVERYTHING)==-1) {
	    printf("SDL_Init: %s\n", SDL_GetError());
	    exit(1);
	}
	Mix_Init(0);
}


void Sound::loadSounds()
{
	printf("a\n");
	music = Mix_LoadMUS("Sounds/music.wav");
	printf("b\n");
	bounce = Mix_LoadWAV("Sounds/bounce.wav");
	printf("c\n");
	hit = Mix_LoadWAV("Sounds/hit.wav");
	printf("d\n");
	Mix_PlayMusic(music,-1);
	printf("e\n");

}

//---------------------------------------------------------------------------
Sound::~Sound(void)
{
	// Mix_FreeMusic(music);
	printf("1\n");
	Mix_FreeChunk(bounce);
	printf("2\n");
	Mix_FreeChunk(hit);
	printf("3\n");
	Mix_CloseAudio();
	printf("4\n");
	Mix_Quit();
	printf("5\n");
	SDL_Quit();
	printf("6\n");
}

int Sound::toggleMusic()
{
	if(Mix_PlayingMusic() == 0)
	{
		return Mix_PlayMusic(music,-1);
	}
	else
	{
		if(Mix_PausedMusic() == 1)
		{
			Mix_ResumeMusic();
		}
		else
		{
			Mix_PauseMusic();
		}
	}
	return 0;
}

int Sound::playBounce()
{
	return Mix_PlayChannel(-1, bounce, 0);
}

int Sound::playHit()
{
	return Mix_PlayChannel(-1, hit, 0);
}
