#ifndef __Sound_h_
#define __Sound_h_

#include "SDL.h"
#include "SDL_mixer.h"

//---------------------------------------------------------------------------
class Sound{
	public:
		Sound(void);
		~Sound(void);
		void loadSounds(void);
		int toggleMusic(void);
		int playBounce(void);
		int playHit(void);
};

#endif // #ifndef __Sound_h_