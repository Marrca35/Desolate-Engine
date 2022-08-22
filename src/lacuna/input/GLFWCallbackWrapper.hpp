#ifndef __glfw_callback_wrapper_hpp_
#define __glfw_callback_wrapper_hpp_

#include "lacuna/include.hpp"
#include "lacuna/util/window/Window.hpp"
#include "Input.hpp"

namespace lacuna
{
    class GLFWCallbackWrapper
    {
    public:
        static void Init(Window &window);

        static void Destroy(Window &window);

        static void GLFWErrorCallback(int error, const char *description);
        static void GLFWFramebufferSizeCallback(GLFWwindow *window, int width, int height);
        static void GLFWMonitorCallback(GLFWmonitor *monitor, int event);
        static void GLFWJoystickCallback(int jid, int event);
        static void GLFWKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void GLFWCharCallback(GLFWwindow *window, unsigned int codepoint);
        static void GLFWCursorPosCallback(GLFWwindow *window, double xpos, double ypos);

    private:
        static void _init(GLFWwindow *window);
        static void _destroy(GLFWwindow *window);

    private:
        static input::Mouse &mouse;
        static input::Keyboard &keyboard;
        static Window& window;
    };
}

#endif // __glfw_callback_wrapper_hpp_