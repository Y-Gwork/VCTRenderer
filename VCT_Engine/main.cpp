// VCT_Engine.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "render_window.h"
#include "initializer.h"
#include "scene/scene.h"
#include "interface/vct_interface.h"

int main(int argc, char* argv[])
{
    RenderWindow renderWindow;
    VCTInterface gui;
    Initializer initializer;
    // vct engine specific gui
    // open window and set rendering context
    renderWindow.Open();
    renderWindow.SetAsCurrentContext();
    // initialize context dependant external libs
    initializer.Start();
    // set interface to current renderwindow
    gui.Initialize(renderWindow);

    // draw
    while(!glfwWindowShouldClose(renderWindow.Handler()))
    {
        glfwPollEvents();
        gui.Draw();
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        gui.Render();
        glfwSwapBuffers(renderWindow.Handler());
    }

    return 0;
}
