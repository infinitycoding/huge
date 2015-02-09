#include <stdio.h>

#include <huge.h>
#include <huge/video/opengl.h>

#include <GL/glew.h> // should not be used

using namespace huge;

const char *vsh_source =
{
    "varying vec3 v; \
varying vec3 lightvec;\
varying vec3 normal;\
varying vec4 FrontColor;\
 \
void main(void) {\
  normal         = normalize(gl_NormalMatrix * gl_Normal);\
  v              = vec3(gl_ModelViewMatrix * gl_Vertex);\
  lightvec       = normalize(vec3(-4.0, 5.0, 3.0) - v);\
 \
  gl_TexCoord[0] = gl_MultiTexCoord0;\
  FrontColor     = gl_Color;\
 \
  gl_Position    = gl_ModelViewProjectionMatrix * gl_Vertex;\
}"
};

const char *fsh_source =
{
    "varying vec3 v;\
varying vec3 lightvec;\
varying vec3 normal;\
varying vec4 FrontColor;\
 \
uniform sampler2D Texture0;\
 \
void main(void) {\
  vec3 Eye       = normalize(-v);\
  vec3 Reflected = normalize(reflect( -lightvec, normal)); \
 \
  vec4 IAmbient  = 0.1 * gl_FrontMaterial.ambient;\
  vec4 IDiffuse  = 0.8 * max(dot(normal, lightvec), 0.0) * gl_FrontMaterial.diffuse;\
  vec4 ISpecular = 1.0 * pow(max(dot(Reflected, Eye), 0.0), gl_FrontMaterial.shininess) * gl_FrontMaterial.specular;\
 \
  gl_FragColor   = IAmbient + IDiffuse + ISpecular;\
}"
};

int main(int argc, char **argv)
{
    printf("Hello World!\n");
    test();

    // windows
    sdl::init();
    sdl::Window *window1 = new sdl::GLWindow("Window 1", Vector2i(800, 600));
    sdl::Window *window2 = new sdl::GLWindow("Window 2", Vector2i(400, 300));

    video::Context *context1 = new sdl::GLContext(window1);
    video::Context *context2 = new sdl::GLContext(window2);

    video::Device *dev1 = new video::OpenGLDevice(context1);
    video::Device *dev2 = new video::OpenGLDevice(context2);

    dev1->context->activate();
    if(glewInit() != GLEW_OK)
    {
        printf("GLEW init failed!\n");
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_COLOR_MATERIAL);

    dev1->clearColor(Color4d(0.0, 0.0, 0.4, 1.0f));
    /*
        GLuint program = glCreateProgram();
        GLuint vsh_id = glCreateShader(GL_VERTEX_SHADER);
        GLuint fsh_id = glCreateShader(GL_FRAGMENT_SHADER);

        int vsh_len = strlen(vsh_source);
        int fsh_len = strlen(fsh_source);

        glShaderSource(vsh_id, 1, (const GLchar**) &vsh_source, &vsh_len);
        glShaderSource(fsh_id, 1, (const GLchar**) &fsh_source, &fsh_len);

        glCompileShader(vsh_id);
        glCompileShader(fsh_id);

        glAttachShader(program, vsh_id);
        glAttachShader(program, fsh_id);
        glLinkProgram(program);

        glUseProgram(program);
    */

    glEnable(GL_LIGHTING);

    Light *light = new Light(Color4f(1.0f, 0.6f, 0.6f, 1.0f));
    light->update(dev1);
    light->enable(dev1);

    // mesh
    List<Mesh*> *meshes = loader::load_obj("test.obj");
    Mesh *mesh = meshes->popBack();

    // perspective
    Camera *cam1 = new Camera();
    Camera *cam2 = new Camera();
    Viewport *view1 = new Viewport(Vector2i(0, 0), Vector2i(800, 600), cam1);
    Viewport *view2 = new Viewport(Vector2i(0, 0), Vector2i(400, 300), cam2);
    cam1->translate(Vector3f(0.0f, -2.0f, -7.0f));
    cam2->translate(Vector3f(0.0f,  2.0f, -5.0f));
    cam2->rotation() = Vector4f(0.0f, 1.0f, 0.0f, 20.0f);

    // use cameras transformation
    dev1->useViewport(view1);
    dev1->useTransformation(*cam1);

    dev2->useViewport(view2);
    dev2->useTransformation(*cam2);


    while(1)
    {
        // poll events
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_WINDOWEVENT:
                    switch(e.window.event)
                    {
                        case SDL_WINDOWEVENT_CLOSE:
                            SDL_Event quit;
                            quit.type = SDL_QUIT;
                            SDL_PushEvent(&quit);
                            break;
                    }
                    break;
                case SDL_QUIT:
                    exit(0);
            }
        }

        // clear buffers
        dev1->clear(video::COLOR_BUFFER_BIT | video::DEPTH_BUFFER_BIT);
        dev2->clear(video::COLOR_BUFFER_BIT | video::DEPTH_BUFFER_BIT);

        // set vertex color
        dev1->color(Color4ub(0xff, 0xff, 0xff, 0xff));
        dev2->color(Color4ub(0x44, 0x55, 0x11, 0xff));

        // render mesh
        dev1->pushMatrix();
        mesh->renderImmediate(dev1);
        dev1->translate(Vector3f(3.0f, 0.0f, 0.0f));
        mesh->renderImmediate(dev1);
        dev1->translate(Vector3f(-6.0f, 0.0f, 0.0f));
        mesh->renderImmediate(dev1);
        dev1->popMatrix();

        dev1->pushMatrix();
        dev1->translate(Vector3f(0.0f, 0.0f, -3.0f));
        mesh->renderImmediate(dev1);
        dev1->translate(Vector3f(3.0f, 0.0f, 0.0f));
        mesh->renderImmediate(dev1);
        dev1->translate(Vector3f(-6.0f, 0.0f, 0.0f));
        mesh->renderImmediate(dev1);
        dev1->popMatrix();

        mesh->renderImmediate(dev2);

        // swap windows
        dev1->context->activate();
        window1->swap();

        dev2->context->activate();
        window2->swap();
    }

    return 0;
}


