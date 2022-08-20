#ifndef __renderer_hpp_
#define __renderer_hpp_
#include "Window.hpp"

#include "lacuna/include.hpp"

namespace lacuna {
    enum RendererAPI : int {
        VULKAN=0, DIRECTX=1, OPENGL=2,
    };

    class Renderer {
        public:
        Renderer(RendererAPI api, Window &window);
        void Init();
        void Destroy();
        private:
        RendererAPI api;
        Window& window;
    };
};
#endif // __renderer_hpp_