#include <stdio.h>
#include "huge.h"

#include <GL/glew.h>
#include <GL/gl.h>

using namespace huge;

int main(int argc, char **argv)
{
	printf("Hello World!\n");
	test();

	// vector test
	Vector<3, int> *vec = new Vector<3, int>();
	vec->data[0] = 5;
	vec->data[1] = 2;
	vec->data[2] = 7;

	vec->add(2);

	printf("vec: %d, %d, %d\n", vec->data[0], vec->data[1], vec->data[2]);

	// opengl test
	sdl::init();
	sdl::Window *window = new sdl::Window();

	if(glewInit() != GLEW_OK)
    {
		printf("GLEW init failed!\n");
	}

	while(1)
	{
		SDL_Event e;
    	while(SDL_PollEvent(&e))
   		{
        	if(e.type == SDL_QUIT)
        	{
            	exit(0);
        	}
    	}

		window->clear();

		glBegin(GL_TRIANGLES);

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f( 0.0f, 1.0f, 0.0f);
		glVertex3f( 1.0f,-1.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f, 0.0f);

		glEnd();

		window->swap();
	}

	return 0;
}

