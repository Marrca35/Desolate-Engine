#ifndef __renderer_hpp_
#define __renderer_hpp_

#include "desolate/include.hpp"
#include "desolate/util/window/Window.hpp"
#include "desolate/input/GLFWCallbackWrapper.hpp"

namespace desolate {
    enum RendererAPI : int {
        VULKAN=0, DIRECTX=1, OPENGL=2,
    };

    class Renderer {
        public:
        static void Init(Window& window, RendererAPI api);
        static void Destroy(Window& window, RendererAPI api);

        static void Update(Window& window);
        static void Render();
        private:
        static void _init(Window& window, RendererAPI api);
        static void _destroy(Window& window, RendererAPI api);
    };
};

#endif // __renderer_hpp_