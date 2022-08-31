#include "Window.hpp"
#include "desolate/input/Input.hpp"

#include <iostream>

namespace desolate
{
    Window::Window(const char *name, int width, int height, int monitor)
        : m_name(name), m_width(width), m_height(height), m_monitor(monitor), m_fullscreen(false), m_keyboard(*this), m_mouse(*this) {}

    void Window::Init()
    {
        if (m_fullscreen)
        {
            m_window = glfwCreateWindow(m_width, m_height, m_name, getMonitor(), nullptr);
        }
        else
        {
            m_window = glfwCreateWindow(m_width, m_height, m_name, nullptr, nullptr);
        }
        if (!m_window)
        {
            ErrorHandler::ThrowError("FATAL: failed to initialize GLFW window!", ErrorType::RUNTIME);
        }
        if (!m_fullscreen)
        {
            glfwGetWindowSize(m_window, &m_width, &m_height);
            const GLFWvidmode *vidmode = glfwGetVideoMode(getMonitor());
            glfwSetWindowPos(m_window, (vidmode->width - m_width) / 2, (vidmode->height - m_height) / 2);
        }
    }

    void Window::Destroy()
    {
        glfwDestroyWindow(m_window);
    }

    void Window::ChangeFullscreen()
    {
        this->m_fullscreen = !m_fullscreen;
        if (m_fullscreen)
        {
            const GLFWvidmode *vidmode = glfwGetVideoMode(getMonitor());
            glfwSetWindowMonitor(m_window, getMonitor(), 0, 0, vidmode->width, vidmode->height, vidmode->refreshRate);
        }
        else
            glfwSetWindowMonitor(m_window, nullptr, 0, 0, m_width, m_height, GLFW_DONT_CARE);
    }

    GLFWmonitor *Window::getMonitor()
    {
        int count = 0;
        GLFWmonitor **monitors = glfwGetMonitors(&count);
        if (!count)
        {
            ErrorHandler::ThrowError("FATAL: couldn't initialize GLFW window, no monitors detected!", ErrorType::RUNTIME);
        }
        return monitors[m_monitor];
    }
}