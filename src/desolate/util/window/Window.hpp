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

        void ChangeFullscreen();

        GLFWwindow *GetWindowHandle() { return m_window; }
        input::Keyboard& GetKeyboard() { return m_keyboard; }
        input::Mouse& GetMouse() { return m_mouse; }
    private:
        GLFWmonitor *getMonitor();

    private:
        GLFWwindow *m_window;

        const char *m_name;
        int m_width, m_height;
        int m_monitor;
        int m_refreshRate;
        bool m_fullscreen;
        input::Keyboard m_keyboard;
        input::Mouse m_mouse;
    };
}

#endif // __window_hpp_