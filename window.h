
#pragma once

#include <SDL.h>
#include <sdl/events.h>

namespace sdl
{
	struct Window
	{
		Window ();
		Window (char *_title, int _width = 800, int _height = 600,
			int _glMajorVer = 0, int _glMinorVer = 0);
		bool create (char *_title = "SDL window", int _width = 800, int _height = 600,
			int _glMajorVer = 0, int _glMinorVer = 0);
		void destroy ();
		void present ();
		bool makeCurrent ();
				
		char *title;
		int width;
		int height;
		int glMajorVer;
		int glMinorVer;
		SDL_Window *sdlWnd;
		SDL_GLContext sdlGlCtx;
	};
}

