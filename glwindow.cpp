
#include <GL/glew.h>
#include "glwindow.h"
#include "sdl.h"
#include "../gs/utils.h"

using namespace gs;

namespace sdl
{
	GlWindow::GlWindow ()
	{
	}
	
	bool GlWindow::create (int _glMajorVer, int _glMinorVer, char *_windowTitle, vec2 _windowSize)
	{
		glMajorVer = _glMajorVer;
		glMinorVer = _glMinorVer;
		
		SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, glMajorVer);
		SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, glMinorVer);
		SDL_GL_SetAttribute (SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		
		if (!Window::create (_windowTitle, _windowSize, true)) {
			return false;
		}
		
		sdlGlCtx = SDL_GL_CreateContext (sdlWnd);
	
		if (sdlGlCtx == NULL) {
			errLog << "SDL error: " << SDL_GetError () << nl;
			destroy ();
			return false;
		}
	
		glewExperimental = GL_TRUE;
		GLenum err = glewInit ();
	
		if (err != GLEW_OK) {
			errLog << "GLEW error: " << glewGetErrorString (err) << nl;
			return false;
		}
		
		return true;
	}

	void GlWindow::present ()
	{
		SDL_GL_SwapWindow (sdlWnd);
	}
}

