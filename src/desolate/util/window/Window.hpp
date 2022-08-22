#ifndef __window_hpp_
#define __window_hpp_

#include "desolate/include.hpp"
#include "desolate/util/error/ErrorHandler.hpp"
#include "desolate/input/Input.hpp"

namespace desolate
{
    class Window
    {
    public:
        Window(const char *name, int width, int height, int monitor);

        void Init();
        void Destroy();

        void SetFullscreen(bool fullscreen) { this->fullscreen = fullscreen; }

        GLFWwindow *GetWindowHandle() { return window; }
        input::Keyboard& GetKeyboard() { return keyboard; }
        input::Mouse& GetMouse() { return mouse; }
    private:
        GLFWmonitor *getMonitor();

    private:
        GLFWwindow *window;

        const char *name;
        int width, height;
        int monitor;
        bool fullscreen;
        input::Keyboard keyboard;
        input::Mouse mouse;
    };
}

#endif // __window_hpp_