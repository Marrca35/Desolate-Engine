#include "GLFWCallbackWrapper.hpp"

#include "Input.hpp"

namespace lacuna
{
    void GLFWCallbackWrapper::Init(Window &window)
    {
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
        if (action == GLFW_PRESS) {
            GLFWCallbackWrapper::window.GetKeyboard().SetKeyPressed(key, true);
        }
        else
        {
            GLFWCallbackWrapper::window.GetKeyboard().SetKeyPressed(key, false);
        }
    }

    void GLFWCallbackWrapper::GLFWCharCallback(GLFWwindow *window, unsigned int codepoint)
    {
    }

    void GLFWCallbackWrapper::GLFWCursorPosCallback(GLFWwindow *window, double xpos, double ypos)
    {
    }
}