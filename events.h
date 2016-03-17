
#pragma once

namespace sdl
{
	struct Window;
	
	struct EventManager
	{
		EventManager ();
		void handleEvents ();
		void handleUpdates ();
		void loop ();
		virtual void onUpdate () {}
		virtual void onQuit () {}
		virtual void onResize (Window& wnd, int width, int height) {}
		
		bool running;
	};
}

