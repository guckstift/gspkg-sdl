
#include "window.h"
#include "sdl.h"
#include "../gs/utils.h"

using namespace gs;

namespace sdl
{
	Window::Window ()
	{
	}
	
	bool Window::create (char *_windowTitle, vec2 _windowSize, bool _glEnabled)
	{
		windowTitle = _windowTitle;
		windowSize = _windowSize;
		glEnabled = _glEnabled;
		
		initVideo ();
		
		sdlWnd = SDL_CreateWindow (
			windowTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, UNPACK2(windowSize),
			(glEnabled ? SDL_WINDOW_OPENGL : 0) | SDL_WINDOW_RESIZABLE
		);
	
		if (sdlWnd == NULL) {
			errLog << "SDL error: " << SDL_GetError () << nl;
			return false;
		}
		
		return true;
	}

	void Window::destroy ()
	{
		SDL_DestroyWindow (sdlWnd);
	}
}

