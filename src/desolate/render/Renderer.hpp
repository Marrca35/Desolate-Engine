#ifndef __renderer_hpp_
#define __renderer_hpp_

#include "desolate/include.hpp"
#include "desolate/util/window/Window.hpp"
#include "desolate/input/GLFWCallbackWrapper.hpp"
#include "desolate/util/opengl/camera/OrthographicCamera.hpp"
#include "desolate/util/opengl/Buffers.hpp"
#include "desolate/util/opengl/Shader.hpp"
#include "desolate/util/opengl/VertexArray.hpp"

namespace desolate {
    enum RendererAPI : int {
        VULKAN=0, DIRECTX=1, OPENGL=2,
    };

    class Renderer {
        public:
        static void Init(Window& window, RendererAPI api);
        static void Destroy(Window& window, RendererAPI api);

        static void Update(Window& window);
        static void Render(Window& window, VertexArray &va, IndexBuffer &ib, std::unique_ptr<Shader> &shader);
        private:
        static void _init(Window& window, RendererAPI api);
        static void _destroy(Window& window, RendererAPI api);
        private:
        desolate::OrthographicCamera camera;
    };
};

#endif // __renderer_hpp_