#include <stdio.h>

#include <huge.h>
#include <huge/video/opengl.h>

#include <GL/glew.h> // should not be used
#include <GL/gl.h>

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
  lightvec       = normalize(gl_LightSource[0].position.xyz - v);\
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
  vec4 IAmbient  = gl_LightSource[0].ambient * gl_FrontMaterial.ambient;\
  vec4 IDiffuse  = gl_LightSource[0].diffuse * max(dot(normal, lightvec), 0.0) * gl_FrontMaterial.diffuse;\
  vec4 ISpecular = gl_LightSource[0].specular * pow(max(dot(Reflected, Eye), 0.0), gl_FrontMaterial.shininess) * gl_FrontMaterial.specular;\
 \
  gl_FragColor   = vec4((IAmbient + IDiffuse) * texture2D(Texture0, vec2(gl_TexCoord[0])) + ISpecular);\
}"
};

int main(int argc, char **argv)
{
    // hello
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

    // gl
    dev1->context->activate();
    if(glewInit() != GLEW_OK)
    {
        printf("GLEW init failed!\n");
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    dev1->clearColor(Color4d(0.0, 0.0, 0.4, 1.0f));

    // shaders
    video::GLSL_Program *program = new video::GLSL_Program();
    video::GLSL_Shader *vshader = new video::GLSL_Shader(GL_VERTEX_SHADER, vsh_source, strlen(vsh_source));
    video::GLSL_Shader *fshader = new video::GLSL_Shader(GL_FRAGMENT_SHADER, fsh_source, strlen(fsh_source));
    program->attach(vshader);
    program->attach(fshader);
    program->link();
    program->use();

    GLuint location = program->getUniformLocation("Texture0");
    glUniform1i(location, 0);

    // lights
    Light *light = new Light(Color4f(1.0f, 1.0f, 1.0f, 1.0f));
    light->translation() = Vector3f(-6.0f, 5.0f, -2.0f);
    light->enable(dev1);

    // mesh
    List<Mesh*> *meshes = loader::load_obj("test.obj");
    Mesh *mesh = meshes->popBack();

    // texture
    Texture2ub *tex = loader::load_texture("texture.png");

    // objects
    List<struct texture_mapping> *textures = new List<struct texture_mapping>();
    textures->pushBack({0, tex});
    dev1->enableTexture(0);

    Object *objects[6];
    objects[0] = new Object(mesh, new Material(Color4f(1.0f, 1.0f, 1.0f, 1.0f), 0.0f, textures), Vector3f(-3.0f, 0.0f, 0.0f));
    objects[1] = new Object(mesh, new Material(Color4f(1.0f, 1.0f, 1.0f, 1.0f), 0.2f, textures), Vector3f( 0.0f, 0.0f, 0.0f));
    objects[2] = new Object(mesh, new Material(Color4f(1.0f, 1.0f, 1.0f, 1.0f), 0.4f, textures), Vector3f( 3.0f, 0.0f, 0.0f));
    objects[3] = new Object(mesh, new Material(Color4f(1.0f, 1.0f, 1.0f, 1.0f), 1.0f, textures), Vector3f(-3.0f, 0.0f,-3.0f));
    objects[4] = new Object(mesh, new Material(Color4f(1.0f, 1.0f, 1.0f, 1.0f), 0.8f, textures), Vector3f( 0.0f, 0.0f,-3.0f));
    objects[5] = new Object(mesh, new Material(Color4f(1.0f, 1.0f, 1.0f, 1.0f), 0.6f, textures), Vector3f( 3.0f, 0.0f,-3.0f));

    // perspective
    Camera *cam1 = new Camera();
    Camera *cam2 = new Camera();
    Viewport *view1 = new Viewport(Vector2i(0, 0), Vector2i(800, 600), cam1);
    Viewport *view2 = new Viewport(Vector2i(0, 0), Vector2i(400, 300), cam2);
    cam1->translate(Vector3f(0.0f, 5.0f, 4.0f));
    cam1->rotation() = Vector4f(1.0f, 0.0f, 0.0f, -30.0f);

    cam2->translate(Vector3f(0.0f, -2.0f, 5.0f));
    cam2->rotation() = Vector4f(1.0f, 0.0f, 0.0f, 10.0f);

    dev1->useViewport(view1);
    dev2->useViewport(view2);

    printf("begin main loop..\n");

    // main loop
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

        // transform
        dev1->pushMatrix();
        dev2->pushMatrix();
        dev1->transform(*cam1);
        dev2->transform(*cam2);

        // light
        dev1->pushMatrix();
        light->useTransformation(dev1);
        light->update(dev1);
        dev1->popMatrix();

        // set vertex color
        dev1->color(Color4ub(0xff, 0xff, 0xff, 0xff));
        dev2->color(Color4ub(0x44, 0x55, 0x11, 0xff));

        // render mesh
        int i;
        for(i = 0; i < 6; i++)
            objects[i]->renderImmediate(dev1);

        mesh->renderImmediate(dev2);

        dev1->popMatrix();
        dev2->popMatrix();

        // swap windows
        dev1->context->activate();
        window1->swap();

        dev2->context->activate();
        window2->swap();
    }

    return 0;
}


