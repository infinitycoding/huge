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
	Vector3f *vec = new Vector3f();
	vec->data[0] = 5.0f;
	vec->data[1] = 2.0f;
	vec->data[2] = 7.0f;

	*vec += 2.2f;

	Vector<1, Vector<3, int> > *vec2 = new Vector<1, Vector<3, int> >();
	vec2->data[0].data[0] = 1;
	vec2->data[0].data[1] = 1;
	vec2->data[0].data[2] = 1;

	*vec2 += 1;

	printf("vec: %f, %f, %f\n", vec->data[0], vec->data[1], vec->data[2]);
	printf("vec2: %d, %d, %d\n", vec2->data[0].data[0], vec2->data[0].data[1], vec2->data[0].data[2]);


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

