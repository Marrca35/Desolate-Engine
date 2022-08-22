#include "Window.hpp"
#include "desolate/input/Input.hpp"

#include <iostream>

namespace desolate
{
    Window::Window(const char *name, int width, int height, int monitor)
        : name(name), width(width), height(height), monitor(monitor), fullscreen(false), keyboard(*this), mouse(*this) {}

    void Window::Init()
    {
        if (fullscreen)
        {
            window = glfwCreateWindow(width, height, name, getMonitor(), nullptr);
        }
        else
        {
            window = glfwCreateWindow(width, height, name, nullptr, nullptr);
        }
        if (!window)
        {
            ErrorHandler::ThrowError("FATAL: failed to initialize GLFW window!", ErrorType::RUNTIME);
        }
        if (!fullscreen)
        {
            glfwGetWindowSize(window, &width, &height);
            const GLFWvidmode *vidmode = glfwGetVideoMode(getMonitor());
            glfwSetWindowPos(window, (vidmode->width - width) / 2, (vidmode->height - height) / 2);
        }
    }

    void Window::Destroy()
    {
        glfwDestroyWindow(window);
    }

    GLFWmonitor *Window::getMonitor()
    {
        int count = 0;
        GLFWmonitor **monitors = glfwGetMonitors(&count);
        if (!count)
        {
            ErrorHandler::ThrowError("FATAL: couldn't initialize GLFW window, no monitors detected!", ErrorType::RUNTIME);
        }
        return monitors[monitor];
    }
}