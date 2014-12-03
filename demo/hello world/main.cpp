#include <GL/glew.h>

#include <stdio.h>
#include "huge.h"

using namespace huge;

int main(int argc, char **argv)
{
	printf("Hello World!\n");
	test();

	sdl::init();
	sdl::Window *window = new sdl::Window();

	if(glewInit() != GLEW_OK)
    {
		printf("GLEW init failed!\n");
	}

	while(1);

	return 0;
}

