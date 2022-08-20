#ifndef __window_hpp_
#define __window_hpp_

#include "lacuna/include.hpp"
#include "GLFWCallbackWrapper.hpp"
#include "lacuna/util/error/ErrorHandler.hpp"

namespace lacuna {
    class Window {
        public:
        Window(const char* name, int width, int height, int monitor);

        void Init();
        void Destroy();

        void SetFullscreen(bool fullscreen) { this->fullscreen = fullscreen; }

        GLFWwindow* GetWindowHandle() { return window; }

        private:
            GLFWmonitor* getMonitor();
        private:
        GLFWwindow* window;

        const char* name;
        int width, height;
        int monitor;
        bool fullscreen;
    };
}

#endif // __window_hpp_