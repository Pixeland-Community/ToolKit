// Pixeland-Toolkit.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>

#include <SDL2/SDL.h>

#include <GL/glu.h>

std::string title = "Pixeland Toolkit";
SDL_Window *mainWindow;
SDL_GLContext mainContext;

bool setOpenGLAttributes();
bool setGLViewport(int width, int height);
void runGame();
void cleanup();

bool init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Failed to init SDL." << std::endl << "Error: " << SDL_GetError() << std::endl;
		return false;
	}

	mainWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);

	if (!mainWindow) {
		std::cout << "Unable to create window." << std::endl << "Error: " << SDL_GetError() << std::endl;
		return false;
	}

	mainContext = SDL_GL_CreateContext(mainWindow);

	if (!mainContext) {
		std::cout << "Unable to create context." << std::endl << "Error: " << SDL_GetError() << std::endl;
		return false;
	}

	setOpenGLAttributes();

	SDL_GL_SetSwapInterval(1);

	return true;
}

bool setOpenGLAttributes () {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	return true;
}

bool setGLViewport (int width, int height) {
	GLfloat ratio;

	if (height == 0)
		height = 1;

	ratio = GLfloat(width) / GLfloat(height);
	glViewport(0, 0, GLsizei(width), GLsizei(height));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return true;
}

int main() {
	if (!init())
		return -1;

	glClearColor(0.0, 0.0, 0.0, 1.0);
	SDL_GL_SwapWindow(mainWindow);
	setGLViewport(640, 480);
	runGame();
	cleanup();
	return 0;
}

void runGame() {
	bool loop = true;

	while (loop) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				loop = false;

			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					loop = false;
					break;
				case SDLK_r:
					// Cover with red and update
					glClearColor(1.0, 0.0, 0.0, 1.0);
					glClear(GL_COLOR_BUFFER_BIT);
					SDL_GL_SwapWindow(mainWindow);
					break;
				case SDLK_g:
					// Cover with green and update
					glClearColor(0.0, 1.0, 0.0, 1.0);
					glClear(GL_COLOR_BUFFER_BIT);
					SDL_GL_SwapWindow(mainWindow);
					break;
				case SDLK_b:
					// Cover with blue and update
					glClearColor(0.0, 0.0, 1.0, 1.0);
					glClear(GL_COLOR_BUFFER_BIT);
					SDL_GL_SwapWindow(mainWindow);
					break;
				default:
					break;
				}
			}
		}
	}
}

void cleanup() {
	// Delete our OpengL context
	SDL_GL_DeleteContext(mainContext);

	// Destroy our window
	SDL_DestroyWindow(mainWindow);

	// Shutdown SDL 2
	SDL_Quit();
}