#include "Window.hpp"

namespace lacuna {
    Window::Window(const char* name, int width, int height, int monitor) :
        name(name), width(width), height(height), monitor(monitor) { }

    void Window::Init() {
        window = glfwCreateWindow(width, height, name, getMonitor(), nullptr);
        if (!window) {
            
        }
    }

    void Window::Destroy() {

    }

    GLFWmonitor* Window::getMonitor() {

    }
}