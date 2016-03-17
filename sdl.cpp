
#include <SDL.h>
#include "sdl.h"
#include "../gs/utils.h"

using namespace gs;

static bool isInit = false;
static bool isInitVideo = false;
static bool isInitAudio = false;

namespace sdl
{
	bool initSdl ()
	{
		if (!isInit) {
			if (SDL_Init (0) != 0) {
				errLog << "SDL error: " << SDL_GetError () << nl;
				return false;
			}
			isInit = true;
		}
		
		return true;
	}
	
	void quit ()
	{
		if (isInit) {
			quitVideo ();
			quitAudio ();
			SDL_Quit ();
			isInit = false;
		}
	}
	
	bool initVideo ()
	{
		if (!isInit) {
			initSdl ();
		}
		if (!isInitVideo) {
			if (SDL_InitSubSystem (SDL_INIT_VIDEO) != 0) {
				errLog << "SDL error: " << SDL_GetError () << nl;
				return false;
			}
			isInitVideo = true;
		}
		
		return true;
	}
	
	void quitVideo ()
	{
		if (isInit && isInitVideo) {
			SDL_QuitSubSystem (SDL_INIT_VIDEO);
			isInitVideo = false;
		}
	}
	
	bool initAudio ()
	{
		if (!isInit) {
			initSdl ();
		}
		if (!isInitAudio) {
			if (SDL_InitSubSystem (SDL_INIT_AUDIO) != 0) {
				errLog << "SDL error: " << SDL_GetError () << nl;
				return false;
			}
			isInitAudio = true;
		}
		
		return true;
	}
	
	void quitAudio ()
	{
		if (isInit && isInitAudio) {
			SDL_QuitSubSystem (SDL_INIT_AUDIO);
			isInitAudio = false;
		}
	}
}

