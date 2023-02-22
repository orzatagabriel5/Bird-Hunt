#include "lab_m1/lab1/lab1.h"

#include <vector>
#include <iostream>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Lab1::Lab1()
{
    // TODO(student): Never forget to initialize class variables!

}


Lab1::~Lab1()
{
}


void Lab1::Init()
{
    // Load a mesh from file into GPU memory. We only need to do it once,
    // no matter how many times we want to draw this mesh.
    {
        Mesh* mesh1 = new Mesh("box");
        mesh1->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
        meshes[mesh1->GetMeshID()] = mesh1;

        Mesh* mesh2 = new Mesh("teapot");
        mesh2->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "teapot.obj");
        meshes[mesh2->GetMeshID()] = mesh2;

        Mesh* mesh3 = new Mesh("bunny");
        mesh3->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "animals"), "bunny.obj");
        meshes[mesh3->GetMeshID()] = mesh3;

        Mesh* mesh4 = new Mesh("plane");
        mesh4->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "plane50.obj");
        meshes[mesh4->GetMeshID()] = mesh4;

    }

    // TODO(student): Load some more meshes. The value of RESOURCE_PATH::MODELS
    // is actually a path on disk, go there and you will find more meshes.
    red = 0;
    blue = 255;
    green = 0;
    
}


void Lab1::FrameStart()
{
}


void Lab1::Update(float deltaTimeSeconds)
{
    glm::ivec2 resolution = window->props.resolution;

    // Sets the clear color for the color buffer

    // TODO(student): Generalize the arguments of `glClearColor`.
    // You can, for example, declare three variables in the class header,
    // that will store the color components (red, green, blue).
    glClearColor(red, green, blue, 1);

   

    // Clears the color buffer (using the previously set color) and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);

    // Render the object
    RenderMesh(meshes["box"], glm::vec3(w, 0.5f, s), glm::vec3(0.5f));

    // Render the object again but with different properties
    RenderMesh(meshes["box"], glm::vec3(-1, 0.5f, 0));

    // TODO(student): We need to render (a.k.a. draw) the mesh that
    // was previously loaded. We do this using `RenderMesh`. Check the
    // signature of this function to see the meaning of its parameters.
    // You can draw the same mesh any number of times.

    if (x == 0) {
        RenderMesh(meshes["bunny"], glm::vec3(0, 0.5f, 0), glm::vec3(0.01f));
    }
    else if (x == 1) {
        RenderMesh(meshes["teapot"], glm::vec3(0, 0.5f, 0), glm::vec3(0.5f));
    }
    else if (x == 2){
        RenderMesh(meshes["box"], glm::vec3(0, 0.5f, 0), glm::vec3(0.5f));
    }



}


void Lab1::FrameEnd()
{
    DrawCoordinateSystem();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Lab1::OnInputUpdate(float deltaTime, int mods)
{
    // Treat continuous update based on input

    // TODO(student): Add some key hold events that will let you move
    // a mesh instance on all three axes. You will also need to
    // generalize the position used by `RenderMesh`.

    if (window->KeyHold(GLFW_KEY_W)) {
        w += 0.01;
    }

    if (window->KeyHold(GLFW_KEY_S)) {
        s += 01;
    }

}


void Lab1::OnKeyPress(int key, int mods)
{
    // Add key press event
    if (key == GLFW_KEY_F) {
        // TODO(student): Change the values of the color components.
        red = 0;
        blue = 0;
        green = 255;

    }

    if (key == GLFW_KEY_Q) {
        if (x < 2) {
            x++;
        }
        else {
            x = 0;
        }
    }

    // TODO(student): Add a key press event that will let you cycle
    // through at least two meshes, rendered at the same position.
    // You will also need to generalize the mesh name used by `RenderMesh`.

}


void Lab1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Lab1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Lab1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Lab1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Lab1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
    // Treat mouse scroll event
}


void Lab1::OnWindowResize(int width, int height)
{
    // Treat window resize event
}
