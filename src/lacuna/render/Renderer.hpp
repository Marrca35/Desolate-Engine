#ifndef __renderer_hpp_
#define __renderer_hpp_

#include "lacuna/include.hpp"
#include "lacuna/util/window/Window.hpp"
#include "lacuna/util/window/GLFWCallbackWrapper.hpp"

namespace lacuna {
    enum RendererAPI : int {
        VULKAN=0, DIRECTX=1, OPENGL=2,
    };

    class Renderer {
        public:
        static void Init(Window& window, RendererAPI api);
        static void Destroy(Window& window, RendererAPI api);
        private:
    };
};

#endif // __renderer_hpp_