#ifndef __window_hpp_
#define __window_hpp_

#include "lacuna/include.hpp"

namespace lacuna {
    class Window {
        public:
        Window(const char* name, int width, int height, int monitor);

        void Init();
        void Destroy();

        GLFWwindow* GetWindowHandle() { return window; }

        private:
            GLFWmonitor* getMonitor();
        private:
        GLFWwindow* window;

        const char* name;
        int width, height;
        int monitor;
    };
}
#endif // __window_hpp_