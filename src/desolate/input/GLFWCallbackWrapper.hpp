#ifndef __glfw_callback_wrapper_hpp_
#define __glfw_callback_wrapper_hpp_

#include "desolate/include.hpp"
#include "desolate/util/window/Window.hpp"

namespace desolate
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
        static void GLFWSrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    private:
        static void _init(GLFWwindow *window);
        static void _destroy(GLFWwindow *window);

    private:
        static input::Mouse *mouse;
        static input::Keyboard *keyboard;
    };
}

#endif // __glfw_callback_wrapper_hpp_