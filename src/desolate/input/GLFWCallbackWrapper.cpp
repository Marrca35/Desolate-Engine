#include "GLFWCallbackWrapper.hpp"

#include "Input.hpp"

#include <iostream>

namespace desolate
{
    input::Keyboard *GLFWCallbackWrapper::keyboard;
    input::Mouse *GLFWCallbackWrapper::mouse;

    void GLFWCallbackWrapper::Init(Window &window)
    {
        keyboard = &window.GetKeyboard();
        mouse = &window.GetMouse();
        _init(window.GetWindowHandle());
    }

    void GLFWCallbackWrapper::_init(GLFWwindow *window)
    {
        glfwSetErrorCallback(GLFWErrorCallback);
        glfwSetFramebufferSizeCallback(window, GLFWFramebufferSizeCallback);
        glfwSetMonitorCallback(GLFWMonitorCallback);
        glfwSetJoystickCallback(GLFWJoystickCallback);
        glfwSetKeyCallback(window, GLFWKeyCallback);
        glfwSetCharCallback(window, GLFWCharCallback);
        glfwSetCursorPosCallback(window, GLFWCursorPosCallback);
        glfwSetScrollCallback(window, GLFWSrollCallback);
    }

    void GLFWCallbackWrapper::Destroy(Window &window)
    {
        _destroy(window.GetWindowHandle());
    }

    void GLFWCallbackWrapper::_destroy(GLFWwindow *window)
    {
        glfwSetErrorCallback(nullptr);
    }

    void GLFWCallbackWrapper::GLFWErrorCallback(int error, const char *description)
    {
        std::cerr << "[GLFW ERROR " << error << "]: " << description << std::endl;
    }

    void GLFWCallbackWrapper::GLFWFramebufferSizeCallback(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void GLFWCallbackWrapper::GLFWMonitorCallback(GLFWmonitor *monitor, int event)
    {
    }

    void GLFWCallbackWrapper::GLFWJoystickCallback(int jid, int event)
    {
    }

    void GLFWCallbackWrapper::GLFWKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_UNKNOWN)
        {
            return;
        }
        if (action == GLFW_PRESS)
        {
            keyboard->SetKeyPressed(key, true);
        }
        else if (action == GLFW_REPEAT)
        {
            keyboard->SetKeyRepeated(key, true);
        }
        else if (action == GLFW_RELEASE)
        {
            keyboard->SetKeyPressed(key, false);
            keyboard->SetKeyRepeated(key, false);
        }
    }

    void GLFWCallbackWrapper::GLFWCharCallback(GLFWwindow *window, unsigned int codepoint)
    {
    }

    void GLFWCallbackWrapper::GLFWCursorPosCallback(GLFWwindow *window, double xpos, double ypos)
    {
        mouse->SetPosition(xpos, ypos);
    }

    void GLFWCallbackWrapper::GLFWSrollCallback(GLFWwindow* window, double xoffset, double yoffset)
    {
        mouse->SetScrollOffset(xoffset, yoffset);
    }
}