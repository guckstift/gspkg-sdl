
#include <gs/utils.h>
#include "window.h"
#include "sdl.h"

using namespace gs;

namespace sdl
{
	Window::Window () :
		title ("SDL window"), width (800), height (600), glMajorVer (0), glMinorVer (0),
		sdlWnd (0), sdlGlCtx (0)
	{
	}
	
	Window::Window (char *_title, int _width, int _height, int _glMajorVer, int _glMinorVer) :
		Window ()
	{
		create (_title, _width, _height, _glMajorVer, _glMinorVer);
	}
	
	bool Window::create (char *_title, int _width, int _height, int _glMajorVer,
		int _glMinorVer)
	{
		title = _title;
		width = _width;
		height = _height;
		glMajorVer = _glMajorVer;
		glMinorVer = _glMinorVer;
		
		initVideo ();
		
		if (glMajorVer)	{
			SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, glMajorVer);
			SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, glMinorVer);
			SDL_GL_SetAttribute (SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		}

		sdlWnd = SDL_CreateWindow (
			title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height, SDL_WINDOW_RESIZABLE | (glMajorVer ? SDL_WINDOW_OPENGL : 0)
		);

		if (sdlWnd == NULL) {
			errLog << "SDL error: " << SDL_GetError () << nl;
			return false;
		}
		
		if (glMajorVer)
		{
			sdlGlCtx = SDL_GL_CreateContext (sdlWnd);
	
			if (sdlGlCtx == NULL) {
				errLog << "SDL error: " << SDL_GetError () << nl;
				destroy ();
				return false;
			}
		}
		
		SDL_SetWindowData (sdlWnd, "gs-sdl-window-instance", this);
		
		return true;
	}

	void Window::destroy ()
	{
		SDL_DestroyWindow (sdlWnd);
	}

	void Window::present ()
	{
		if (sdlGlCtx) {
			SDL_GL_SwapWindow (sdlWnd);
		}
	}
	
	bool Window::makeCurrent ()
	{
		if (sdlGlCtx) {
			if (SDL_GL_MakeCurrent (sdlWnd, sdlGlCtx)) {
				errLog << "SDL error: " << SDL_GetError () << nl;
				return false;
			}
		}
			
		return true;
	}
}

