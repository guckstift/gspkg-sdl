
#pragma once

#include <SDL.h>
#include <glm/fwd.hpp>
#include <glm/vec2.hpp>

namespace sdl
{
	using glm::vec2;
	
	struct Window
	{
		Window ();
		bool create (char *_windowTitle = "SDL window", vec2 _windowSize = vec2(800, 600),
			bool _glEnabled = false);
		void destroy ();
		
		char *windowTitle;
		vec2 windowSize;
		bool glEnabled;
		SDL_Window *sdlWnd;
	};
}

