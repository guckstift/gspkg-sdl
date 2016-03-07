
#pragma once

#include <SDL.h>
#include <glm/fwd.hpp>
#include <glm/vec2.hpp>
#include "window.h"

namespace sdl
{
	using glm::vec2;
	
	struct GlWindow : Window
	{
		GlWindow ();
		bool create (int _glMajorVer, int _glMinorVer, char *_windowTitle = "SDL OpenGL window",
			vec2 _windowSize = vec2(800, 600));
		void present ();
		
		int glMajorVer;
		int glMinorVer;
		SDL_GLContext sdlGlCtx;
	};
}

