#ifndef __glfw_callback_wrapper_hpp_
#define __glfw_callback_wrapper_hpp_

#include "lacuna/include.hpp"

namespace lacuna {
    class GLFWCallbackWrapper {
        public:
        static void Init();

        static void Destroy();

        static void GLFWErrorCallback(int error, const char* description);
        private:
    };
}

#endif // __glfw_callback_wrapper_hpp_