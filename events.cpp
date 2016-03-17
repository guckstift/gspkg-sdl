
#include "sdl.h"
#include "../gs/utils.h"
#include "events.h"
#include "window.h"

using namespace gs;

namespace sdl
{
	EventManager::EventManager () :
		running (false)
	{
		initSdl ();
	}
		
	void EventManager::handleEvents ()
	{
		SDL_Event event;
		SDL_Window* sdlWnd;
		Window* wnd;
		
		while (SDL_PollEvent (&event) == 1)
		{
			switch (event.type) {
				case SDL_QUIT:
					running = false;
					onQuit ();
					break;
				case SDL_WINDOWEVENT: {
					sdlWnd = SDL_GetWindowFromID (event.window.windowID);
					wnd = (Window*) SDL_GetWindowData (sdlWnd, "gs-sdl-window-instance");
					switch (event.window.event) {
						case SDL_WINDOWEVENT_RESIZED:
							wnd->width = event.window.data1;
							wnd->height = event.window.data2;
							onResize (*wnd, wnd->width, wnd->height);
							break;
					}
					break;
				}
			}
		}
	}

	void EventManager::loop ()
	{
		running = true;
		
		while (running) {
			handleEvents ();
			onUpdate ();
		}
	}
}

